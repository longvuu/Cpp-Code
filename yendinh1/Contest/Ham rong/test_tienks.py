#!/usr/bin/env python3
"""
test_tienks.py

- Finds all TIENKS/tienks C++ files (case-insensitive).
- Attempts to compile each with g++ to an executable.
- Implements a Python reference solver for the weighted-interval scheduling problem.
- Generates deterministic and random tests, runs each executable with a timeout,
  compares outputs with the reference, and prints a summary + a detailed report file.

Usage:
    python test_tienks.py [root_dir] [--runs 100] [--max-n 200] [--report out.txt]

Notes:
- This assumes a working C++ compiler accessible as `g++` in PATH. On Windows use MinGW/MSYS2 or install g++.
- If compilation fails for any file the script will skip running that executable and report the failure.
"""
import os
import sys
import re
import argparse
import subprocess
import tempfile
import random
import time
import shutil
from collections import OrderedDict

CPP_NAME_RE = re.compile(r'(?i)^ti(en)?ks.*\.cpp$')


def find_cpp_files(root):
    res = []
    for dirpath, dirs, files in os.walk(root):
        for f in files:
            if CPP_NAME_RE.match(f):
                res.append(os.path.join(dirpath, f))
    return sorted(res)


def compile_cpp(src, out_dir):
    base = os.path.splitext(os.path.basename(src))[0]
    exe = os.path.join(out_dir, base + '.exe')

    # Build list of compiler executables to try. Prefer ones on PATH, then common locations.
    compilers = []
    for name in ('g++', 'clang++'):
        p = shutil.which(name)
        if p:
            compilers.append(p)
    # common MinGW / MSYS2 locations
    common_paths = [r'D:\MinGW\bin\g++.exe', r'C:\MinGW\bin\g++.exe', r'C:\msys64\mingw64\bin\g++.exe', r'C:\msys64\mingw32\bin\g++.exe']
    for p in common_paths:
        if os.path.exists(p) and p not in compilers:
            compilers.append(p)

    if not compilers:
        # still allow trying just 'g++' so subprocess shows helpful error
        compilers = ['g++', 'clang++']

    last_log = ''
    for comp in compilers:
        cmds_to_try = [
            [comp, '-std=c++17', '-O2', src, '-o', exe],
            [comp, '-std=c++17', '-O2', src, '-o', exe, '-lstdc++fs'],
        ]
        for cmd in cmds_to_try:
            try:
                proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=30)
                log = proc.stdout.decode(errors='replace') + proc.stderr.decode(errors='replace')
                last_log = log
                if proc.returncode == 0:
                    return True, exe, log
            except FileNotFoundError as e:
                # compiler not found at that path
                last_log = str(e)
            except Exception as e:
                last_log = str(e)
    return False, exe, last_log


# Reference solver: sort by r, dp + binary search
import bisect

def reference_solver(lines):
    # lines: list of strings: first line n, then n lines with l r w
    it = iter(lines)
    try:
        n = int(next(it).strip())
    except StopIteration:
        return ''
    intervals = []
    for _ in range(n):
        l, r, w = map(int, next(it).split())
        intervals.append((l, r, w))
    intervals.sort(key=lambda x: x[1])
    ends = [r for (_, r, _) in intervals]
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        l, r, w = intervals[i - 1]
        # find last j with end <= l
        j = bisect.bisect_right(ends, l)  # returns index where ends[index-1] <= l < ends[index]
        # but we need last index with r <= l among first i-1 intervals
        # bisect_right on full ends gives position in full list; but we want within first i-1
        # Use bisect_right on ends up to i-1
        k = bisect.bisect_right(ends, l, 0, i - 1)
        dp[i] = max(dp[i - 1], dp[k] + w)
    return str(dp[n])


def run_executable(exe_path, input_text, timeout=2):
    try:
        proc = subprocess.run([exe_path], input=input_text.encode(), stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout)
        out = proc.stdout.decode().strip()
        err = proc.stderr.decode().strip()
        return proc.returncode, out, err
    except subprocess.TimeoutExpired:
        return None, None, 'TIMEOUT'
    except Exception as e:
        return -1, None, str(e)


def gen_random_test(n, coord_max=1000, weight_max=1000):
    arr = []
    for _ in range(n):
        a = random.randint(0, coord_max)
        b = random.randint(0, coord_max)
        if a == b:
            b = a + 1
        if a > b:
            a, b = b, a
        w = random.randint(0, weight_max)
        arr.append((a, b, w))
    lines = [str(n)] + ['{} {} {}'.format(a, b, w) for (a, b, w) in arr]
    return '\n'.join(lines) + '\n'


def main(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument('root', nargs='?', default='.', help='root to search')
    parser.add_argument('--runs', type=int, default=200, help='number of random tests')
    parser.add_argument('--max-n', type=int, default=200, help='max intervals per random test')
    parser.add_argument('--report', default='tienks_test_report.txt', help='report file')
    parser.add_argument('--seed', type=int, default=12345, help='random seed')
    args = parser.parse_args(argv)

    root = args.root
    random.seed(args.seed)

    cpp_files = find_cpp_files(root)
    if not cpp_files:
        print('No tienks cpp files found under', root)
        return 1

    tmpdir = tempfile.mkdtemp(prefix='tienks_test_')
    print('Compiling {} files into {}'.format(len(cpp_files), tmpdir))
    compiled = OrderedDict()
    for f in cpp_files:
        ok, exe, log = compile_cpp(f, tmpdir)
        compiled[f] = {'ok': ok, 'exe': exe, 'log': log}
        print(' -', os.path.basename(f), '->', 'OK' if ok else 'FAILED')
        if not ok:
            print('   compile log:', log[:1000].replace('\n', ' '))

    # Prepare test cases: some small deterministic cases + random
    tests = []
    # small deterministic
    tests.append(('sample-1', '4\n1 4 5\n1 3 8\n3 5 4\n4 6 9\n'))  # from one file comment
    tests.append(('single-interval', '1\n0 10 100\n'))
    tests.append(('disjoint', '3\n1 2 5\n3 4 6\n5 6 7\n'))
    tests.append(('nested', '3\n1 10 100\n2 3 10\n4 5 20\n'))
    tests.append(('same-ends', '3\n1 3 5\n1 3 10\n3 5 7\n'))

    # random tests
    runs = args.runs
    for i in range(runs):
        n = random.randint(0, min(50, args.max_n))  # keep sizes moderate for speed
        tests.append((f'rand-{i}', gen_random_test(n, coord_max=500, weight_max=1000)))

    # Run tests
    report_lines = []
    report_lines.append('TIENKS test harness report')
    report_lines.append('root: ' + os.path.abspath(root))
    report_lines.append('seed: {}'.format(args.seed))
    report_lines.append('compiled summary:')
    for f,info in compiled.items():
        report_lines.append('{} -> {}'.format(f, 'OK' if info['ok'] else 'FAILED'))
    report_lines.append('\nRunning {} tests...'.format(len(tests)))

    # For each test compute reference
    exe_results = {f: [] for f in cpp_files}
    failures = []
    for tid, (name, input_txt) in enumerate(tests):
        ref = reference_solver(input_txt.splitlines())
        for f, info in compiled.items():
            if not info['ok']:
                exe_results[f].append({'test': name, 'skipped': True})
                continue
            code, out, err = run_executable(info['exe'], input_txt, timeout=2)
            if code is None:
                # timeout
                exe_results[f].append({'test': name, 'ok': False, 'reason': 'TIMEOUT', 'out': out, 'err': err})
                failures.append((f, name, 'TIMEOUT'))
            elif code != 0 and err:
                exe_results[f].append({'test': name, 'ok': False, 'reason': 'RUNTIME_ERROR', 'out': out, 'err': err})
                failures.append((f, name, 'RUNTIME_ERROR'))
            else:
                # Compare outputs as stripped ints
                got = out.strip() if out is not None else ''
                # Some implementations may print text; try to extract last integer token
                got_token = None
                if got:
                    toks = re.findall(r'-?\d+', got)
                    if toks:
                        got_token = toks[-1]
                expected_token = re.search(r'-?\d+', ref).group(0) if re.search(r'-?\d+', ref) else ref
                ok = (got_token == expected_token)
                exe_results[f].append({'test': name, 'ok': ok, 'got': got, 'expected': ref})
                if not ok:
                    failures.append((f, name, 'WRONG', got, ref))

    # Summarize
    report_lines.append('\nSummary:')
    for f,info in compiled.items():
        total = sum(1 for r in exe_results[f] if not r.get('skipped'))
        passed = sum(1 for r in exe_results[f] if r.get('ok'))
        skipped = sum(1 for r in exe_results[f] if r.get('skipped'))
        report_lines.append('{} : passed {}/{}  skipped {}'.format(f, passed, total, skipped))

    if failures:
        report_lines.append('\nFailures (first 100 shown):')
        for t in failures[:200]:
            if t[2] == 'WRONG':
                report_lines.append('File: {} Test: {} WRONG -> got: {} expected: {}'.format(t[0], t[1], t[3], t[4]))
            else:
                report_lines.append('File: {} Test: {} ERROR: {}'.format(t[0], t[1], t[2]))
    else:
        report_lines.append('\nAll compiled executables matched the reference on generated tests.')

    # write report
    report_path = os.path.join(root, args.report)
    with open(report_path, 'w', encoding='utf-8') as f:
        f.write('\n'.join(report_lines))
    print('\n'.join(report_lines))
    print('\nReport written to', report_path)
    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
