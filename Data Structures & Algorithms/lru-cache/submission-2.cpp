class LRUCache {
public:
    vector<pair<int,int>> arr;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i].first == key)
            {
                auto temp = arr[i];
                arr.erase(arr.begin()+i);
                arr.push_back(temp);
                return temp.second;
            }
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i].first == key)
            {
                arr[i].second = value;
                auto temp = arr[i];
                arr.erase(arr.begin()+i);
                arr.push_back(temp);
                return;
            }
        }

        if(arr.size() >= n)
        {
            arr.erase(arr.begin());
            arr.push_back({key, value});
        }
        else
        {
            arr.push_back({key, value});
        }
        
    }
};
