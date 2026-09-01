class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
        {
            return false;
        }

        int n1 = s1.size();
        int n2 = s2.size();
        map<int, int> mpp;
        for(int i = 0; i < n1; i++)
        {
            mpp[s1[i]]++;
        }
        int p1 = 0;
        int p2 = p1+n1-1;
        map<int, int> s2_mpp;
        for(int i = p1; i <= p2; i++)
        {
            s2_mpp[s2[i]]++;
        }

        if(mpp == s2_mpp) return true;
        while(p1 <= p2 && p2 < n2-1)
        {
            s2_mpp[s2[p1]]--;
            if(s2_mpp[s2[p1]] == 0)
            {
                s2_mpp.erase(s2[p1]);
            }
            p1++;
            p2++;
            s2_mpp[s2[p2]]++; 
            if(mpp == s2_mpp)
            {
                return true;
            }
        }

        return false;
    }
};
