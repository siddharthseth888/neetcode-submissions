class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int p1 = 0;
        int maxi = 0;

        for(int p2 = 0; p2 < s.length(); p2++)
        {
            if(mpp.find(s[p2]) != mpp.end())
            {
                p1 = max(p1, mpp[s[p2]] + 1);
            }
            mpp[s[p2]] = p2;
            maxi = max(maxi, p2-p1+1);
        }

        return maxi;
    }
};
