class Solution {
public:
    int MOD = 1e9+7;
    int numberOfWays(string corridor) {
        vector<int> seats;
        for(int i=0; i<corridor.length(); i++) {
            if(corridor[i] =='S') seats.push_back(i);
        }
        int n = seats.size();
        if(n<2 || n%2==1) return 0;

        long long ans=1;
        int idx=1;
        while(idx < n-1) {
            ans = (ans % MOD * (seats[idx+1] - seats[idx])) % MOD;
            idx+=2;     
        }
        return ans;
    }
};