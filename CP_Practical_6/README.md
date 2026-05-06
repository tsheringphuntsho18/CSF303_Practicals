Submit: code file, screenshots, and a reflection for the implementation

// 1. Implement the basic trie algorithm and perform the insert, search and deletion operations

#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;
class TrieNode {
public:
    unordered_map<char, shared_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    shared_ptr<TrieNode> root;

public:
    Trie() {
        root = make_shared<TrieNode>();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        auto current = root;
        for (char c : word) {
            if (!current->children[c]) {
                current->children[c] = make_shared<TrieNode>();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(const string& word) {
        auto current = root;
        for (char c : word) {
            if (!current->children[c]) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }

    // Delete a word from the trie
    bool remove(const string& word) {
        return removeHelper(root, word, 0);
    }

private:
    bool removeHelper(shared_ptr<TrieNode> node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                return node->children.empty();
            }
            return false;
        }

        char c = word[depth];
        if (removeHelper(node->children[c], word, depth + 1)) {
            node->children.erase(c);
            return !node->isEndOfWord && node->children.empty();
        }
        return false;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");

    cout << "Search 'hello': " << trie.search("hello") << endl;
    cout << "Search 'world': " << trie.search("world") << endl;
    cout << "Search 'trie': " << trie.search("trie") << endl;

    trie.remove("hello");
    cout << "Search 'hello' after deletion: " << trie.search("hello") << endl;

    return 0;
}
