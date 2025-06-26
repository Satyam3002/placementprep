class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int maxproduct = nums[0];
        int minproduct = nums[0];
        for(int i =0; i<nums.size();i++) {
            int curr = nums[i];
            int tempMax = max({curr, curr * maxproduct, curr * minproduct});
            int tempMin = min({curr, curr * maxproduct, curr * minproduct});

            maxproduct = tempMax;
            minproduct = tempMin;
            result = max(result,maxproduct);
        }
        return result;
    }
};