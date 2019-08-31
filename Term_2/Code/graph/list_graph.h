#pragma once

#include "graph.h"

#include <vector>

using std::vector;

class CListGraph : public IGraph {
public:
	CListGraph(int vertexCount);

	virtual void AddEdge(int from, int to);
	virtual int VerticesCount() const;
	virtual void GetNextVertices(int vertex, vector<int>& vertices) const;
	virtual void GetPrevVertices(int vertex, vector<int>& vertices) const;

private:
	vector<vector<int>> adjacencyList;
};
