#define PII pair<int, int>
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> dist1(n+1, INT_MAX);
        vector<int> dist2(n+1, INT_MAX);
        vector<int> freq(n+1);
        priority_queue<PII, vector<PII>, greater<PII>> min_heap;
        min_heap.push({0, 1}); // {dist(time), node}
        dist1[1]=0;
        while(!min_heap.empty()) {
            auto [timeTaken, node] = min_heap.top(); min_heap.pop();
            freq[node]++;

            if(freq[node]==2 && node==n) return timeTaken;
            if((timeTaken/change)%2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            }
            else {
                timeTaken = timeTaken + time;
            }

            for(auto &nei:adj[node]) {
                if (freq[nei] == 2) continue;
                // Update dist1 if it's more than the current timeTaken and store its value in
                // dist2 since that becomes the second minimum value now.
                if (dist1[nei] > timeTaken) {
                    dist2[nei] = dist1[nei];
                    dist1[nei] = timeTaken;
                    min_heap.push({timeTaken, nei});
                } else if (dist2[nei] > timeTaken && dist1[nei] != timeTaken) {
                    dist2[nei] = timeTaken;
                    min_heap.push({timeTaken, nei});
                }
            }
        }
        return 0;
    }
};