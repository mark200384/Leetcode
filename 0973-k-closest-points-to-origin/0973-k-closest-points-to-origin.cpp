class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> ans;
        for(vector<int> p:points) {
            int dist=pow(p[0], 2)+pow(p[1], 2);
            pq.push({dist,{p[0], p[1]}});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            auto it=pq.top().second;
            pq.pop();
            vector<int> temp;
            temp.push_back(it.first);
            temp.push_back(it.second);
            ans.push_back(temp);
        }
        return ans;
    }
};