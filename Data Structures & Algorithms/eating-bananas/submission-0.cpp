class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        if(n > h)
        {
            return -1;
        }

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            int time = 0;
            for(int i = 0; i < n; i++)
            {
                time += ceil(piles[i]*1.0/mid);
            }

            if(time <= h)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};
