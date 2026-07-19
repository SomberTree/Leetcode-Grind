class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> f(3);
        for (int i:nums) {
            f[i]++;
        }

        int n = nums.size();
        int i = 0;
        int j = 0;
        while (n--) {
            while (j<3 && !f[j]) j++;
            nums[i++] = j;
            f[j]--;
        }
    }
};