class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixmax(n);
        prefixmax[0] = nums[0];
        for (int i=1 ; i<n ; i++){
            prefixmax[i] = max (prefixmax[i-1] , nums[i]);
        }
        
        vector<int> suffixmax(n);
        suffixmax[n-1] = nums[n-1];
        for (int i=n-2 ; i>=0 ; i--){
            suffixmax[i] = max(suffixmax[i+1] , nums[i]);
        }
        
        int answer = 0;
        for (int i=0 ; i<n ; i++){
            int left_max = prefixmax[i];
            int right_max = suffixmax[i];
            if (nums[i] < left_max && nums[i] < right_max){
                answer += min (left_max , right_max) - nums[i];
            }
        }
        return answer;
    }
};