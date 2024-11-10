#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int> arr, int target)
{
    int st = 0;
    int end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[st] <= arr[mid]) //----> left half is sorted
        {
            if (arr[st] <= target && target <= arr[mid]) //--->Target is in left half
                end = mid - 1;
            else //--->Target is in right half
                st = mid + 1;
        }
        else //----> right half is sorted
        {
            if (arr[mid] <= target && target <= arr[end]) //--->Target is in right half
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    cout << searchInRotatedSortedArray(nums, target);
    return 0;
}
