class Solution {
public:
    //maximize the total score by strategically playing these tokens. 
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1; 
        while(i<=j) { 
            if (power >= tokens[i]) {
                score++;
                power -= tokens[i++];
            }
            else if(i < j && score > 0) {
                score--;
                power += tokens[j--];
            }
            else {
                return score;
            }
        }
        return score;
    }
};

// if power >= tokens[i], -tokens[i] and score++
// if score > 0, += tokens[i] and score--

/*
What patterns do we notice in how the tokens are played to maximize the score in the above examples?

The lowest power tokens are played face-up to increase the score.
The highest power tokens are played face-down to increase power.
*/