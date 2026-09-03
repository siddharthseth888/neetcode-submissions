class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> st;
        int n = heights.size();
        int max_area = 0;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                if(st.empty())
                {
                    pse = -1;
                }

                max_area = max(max_area, heights[el]*(nse-pse-1));
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int el = st.top();
            st.pop();
            
            int nse = n; 
            int pse = st.empty() ? -1 : st.top();

            max_area = max(max_area, heights[el] * (nse - pse - 1));
        }

        return max_area;
        
    }
};
