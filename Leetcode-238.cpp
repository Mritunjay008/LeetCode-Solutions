#include <bits/stdc++.h>
using namespace std;

class Bruteforce
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            int prod = 1;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                prod = prod*nums[j];
            }
            ans[i] = prod;
        }
        return ans;
    }
};

class Best : public Bruteforce
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n, 1);
        pre[0] = 1;
        for (int i = 1; i < n; i++)
        {
            pre[i] = nums[i - 1] * pre[i - 1];
        }

        vector<int> suf(n, 1);
        suf[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = nums[i + 1] * suf[i + 1];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(pre[i] * suf[i]);
        }
        return ans;
    }
};

class Best : public Bruteforce
{
// Space optimized code 
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
        {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int suf = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = ans[i] * nums[i + 1] * suf;
            suf = suf * nums[i + 1];
        }
        return ans;
    }
};



int main()
{
    vector<int> v = {1,2,3,4};
    Best solution;
    v = solution.productExceptSelf(v);
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
