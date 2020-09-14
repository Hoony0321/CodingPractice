#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int>> Map;
int Size[2];
int BlockNum;
vector<vector<int>> Block;

int main() {

	cin >> Size[0] >> Size[1];
	Map.resize(Size[0]);
	for (auto& elem : Map) {
		elem.resize(Size[1], 0);
	}
	cin >> BlockNum;
	Block.resize(BlockNum);
	for (auto& elem : Block) {
		elem.resize(4, 0);
	}
	for (int i = 0; i < BlockNum; i++) {
		for (auto& elem : Block[i]) {
			cin >> elem;
		}
	}

	//Map에 블럭 표시


}