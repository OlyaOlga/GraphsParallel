#pragma once
#include<vector>
#include "Graph.h"
using namespace std;
class FloydAlgorithm
{
	void allocate_helper_matrix(vector<vector<int>>&  matrix);
	vector<vector<int>> W_prev;
	vector<vector<int>> W_next;
	vector<vector<int>> theta_prev;
	vector<vector<int>> theta_next;
	int quantity_of_vertices;
public:
	FloydAlgorithm(Graph graph);
	void form_initial_W(Graph& graph);
	void form_initial_theta(vector<vector<int>>& theta);
	void printMatrix(vector<vector<int>>& matrix);
	void algorithm();
	void k_th_iteration(int k);
	vector<vector<int>> get_W();
	vector<vector<int>> get_theta();
	~FloydAlgorithm();
};

