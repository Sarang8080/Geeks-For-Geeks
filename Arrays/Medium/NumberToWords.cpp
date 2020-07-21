/*
Given number into words. For example, if “1234” is given as input, output should be “one thousand two hundred and thirty four”

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the number into words (in small letter).

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 9999

Example:

Input:
2
2
142

Output:
two
one hundred and forty two
*/
#include <bits/stdc++.h>
using namespace std;
void Helper(string n)
{
    if (n[0] == '0')
    {
        Helper(n.substr(1));
        return;
    }
    if (n.length() <= 2)
    {
        if (n == "1")
            cout << "one ";
        else if (n == "2")
            cout << "two ";
        else if (n == "3")
            cout << "three ";
        else if (n == "4")
            cout << "four ";
        else if (n == "5")
            cout << "five ";
        else if (n == "6")
            cout << "six ";
        else if (n == "7")
            cout << "seven ";
        else if (n == "8")
            cout << "eight ";
        else if (n == "9")
            cout << "nine ";
        else if (n == "10")
            cout << "ten ";
        else if (n == "11")
            cout << "eleven ";
        else if (n == "12")
            cout << "twelve ";
        else if (n == "13")
            cout << "thirteen ";
        else if (n == "14")
            cout << "fourteen ";
        else if (n == "15")
            cout << "fifteen ";
        else if (n == "16")
            cout << "sixteen ";
        else if (n == "17")
            cout << "seventeen ";
        else if (n == "18")
            cout << "eighteen ";
        else if (n == "19")
            cout << "nineteen ";
        else if (n == "20")
            cout << "twenty ";
        else if (n[0] == '2')
        {
            cout << "twenty ";
            Helper(n.substr(1));
        }
        else if (n[0] == '3')
        {
            cout << "thirty ";
            Helper(n.substr(1));
        }
        else if (n[0] == '4')
        {
            cout << "forty ";
            Helper(n.substr(1));
        }
        else if (n[0] == '5')
        {
            cout << "fifty ";
            Helper(n.substr(1));
        }
        else if (n[0] == '6')
        {
            cout << "sixty ";
            Helper(n.substr(1));
        }
        else if (n[0] == '7')
        {
            cout << "seventy ";
            Helper(n.substr(1));
        }
        else if (n[0] == '8')
        {
            cout << "eighty ";
            Helper(n.substr(1));
        }
        else if (n[0] == '9')
        {
            cout << "ninety ";
            Helper(n.substr(1));
        }
    }
    else if (n.length() == 3)
    {
        Helper(n.substr(0, 1));
        cout << "hundred ";
        if (n[1] != '0' || n[2] != '0')
            cout << "and ";
        Helper(n.substr(1));
    }
    else if (n.length() == 4)
    {
        Helper(n.substr(0, 1));
        cout << "thousand ";
        Helper(n.substr(1));
    }
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        Helper(n);
        cout << endl;
    }
    return 0;
}