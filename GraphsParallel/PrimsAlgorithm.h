#pragma once
#include "Graph.h"
#include"MinValData.h"
#include<vector>

class PrimsAlgorithm
{
	Graph graph;
	Graph result;
	void initial_fill_result(int size);
	void fill_graph(Graph& _graph);
	std::vector<bool> included_vertices;
	bool all_vertices_included();
	MinValData find_min_val(MinValData& min_value, int from, int to);
	void find_min_distance_vertex();
	void find_min_distance_vertex_parallel();
public:
	PrimsAlgorithm(Graph _graph);
	void print();
	void algorithm();
	void parallel_algorithm();
	~PrimsAlgorithm();
};

