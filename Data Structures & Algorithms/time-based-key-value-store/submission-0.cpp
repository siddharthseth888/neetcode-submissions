class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mpp; //{key,{timestamp, value}}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end())
        {
            return ""; 
        }
        auto &vec = mpp[key];
        int left = 0;
        int right = vec.size()-1;
        string ans = "";
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(vec[mid].first == timestamp)
            {
                ans = vec[mid].second;
                break;
            }
            else if(vec[mid].first > timestamp)
            {
                right = mid-1;
            }
            else
            {
                ans = vec[mid].second;
                left = mid+1;
            }
        }

        return ans;

    }
};
