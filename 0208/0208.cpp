#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* children[26] = {};
        bool end = false;
    };
    Node* root = new Node();

    int find(const string& word) {
        Node* node = root;
        for (char c: word) {
            c -= 'a';
            if (node->children[c] == nullptr) return 0;
            node = node->children[c];
        }
        return node->end ? 2 : 1;
    }

    void destroy(Node* node) {
        if (node == nullptr) return;
        for (Node* children: node->children) destroy(children);
        delete node;
    }

public:
    Trie() {
        
    }

    ~Trie() {
        destroy(root);
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) cur->children[c] = new Node();
            cur = cur->children[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return find(word) == 2;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != 0;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */