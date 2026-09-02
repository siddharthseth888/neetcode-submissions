class MinStack {
public:
    stack<pair<int,int>> st; //store the val, minimum_value seen till now
    MinStack() 
    {
    }
    
    void push(int val) 
    {
        if(st.empty())
        {
            st.push({val, val});
        } 
        else
        {
            int current_min = st.top().second;
            st.push({val, min(current_min, val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() 
    {
        return st.top().second;
    }
};
