#include "PrimsAlgorithm.h"
#include <iostream>
#include<thread>
#include<future>

using namespace std;

void PrimsAlgorithm::initial_fill_result(int size)
{
	result = Graph(size);
	for (size_t i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			result.matrix[i][j] = 0;
		}
	}
}

PrimsAlgorithm::PrimsAlgorithm(Graph _graph)
{
	graph = Graph(_graph.quantity_of_vertices);
	fill_graph(_graph);
	initial_fill_result(graph.quantity_of_vertices);
	included_vertices = vector<bool>(_graph.quantity_of_vertices, false);
}

void PrimsAlgorithm::fill_graph(Graph & _graph)
{
	for (size_t i = 0; i < _graph.quantity_of_vertices; ++i)
	{
		for (size_t j = i; j < _graph.quantity_of_vertices; ++j)
		{
			if (i == j)
			{
				graph.connect_vertices(i, j, 0);
			}
			else
			{
				graph.undirected_connect_vertices(i, j, _graph.matrix[i][j]);
			}
		}
	}
}

bool PrimsAlgorithm::all_vertices_included()
{
	for (int i = 0; i < included_vertices.size();++i)
	{
		if (included_vertices[i] == false)
		{
			return false;
		}
	}
	return true;
}

MinValData PrimsAlgorithm::find_min_val(MinValData& min_value, int from, int to)
{
	for (int i = from; i < to; ++i)
	{
		if (included_vertices[i] == true)
		{
			for (size_t j = 0; j < graph.quantity_of_vertices; ++j)
			{
				if (included_vertices[j] == false && graph.matrix[i][j] != 0 && graph.matrix[i][j] < min_value.value)
				{
					min_value.value = graph.matrix[i][j];
					min_value.i = i;
					min_value.j = j;
				}

			}
		}
	}
	return min_value;
}

void PrimsAlgorithm::print()
{
	cout << "Graph:" << endl;
	cout << graph;
	cout << "Result:" << endl;
	cout << result;
}

void PrimsAlgorithm::algorithm()
{
	included_vertices[0] = true;
	while (all_vertices_included() != true)
	{
		find_min_distance_vertex();
	}
}

void PrimsAlgorithm::parallel_algorithm()
{
	included_vertices[0] = true;
	while (all_vertices_included() != true)
	{
		find_min_distance_vertex_parallel();
	}

}

void PrimsAlgorithm::find_min_distance_vertex_parallel()
{	
	int quantity_of_threads = 2;
	int from = 0;
	int step = result.quantity_of_vertices / quantity_of_threads;
	int to = step;
	vector<future<MinValData>> threads;
	vector<MinValData> items;
	while (to <= result.quantity_of_vertices)
	{
		MinValData current_value;
		threads.push_back(async(&PrimsAlgorithm::find_min_val, this, current_value, from, to));
		from = to;
		to += step;
	}
	for (int i = 0; i < threads.size(); ++i)
	{
		items.push_back(threads[i].get());
	}

	MinValData min_value = MinValData::find_minimum(items);

	included_vertices[min_value.j] = true;
	result.matrix[min_value.i][min_value.j] = min_value.value;
}

void PrimsAlgorithm::find_min_distance_vertex()
{
	MinValData current_value;
	find_min_val(current_value, 0, result.quantity_of_vertices);
	included_vertices[current_value.j] = true;
	result.matrix[current_value.i][current_value.j] = current_value.value;
}

PrimsAlgorithm::~PrimsAlgorithm()
{
}
