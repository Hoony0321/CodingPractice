#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int num;
int Size;
vector<vector<int>> List;
vector<vector<int>> result;

int order;
bool Judge(vector<int> vec1, vector<int> vec2) {
	int num = 0;
	for (int i = 0; i < Size; i++) {
		if (vec1[i] != vec2[i]) { num++; }
	}
	if (num == 1) { return true; }
	else { return false; }
}

void DFS(int current,int target, vector<int> used) {

	for (int i = 0; i < List.size(); i++) {
		//전에 사용한 index가 아니면 검사
		if ((find(used.begin(), used.end(), i) == used.end())) {
			if (Judge(List[i], List[current])) {
				used.push_back(i);

				if (i == target) { 
					for (auto elem : used) {
						result[order].push_back(elem);
					}
					break;
				}

				DFS(i, target, used);
				used.pop_back();
			}

		}

		
	}
}

int main() {
	cin >> num >> Size;
	List.resize(num);
	string Val;
	for (int i = 0; i < num; i++) {
		List[i].resize(Size);
		cin >> Val;
		for (int j = 0; j < Size; j++) {
			List[i][j] = Val[j] - '0';
		}
	}
	
	int times;
	cin >> times;
	result.resize(times);
	int target;
	for (int i = 0; i < times; i++) {
		cin >> target;
		order = i;
		DFS(0, target - 1, { 0 });
	}

	for (auto elem : result) {
		for (auto elem2 : elem) {
			cout << elem2 + 1 << " ";
		}
		cout << endl;
	}



}