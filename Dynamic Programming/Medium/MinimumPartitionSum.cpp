/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=200
1<=N<=50
1<=A[i]<=200


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Testcase 1:
Subset1 = {1, 5, 6} ; sum of Subset1 = 12
Subset2 = {11} ;       sum of Subset2 = 11

Testcase 2:
Subset1 = {7, 46} ;   sum = 53
Subset2 = {36, 40} ; sum = 76
*/
#include <bits/stdc++.h>
using namespace std;

int subsetsum(int arr[], int n, int sum)
{
    int subset[n + 1][sum + 1];
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        subset[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        subset[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
            if (j >= arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
            }
        }
    }
    for (int j = 0; j <= sum / 2; j++)
    {
        if (subset[n][j])
        {
            v.push_back(j);
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, sum - (2 * v[i])); //range - 2s1
    }
    return mn;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        cout << subsetsum(arr, n, total) << endl;
    }
    return 0;
}
