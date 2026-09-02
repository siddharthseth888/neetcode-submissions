class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> res(n,0);

        for(int i = n-1; i >= 0; i--)
        {
            if(st.empty())
            {
                st.push({i, temperatures[i]});
                res[i] = 0;
                continue;
            }
            while(!st.empty() && temperatures[i] >= st.top().second)
            {
                st.pop();
            }
            if(!st.empty() && temperatures[i] < st.top().second)
            {
                res[i] = st.top().first-i;
            }


            st.push({i, temperatures[i]});
        }

        return res;
    }
};
