#include<iostream>
#include<string>
using namespace std;

int main() {
	string inputData;

	cin >> inputData;


	for (int i = inputData.size() - 1; i >= 0; i--) {
		cout << inputData[i];
	}
	cout << endl;
}