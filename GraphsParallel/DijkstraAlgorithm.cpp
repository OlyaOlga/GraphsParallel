#include "DijkstraAlgorithm.h"
#include <iostream>
#include <future>
#include<thread>
#include<vector>

DijkstraAlgorithm::DijkstraAlgorithm(Graph _graph, int _number_of_initial_vertex, bool _is_parallel):
	number_of_initial_vertex(_number_of_initial_vertex),
	graph(_graph),
	is_parallel(_is_parallel)
{
	labels = vector<bool>(graph.quantity_of_vertices, false);
	distances = vector<int>(graph.quantity_of_vertices, INT_MAX);
	shortest_way = vector<int>(graph.quantity_of_vertices, -1);
	distances[_number_of_initial_vertex] = 0;
}

void DijkstraAlgorithm::algorithm()
{
	while (has_unlabeled_vertices())
	{
		int index_of_min_distance = find_min_distance();
		if (is_parallel == true)
		{
			process_vertex(index_of_min_distance);
		}
		else
		{
			process_vertex(index_of_min_distance, true);
		}
	}
}

void DijkstraAlgorithm::process_vertex(int num_of_vertex)
{
	vector<thread> threads;
	int quantity_of_threads = 2;
	int from = 0;
	int step = graph.quantity_of_vertices / quantity_of_threads;
	int to = step;
	for (; to <graph.quantity_of_vertices; from=to, to+= step)
	{
		threads.push_back(thread(&DijkstraAlgorithm::help_parallel_process_vertex, this, from, to, num_of_vertex));
	}
	for (int i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}
	labels[num_of_vertex] = true;
}

void DijkstraAlgorithm::process_vertex(int num_of_vertex, bool)
{
	
	for (size_t i = 0; i < distances.size(); i++)
	{
		if (graph.matrix[num_of_vertex][i] != 0 && labels[i] == false)
		{
			check_current_neighbour(num_of_vertex, i);
		}
	}
	labels[num_of_vertex] = true;
}

void DijkstraAlgorithm::help_parallel_process_vertex(int from, int to, int num_of_vertex)
{
	for (size_t i = from; i < to; i++)
	{
		if (graph.matrix[num_of_vertex][i] != 0 && labels[i] == false)
		{
			check_current_neighbour(num_of_vertex, i);
		}
	}
}

bool DijkstraAlgorithm::has_unlabeled_vertices()
{
	for (size_t i = 0; i < labels.size(); ++i)
	{
		if (labels[i] == false) 
		{
			return true;
		}
	}
	return false;
}

int DijkstraAlgorithm::find_min_distance()
{
	int min_index;
	int min_value = INT_MAX;
	for (size_t i = 0; i < labels.size(); i++)
	{
		if (labels[i] == false)
		{
			if (distances[i] <= min_value)
			{
				min_value = distances[i];
				min_index = i;
			}
		}
	}
	return min_index;
}

void DijkstraAlgorithm::check_current_neighbour(int num_of_current_vertex, int current_neighbour)
{
	if (distances[current_neighbour] > distances[num_of_current_vertex] + graph.matrix[num_of_current_vertex][current_neighbour])
	{
		distances[current_neighbour] = distances[num_of_current_vertex] + graph.matrix[num_of_current_vertex][current_neighbour];
		shortest_way[current_neighbour] = num_of_current_vertex;
	}
}

vector<int> DijkstraAlgorithm::get_minimum_distances()
{
	return distances;
}

vector<int> DijkstraAlgorithm::get_shortest_way()
{
	return shortest_way;
}




DijkstraAlgorithm::~DijkstraAlgorithm()
{
}
