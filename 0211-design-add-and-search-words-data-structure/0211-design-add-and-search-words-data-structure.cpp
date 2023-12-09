class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode() {
        isWord = false;
        for(auto &c:child) {
            c = nullptr;
        }
    }
    ~TrieNode() {
        for(auto &c:child) {
            delete c;
        }
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char ch:word) {
            int i = ch-'a';
            if(!curr->child[i]) curr->child[i] = new TrieNode();
            curr = curr->child[i];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return helper(word, root);
    }
    
    bool helper(string word, TrieNode* node) {
        for(int i=0; i<word.length(); i++) {
            if(word[i] =='.') {
                for(auto c:node->child) {
                    if(c && helper(word.substr(i+1),c)) {
                        return true;
                    }
                }
                return false;
            }
            if(!node->child[word[i]-'a']) return false;
            node = node->child[word[i]-'a'];
        }
        return node->isWord;
    }
};
