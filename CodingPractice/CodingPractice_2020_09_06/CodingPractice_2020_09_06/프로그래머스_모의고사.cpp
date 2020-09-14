#include <string>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> collect(answers.size(), 0);
	vector<int> secondPerson = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> thirdPerson = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int num1;
	int num2;
	int num3;

	for (int i = 0; i < answers.size(); i++) {
		//첫번째
		num1 = i % 5 + 1;
		if (answers[i] == num1) collect[0] += 1;
		//두번째
		num2 = i % 8;
		if (answers[i] == secondPerson[i]) collect[1] += 1;
		//세번째
		num3 = i % 10;
		if (answers[i] == thirdPerson[i]) collect[2] += 1;
	}

	int MaxValue = *max_element(collect.begin(), collect.end());

	for (int i = 0; i < 3; i++) {
		if (collect[i] == MaxValue) answer.push_back(i + 1);
	}

	return answer;
}
