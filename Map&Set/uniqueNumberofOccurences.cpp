class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>freq;
        set<int> check;

        for(int i =0;i<arr.size();i++) {
            int num = arr[i];
            freq[num]++;
        }

        for(auto it : freq) {
           if(check.find(it.second) != check.end()) {
            return false;
           } else {
            check.insert(it.second);
           }           
        }

        return true;
    }
};