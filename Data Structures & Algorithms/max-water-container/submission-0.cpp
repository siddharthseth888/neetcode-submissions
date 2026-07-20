class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int max_area = 0;
        while(l < r)
        {
            int length = r-l;
            int width = min(heights[r],heights[l]);
            int area = length*width;
            max_area = max(max_area, area);

            if(heights[r] <= heights[l])
            {
                r--;
            }
            else if(heights[r] > heights[l])
            {
                l++;
            }
        }

        return max_area;
    }
};
