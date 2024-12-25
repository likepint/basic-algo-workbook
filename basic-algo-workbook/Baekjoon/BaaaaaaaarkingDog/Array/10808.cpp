#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

string Input()
{
	string sentence = "";
	cin >> sentence;

	return sentence;
}

vector<int> execute(const string& InSentence)
{
	vector<int> alphabets(26, 0);

	for (const auto& idx : InSentence)
		alphabets[idx - 'a'] += 1;

	return alphabets;
}

int main()
{
	string sentence = Input();

	vector<int> alphabets = execute(sentence);

	for (const auto& idx : alphabets)
		cout << idx << ' ';

	cout << endl;

	return 0;
}