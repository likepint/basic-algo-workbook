// 방문 길이

#include "../Global.h"
#include <string>
#include <map>

using namespace std;

#define X first
#define Y second

int solution(string directions)
{
    map<pair<pair<int, int>, pair<int, int>>, bool> paths;

    pair<int, int> current = {0, 0};

    for (const auto& direction : directions)
    {
        pair<int, int> next = current;

        if (direction == 'U')
            next.Y += 1;
        else if (direction == 'D')
            next.Y -= 1;
        else if (direction == 'R')
            next.X += 1;
        else if (direction == 'L')
            next.X -= 1;

        if (-5 > next.X or next.X > 5)
            continue;

        if (-5 > next.Y or next.Y > 5)
            continue;

        if (paths.find({current, next}) == paths.end())
        {
            paths.insert({{current, next}, true});
            paths.insert({{next, current}, true});
        }

        current = next;
    }

    return (int)paths.size() / 2;
}

int main()
{
    string directions = "";

    directions = "ULURRDLLU";
    cout << solution(directions) << endl;

    directions = "LULLLLLLU";
    cout << solution(directions) << endl;

    directions = "URULDD";
    cout << solution(directions) << endl;

    return 0;
}
