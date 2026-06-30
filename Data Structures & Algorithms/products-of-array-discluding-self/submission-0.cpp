class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        long long prod = 1;
        vector<int> pref(n);
        vector<int> suff(n);
        vector<int> ans(n);

        pref[0] = 1;
        suff[n-1] = 1;

        for(int i = 1; i < n; i++)
        {
            pref[i] = nums[i-1] * pref[i-1];
        }

        for(int i = n-2; i >= 0; i--)
        {
            suff[i] = suff[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            ans[i] = suff[i] * pref[i];
        }

        return ans;

    }
};
