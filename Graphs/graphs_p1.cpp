#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int num_vertices;
	list<int> *adj;

public:
	Graph(int num_vertices);
	void addEdge(int v, int w);
	void DFS(int v, vector<bool> &visited);
	int mother_vertex();
};


Graph::Graph(int num_vertices)
{
	this->num_vertices = num_vertices;
	adj = new list<int>[num_vertices];
}


void Graph::DFS(int v, vector<bool> &visited)
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited);
}


void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


int Graph::mother_vertex()
{
	vector <bool> visited(num_vertices, false);
	int v = 0;

	for (int i = 0; i < num_vertices; i++)
	{
		if (visited[i] == false)
		{
			DFS(i, visited);
			v = i;
		}
	}

	fill(visited.begin(), visited.end(), false);
	DFS(v, visited);
	for (int i=0; i<num_vertices; i++)
		if (visited[i] == false)
			return -1;

	return v;
}


int main()
{
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

    int mv = g.mother_vertex();
	cout << "\n Mother Vertex = " <<mv<<endl;

	return 0;
}
