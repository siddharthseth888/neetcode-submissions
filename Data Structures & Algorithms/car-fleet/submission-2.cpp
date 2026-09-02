class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int,double>> cars;

        int n = position.size();
        for(int i = 0; i < n; i++)
        {
            int dist = target-position[i];
            double time = dist*1.0/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(),cars.end());

        int fleet = 1;
        for(int i = n-1; i > 0; i--)
        {
            if(cars[i].second >= cars[i-1].second)
            {
                cars[i-1].second = cars[i].second;
            }
            else
            {
                fleet++;
            }
        }

        return fleet;
    }
};
