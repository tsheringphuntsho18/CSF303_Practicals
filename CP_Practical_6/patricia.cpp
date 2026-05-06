// 2. Implement PATRICIA algorithm and perform insert, search, and deletion

#include <iostream>
#include <memory>
#include <string>

class PatriciaNode {
public:
    std::string key;
    std::shared_ptr<PatriciaNode> left;
    std::shared_ptr<PatriciaNode> right;

    PatriciaNode(const std::string& k) : key(k), left(nullptr), right(nullptr) {}
};

class PatriciaTrie {
private:
    std::shared_ptr<PatriciaNode> root;

public:
    PatriciaTrie() : root(nullptr) {}

    // Insert a word into the Patricia Trie
    void insert(const std::string& word) {
        root = insertHelper(root, word);
    }

    // Search for a word in the Patricia Trie
    bool search(const std::string& word) {
        return searchHelper(root, word);
    }

    // Delete a word from the Patricia Trie
    void remove(const std::string& word) {
        root = removeHelper(root, word);
    }

private:
    std::shared_ptr<PatriciaNode> insertHelper(std::shared_ptr<PatriciaNode> node, const std::string& word) {
        if (!node) return std::make_shared<PatriciaNode>(word);

        // Find the common prefix
        int commonPrefixLength = findCommonPrefix(node->key, word);
        if (commonPrefixLength == 0) {
            // No common prefix, create a new root
            auto newRoot = std::make_shared<PatriciaNode>(word);
            newRoot->left = node;
            return newRoot;
        }

        // If the node's key is the same as the word, do nothing
        if (commonPrefixLength == node->key.size()) {
            return node;
        }

        // Split the node
        auto newInternalNode = std::make_shared<PatriciaNode>(node->key.substr(0, commonPrefixLength));
        newInternalNode->left = std::make_shared<PatriciaNode>(node->key.substr(commonPrefixLength));
        newInternalNode->right = std::make_shared<PatriciaNode>(word.substr(commonPrefixLength));
        return newInternalNode;
    }

    bool searchHelper(std::shared_ptr<PatriciaNode> node, const std::string& word) {
        if (!node) return false;

        if (node->key == word) return true;

        if (word < node->key) {
            return searchHelper(node->left, word);
        } else {
            return searchHelper(node->right, word);
        }
    }

    std::shared_ptr<PatriciaNode> removeHelper(std::shared_ptr<PatriciaNode> node, const std::string& word) {
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

    std::shared_ptr<PatriciaNode> findMin(std::shared_ptr<PatriciaNode> node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    int findCommonPrefix(const std::string& s1, const std::string& s2) {
        int minLength = std::min(s1.size(), s2.size());
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

    std::cout << "Search 'hello': " << trie.search("hello") << std::endl;
    std::cout << "Search 'world': " << trie.search("world") << std::endl;
    std::cout << "Search 'trie': " << trie.search("trie") << std::endl;

    trie.remove("hello");
    std::cout << "Search 'hello' after deletion: " << trie.search("hello") << std::endl;

    return 0;
}
