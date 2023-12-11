class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int num:arr) {
            count[num]++;
        }
        for(auto p=count.begin(); p!=count.end(); p++){
            if(p->second > arr.size()/4) {
                return p->first;
            }
        }
        return -1;
    }
};