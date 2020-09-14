#include<iostream>

using namespace std;

int main() {

	int inputSize;
	string inputData;

	cin >> inputSize >> inputData;

	int pos = 3;
	while (pos < inputSize) {
		inputData.insert(inputSize - pos, ",");
		pos += 3;
	}

	cout << inputData << endl;


}