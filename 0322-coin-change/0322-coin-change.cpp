class Solution {
public:
    //f(n) = Min( 1 + f(n- c1), 1+ f(n-c2),…, 1+f(n-ck) )
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1) return 0;
        vector<long long int> res(amount+1,INT_MAX);
        res[0]=0;
        for(int i=1; i<=amount; i++) {
            for(int coin:coins) {
                if(coin<=i && res[i-coin]!=INT_MAX)
                    res[i] = min(res[i], 1+res[i-coin]);
            }
        }
        return res[amount]==INT_MAX? -1:res[amount];
    }
};
/*
  11選1剩10
    選2剩9
    選5剩6
*/