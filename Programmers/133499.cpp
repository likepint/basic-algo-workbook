// 옹알이 (2)

#include "../Global.h"
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

const vector<string> Sounds = {"aya", "ye", "woo", "ma"};

bool IsValid(const string& s)
{
    int index = 0;
    int prevSoundIndex = -1;

    while (index < (int)(s.length()))
    {
        bool bMatched = false;

        for (int idx = 0; idx < (int)(Sounds.size()); ++idx)
        {
            string sound = Sounds[idx];

            if (s.length() - index < sound.length()) // 남은 길이가 단어보다 짧다면
                continue;

            // 현재 위치의 문자열이 발음 가능한 단어가 있는지 확인
            if (s.substr(index, sound.length()) == sound)
            {
                if (prevSoundIndex == idx) // 연속으로 똑같은 발음인지 체크
                    return false;

                index += (int)(sound.length());
                prevSoundIndex = idx;
                bMatched = true;
                break;
            }
        }
        
        if (!bMatched) // 매칭되지 않았다면
            return false;
    }

    return true;
}

int solution(vector<string> babbling)
{
    int answer = 0;

    for (const string& s : babbling)
    {
        if (IsValid(s))
            answer++;
    }

    return answer;
}

int main()
{
    vector<string> babbling;

    babbling = {"aya", "yee", "u" "maa"};
    cout << solution(babbling) << endl;

    babbling = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    cout << solution(babbling) << endl;

    return 0;
}
