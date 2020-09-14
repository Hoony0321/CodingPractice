#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> vec(7, 0);

int main() {
	for (auto& elem : vec) {
		cin >> elem;
	}
	sort(vec.begin(), vec.end());
	cout << vec[6] << endl;
	cout << vec[5] << endl;
}