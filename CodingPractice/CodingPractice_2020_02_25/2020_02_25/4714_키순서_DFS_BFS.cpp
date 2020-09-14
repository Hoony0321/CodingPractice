#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int studentNum;

vector<vector<int>> Info;
vector<bool> visited;
vector<int> checking;
int nu2 = 1;
int presentNum = 0;
void DFS(int num) {
	cout << nu2 << "실행" << endl;
	nu2++;
	checking[presentNum - 1] += Info[num - 1].size();
	for (int i = 0; i < Info[num - 1].size(); i++) {
		checking[Info[num - 1][i] - 1] += 1;
		DFS(Info[num - 1][i]);
	}
	
}

int main() {
	int inputNum;
	cin >> studentNum >> inputNum;
	Info.resize(studentNum);

	visited.resize(studentNum);
	checking.resize(studentNum);
	


	for (int i = 0; i < inputNum; i++) {
		int a, b;
		cin >> a >> b;
		Info[b - 1].push_back(a);
	}

	for (auto elem : Info) {
		for (auto elem2 : elem) {
			cout << elem2 << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < studentNum; i++) {
		presentNum = i + 1;
		DFS(i + 1);
	}
	int num = 0;
	cout << "결과" << endl;
	for (auto elem : checking) {
		cout << elem << " ";
		if (elem >= studentNum - 1) { num++; }
	}
	cout << num << endl;

	
}