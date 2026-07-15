class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int curr=0;
        for (int i=0; i<nums.size(); i++) {
            if (!nums[i]) {
                ans = max(curr, ans);
                curr = 0;
            }
            curr += nums[i];
        }
        ans = max(ans, curr);

        return ans;
    }
};