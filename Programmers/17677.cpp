// [1차] 뉴스 클러스터링

#include "../Global.h"
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> TwoLetters(const string& InString)
{
    unordered_map<string, int> result;

    string twoLetters = "";

    for (const auto& letter : InString)
    {
        if (isalpha(letter))
        {
            twoLetters += tolower(letter);
        }
        else twoLetters.clear();

        if (twoLetters.length() == 2)
        {
            result[twoLetters]++;
            twoLetters = tolower(letter);
        }
    }

    return result;
}

unordered_map<string, int> MakeIntersection(unordered_map<string, int>& InLetters1, unordered_map<string, int>& InLetters2)
{
    unordered_map<string, int> result;

    for (const auto& letter : InLetters1)
    {
        if (InLetters2.find(letter.first) != InLetters2.end())
            result[letter.first] = min(InLetters1[letter.first], InLetters2[letter.first]);
    }

    return result;
}

unordered_map<string, int> MakeUnion(unordered_map<string, int>& InLetters1, unordered_map<string, int>& InLetters2)
{
    unordered_map<string, int> result = InLetters1;

    for (const auto& letter : InLetters2)
        result[letter.first] = max(result[letter.first], letter.second);

    return result;
}

int solution(string str1, string str2)
{
    unordered_map<string, int> Letters1 = TwoLetters(str1);
    unordered_map<string, int> Letters2 = TwoLetters(str2);

    unordered_map<string, int> inter = MakeIntersection(Letters1, Letters2);
    unordered_map<string, int> uni = MakeUnion(Letters1, Letters2);
    
    int s1 = 0, s2 = 0;
    for (const auto& letter : inter)
        s1 += letter.second;

    for (const auto& letter : uni)
        s2 += letter.second;
    
    if (s2 == 0)
        return 65536;
    
    return (double)s1 / s2 * 65536;
}

int main()
{
    string str1, str2;

    str1 = "FRANCE";
    str2 = "french";
    cout << solution(str1, str2) << endl;

    str1 = "handshake";
    str2 = "shake hands";
    cout << solution(str1, str2) << endl;

    str1 = "aa1+aa2";
    str2 = "AAAA12";
    cout << solution(str1, str2) << endl;

    str1 = "E=M*C^2";
    str2 = "e=m*c^2";
    cout << solution(str1, str2) << endl;

    return 0;
}
