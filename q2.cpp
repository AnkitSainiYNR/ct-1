// Ankit Saini
// 2010991825
// Set - 5
// Q - 2

#include <bits/stdc++.h>
using namespace std;

// Function to print all subarrays in the array
vector<pair<int, int>> f_subArr(int arr[], int n)
{
    // empty map
    unordered_map<int, vector<int>> map;

    // vector of pairs to store subarray starting and ending index
    vector<pair<int, int>> out;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // if sum is 0, we found a subarray starting from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));

        // it may be at-least 1 subarray with zero-sum
        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        map[sum].push_back(i);
    }
    return out;
}

// function to print all subarrays with sum 0
void print(vector<pair<int, int>> out, int arr[])
{
	cout<<"Subarrays with zero-sum are:"<<endl;
    for (auto it = out.begin(); it != out.end(); it++)
    {
    	cout <<"{";
        for (int i = it->first; i <= it->second; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<"}"<< endl;
    }
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

    vector<pair<int, int>> out;

    try
    {
        out = f_subArr(arr, size);
        if (out.size() == 0)
            throw(0);
    }
    catch (int size)
    {
        cout << "Size is " << size << endl;
    }

    // if we didn’t find any subarray with 0 sum,
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out, arr);

    return 0;
}

