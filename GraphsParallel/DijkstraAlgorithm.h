#pragma once
#include "Graph.h"
#include<vector>
using namespace std;
class DijkstraAlgorithm
{
	Graph graph;
	int number_of_initial_vertex;
	vector<int> distances;
	vector<bool> labels;
	vector<int> shortest_way;
	void process_vertex(int num_of_vertex);
	bool has_unlabeled_vertices();
	int find_min_distance();
	void check_current_neighbour(int num_of_current_vertex, int current_neighbour);//parallel method
	void DijkstraAlgorithm::process_vertex(int num_of_vertex, bool);//successive method
	void help_parallel_process_vertex(int from, int to, int num_of_vertex);
	bool is_parallel;
public:
	DijkstraAlgorithm(Graph _graph, int _number_of_initial_vertex=0, bool _is_parallel=true);
	void algorithm();	
	vector<int> get_minimum_distances();
	vector<int> get_shortest_way();
	~DijkstraAlgorithm();
};

