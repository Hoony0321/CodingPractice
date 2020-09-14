#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//이 문제는 입력값이 이미 배열에 들어가있는 상태임.
//즉 이 함수만 작성하면 문제가 해결되는 문제.

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i]) { answer = participant[i]; return answer; }
	}

}