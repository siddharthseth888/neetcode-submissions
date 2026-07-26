class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        map<char, int> mpp;
        int maxf = 0;
        int maxlen = 0;
        for(int r = 0; r < n; r++)
        {
            mpp[s[r]]++;
            for(auto it: mpp)
            {
                maxf = max(maxf, mpp[s[r]]);
            }
            int len = r-l+1;
            if(len-maxf <= k)
            {
                maxlen = max(maxlen, len);
            }
            else
            {
                while((r-l+1) - maxf > k)
                {
                    mpp[s[l]]--;
                    l++;
                    for(auto it: mpp)
                    {
                        maxf = max(maxf, it.second);
                    }
                }
            }
        }

        return maxlen;
    }
};
