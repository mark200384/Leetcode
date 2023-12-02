class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(char c:chars)
            mp[c]++;
        
        int ans=0;
        for(string word:words) {
            unordered_map<char, int> tmp=mp;
            int flag=0;
            for(int i=0; i<word.length(); i++) {
                tmp[word[i]]--;
                if(tmp[word[i]] < 0) {
                    flag=1;
                    break;
                }
            }
            if(!flag) {
                ans += word.length();
            }
        }
        return ans;
    }
};