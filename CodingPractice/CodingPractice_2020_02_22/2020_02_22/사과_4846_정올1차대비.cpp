#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int schoolNum;

vector<vector<int>> Information;

int Function(vector<int> vec) {

	return vec[1] % vec[0];
}

int main() {
	cin >> schoolNum;
	Information.resize(schoolNum);
	for (auto& elem : Information) {
		elem.resize(2, 0);
	}
	for (int i = 0; i < schoolNum; i++) {
		cin >> Information[i][0] >> Information[i][1];
	}
	int sum = 0;
	for (auto elem : Information) {
		sum += Function(elem);
	}

	cout << sum;
}