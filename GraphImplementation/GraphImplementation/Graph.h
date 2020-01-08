#pragma once
class Graph
{
private:
	bool** adjacencyMatrix; // The adjacency matrix representation of our graph.
	unsigned int numVertices; // The number of vertices.

public:
	Graph(unsigned int numVertices); // Constructor to create the adjacency matrix.

	~Graph(); // Destructor (clean up the adjacency matrix).
	bool adjacency(unsigned int sourceVertex, unsigned int destinationVertex); // Determines if two vertices are adjacent.
	int firstNeighbor(unsigned int vertex, unsigned int start); // Returns the first (lowest-index) neighbor of the given vertex from start on, else returns -1.
	bool addEdge(unsigned int sourceVertex, unsigned int destinationVertex); // Adds an edge from the source to the destination. Returns true if new edge, false otherwise.
	bool removeEdge(unsigned int sourceVertex, unsigned int destinationVertex); // Removes an edge if present. Returns true if deleted, false otherwise.
};