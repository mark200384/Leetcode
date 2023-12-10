class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

/*
1 2 3
4 5 6 

1 4 
2 5
3 6

*/