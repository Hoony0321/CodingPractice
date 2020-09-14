#include<iostream>
#include<vector>

using namespace std;

int MapSize;


vector<vector<int>> Map;
vector<vector<bool>> Visited;

void Visiting(int i, int j);

void Search(int x, int y, int sum, vector<vector<bool>> Visited);

int Max = -1;


int main() {

	cin >> MapSize;

	Map.resize(MapSize);
	for (int i = 0; i < MapSize; i++) {
		Map[i].resize(MapSize, -1);
	}

	Visited.resize(MapSize);
	for (int i = 0; i < MapSize; i++) {
		Visited[i].resize(MapSize, false);
	}


	for (auto& elem : Map) {
		for (auto& elem2 : elem) {
			cin >> elem2;
		}
	}

	for (int i = 0; i < MapSize; i++) {
		Search(0, i,0, Visited);
	}

	cout << Max << endl;
	

}

void Visiting(int i, int j, vector<vector<bool>>& Visited) {
	for (int a = 0; a < MapSize; a++) {
		Visited[i][a] = true;
		Visited[a][j] = true;
	}
}

void Search(int x, int y,int sum, vector<vector<bool>> Visited) {
	if (x == MapSize) {
		if (sum > Max) {
			Max = sum;
		}
		return;
	}
	
	//방문해도 되는 곳
	if (Visited[x][y] != true) {
		Visited[x][y] = true;
		Visiting(x, y,Visited);
		sum += Map[x][y];

		for (int i = 0; i < MapSize; i++) {
			Search(x + 1, i, sum, Visited);
		}
	}

	//방문하면 안 되는 곳
	else {
		return;
	}
}