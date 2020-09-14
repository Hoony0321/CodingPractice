#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int K;
int C;
vector<vector<int>> result(0, vector<int>(2, 0));

bool JudgeFucntion(int round, vector<int> match, bool first) {
	if (round == K) {
		if (first) {
			if (match[0] + K - round < match[1]) { result.push_back(match);  return false; }
			else if (match[1] + K - round + 1 < match[0]) { result.push_back(match);  return false; }
			else { return true; }
		}
		else {
			if (match[0] + K - round < match[1]) { result.push_back(match);  return false; }
			else if (match[1] + K - round < match[0]) { result.push_back(match);  return false; }
			else { return true; }
		}
	}
	else {
		if (first) {
			if (match[0] + K - round < match[1]) { return false; }
			else if (match[1] + K - round + 1 < match[0]) { return false; }
			else { return true; }
		}
		else {
			if (match[0] + K - round < match[1]) { return false; }
			else if (match[1] + K - round < match[0]) { return false; }
			else { return true; }
		}
	}
	
	
}

void DFS(int round, vector<int> match) {
	if (round > K) { result.push_back(match); return; }

	//영희 o
	match[0] += 1;
	if (!JudgeFucntion(round, match, true)) { return; }
	//동수 o
	match[1] += 1;
	if (!JudgeFucntion(round, match, false)) { return; }
	DFS(round + 1, match);
	//동수 x
	match[1] -= 1;
	if (!JudgeFucntion(round, match, false)) { return; }
	DFS(round + 1, match);


	//초기화
	match[0] -= 1;

	//영희 x
	if (!JudgeFucntion(round, match, true)) { return; }
	//동수 o
	match[1] += 1;
	if (!JudgeFucntion(round, match, false)) { return; }
	DFS(round + 1, match);
	//동수 x
	match[1] -= 1;
	if (!JudgeFucntion(round, match, false)) { return; }
	DFS(round + 1, match);



}
// 03 -> 0 0 -> 0 0 -> 0 1 -> 0 2 -> 
int main() {
	cin >> K >> C;
	vector<bool> check;

	DFS(1, { 0,0 });

	for (int i = 0; i < C; i++) {
		int a, b;
		cin >> a >> b;
		for (auto elem : result) {
			if (elem[0] == a) {
				if (elem[1] == b) {
					check.push_back(true);
				}
			}
		}

		check.push_back(false);
	}

	for (auto elem : check) {
		cout << elem << endl;
	}


	for (auto elem1 : result) {
		for (auto elem : elem1) {
			cout << elem << " ";
		}
		cout << endl;
	}
}