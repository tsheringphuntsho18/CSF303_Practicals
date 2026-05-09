#include <bits/stdc++.h> 
using namespace std;

class TrieNode {
    public:

    // pointer array for child nodes of each node
    TrieNode* children[26];

    // Used for indicating ending of string
    bool isLeaf;

    TrieNode() {
      
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with NULL
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Method to insert a key into the Trie
void insert(TrieNode* root, const string& key) {
  
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr) {
          
            // If node for current character does 
            // not exist then make a new node
            TrieNode* newNode = new TrieNode();
          
            // Keep the reference for the newly
            // created node
            curr->children[c - 'a'] = newNode;
        }
      
        // Move the curr pointer to the
        // newly created node
        curr = curr->children[c - 'a'];
    }

    // Mark the end of the word
    curr->isLeaf = true;
}

// Method to search a key in the Trie
bool search(TrieNode* root, const string& key) {
  
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr) 
            return false;
        
        // Move the curr pointer to the 
        // already existing node for the 
        // current character
        curr = curr->children[c - 'a'];
    }

    // Return true if the word exists 
    // and is marked as ending
    return curr->isLeaf;
}

// Method to delete a key in the Trie
bool deleteKey(TrieNode* root, const string& key) {

    // Helper function to delete a key
    function<bool(TrieNode*, const string&, int)> deleteHelper = [&](TrieNode* curr, const string& key, int depth) {
        if (curr == nullptr) return false;

        // If we have reached the end of the key
        if (depth == key.size()) {
            // If the key is marked as leaf, unmark it
            if (curr->isLeaf) {
                curr->isLeaf = false;
                // If the current node has no children, delete it
                for (int i = 0; i < 26; i++) {
                    if (curr->children[i] != nullptr) return false;
                }
                return true;
            }
            return false;
        }

        // Get the index of the current character
        int index = key[depth] - 'a';

        // Recur for the child node
        if (deleteHelper(curr->children[index], key, depth + 1)) {
            // If the child node can be deleted
            delete curr->children[index];
            curr->children[index] = nullptr;

            // If the current node is not a leaf and has no children, delete it
            if (!curr->isLeaf) {
                for (int i = 0; i < 26; i++) {
                    if (curr->children[i] != nullptr) return false;
                }
                return true;
            }
            return false;
        }
        return false;
    };

    deleteHelper(root, key, 0);
    return true;
}

int main()
{

    // Create am example Trie
    TrieNode *root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "dad"};
    for (const string &s : arr)
    {
        insert(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    cout << "Search results before delete: ";
    for (string &s : searchKeys){
        
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout << "\n";

    // checking after delete
    cout << "Deleting 'do'...\n";
    deleteKey(root, "do");
    
    cout << "Search results after deleting 'do': ";
    for (string &s : searchKeys){
        
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout << "\n";

    return 0;
}
