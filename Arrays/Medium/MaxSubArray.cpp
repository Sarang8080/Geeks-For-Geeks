/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
Print the Sub-array with maximum sum.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
-100 ≤ A[i] ≤ 100

Example:
Input
2
3
1 2 3
2
-1  2
Output
1 2 3
2
*/
#include <bits/stdc++.h>
using namespace std;

int indexOfMax(int arr[], int n) //finding the index of max element, so that we can take it from sum array
{
    int mx = arr[0], index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= mx)
        {
            mx = arr[i];
            index = i;
        }
    }
    return index;
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
        int arr[n], sum[n], c = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] < 0)
            {
                sum[i] = -1;
                c = 0;
            }

            else
            {
                c += arr[i];
                sum[i] = c;
            }
        }
        int index = indexOfMax(sum, n);
        int start = index;
        while (start >= 0 && sum[start] >= 0)
        {
            start--;
        }

        for (int i = start + 1; i <= index; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    return 0;
}