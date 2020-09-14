#include<iostream>

using namespace std;

int main() {

	int targetNumber;
	int result;


	cin >> targetNumber;
	

	int prev_2 = 1;
	int prev_1 = 1;

	if (targetNumber == 1 || targetNumber == 2) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 3; i <= targetNumber; i++) {
		result = prev_2 + prev_1;
		prev_2 = prev_1;
		prev_1 = result;

	}

	cout << result << endl;

}