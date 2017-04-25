#include<iostream>
#include<fstream>

using namespace std;
#define maxNum 100

bool match(int graph[maxNum][maxNum], int leftVertex, bool seen[], int matchR[], int leftVertexNum, int rightVertexNum) {
		
	for (int rightVertex = 0; rightVertex < rightVertexNum; rightVertex++) {
		if (graph[leftVertex][rightVertex] == 1 && !seen[rightVertex]) {
			seen[rightVertex] = true;
			if (matchR[rightVertex] < 0 || match(graph, matchR[rightVertex], seen, matchR, leftVertexNum, rightVertexNum)) {
				matchR[rightVertex] = leftVertex;
				
				return true;
			}
		}
	}

	return false;
}

int maxMatch(int graph[maxNum][maxNum], int leftVertexNum, int rightVertexNum) {
	int matchR[maxNum];

	memset(matchR, -1, sizeof(matchR));
	int result = 0;
	for (int leftVertex = 0; leftVertex < leftVertexNum; leftVertex++) {
		bool seen[maxNum];
		memset(seen, 0, sizeof(seen));

		if (match(graph, leftVertex, seen, matchR, leftVertexNum, rightVertexNum)) {			
			result++;
		}
	}


	for (int i = 0; i < rightVertexNum; i++) {
		if (matchR[i] != -1) {
			cout << matchR[i] << " - " << i << endl;
		}
	}
	return result;
}

int main() {
	
	ifstream fin("matching.inp");

	int leftVertexNum, rightVertexNum;
	int row, col;
	int bipartiteGraph[maxNum][maxNum] = { 0, };
	fin >> leftVertexNum >> rightVertexNum;

	for (int i = 0; i < leftVertexNum; i++) {
		fin >> row >> col;
		for (int j = 0; j < col; j++) {
			int temp;
			fin >> temp;
			bipartiteGraph[i][temp - 1] = 1;
		}
	}

	cout << maxMatch(bipartiteGraph,leftVertexNum, rightVertexNum) << endl;

}