#pragma once
#include<vector>
#include "Graph.h"
using namespace std;
class FloydAlgorithm
{
	vector<vector<int>> W_prev;
	vector<vector<int>> W_next;
	vector<vector<int>> theta_prev;
	vector<vector<int>> theta_next;
	int quantity_of_vertices;
public:
	FloydAlgorithm(Graph graph);
	void form_initial_W(Graph& graph);
	void form_initial_theta();
	void printMatrix(vector<vector<int>>& matrix);
	vector<vector<int>> get_W();
	vector<vector<int>> get_theta();
	~FloydAlgorithm();
};

