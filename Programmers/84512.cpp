// 모음사전

#include "../Global.h"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> MakeDict(const vector<char>& InAlphabet)
{
    unordered_map<string, int> dict;

    int index = 0;

    for (const auto& a : InAlphabet)
    {
        string first = "";
        first += a;
        dict[first] = ++index;

        for (const auto& e : InAlphabet)
        {
            string second = first;
            second += e;
            dict[second] = ++index;

            for (const auto& i : InAlphabet)
            {
                string third = second;
                third += i;
                dict[third] = ++index;

                for (const auto& o : InAlphabet)
                {
                    string fourth = third;
                    fourth += o;
                    dict[fourth] = ++index;

                    for (const auto& u : InAlphabet)
                    {
                        string fifth = fourth;
                        fifth += u;
                        dict[fifth] = ++index;
                    }
                }
            }
        }
    }

    return dict;
}

int solution1(string word)
{
    vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};

    unordered_map<string, int> dict = MakeDict(alphabet);

    return dict[word];
}

void MakeRecursiveDict
(
    const vector<char>& InAlphabet,
    unordered_map<string, int>& InDict,
    string Current,
    int& InIndex,
    int InMaxDepth
)
{
    if (Current.length() == InMaxDepth)
        return;

    for (const auto& alphabet : InAlphabet)
    {
        string next = Current + alphabet;
        InDict[next] = ++InIndex;
        
        MakeRecursiveDict(InAlphabet, InDict, next, InIndex, InMaxDepth);
    }
}

int solution2(string word)
{
    vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};

    unordered_map<string, int> dict;

    int index = 0;

    MakeRecursiveDict(alphabet, dict, "", index, 5);

    return dict[word];
}

int main()
{
    string word = "";

    word = "AAAAE";
    cout << solution1(word) << endl;
    cout << solution2(word) << endl;

    word = "AAAE";
    cout << solution1(word) << endl;
    cout << solution2(word) << endl;

    word = "I";
    cout << solution1(word) << endl;
    cout << solution2(word) << endl;

    word = "EIO";
    cout << solution1(word) << endl;
    cout << solution2(word) << endl;

    return 0;
}
