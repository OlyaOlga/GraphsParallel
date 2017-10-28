#pragma once
#include <fstream>

using std::ostream;
using std::istream;

class DijkstraAlgorithm;
class FloydAlgorithm;
class PrimsAlgorithm;
class Graph
{
private:
	friend class DijkstraAlgorithm;
	friend class FloydAlgorithm;
	friend class PrimsAlgorithm;
	int** matrix;
	int quantity_of_vertices;
	void initialize_matrix();
	void allocate_matrix();
public:
	Graph(int _quantity_of_vertices=1);
	Graph(const Graph& graph);
	Graph operator=(const Graph& graph);
	void connect_vertices(int i, int j, int distance = 1);
	void undirected_connect_vertices(int i, int j, int distance = 1);
	friend ostream& operator<<(ostream& stream, const Graph& graph);
	friend istream& operator >> (istream& stream, Graph& graph);
	~Graph();
	
};

