#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& vec, vector<vector<bool>>& visited, int x, int y) {
	
	if (visited[x][y] == true) return;

	visited[x][y] = true;

	for (int i = 0; i < vec.size(); i++) {
		if (vec[x][i] == 1 && !visited[x][i]) {
			dfs(vec, visited, i, i);
		}
		
	}

}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<vector<bool>> visited(n, vector<bool>(n,false));

	for (int i = 0; i < n; i++) {
		if (visited[i][i] == false) {
			answer += 1;
			dfs(computers, visited, i, i);
		}
	}
	return answer;
}