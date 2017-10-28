#include<iostream>
#include <vector>
#include <fstream>
#include<ctime>
#include "Graph.h"
#include "DijkstraAlgorithm.h"
#include "FloydAlgorithm.h"
#include "PrimsAlgorithm.h"
using namespace std;

void Dijkstra()
{
	cout << "Dijkstra" << endl;
	Graph randomGraph(2000);
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
	cout << endl;
}

void Floyd()
{
	Graph gr(100);
	cout << "Floyd:" << endl;
	FloydAlgorithm algorithm(gr);
	int time = clock();
	algorithm.parallel_algorithm();
	int another_time = clock();
	cout << "parallel: " << another_time - time << endl;
	cout << endl;
	FloydAlgorithm sucsessive(gr);
	time = clock();
	sucsessive.algorithm();
	another_time = clock();
	cout << "not parallel: " << another_time - time << endl;
	cout << endl;
}

void Prim()
{
	Graph gr(100);
	cout << "Prims algorithm:" << endl;
	PrimsAlgorithm prim(gr);
	int time = clock();
	prim.parallel_algorithm();
	int another_time = clock();
	cout << "parallel: " << another_time - time << endl;
	cout << endl;

	PrimsAlgorithm succsessive(gr);
	time = clock();
	succsessive.algorithm();
	another_time = clock();
	cout << "not parallel: " << another_time - time << endl;
	cout << endl;
}

void main() 
{
	Dijkstra();
	Floyd();
	Prim();
	system("pause");
}