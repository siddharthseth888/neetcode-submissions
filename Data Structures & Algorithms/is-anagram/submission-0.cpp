class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mpp;
        int n1 = s.size();
        int n2 = t.size();

        for(int i = 0; i < n1; i++)
        {
            mpp[s[i]]++;
        }

        for(int j = 0; j < n2; j++)
        {
            mpp[t[j]]--;
        }

        for(auto it: mpp)
        {
            if(it.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
