class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;
        int n = strs.size();
        vector<vector<string>> ans;

        for(auto s: strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mpp[t].push_back(s);
        }

        for(auto it: mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
