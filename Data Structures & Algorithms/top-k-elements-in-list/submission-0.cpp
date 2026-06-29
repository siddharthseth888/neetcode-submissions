class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        vector<vector<int>> mpp(n+1);
        for(auto it: mp)
        {
            int freq = it.second;
            int el = it.first;
            mpp[freq].push_back(el);
        }

        vector<int> ans;

        for(int i = n; i >= 0; i--)
        {
            for(int j = 0; j < mpp[i].size(); j++)
            {
                ans.push_back(mpp[i][j]);
                if(ans.size() == k)
                {
                    return ans;
                }
            }
        }

        

        return ans;
    }
};
