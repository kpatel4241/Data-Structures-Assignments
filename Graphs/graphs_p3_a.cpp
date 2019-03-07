#include<bits/stdc++.h>

using namespace std;

class Graph
{
	int num_vertices;
	list<int> *adj_list;

	bool check_cycle(int v, bool visited[], int parent);

public:
	Graph(int num_vertices);
	void add_edge_undirected(int v, int w);
	bool is_cyclic();
};

Graph::Graph(int num_vertices)
{
	this->num_vertices = num_vertices;
	adj_list = new list<int>[num_vertices];
}

void Graph::add_edge_undirected(int v, int w)
{
	adj_list[v].push_back(w);
	adj_list[w].push_back(v);
}


bool Graph::check_cycle(int v, bool visited[], int parent)
{
	visited[v] = true;

	for (auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i)
	{
		if (!visited[*i])
		{
		if (check_cycle(*i, visited, v))
			return true;
		}
		else if (*i != parent)
		return true;
	}
	return false;
}


bool Graph::is_cyclic()
{
	bool *visited = new bool[num_vertices];
	for (int i = 0; i < num_vertices; i++)
		visited[i] = false;

	for (int u = 0; u < num_vertices; u++)
		if (!visited[u])
		if (check_cycle(u, visited, -1))
			return true;

	return false;
}


int main()
{
	Graph g1(6);
	g1.add_edge_undirected(0, 1);
	g1.add_edge_undirected(0, 2);
	g1.add_edge_undirected(0, 4);
	g1.add_edge_undirected(3, 1);
	g1.add_edge_undirected(2, 3);
	g1.add_edge_undirected(2, 5);

	g1.is_cyclic()? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

	Graph g2(6);
	g2.add_edge_undirected(0, 1);
	g2.add_edge_undirected(0, 2);
	g2.add_edge_undirected(0, 4);
	g2.add_edge_undirected(2, 3);
	g2.add_edge_undirected(2, 5);
	g2.is_cyclic()? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

	return 0;
}
