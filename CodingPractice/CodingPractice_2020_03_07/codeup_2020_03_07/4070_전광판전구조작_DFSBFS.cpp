#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> Map;
vector<vector<int>> Map2;
int a, b;
vector<vector<bool>> Visited;
vector<vector<bool>> Visited2;
int action = 0;
int action2 = 0;

void DFS_ON(int y,int x,bool first) {
	if (Visited[y][x]) { return; }

	Visited[y][x] = true;

	if (Map[y][x] == 1) { return; }

	Map[y][x] = 1;
	if (first) { action++; }

	//Up
	if( !(y - 1 < 0)){ DFS_ON(y - 1, x,false); }
	//Down
	if(!(y + 1 > a - 1)){ DFS_ON(y + 1, x, false); }
	//Left
	if(!(x - 1 < 0)){ DFS_ON(y, x - 1, false); }
	//Right
	if(!(x + 1 > b - 1)){ DFS_ON(y, x + 1, false); }
}


void DFS_OFF(int y, int x, bool first) {
	if (Visited2[y][x]) { return; }

	Visited2[y][x] = true;

	if (Map2[y][x] == 0) { return; }

	Map2[y][x] = 0;
	if (first) { action2++; }

	//Up
	if (!(y - 1 < 0)) { DFS_OFF(y - 1, x, false); }
	//Down
	if (!(y + 1 > a - 1)) { DFS_OFF(y + 1, x, false); }
	//Left
	if (!(x - 1 < 0)) { DFS_OFF(y, x - 1, false); }
	//Right
	if (!(x + 1 > b - 1)) { DFS_OFF(y, x + 1, false); }
}


int main() {
	
	cin >> a >> b;
	Map.resize(a);
	Visited.resize(a);

	for (auto& elem : Map) {
		elem.resize(b);
	}

	for (auto& elem : Visited) {
		elem.resize(b);
	}



	Map2.resize(a);
	Visited2.resize(a);

	for (auto& elem : Map2) {
		elem.resize(b);
	}

	for (auto& elem : Visited2) {
		elem.resize(b);
	}
	int num;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> num;
			Map[i][j] = num;
			Map2[i][j] = num;
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			DFS_ON(i, j,true);
			DFS_OFF(i, j, true);
		}
	}

	cout << action << " " << action2 << endl;
}