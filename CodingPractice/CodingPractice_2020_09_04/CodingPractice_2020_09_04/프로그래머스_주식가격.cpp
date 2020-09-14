#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size(),0);
	int time = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		time = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			time++;
			if (j == prices.size() - 1) answer.push_back(time);
			else if (prices[i] > prices[j]) answer.push_back(time); break;
		}

	}


	return answer;
}