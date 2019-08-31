#include <vector>
#include <iostream>

#include "dfs.h"

using std::vector;
using std::cout;
using std::endl;

void DFS(const IGraph* graph) {
	vector<bool> wasUsed(graph->VerticesCount(), false);
	for (int i = 0; i < graph->VerticesCount(); i++) {
		if (wasUsed[i]) {
			continue;
		}
		vector<int> stack = {i};
		wasUsed[i] = true;
		while (!stack.empty()) {
			int currentVertex = stack.back();
			stack.pop_back();
			cout << currentVertex << endl;
			vector<int> neighbors;
			graph->GetNextVertices(currentVertex, neighbors);
			for (int j : neighbors) {
				if (wasUsed[j]) {
					continue;
				}
				stack.push_back(j);
				wasUsed[j] = true;
			}
		}
	}
}
