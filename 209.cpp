class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int mn = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum+=nums[i];
            while (sum>=target)
            {
                mn = min(mn, i-start+1);
                sum-=nums[start++];
            }
        }
        return mn==INT_MAX ? 0 : mn;
    }
};
