class TrieNode {
public:
    bool isWord=false;
    TrieNode * child[26];
    TrieNode () {
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
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(string word:wordDict) {
            TrieNode* curr = root;
            for(char c:word) {
                int i = c-'a';
                if(!curr->child[i]) curr->child[i] = new TrieNode();
                curr = curr->child[i];
            }
            curr->isWord = true;
        }

        vector<bool> dp(s.length(), false); //true: end of words
        for(int i=0; i<s.length(); i++) {
            if(i==0 || dp[i-1]) {//前一個字元是某word結尾
                TrieNode* curr = root;
                for(int j=i ; j<s.length(); j++) {
                    char c = s[j];
                    if(!curr->child[c-'a']) {
                        break;
                    }
                    curr = curr->child[c-'a'];
                    if(curr->isWord) dp[j]=true;
                }
            }
        }
        return dp[s.length()-1];
    }
};