#include<iostream>
#include<list>

using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adj;

public:

    Graph(int vertices);
    void add_edge(int a, int b);
    bool check_path(int src, int dest);
};


Graph :: Graph(int vertices)
{
    this->vertices = vertices;
    adj = new list<int>[vertices];
}


void Graph :: add_edge(int a, int b)
{
    adj[a].push_back(b);
}


bool Graph :: check_path(int src , int dest)
{
    if(src == dest)
        return true;

    int i;
    bool *visited = new bool[vertices];
    for(i=0;i<vertices;i++)
        visited[i] = false;


    list<int> list;

    visited[src] = true;
    list.push_back(src);

    while(!list.empty())
    {
        src = list.front();
        list.pop_front();

        for(auto i=adj[src].begin();i!=adj[src].end();i++)
        {
            if(*i == dest)
                return true;

            if(!visited[*i])
            {
                visited[*i] = true;
                list.push_back(*i);
            }
        }
    }
    
    return false;
}


int main()
{
    Graph g1(4);
    int src,dest;

    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    g1.add_edge(2, 3);
    g1.add_edge(3, 3);

    cout<<"\n Enter the Source and Destination Vertex : ";
    cin>>src>>dest;

    if(g1.check_path(src,dest) == true)
        cout<<"\n There is a path from "<<src<<" to "<<dest<<endl;
    else
        cout<<"\n There is no path from "<<src<<" to "<<dest<<endl;

    int temp = src;
    src = dest;
    dest = temp;

    if(g1.check_path(src,dest) == true)
        cout<<"\n There is a path from "<<src<<" to "<<dest<<endl;
    else
        cout<<"\n There is no path from "<<src<<" to "<<dest<<endl;

        return 0;
}
