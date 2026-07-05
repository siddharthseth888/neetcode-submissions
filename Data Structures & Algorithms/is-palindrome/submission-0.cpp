class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                st += s[i] - 'A' + 'a';
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
            {
                st += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                st += s[i];
            }
        }

        string st_reverse = "";
        for(int i = st.size()-1; i >= 0; i--)
        {
            st_reverse += st[i];
        }

        if(st == st_reverse)
        {
            return true;
        }

        return false;

    }
};
