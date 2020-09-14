#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Box[100][100][100];
int M, N, H;
int days = 0;
vector<vector<int>> Direction = { {-1, 0 ,0},{+1,0,0},{0,+1,0},{0,-1,0},{0,0,-1},{0,0,+1} };


void DFS(int x, int y, int z) {
	if (Box[z][y][x] == 1) {
		if (1== 1) {
			for (int i = 0; i < 6; i++) {
				Box[z + Direction[i][0]][y + Direction[i][1]][x + Direction[i][2]] = 1;
			}
		}
	}







}

int main() {
	//M 가로 N 세로 H 높이
	cin >> M >> N >> H;

	for (int a = 0; a < H; a++) {
		for (int b = 0; b < N; b++) {
			for (int c = 0; c < M; c++) {
				cin >> Box[a][b][c];
			}
		}
	}








}