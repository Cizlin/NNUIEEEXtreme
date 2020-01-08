#include "Graph.h"

Graph::Graph(unsigned int numVertices)
{
	this->numVertices = numVertices; // Set matrix size.
	adjacencyMatrix = new bool* [numVertices]; // Allocate rows.
	for (int i = 0; i < numVertices; ++i)
	{
		adjacencyMatrix[i] = new bool[numVertices]; // Allocate columns.
	}
}

Graph::~Graph()
{
	for (int i = 0; i < numVertices; ++i)
	{
		delete[] adjacencyMatrix[i]; // Deallocate columns.
		adjacencyMatrix[i] = nullptr;
	}
	delete[] adjacencyMatrix; // Deallocate rows.
	adjacencyMatrix = nullptr;
}

bool Graph::adjacency(unsigned int sourceVertex, unsigned int destinationVertex)
{
	return adjacencyMatrix[sourceVertex][destinationVertex];
}

int Graph::firstNeighbor(unsigned int vertex, unsigned int start = 0)
{
	for (int i = start; i < numVertices; ++i)
	{
		if (adjacencyMatrix[vertex][i])
		{
			return adjacencyMatrix[vertex][i]; // Found the vertex, return its index.
		}
	}

	return -1; // Did not find any vertex.
}

bool Graph::addEdge(unsigned int sourceVertex, unsigned int destinationVertex)
{
	bool edgeExists = adjacencyMatrix[sourceVertex][destinationVertex];
	adjacencyMatrix[sourceVertex][destinationVertex] = true;
	return !edgeExists;
}

bool Graph::removeEdge(unsigned int sourceVertex, unsigned int destinationVertex)
{
	bool edgeExists = adjacencyMatrix[sourceVertex][destinationVertex];
	adjacencyMatrix[sourceVertex][destinationVertex] = false;
	return edgeExists;
}