#include "Graph.h"



void Graph::initialize_matrix()
{
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		for (int j = 0; j < quantity_of_vertices; ++j)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}
			if (rand() % 3 == 0)
			{
				matrix[i][j] = rand()%20;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void Graph::allocate_matrix()
{
	matrix = new int*[quantity_of_vertices];
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		matrix[i] = new int[quantity_of_vertices];
	}
}

Graph::Graph(int _quantity_of_vertices):
	quantity_of_vertices(_quantity_of_vertices)
{
	allocate_matrix();
	initialize_matrix();
}

Graph::Graph(const Graph & graph)
{
	quantity_of_vertices = graph.quantity_of_vertices;
	allocate_matrix();
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		for (int j = 0; j < quantity_of_vertices; ++j)
		{
			matrix[i][j] = graph.matrix[i][j];
		}
	}
}

Graph Graph::operator=(const Graph & graph)
{
	if (&graph != this)
	{
		for (int i = 0; i < quantity_of_vertices; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		quantity_of_vertices = graph.quantity_of_vertices;
		allocate_matrix();
		for (int i = 0; i < quantity_of_vertices; ++i)
		{
			for (int j = 0; j < quantity_of_vertices; ++j)
			{
				matrix[i][j] = graph.matrix[i][j];
			}
		}
	}
	return *this;
}

void Graph::connect_vertices(int i, int j, int distance)
{
	matrix[i][j] = distance;
}

void Graph::undirected_connect_vertices(int i, int j, int distance)
{
	connect_vertices(i, j, distance);
	connect_vertices(j, i, distance);
}

Graph::~Graph()
{
	for (int i = 0; i < quantity_of_vertices; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

/*void Graph::fil_test_graph()
{
	 {
		{0, 7, 9, 0, 0, 14},
		{ 7,0,10,15,0,0 },
		{ 9,10,0,11,0,2 },
		{ 0,15,11,0,6,0 },
		{ 0,0,0,6,0,9 },
		{ 14,0,2,0,9,0 }
	};
}*/

ostream & operator<<(ostream & stream, const Graph & graph)
{
	for (int i = 0; i < graph.quantity_of_vertices; ++i)
	{
		for (int j = 0; j < graph.quantity_of_vertices; ++j)
		{
			stream << graph.matrix[i][j] << " ";
		}
		stream << std::endl;
	}
	return stream;
}

istream & operator >> (istream & stream, Graph & graph)
{
	for (int i = 0; i < graph.quantity_of_vertices; ++i)
	{
		delete[] graph.matrix[i];
	}
	delete[] graph.matrix;

	
	stream >> graph.quantity_of_vertices;
	graph.allocate_matrix();
	for (int i = 0; i < graph.quantity_of_vertices; ++i)
	{
		for (size_t j = 0; j < graph.quantity_of_vertices; ++j)
		{
			stream >> graph.matrix[i][j];
		}
	}
	return stream;
}
