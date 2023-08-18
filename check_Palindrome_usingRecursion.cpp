#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(string str, int i, int j)
{
    // base case
    if (i > j)
    {
        // i>j =>> means it reached the end case when i becomes greater than j
        return true;
    }
    else if (str[i] != str[j])
    {
        return false; // If characters at positions i and j are not equal, it's not a palindrome
    }

    else
    {
        // recursive case
        checkPalindrome(str, i + 1, j - 1);
    }
}

int main()
{
    string str;
    cout << "Enter string: " << endl;
    cin >> str;

    bool isPalindrome = checkPalindrome(str, 0, str.length() - 1);

    if (isPalindrome)
    {
        cout << str << " is a Palindromic sequence" << endl;
    }
    else
    {
        cout << str << " is NOT a Palindromic sequence" << endl;
    }
    return 0;
}