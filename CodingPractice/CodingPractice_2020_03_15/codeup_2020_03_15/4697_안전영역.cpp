#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int Max_height = 0;
int Min_height = 100;
int Size;
int result;
vector<int> vec;
vector<vector<int>> MAP;
vector<vector<bool>> Visited;

void DFS(int y,int x,int height,bool first) {
	if (Visited[y][x]) { return; }
	Visited[y][x] = true;

	if (MAP[y][x] <= height) { return; }

	//영역 개수 체크(처음일 경우만 카운팅)
	if (first) { result++; first = false; }

	//up
	if(!(y-1<0)){ DFS(y - 1, x, height, first); }
	//down
	if(!(y+1 > Size - 1)){ DFS(y + 1, x, height, first); }
	//left
	if(!(x-1 < 0)){ DFS(y, x - 1, height, first); }
	//down
	if(!(x+1 > Size - 1)){ DFS(y, x + 1, height, first); }
	

}

int main() {
	cin >> Size;
	MAP.resize(Size);
	Visited.resize(Size);
	for (int i = 0; i < Size; i++) {
		MAP[i].resize(Size);
		Visited[i].resize(Size);
	}

	for (auto& elem : MAP) {
		for (auto& elem2 : elem) {
			cin >> elem2;
			if (elem2 > Max_height) { Max_height = elem2; }
			if (elem2 < Min_height) { Min_height = elem2; }
		}
	}

	for (int i = Min_height; i < Max_height; i++) {
		//Visited 초기화
		for (int a = 0; a < Size; a++) {
			for (int b = 0; b < Size; b++) {
				Visited[a][b] = false;
			}
		}


		for (int p = 0; p < Size; p++) {
			for (int q = 0; q < Size; q++) {
				DFS(p, q, i, true);
			}
		}

		vec.push_back(result);
		result = 0;
	}

	sort(vec.begin(), vec.end());
	cout << vec[vec.size() - 1] << endl;
}