#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Width;
int Height;
int result = 0;
vector<vector<int>> MAP;
vector<vector<bool>> Visited;
vector<vector<int>> Direction = { {-1,0} ,{+1,0} ,{0,-1} ,{0,+1} ,{-1,-1} ,{-1,+1} ,{+1,-1} ,{+1,+1} };

void DFS(int y, int x, bool first) {
	if (Visited[y][x]) { return; }
	Visited[y][x] = true;
	if (MAP[y][x] == 0) { return; }
	if (first) { result++; first = false; }

	for (int i = 0; i < Direction.size(); i++) {
		if (y + Direction[i][0] >= 0 && y + Direction[i][0] <= Height - 1 && x + Direction[i][1] >= 0 && x + Direction[i][1] <= Width - 1) {
			DFS(y + Direction[i][0], x + Direction[i][1], first);
		}
	}


}

int main() {
	cin >> Width >> Height;

	MAP.resize(Height);
	Visited.resize(Height);

	for (int i = 0; i < Height; i++) {
		MAP[i].resize(Width);
		Visited[i].resize(Width);
	}
	char InputVal;

	for (auto& elem : MAP) {
		for (auto& elem2 : elem) {
			cin >> InputVal;
			if (InputVal == '.') { elem2 = 0; }
			else { elem2 = 1; }
		}
	}
	int num = 1;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			DFS(i, j, true);
		}
	}

	cout << result << endl;


}