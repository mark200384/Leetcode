class Solution {
public:
    int m, n;
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int idx) {
        if(idx == word.length()) return true;
        else if(i>=m ||i<0 || j>=n || j<0 ||word[idx] != board[i][j]) return false;
        
        char tmp = board[i][j];
        board[i][j] =' ';
        bool flag = dfs(board, i-1, j, word, idx+1) || dfs(board, i+1, j, word, idx+1) ||
            dfs(board, i, j-1, word, idx+1) || dfs(board, i, j+1, word, idx+1);
        board[i][j] = tmp;
        return flag; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};