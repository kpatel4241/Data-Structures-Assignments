//
// Created by KP on 17-03-2019.
//

#include<bits/stdc++.h>

using namespace std;

void next_fit(int block_size[] , int m , int requested_size[] , int n)
{
    int _alloc_mem[n];
    memset(_alloc_mem , -1 , sizeof(_alloc_mem));

    for(auto i=0;i<n;i++)
    {
        for(auto j=0;j<m;j=(j+1)%m)
        {
            if(block_size[j] >= requested_size[i]) {
                _alloc_mem[i] = j;

                block_size[j] -= requested_size[i];
                break;
            }
        }
    }

    cout<<"\n Block No. \tRequested Size \tBlock No.\n";
    for(auto i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<requested_size[i]<<"\t\t";
        if(_alloc_mem[i] != -1)
            cout<<_alloc_mem[i]+1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }
}


/* int main()
{
    int i,n,m;
    cout<<"\n Enter the no. of block_sizes : ";
    cin>>m;

    int block_size[m];
    cout<<"\n Enter the Block Sizes : ";
    for(i=0;i<m;i++)
        cin>>block_size[i];

    cout<<"\n Block Size : ";
    for(auto i=0;i<m;i++)
        cout<<block_size[i]<<" ";
    cout<<endl;

    cout<<"\n Enter the no. of requested_size : ";
    cin>>n;

    int request_size[n];
    cout<<"\n Enter the Array of Block Size : ";
    for(i=0;i<n;i++)
        cin>>request_size[i];

    best_fit(block_size,m,request_size,n);

    return 0;
}
*/

int main()
{
    int block_size[] = {100, 500, 200, 300, 600};
    int requested_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(requested_size)/ sizeof(requested_size[0]);

    cout<<"\n Block Size : ";
    for(auto i=0;i<m;i++)
        cout<<block_size[i]<<" ";
    cout<<endl;

    next_fit(block_size , m , requested_size , n);

    return 0;
}
