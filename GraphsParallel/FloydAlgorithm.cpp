#include "FloydAlgorithm.h"
#include <iostream>

void FloydAlgorithm::allocate_helper_matrix(vector<vector<int>>& matrix)
{
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		vector<int> current_row(quantity_of_vertices, 0);
		matrix.push_back(current_row);
	}
}

FloydAlgorithm::FloydAlgorithm(Graph graph)
{
	quantity_of_vertices = graph.quantity_of_vertices;
	form_initial_W(graph);
	form_initial_theta(theta_next);
	form_initial_theta(theta_prev);
	allocate_helper_matrix(W_next);
}

void FloydAlgorithm::form_initial_W(Graph & graph)
{
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		vector<int> curr_vector(quantity_of_vertices, 0);
		for (int j = 0; j < quantity_of_vertices; ++j)
		{
			int value_to_add = 0;
			if (i != j)
			{
				if (graph.matrix[i][j] == 0)
				{
					value_to_add = INT_MAX;
				}
				else
				{
					value_to_add = graph.matrix[i][j];
				}
			}
			curr_vector[j] = value_to_add;
		}
		W_prev.push_back(curr_vector);
	}
}

void FloydAlgorithm::form_initial_theta(vector<vector<int>>& theta)
{
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		vector<int> curr_vector(quantity_of_vertices, i+1);
		for (int j = 0; j < quantity_of_vertices; ++j)
		{
			if (i == j)
			{
				curr_vector[j] = 0;
			}
		}
		theta.push_back(curr_vector);
	}
}

void FloydAlgorithm::printMatrix(vector<vector<int>>& matrix)
{
	for (size_t i = 0; i < quantity_of_vertices; ++i)
	{
		for (size_t j = 0; j < quantity_of_vertices; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void FloydAlgorithm::algorithm()
{
	for (int k = 0; k < quantity_of_vertices; ++k)
	{
		k_th_iteration(k);
		W_prev = W_next;
		cout << "k:" << k << endl;
		printMatrix(W_prev);
		cout << endl;
		theta_prev = theta_next;
	}
}

void FloydAlgorithm::k_th_iteration(int k)
{
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		for (int j = 0; j < quantity_of_vertices; ++j)
		{
			if (i == k || j == k || i==j)
			{
				W_next[i][j] = W_prev[i][j];
				theta_next[i][j] = theta_prev[i][j];
			}
			else
			{
				int min = W_prev[i][j];
				if (W_prev[i][k] != INT_MAX&&W_prev[k][j] != INT_MAX)
				{
					int possible_min = W_prev[i][k] + W_prev[k][j];
					if (possible_min < min)
					{
						W_next[i][j] = possible_min;
						theta_next[i][j] = theta_prev[k][j];
						continue;
					}
				}
				W_next[i][j] = W_prev[i][j];
				theta_next[i][j] = theta_prev[i][j];
			}
		}
	}
}

vector<vector<int>> FloydAlgorithm::get_W()
{
	return W_prev;
}

vector<vector<int>> FloydAlgorithm::get_theta()
{
	return theta_prev;
}

FloydAlgorithm::~FloydAlgorithm()
{
}
