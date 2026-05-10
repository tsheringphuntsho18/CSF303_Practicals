// PATRICIA algorithm

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class PatriciaNode {
public:
    string key;
    shared_ptr<PatriciaNode> left;
    shared_ptr<PatriciaNode> right;

    PatriciaNode(const string& k) : key(k), left(nullptr), right(nullptr) {}
};

class PatriciaTrie {
private:
    shared_ptr<PatriciaNode> root;

public:
    PatriciaTrie() : root(nullptr) {}

    // Insert a word into the Patricia Trie
    void insert(const string& word) {
        root = insertHelper(root, word);
    }

    // Search for a word in the Patricia Trie
    bool search(const string& word) {
        return searchHelper(root, word);
    }

    // Delete a word from the Patricia Trie
    void remove(const string& word) {
        root = removeHelper(root, word);
    }

private:
    shared_ptr<PatriciaNode> insertHelper(shared_ptr<PatriciaNode> node, const string& word) {
        if (!node) return make_shared<PatriciaNode>(word);

        // Find the common prefix
        int commonPrefixLength = findCommonPrefix(node->key, word);
        if (commonPrefixLength == 0) {
            // No common prefix, create a new root
            auto newRoot = make_shared<PatriciaNode>(word);
            newRoot->left = node;
            return newRoot;
        }

        // If the node's key is the same as the word, do nothing
        if (commonPrefixLength == node->key.size()) {
            return node;
        }

        // Split the node
        auto newInternalNode = make_shared<PatriciaNode>(node->key.substr(0, commonPrefixLength));
        newInternalNode->left = make_shared<PatriciaNode>(node->key.substr(commonPrefixLength));
        newInternalNode->right = make_shared<PatriciaNode>(word.substr(commonPrefixLength));
        return newInternalNode;
    }

    bool searchHelper(shared_ptr<PatriciaNode> node, const string& word) {
        if (!node) return false;

        if (node->key == word) return true;

        if (word < node->key) {
            return searchHelper(node->left, word);
        } else {
            return searchHelper(node->right, word);
        }
    }

    shared_ptr<PatriciaNode> removeHelper(shared_ptr<PatriciaNode> node, const string& word) {
        if (!node) return nullptr;

        if (node->key == word) {
            // Node to be deleted found
            if (!node->left && !node->right) {
                return nullptr;  // Leaf node
            }
            if (!node->left) {
                return node->right;  // Only right child
            }
            if (!node->right) {
                return node->left;  // Only left child
            }
            // Node with two children
            auto minNode = findMin(node->right);
            node->key = minNode->key;
            node->right = removeHelper(node->right, minNode->key);
        } else if (word < node->key) {
            node->left = removeHelper(node->left, word);
        } else {
            node->right = removeHelper(node->right, word);
        }
        return node;
    }

    shared_ptr<PatriciaNode> findMin(shared_ptr<PatriciaNode> node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    int findCommonPrefix(const string& s1, const string& s2) {
        int minLength = min(s1.size(), s2.size());
        for (int i = 0; i < minLength; i++) {
            if (s1[i] != s2[i]) return i;
        }
        return minLength;
    }
};

int main() {
    PatriciaTrie trie;
    trie.insert("hello");
    trie.insert("world");

    cout << "Search 'hello': " << trie.search("hello") << endl;
    cout << "Search 'world': " << trie.search("world") << endl;
    cout << "Search 'tshering': " << trie.search("tshering") << endl;

    trie.remove("hello");
    cout << "Search 'hello' after deletion: " << trie.search("hello") << endl;

    return 0;
}
