#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int Combination(int n, int r) {
	if (n < r) { return 0; }
	if (n == r || r == 0) { return 1; }
	else {
		return Combination(n - 1, r - 1) + Combination(n - 1, r);
	}
}






int main() {

	int inputSize;
	cin >> inputSize;

	vector<int> array_rest_0;
	vector<int> array_rest_2;
	vector<int> array_rest_1;

	int tempNum;
	for (int i = 0; i < inputSize; i++) {
		cin >> tempNum;
		if (tempNum % 3 == 0) {
			array_rest_0.push_back(tempNum);
		}
		else if (tempNum % 3 == 2) {
			array_rest_2.push_back(tempNum);
		}
		else {
			array_rest_1.push_back(tempNum);
		}
	}

	int answer = 0;

	answer += Combination(array_rest_0.size(), 2);
	answer += array_rest_1.size() * array_rest_2.size();

	cout << answer;

}