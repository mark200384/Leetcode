class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(int num:nums)
            pq.push(num);
        int ans=0;
        while(k--) {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};