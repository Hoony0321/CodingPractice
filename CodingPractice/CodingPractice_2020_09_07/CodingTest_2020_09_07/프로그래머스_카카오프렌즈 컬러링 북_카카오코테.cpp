#include <iostream>
#include <vector>


using namespace std;

void DFS(int y, int x, int& number_of_area, int& max_size, vector<vector<int>>& map, vector<vector<bool>>& visited, bool first) {
	if (first) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) { //�湮���� ����.
					visited[i][j] = true;
					if (map[i][j] != 0) {

					}
				}
			}
		}
	}
	else {

	}
	


}

//���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<vector<bool>> visited(m, vector<bool>(n, false));



	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {




}
