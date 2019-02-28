#include <bits/stdc++.h>
using namespace std;

int binomial_coefficient(int n,int k)
{
	int r_bc = 1;

	if (k > n - k)
		k = n - k;

	for (int i = 0; i < k; ++i)
	{
		r_bc *= (n - i);
		r_bc /= (i + 1);
	}

	return r_bc;
}


int catalan(int n)
{
    int c = binomial_coefficient(2*n, n);
	return c/(n+1);
}


int count_BST(int n)
{
	int count = catalan(n);
	return count;
}


int main()
{

	int count1,n;

	cout<<"\n Enter the No. of Nodes : ";
	cin>>n;

	count1 = count_BST(n);
	cout<<"Count of structurally different BSTs =  "<<count1<<endl;

	return 0;
}
