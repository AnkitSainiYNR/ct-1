// Ankit Saini
// 2010991825
// Set - 5
// Q - 1

#include <bits/stdc++.h>
using namespace std;

// fun to find the length of longest subarray having sum target
int len_longSubarr(int arr[],
                    int n,
                    int target)
{
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {

        // sum
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == target)
            maxLen = i + 1;

        // make an entry for 'sum' if it isnot present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;

        if (um.find(sum - target) != um.end())
        {

            // update maxLength
            if (maxLen < (i - um[sum - target]))
                maxLen = i - um[sum - target];
        }
    }
    return maxLen;
}

int main()
{
	int size;
	cout<<"Enter Size: ";
	cin>>size;
	int arr[size];
	cout<<"Enter Elements: ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	int target;
	cout<<"Enter Target: ";
	cin>>target;
	
    int res;

    try
    {
        res = len_longSubarr(arr, size, target);
        if (!res)
            throw("No subarray found");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "Length = " << res;
    return 0;
}
