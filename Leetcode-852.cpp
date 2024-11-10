#include<bits/stdc++.h>
using namespace std;

int peakInMountainArray(vector<int> arr)
{
    int st = 1;
    int end = arr.size()-2;
    //we have started start at index 1 and end at total size - 2 because of in question it is given that 
    //peak cannot be index 0 and index last
    while(st <= end)
    {
        int mid = st + (end-st)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return arr[mid];
        else if(arr[mid] > arr[mid-1])
        {
            st = mid+1;
        }
        else
            end = mid-1;
    }
}

int main()
{
    vector<int> nums = {0, 2, 1, 0};
    cout<<peakInMountainArray(nums);
    return 0;
}
