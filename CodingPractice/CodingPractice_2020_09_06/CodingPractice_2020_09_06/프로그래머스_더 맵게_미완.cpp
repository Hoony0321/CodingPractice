#include <string>
#include <vector>
#include <iostream>



using namespace std;

void swap(vector<int>& vec, int index1, int index2) {
	int temp = vec[index1];
	vec[index1] = vec[index2];
	vec[index2] = temp;
}

void heapUp(vector<int>& vec, int child) {
	int parent = (child - 1) / 2;

	if (parent > child) {
		swap(vec, parent, child); 
		heapUp(vec, parent);
	}
	
}

void heapDown(vector<int>& vec, int root) {
	int minChild;
	int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;
	if (leftChild >= vec.size()) return;
	if (leftChild == vec.size() - 1) {
		minChild = leftChild;
	}
	else {
		if (vec[leftChild] < vec[rightChild]) minChild = leftChild;
		else minChild = rightChild;
	}
	

	if (vec[root] > vec[minChild]) {
		swap(vec, root, minChild);
		heapDown(vec, minChild);
	}
}

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int minChild;
	//¼¯±â
	while (scoville[0] < K) {
		if (scoville.size() == 2) {
			if (scoville[0] + scoville[1] * 2 < K) {
				return -1;
			}
			else {
				return answer + 1;
			}
		}

		if (scoville[1] < scoville[2]) minChild = 1;
		else minChild = 2;

		int element_new = scoville[0] + scoville[minChild] * 2;
		scoville[0] = element_new;

		heapDown(scoville, 0);


		scoville[0] = scoville[scoville.size() - 1];
		scoville.erase(scoville.end() - 1);

		heapDown(scoville, 0);


		answer += 1;
	}


	return answer;
}

int main() {
	vector<int> test = { 1, 2, 3, 9, 10, 12 };
	cout << solution(test, 15) << endl;
}