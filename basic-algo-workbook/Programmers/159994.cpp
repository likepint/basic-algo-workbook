// 카드 뭉치

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int idx1 = 0, idx2 = 0;

    for (size_t i = 0; i < goal.size(); ++i)
    {
        if (idx1 < cards1.size() and goal[i] == cards1[idx1])
        {
            idx1++;
        }
        else if (idx2 < cards2.size() and goal[i] == cards2[idx2])
        {
            idx2++;
        }
        else return "No";
    }

    return "Yes";
}

int main()
{
    vector<string> cards1, cards2, goal;
    string result;

    cards1 = { "i", "drink", "water" };
    cards2 = { "want", "to" };
    goal = { "i", "want", "to", "drink", "water" };

    cout << (result = solution(cards1, cards2, goal)) << endl;

	return 0;
}