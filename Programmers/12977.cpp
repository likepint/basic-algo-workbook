// 소수 만들기

#include "../Global.h"
#include <vector>

using namespace std;

const int MAX_NUMBER = 1000;

// BackTracking
vector<bool> MakePrimeNumberList(size_t InMax)
{
    vector<bool> prime(InMax + 1, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= (int)InMax; ++i)
    {
        if (prime[i])
        {
            for (int k = i * i; k <= (int)InMax; k += i)
                prime[k] = false;
        }
    }

    return prime;
}

void backtrack(const vector<bool>& prime, const vector<int>& nums, int& answer, int start, int count, int sum)
{
    if (count == 3)
    {
        if (prime[sum])
            answer++;

        return;
    }

    for (int idx = start; idx < (int)nums.size(); ++idx)
        backtrack(prime, nums, answer, idx + 1, count + 1, sum + nums[idx]);
}

// 백트래킹
int solution2(vector<int> nums)
{
    vector<bool> prime = MakePrimeNumberList(MAX_NUMBER * nums.size());

    int answer = 0;

    backtrack(prime, nums, answer, 0, 0, 0);

    return answer;
}

// 3중 반복문
int solution1(vector<int> nums)
{
    vector<bool> prime = MakePrimeNumberList(MAX_NUMBER * nums.size());

    int answer = 0;

    for (int i = 0; i < (int)nums.size(); ++i)
    {
        for (int j = i + 1; j < (int)nums.size(); ++j)
        {
            for (int k = j + 1; k < (int)nums.size(); ++k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (prime[sum])
                    answer++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = vector<int>();

    // 3중 반복문
    nums = {1, 2, 3, 4};
    cout << solution1(nums) << endl;
    cout << solution2(nums) << endl;

    nums = {1, 2, 7, 6, 4};
    cout << solution1(nums) << endl;
    cout << solution2(nums) << endl;

    return 0;
}
