#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int codeSize;
int resultSize;
vector<char> code;
vector<char> result;

void backtrack(int pos, int prev, int consonant, int vowel);

int isVowel(char tmpChar);

int main() {
	cin >> resultSize;
	cin >> codeSize;
	char inputData;

	result.resize(resultSize);
	for (int i = 0; i < codeSize; i++) {
		cin >> inputData;
		code.push_back(inputData);
	}

	//Á¤·Ä
	sort(code.begin(), code.end());

	backtrack(0, -1, 0, 0);
}

void backtrack(int pos, int prev, int consonant, int vowel) {
	if (pos == resultSize) {
		if (consonant >= 2 && vowel >= 1) {
			for (auto elem : result) cout << elem;
			cout << endl;
		}
		return;
	}

	if (prev < codeSize) {
		for (int i = prev + 1; i < codeSize; i++) {
			result[pos] = code[i];
			if (isVowel(code[i]) == 1) {
				backtrack(pos + 1, i, consonant, vowel + 1);
			}
			else backtrack(pos + 1, i, consonant + 1, vowel);
			
		}
	}
	
}

int isVowel(char tmpChar) {
	if (tmpChar == 'a') return 1;
	else if (tmpChar == 'e') return 1;
	else if (tmpChar == 'i') return 1;
	else if (tmpChar == 'o') return 1;
	else if (tmpChar == 'u') return 1;
	else return 0;
}