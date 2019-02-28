#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    struct Node *next;
}Node;


struct Node *create_node(int key)
{
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node -> key = key;
    new_node -> next = NULL;

    return new_node;
}

struct Node *create_head()
{
    struct Node * temp_head = NULL;
    return temp_head;
}


int hashed(int key, int hash_key)
{
    return key % hash_key;
}


struct Node **create(int n)
{
    struct Node **set= (struct Node **)malloc(n*sizeof(struct Node*));
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = NULL;
        set[i] = temp;
    }
    return set;
}

void add_list(struct Node **set, int key)
{
    if (*set == NULL)
    {
        *set = create_node(key);
        return;
    }

    bool presence_flag = false;
    struct Node *temp_root;


    for (temp_root = *set; temp_root != NULL; temp_root = temp_root -> next)
    {
        if (temp_root -> key == key)
        {
            presence_flag = true;
            break;
        }
    }

    if (!presence_flag)
    {
        struct Node * new_node = create_node(key);
        new_node -> next = *set;
        *set = new_node;
    }
    return;
}


void insert(struct Node **set, int key)
{
    int index = hashed(key, 10);
    add_list(&set[index], key);
}


int is_empty_list(struct Node * S)
{
    if (S == NULL)
        return 1;
    return 0;
}


int is_empty(struct Node **S, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!is_empty_list(S[i]))
        {
            return 0;
        }
    }
    return 1;
}


int is_element_of_list(struct Node *set, int key)
{
    if (is_empty_list(set))
        return 0;

    struct Node * temp_root = set;
    while(temp_root -> key != key)
    {
        if (temp_root -> next == NULL)
            return 0;
        temp_root = temp_root -> next;
    }
    return 1;
}


int is_element_of(struct Node **S, int n, int x)
{
    if (is_empty(S, n))
        return 0;

    for (int i = 0; i < n; i++)
    {
        if (is_element_of_list(S[i],x))
            return 1;
    }
    return 0;
}


int size_list(struct Node *set)
{
    if (set == NULL)
    {
        return 0;
    }
    int count = 0;

    for (struct Node * temp_root = set; temp_root != NULL; temp_root = temp_root -> next)
        count++;
    return count;
}


int size(struct Node ** set, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        count += size_list(set[i]);
    return count;
}


void enumerate_list(struct Node *set)
{
    struct Node *temp_root = set;

    if (temp_root == NULL)
    {
        return;
    }

    for (temp_root = set; temp_root != NULL; temp_root = temp_root -> next)
    {
        cout<<" "<<temp_root->key;
    }
}


void enumerate(struct Node **set, int n)
{
    if (is_empty(set, n))
    {
        cout<<"\n Set is Empty"<<endl;
        return;
    }

   cout<<"\n Elements in the Set : ";
    for (int i = 0; i < n; i++)
        enumerate_list(set[i]);
    return;
}

struct Node ** build(int a[], int count, int n)
{
    struct Node **new_set = create(n);

    for (int i = 0; i < count; i++)
    {
        int index = hashed(a[i], 10);
        add_list( &new_set[index], a[i]);
    }
    return new_set;
}


int main()
{
    struct Node **set = create(10);
    insert(set,18);
    insert(set,25);
    insert(set,7);

    cout<<"Implementing is_element_of(S,x) ... \n";
    int v1 = is_element_of(set, 10, 12);
    if(v1 == 1)
        cout<<"\n Element is Present"<<endl;
    else
        cout<<"\n Element is not present"<<endl;

    cout<<"Implementing is_empty(S)... \n";
    int v2 = is_empty(set,10);
    if(v2 == 1)
        cout<<"\n Set is Empty"<<endl;
    else
        cout<<"\n Set is not-empty"<<endl;

    cout<<"Implementing size(S) ... \n";
    int v3 = size(set,10);
    cout<<"\n Size/Cardinality of the Set = "<<v3<<endl;

    cout<<"Implementing enumerate(S)... \n";
    cout<<"\n Enumerating the Set : "<<endl;
    enumerate(set,10);

    cout<<"Implementing build(x1,x2,x3,x4...,xn) ... \n";
    int a[] = {10,20,30,40,50};
    struct Node **set1 = build(a,5,10);
    enumerate(set1,10);

    return 0;
}
