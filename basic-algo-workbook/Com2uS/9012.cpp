#include <iostream>
#include <stack>

using namespace std;

#define endl '\n'

int T;

bool IsVPS(const string& InStr)
{
    stack<char> ps;

    for (char ch : InStr)
    {
        if (ch == '(')
        {
            ps.push(ch);
        }
        else // ch == ')'
        {
            if (ps.empty())
                return false;

            ps.pop();
        }
    }

    return ps.empty();
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        string input;
        cin >> input;

        cout << (IsVPS(input) ? "YES" : "NO") << endl;
    }

    return 0;
}