class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> st;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int second_op = stoi(st.top());
                st.pop();
                int first_op = stoi(st.top());
                st.pop();

                string token = tokens[i];
                int res = 0;
                if (token == "+") res += first_op + second_op;
                else if (token == "-") res += first_op-second_op;
                else if (token == "*") res += first_op*second_op;
                else if (token == "/") res += first_op/second_op;
                st.push(to_string(res));
            }

            else
            {
                st.push(tokens[i]);
            }
        }


        return stoi(st.top());
    }
};
