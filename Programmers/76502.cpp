// 괄호 회전하기

#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define endl '\n'

bool IsCorrect(const string& brackets)
{
    stack<char> stk;

    for (char bracket : brackets)
    {
        if (bracket == '(' or bracket == '[' or bracket == '{')
        {
            stk.push(bracket);

            continue;
        }

        if (stk.empty()) return false;

        if (bracket == ')' and stk.top() == '(')
            stk.pop();
        else if (bracket == ']' and stk.top() == '[')
            stk.pop();
        else if (bracket == '}' and stk.top() == '{')
            stk.pop();
        else return false;
    }

    return stk.empty();
}

int solution(string brackets)
{
    int answer = 0;

    for (int i = 0; i < (int)brackets.size(); ++i)
    {
        if (IsCorrect(brackets))
            answer++;

        brackets = brackets.substr(1) + brackets[0];
    }

    return answer;
}

// int solution(string brackets)
// {
//     queue<char> q;
//     for (int idx = 0; idx < (int)brackets.size(); ++idx)
//         q.push(brackets[idx]);
//
//     int answer = 0;
//     
//     for (int idx = 0; idx < (int)brackets.size(); ++idx)
//     {
//         queue<char> t = q;
//         stack<char> s;
//
//         while (!t.empty())
//         {
//             if (s.empty() or t.front() == '(' or t.front() == '[' or t.front() == '{')
//             {
//                 s.push(t.front());
//             }
//             else
//             {
//                 switch (s.top())
//                 {
//                     case '(':
//                     {
//                             if (t.front() == ')')
//                                 s.pop();
//
//                             break;
//                     }
//                     case '[':
//                     {
//                             if (t.front() == ']')
//                                 s.pop();
//
//                             break;
//                     }
//                     case '{':
//                     {
//                             if (t.front() == '}')
//                                 s.pop();
//
//                             break;
//                     }
//                 }
//             }
//             
//             t.pop();
//         }
//
//         if (s.empty()) answer++;
//
//         q.push(q.front());
//         q.pop();
//     }
//     
//     return answer;
// }

int main()
{
    string brackets = "";

    brackets = "[](){}";
    cout << solution(brackets) << endl;

    brackets = "}]()[{";
    cout << solution(brackets) << endl;

    brackets = "[)(]";
    cout << solution(brackets) << endl;

    brackets = "}}}";
    cout << solution(brackets) << endl;

    return 0;
}
