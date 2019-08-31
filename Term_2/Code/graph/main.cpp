#include "list_graph.h"
#include "dfs.h"

#include <iostream>

using namespace std;

int main() {
	CListGraph graph(10);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 3);
	graph.AddEdge(0, 1);
	graph.AddEdge(3, 4);
	graph.AddEdge(4, 5);
	graph.AddEdge(5, 6);
	graph.AddEdge(2, 7);
	graph.AddEdge(8, 9);
	
	DFS(&graph);
	return 0;
}
