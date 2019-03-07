#include<bits/stdc++.h>
#define V 10

using namespace std;


bool graph_color(int G[][V],int color[],int pos, int c)
{

	if(color[pos] != -1 && color[pos] !=c)
		return false;

	color[pos] = c;
	bool ans = true;
	for(int i=0;i<V;i++)
	{
		if(G[pos][i])
		{
			if(color[i] == -1)
				ans = graph_color(G,color,i,1-c);

			if(color[i] !=-1 && color[i] != 1-c)
				return false;
		}
		if (!ans)
			return false;
	}
	return true;
}


bool check_bipartite(int G[][V])
{
	int color[V];
	for(int i=0;i<V;i++)
		color[i] = -1;

	//start is vertex 0;
	int pos = 0;
	// two colors 1 and 0
	return graph_color(G,color,pos,1);

}



int main()
{
    int G1[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

	cout<<"\n Checking for G1 : ";
	if(check_bipartite(G1))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


	int G2[][V] = {{0,1,1},
	{1,1,1},
	{1,1,0}
	};

	cout<<"\n Checking for G2 : ";
	if(check_bipartite(G2))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

	return 0;
}
