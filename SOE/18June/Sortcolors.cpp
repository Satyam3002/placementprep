class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};



//bubble sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1) {
            if(nums[i]>nums[i+1]) {
                swap(nums[i],nums[i+1]);
                i=0;
            }
            else{
                i++;
            }
        }
    }
};