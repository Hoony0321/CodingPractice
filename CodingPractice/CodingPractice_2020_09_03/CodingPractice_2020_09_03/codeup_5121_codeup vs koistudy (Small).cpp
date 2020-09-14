#include<iostream>
#include<vector>

using namespace std;

int day;
vector<int> codeup;
vector<int> koistudy;
int maxVal;

void dfs(int index, int cod, int koi, int sum) {
	
	if (index == day) { // 종료
		if (cod > 0 && koi > 0) {
			if (sum > maxVal) maxVal = sum;
			return;
		}
		else {
			if (cod == 0) { // codeup 1개도 없을때
				for (int i = 0; i < day; i++) {
					dfs(index, cod + 1, koi - 1, sum - koistudy[i] + codeup[i]);
				}
			}
			else { // koistudy 1개도 없을때
				for (int i = 0; i < day; i++) {
					dfs(index, cod - 1, koi + 1, sum + koistudy[i] - codeup[i]);
				}
			}


		}
		
	}
	else{
		if (codeup[index] > koistudy[index]) dfs(index + 1, cod + 1, koi, sum + codeup[index]);
		else  dfs(index + 1, cod, koi + 1, sum + koistudy[index]);
		
	}
}



int main() {
	cin >> day;
	int tmpData;
	for (int i = 0; i < day; i++) {
		cin >> tmpData;
		codeup.push_back(tmpData);
	}

	for (int i = 0; i < day; i++) {
		cin >> tmpData;
		koistudy.push_back(tmpData);
	}

	dfs(0, 0, 0, 0);

	cout << maxVal << endl;

}