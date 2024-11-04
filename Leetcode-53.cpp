#include <vector>
#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

class BruteForce
{
public:
    // BruteForce Approach
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int st = 0; st < n; st++)
        {
            int cSum = 0;
            for (int end = st; end < n; end++)
            {
                cSum = cSum + nums[end];
                maxSum = max(cSum, maxSum);
            }
        }
        return maxSum;
    }
};

class Best : public BruteForce
{
// Best Approach
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int mxSum = INT_MIN, curSum = 0;
        for (int i = 0; i < n; i++)
        {
            curSum += nums[i];
            mxSum = max(mxSum, curSum);
            if (curSum < 0)
                curSum = 0;
        }
        return mxSum;
    }
};
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Best solution;
    cout << solution.maxSubArray(arr);
    return 0;
}