class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int number_of_zeros = 0;
        for (int n: nums) if (!n) number_of_zeros++;

        int slow=0;
        for (int fast=0; fast<nums.size(); fast++) {
            if (nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }

        int i=nums.size()-1;
        while (number_of_zeros--) {
            nums[i--] = 0;
        }
    }
};