class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        int total_water = 0;
        int maxi1 = 0;
        int maxi2 = 0;
        for(int i = 0; i < n; i++)
        {
            maxi1 = max(maxi1, height[i]);
            leftMax[i] = maxi1;
            maxi2 = max(maxi2, height[n-i-1]);
            rightMax[n-i-1] = maxi2;
        }
        for(int i = 0; i < n; i++)
        {
            if(height[i] < leftMax[i] && height[i] < rightMax[i])
            {
                int water_stored = min(leftMax[i],rightMax[i]) - height[i];
                if(water_stored > 0)
                {
                    total_water += water_stored;
                }
            }
        }

        return total_water;

    }
};
