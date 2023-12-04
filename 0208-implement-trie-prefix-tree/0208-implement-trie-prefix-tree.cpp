class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &c : child) c = nullptr;
    }
    ~TrieNode() {
        for (auto &c : child) {
            if (c) {
                delete c;
                c = nullptr;
            }
        }
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(char c:word) {
            int i = c - 'a';
            if(!cur->child[i]) cur->child[i] = new TrieNode(); 
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(char c:word) {
            int i = c - 'a';
            if(!cur->child[i]) return false;
            cur = cur->child[i];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(char c:prefix) {
            int i = c - 'a';
            if(!cur->child[i]) return false;
            cur = cur->child[i];
        }
        return true;
    }
};
