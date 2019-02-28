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


void add(struct Node **set, int key)
{
    int index = hashed(key, 10);
    add_list(&set[index], key);
}


void remove_list(struct Node ** set, int key)
{
    struct Node * temp_root = *set;
    struct Node * backward_pointer;

    if (temp_root != NULL && temp_root -> key == key)
    {
        *set = temp_root -> next;
        free(temp_root);
        return;
    }

    while (temp_root != NULL && temp_root -> key != key)
    {
        backward_pointer = temp_root;
        temp_root = temp_root -> next;
    }

    if (temp_root == NULL)
    {
        cout<<"\n Key is not found in the given Set.";
        return;
    }

    backward_pointer -> next = temp_root -> next;
    free(temp_root);
    return;
}

// remove function: removes the element key from given set, if it is present.
void remove(struct Node ** set, int key)
{
    int index = hashed(key, 10);
    remove_list(&set[index], key);
}


void enumerate_list(struct Node *set)
{
    struct Node * temp_root = set;

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


int main()
{
    struct Node **set = create(10);

    // Implemennting add(S,x)
    add(set,2);
    add(set,4);
    add(set,8);
    add(set,16);
    add(set,64);

    // Enumerating the list.
    enumerate(set,10);

    // implementing remove(S,x)
    remove(set,8);
    remove(set,16);

    enumerate(set,10);

    return 0;
}
