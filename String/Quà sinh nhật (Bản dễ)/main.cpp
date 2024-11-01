#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    TrieNode* fail;
    bool end;
    TrieNode() : children(26, nullptr), fail(nullptr), end(false) {}
};

class AhoCorasick {
public:
    AhoCorasick(const vector<string>& patterns) {
        root = new TrieNode();
        buildTrie(patterns);
        buildFailureLinks();
    }

    void removeOccurrences(string& text) {
        TrieNode* node = root;
        int i = 0;
        while (i < text.size()) {
            int index = text[i] - 'a';
            while (node != root && node->children[index] == nullptr) {
                node = node->fail;
            }
            node = node->children[index];
            if (node == nullptr) node = root;
            if (node->end) {
                int len = patterns[node].size();
                text.erase(i - len + 1, len);
                i = max(0, i - len + 1);
                node = root;
            } else {
                ++i;
            }
        }
    }

private:
    TrieNode* root;
    unordered_map<TrieNode*, string> patterns;

    void buildTrie(const vector<string>& patterns) {
        for (const string& pattern : patterns) {
            TrieNode* node = root;
            for (char c : pattern) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->end = true;
            this->patterns[node] = pattern;
        }
    }

    void buildFailureLinks() {
        queue<TrieNode*> q;
        root->fail = root;
        for (TrieNode* child : root->children) {
            if (child != nullptr) {
                child->fail = root;
                q.push(child);
            }
        }
        while (!q.empty()) {
            TrieNode* node = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i) {
                TrieNode* child = node->children[i];
                if (child != nullptr) {
                    TrieNode* fail = node->fail;
                    while (fail != root && fail->children[i] == nullptr) {
                        fail = fail->fail;
                    }
                    if (fail->children[i] != nullptr) {
                        fail = fail->children[i];
                    }
                    child->fail = fail;
                    if (fail->end) {
                        child->end = true;
                    }
                    q.push(child);
                }
            }
        }
    }
};

int main() {
    string st;
    string t;
    cin >> st >> t;
    AhoCorasick ac({t});
    ac.removeOccurrences(st);
    cout << st;
    return 0;
}
