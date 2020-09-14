#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
int number_of_house;
int Min;
vector<vector<int>> Map;
vector<vector<int>> costMap;

int main() {
	

	cin >> number_of_house;

	Map.resize(number_of_house);
	costMap.resize(number_of_house + 1);
	for (int i = 0; i < number_of_house; i++) {
		Map[i].resize(3);
		for (int j = 0; j < 3; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < number_of_house + 1; i++) {
		costMap[i].resize(3, 0);
	}

	for (int i = 1; i < number_of_house+1; i++) {
		costMap[i][0] = min(costMap[i - 1][1], costMap[i - 1][2]) + Map[i-1][0];
		costMap[i][1] = min(costMap[i - 1][0], costMap[i - 1][2]) + Map[i-1][1];
		costMap[i][2] = min(costMap[i - 1][1], costMap[i - 1][0]) + Map[i-1][2];
	}


	Min = *min_element(costMap[number_of_house].begin(),costMap[number_of_house].end());

	cout << Min << endl;



}