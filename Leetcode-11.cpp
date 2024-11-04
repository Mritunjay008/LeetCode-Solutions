#include <bits/stdc++.h>
using namespace std;

class BruteForce
{
public:
    // BruteForce Approach
    int maxArea(vector<int> &height)
    {
        int maxWater = 0;
        int n = height.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int width = j - i;
                int minLength = min(height[i], height[j]);
                maxWater = max(minLength * width, maxWater);
            }
        }
        return maxWater;
    }
};
class Best : public BruteForce
{
public:
    // Bst Approach using 2 pointer
    int maxArea(vector<int> &height)
    {
        int maxWater = 0;
        int n = height.size();
        int i = 0;
        int j = n-1;
        while(i < j)
        {
            int width = j - i;
            int minLength = min(height[i], height[j]);
            maxWater = max(minLength * width, maxWater);

            if(minLength == height[i])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};

int main()
{
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    Best solution;
    cout<<solution.maxArea(height);
    return 0;
}