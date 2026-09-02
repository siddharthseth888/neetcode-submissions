class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }

                char topMost_char = st.top();
                if(ch == ')' && topMost_char == '(' || ch == '}' && topMost_char == '{' || ch == ']' && topMost_char == '[')
                {
                    st.pop();
                    continue;
                }

                return false;
            }
        }

        if(st.empty())
        {
            return true;
        }

        return false;
    }
};
