class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m-1;

        int flag = 0;
        int mid;
        while(top <= bottom)
        {
            mid = top + (bottom-top)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1])
            {
                flag = 1;
                break;
            }

            else if(target < matrix[mid][0])
            {
                bottom = mid - 1;
            }

            else
            {
                top = mid + 1;
            }
        }

        if(flag != 1)
        {
            return false;
        }

        int low = 0;
        int high = n-1;

        while(low <= high)
        {
            int middle = low + (high-low)/2;
            if(matrix[mid][middle] == target)
            {
                return true;
            }
            else if(matrix[mid][middle] < target)
            {
                low = middle+1;
            }
            else
            {
                high = middle-1;
            }
        }

        return false;
    }
};
