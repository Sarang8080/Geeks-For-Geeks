/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<string> dict;
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            dict.insert(a);
        }
        string word;
        cin >> word;
        int size = word.size();
        vector<int> wb(size + 1, 0);
        wb[0] = 1;
        for (int i = 1; i <= size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string a = word.substr(j, i - j);
                if (dict.count(a) && wb[j] == 1)
                {
                    wb[i] = 1;
                }
            }
        }
        cout << wb[size] << endl;
    }
    return 0;
}