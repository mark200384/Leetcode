class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode() {
        isWord = false;
        for(auto &c: child) {
            c = nullptr;
        }
    }
    ~TrieNode() {
        for(auto &c:child) {
            if(c) {
                delete c;
                c = nullptr;
            }
        }
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* p = root;
        for(char &c:word) {
            int i = c-'a';
            if(!p->child[i]) {
                p->child[i] = new TrieNode();
            }
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word,root);   
    }

    bool searchHelper(string word, TrieNode*  node){
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c: node->child){
                    if(c && searchHelper(word.substr(i+1),c)){
                        return true;
                    }
                }
                return false;
            }
            int index=ch-'a';
            if(node->child[index]==NULL){
                return false;
            }
            node=node->child[index];
        }
        return node->isWord;
        
    }
};