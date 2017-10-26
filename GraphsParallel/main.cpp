#include<iostream>
#include <vector>
#include <fstream>
#include<ctime>
#include "Graph.h"
#include "DijkstraAlgorithm.h"
#include "FloydAlgorithm.h"
using namespace std;

void Dijkstra()
{
	cout << "Dijkstra" << endl;
	Graph randomGraph(2000);
	cout << "filled" << endl;
	DijkstraAlgorithm dijkstra(randomGraph, 0);
	int time = clock();
	dijkstra.algorithm();
	int another_time = clock();
	cout << "parallel: " << another_time - time << endl;
	cout << endl;

	DijkstraAlgorithm successiveAlg(randomGraph, 0, false);
	time = clock();
	successiveAlg.algorithm();
	another_time = clock();
	cout << "not parallel: " << another_time - time << endl;
	system("pause");
}

void main()
{
	Graph gr;
	fstream file("Floyd.txt");
	file >> gr;
	FloydAlgorithm algorithm(gr);
	algorithm.printMatrix(algorithm.get_W());
	cout << endl;
	algorithm.printMatrix(algorithm.get_theta());
	system("pause");
}