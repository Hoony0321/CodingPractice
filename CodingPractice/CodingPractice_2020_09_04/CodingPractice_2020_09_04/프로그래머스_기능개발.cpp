#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> finishList; //완료된 작업
	int stage = 0; //현재 진행해야 할 단계
	//일 진행
	while (stage != progresses.size()) {
		for (int i = 0; i < progresses.size(); i++) {
			if (progresses[i] < 100) {
				progresses[i] += speeds[i];
				if (progresses[i] >= 100) {
					finishList.push_back(i);
				}
			}
		}

		sort(finishList.begin(), finishList.end());

		int cnt = 0;
		int listSize = finishList.size();
		for (int i = stage; i < stage + listSize; i++) {
			if (i == *finishList.begin()) {
				cnt++;
				finishList.erase(finishList.begin());
			}
			else break;
		}

		if (cnt != 0) {
			stage += cnt;
			answer.push_back(cnt);
		}
	}


	return answer;
}

int main() {
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };

	for (auto elem : solution(progresses, speeds)) {
		cout << elem << " ";
	}
	cout << endl;
	
}