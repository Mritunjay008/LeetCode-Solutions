#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    //This is to avoid overflow condition
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    int st = 2;
    int end = n - 3;

    
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if ((arr[mid] != arr[mid + 1]) && (arr[mid] != arr[mid - 1]))
        {
            return arr[mid];
        }
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid - 1]) //--->answer in left part
                end = mid - 1;
            else //--->answer in right part
                st = mid + 1;
        }
        else
        {
            if (arr[mid] == arr[mid - 1]) //--->answer in right part
                st = mid + 1;
            else //--->answer in left part
                end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(arr);
    return 0;
}
