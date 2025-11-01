#!/usr/bin/env python3
"""
compare_tienks.py
Searches a directory tree for all C++ files named like "tienks.cpp" (case-insensitive),
normalizes them (strip comments and whitespace), then computes pairwise similarity
and shows unified diffs for differing files.

Usage:
    python compare_tienks.py [root_dir] [--min-diff 0.99] [--report out.txt]

By default root_dir is the current directory.
"""
import os
import sys
import re
import argparse
import difflib
import itertools
from collections import OrderedDict

CPP_NAME_RE = re.compile(r'(?i)^ti(en)?ks.*\.cpp$')

def find_tienks_files(root):
    matches = []
    for dirpath, dirs, files in os.walk(root):
        for f in files:
            if CPP_NAME_RE.match(f):
                matches.append(os.path.join(dirpath, f))
    return sorted(matches)

# Remove /* ... */ and //... comments (simple but works for common cases)
COMMENT_BLOCK_RE = re.compile(r'/\*.*?\*/', re.S)
COMMENT_LINE_RE = re.compile(r'//.*?$', re.M)

def strip_comments(text):
    text = COMMENT_BLOCK_RE.sub('', text)
    text = COMMENT_LINE_RE.sub('', text)
    return text

def normalize_text(text):
    # Remove comments
    t = strip_comments(text)
    # Replace Windows newlines and normalize whitespace
    lines = [l.strip() for l in t.splitlines()]
    # drop empty lines
    lines = [l for l in lines if l]
    # collapse multiple spaces inside lines
    lines = [re.sub(r'\s+', ' ', l) for l in lines]
    return '\n'.join(lines)


def read_file(path):
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        return f.read()


def pairwise_compare(files, original_texts, normalized_texts, min_diff=0.0):
    n = len(files)
    results = []
    for i, j in itertools.combinations(range(n), 2):
        f1 = files[i]
        f2 = files[j]
        norm1 = normalized_texts[f1]
        norm2 = normalized_texts[f2]
        if not norm1 and not norm2:
            ratio = 1.0
        else:
            ratio = difflib.SequenceMatcher(None, norm1, norm2).ratio()
        if ratio < min_diff:
            # produce unified diff on original files (line-wise)
            o1 = original_texts[f1].splitlines()
            o2 = original_texts[f2].splitlines()
            ud = '\n'.join(difflib.unified_diff(o1, o2, fromfile=f1, tofile=f2, lineterm=''))
        else:
            ud = None
        results.append({'file1': f1, 'file2': f2, 'similarity': ratio, 'diff': ud})
    return results


def print_report(files, results, out_stream=sys.stdout):
    print('Found {} file(s):'.format(len(files)), file=out_stream)
    for f in files:
        print(' -', f, file=out_stream)
    print('\nPairwise similarity matrix (0..1, 1=identical normalized):\n', file=out_stream)

    # header
    print('\t' + '\t'.join([os.path.basename(f) for f in files]), file=out_stream)
    # compute normalized texts for indexing
    idx = {f:i for i,f in enumerate(files)}
    # build matrix
    mat = [[None]*len(files) for _ in files]
    for r in results:
        i = idx[r['file1']]
        j = idx[r['file2']]
        mat[i][j] = r['similarity']
        mat[j][i] = r['similarity']
    for i,f in enumerate(files):
        row = [os.path.basename(f)] + [('{:.3f}'.format(mat[i][j]) if mat[i][j] is not None else ('1.000' if i==j else '-')) for j in range(len(files))]
        print('\t'.join(row), file=out_stream)
    print('\nDetailed diffs for pairs with differences (if any):\n', file=out_stream)
    any_diffs = False
    for r in results:
        if r['diff']:
            any_diffs = True
            print('--- DIFF: {}  <->  {}  (similarity={:.3f})'.format(os.path.basename(r['file1']), os.path.basename(r['file2']), r['similarity']), file=out_stream)
            print(r['diff'], file=out_stream)
            print('\n', file=out_stream)
    if not any_diffs:
        print('No diffs above threshold (all normalized files are similar).', file=out_stream)


def main(argv):
    parser = argparse.ArgumentParser(description='Compare TIENKS.cpp variants across folders')
    parser.add_argument('root', nargs='?', default='.', help='Root directory to search (default: current dir)')
    parser.add_argument('--min-diff', type=float, default=0.0, help='Only include diffs when similarity < min-diff (0..1). Default 0.0 (show all diffs).')
    parser.add_argument('--report', default=None, help='If set, write report to this file as well as stdout')
    args = parser.parse_args(argv)

    root = args.root
    files = find_tienks_files(root)
    if not files:
        print('No tienks/TIENKS cpp files found under:', root)
        return 1

    original_texts = OrderedDict()
    normalized_texts = {}
    for f in files:
        txt = read_file(f)
        original_texts[f] = txt
        normalized_texts[f] = normalize_text(txt)

    results = pairwise_compare(files, original_texts, normalized_texts, min_diff=args.min_diff)

    # Print to stdout and optionally to report file
    print_report(files, results, sys.stdout)
    if args.report:
        with open(args.report, 'w', encoding='utf-8') as out:
            print_report(files, results, out)
        print('\nWrote report to:', args.report)
    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
