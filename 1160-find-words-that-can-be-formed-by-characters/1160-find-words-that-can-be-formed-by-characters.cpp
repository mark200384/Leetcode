class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26, 0);
        for(char c:chars) {
            mp[c-'a']++;
        }
        
        int ans=0;
        for(string word:words) {
            vector<int> tmp = mp;
            int flag=0;
            for(int j=0; j<word.size(); j++) {
                tmp[word[j]-'a']--;
                if(tmp[word[j]-'a'] < 0) {
                    flag=1;
                    break;
                }
            }
            if(!flag) ans += word.length();
        }
        return ans;
    }
};