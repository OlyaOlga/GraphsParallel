#include "FloydAlgorithm.h"
#include <iostream>

FloydAlgorithm::FloydAlgorithm(Graph graph)
{
	quantity_of_vertices = graph.quantity_of_vertices;
	form_initial_W(graph);
	form_initial_theta();
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

void FloydAlgorithm::form_initial_theta()
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
		theta_prev.push_back(curr_vector);
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
