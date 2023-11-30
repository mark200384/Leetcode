class Solution {
public:
    struct Compare {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) 
                return a.first > b.first;           // min heap (high priority)     
            else 
                return a.second < b.second;         // low alphabetical order if we got same priority 
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string str:words) {
            mp[str]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> minHeap;
        
        for(const auto& p:mp) {
            minHeap.push({p.second, p.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        vector<string> res;
        while(!minHeap.empty()) {
            res.insert(res.begin(), minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};