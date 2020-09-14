#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int>& vec, int stage, int sum, int target,int& answer) {
	if (stage == vec.size()) { // ¿Ï·á
		if (sum == target) answer += 1;
	}
	else {

		dfs(vec, stage + 1, sum + vec[stage], target,answer);
		dfs(vec, stage + 1, sum - vec[stage], target,answer);

	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	dfs(numbers, 0, 0, target, answer);

	return answer;
}

int main() {
	vector<int> test = { 1,1,1,1,1 };
	int target = 3;

	cout << solution(test, target) << endl;

}