#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    void solve(int index, string digits, string output, vector<string> &ans, string mapping[])
    {

        // base case
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }
        int no = digits[index] - '0';
        string value = mapping[no];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(index + 1, digits, output, ans, mapping);

            output.pop_back(); // backtracking
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string output;
        int index = 0;

        if (digits.length() == 0)
        {
            return ans;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // here index+1 ni krenge
        solve(index, digits, output, ans, mapping);
        return ans;
    }
};

int main()
{
    system("cls");
    string digits;
    cout << "Enter any two digits from keypad (2-9):" << endl;
    cin >> digits;

    if (digits.length() <= 1)
    {
        cout << "Please enter exactly one or two digits:" << endl;
        return 0;
    }

    Solution s;
    vector<string> result = s.letterCombinations(digits);
    cout << "Possible combinations will be:" << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}