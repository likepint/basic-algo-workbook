#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define endl '\n'

// 내림차순 함수 정렬
bool compare(const int& a, const int& b)
{
	return a > b;
}

int solution1(int k, vector<int> tangerine)
{
	int answer = 0;

	unordered_map<int, int> tangerineMap;
	for (size_t i = 0; i < tangerine.size(); ++i)
		tangerineMap[tangerine[i]]++;

	vector<int> numbers; // 크기에 따른 개수만 저장
	for (const auto& tan : tangerineMap)
		numbers.emplace_back(tan.second);

	// compare 함수로 내림차순 정렬
	sort(numbers.begin(), numbers.end(), compare);

	for (const auto& tan : numbers)
	{
		k -= tan;

		answer++;

		if (k <= 0)
			break;
	}

	return answer;
}

int solution2(int k, vector<int> tangerine)
{
	int answer = 0;

	unordered_map<int, int> tangerineMap; // <크기, 개수> 저장
	for (size_t i = 0; i < tangerine.size(); ++i)
		tangerineMap[tangerine[i]]++;

	vector<int> numbers; // 크기에 따른 개수만 저장
	for (const auto& tan : tangerineMap)
		numbers.emplace_back(tan.second);

	sort(numbers.begin(), numbers.end(), [](const auto& a, const auto& b)
		{
			return a > b;
		}); // 람다를 사용하여 내림차순 compare 함수 구현

	for (const auto& num : numbers)
	{
		k -= num;

		answer++;

		if (k <= 0)
			break;
	}

	return answer;
}

int main()
{
	int k = 6, result = 0;
	vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 };

	result = solution2(k, tangerine);

	cout << result << endl;

	return 0;
}