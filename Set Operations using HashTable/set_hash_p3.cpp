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


void add(struct Node **set, int key)
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

void enumerate_list(struct Node * set)
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



struct Node ** _union(struct Node ** S,struct Node ** T, int n)
{
    if (is_empty(S, n) && is_empty(T, n))
    {
        cout<<"\n Both the sets given for union operation are empty.";
        return NULL;
    }
    else if (is_empty(S, n))             // If one of the set is empty return other set.
        return T;
    else if (is_empty(T, n))
        return S;                       // If none of the sets is empty then
    else
    {
            // Initiate set for union operation
            struct Node ** or_set = create(n);

            for (int i = 0; i < n; i++)
            {
                for ( struct Node* temp = S[i]; temp != NULL; temp = temp -> next)
                {
                    add(or_set, temp -> key);
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (struct Node* temp = T[i]; temp != NULL; temp = temp -> next)
                {
                    if(!is_element_of(or_set, 10,temp -> key))
                        add(or_set, temp -> key);
                }
            }

            // Return union of two sets.
            return or_set;
    }
}

// intersection(S, T) Function: returns the intersection of sets S and T
struct Node ** intersection(struct Node ** S, struct Node ** T, int n)
{
    if (is_empty(S, n) && is_empty(T, n))
    {
       cout<<"\n Both the sets given for Intersection operation are empty.";
        return NULL;
    }
    else if (is_empty(S, n))
        return NULL;
    else if (is_empty(T, n))
        return NULL;
    else
    {
        struct Node ** and_set = create(n);

        for (int i = 0; i < n; i++)
        {
            for (struct Node * temp = S[i]; temp != NULL; temp = temp -> next)
            {
                if(is_element_of( T, 10,temp -> key))
                    add(and_set, temp -> key);
            }
        }
        return and_set;
    }
}

// difference(S, T) function: return the difference of sets S and T
struct Node ** difference(struct Node ** S, struct Node ** T, int n)
{
    if (is_empty(S, n))
    {
        printf("%s", "\nFirst set given for difference operation is empty.");
        return NULL;
    }
    else if (is_empty(T, n))
        return S;
    else
    {
            // Initiate set for Difference pointer.
        struct Node ** diff_set = create(n);
        for (int i = 0; i < n; i++)
        {
            for (struct Node * temp = S[i]; temp != NULL; temp = temp -> next)
            {
                // If present in S but not in T, insert the element.
                if (!is_element_of( T, n,temp -> key))
                    add(diff_set, temp -> key);
            }
        }

        // Return difference of two sets.
        return diff_set;
    }
}

// subset(S, T) function: a predicate that tests whether the set S is a subset of set T
int subset(struct Node ** S, struct Node ** T, int n)
{
    // Traverse through subset to be checked
    for (int i = 0; i < n; i++)
    {
        for (struct Node * temp = S[i]; temp != NULL; temp = temp -> next)
        {
            // If element not present in set T return false/0.
            if (!is_element_of( T, 10 ,temp -> key))
                return 0;
        }
    }
    // If all elements of S are in T, then return True/1.
    return 1;
}


int main()
{
    struct Node **set=create(10);
    int A[] = {16,25,36,49,64,81,100};
    int B[] = {11,99,22,88,33,77,44,66,55};

    struct Node **set_A = build(A,7,10);
    struct Node **set_B = build(B,9,10);

    cout<<"\n Set-A : \n";
    enumerate(set_A,10);
    cout<<"\n Set-B : \n";
    enumerate(set_B,10);

    cout<<"\n Implementing union() ... \n";
    enumerate(_union(set_A,set_B,10),10);

    cout<<"\n Implementing intersection() ... \n";
    enumerate(intersection(set_A,set_B,10),10);

    cout<<"\n Implementing difference() ... \n";
    enumerate(difference(set_A,set_B,10),10);

    cout<<"\n Checking for A subset B ... \n";
    int ss = subset(set_A,set_B,10);
    if(ss == 1)
        cout<<"\n True \n";
    else
        cout<<"\n False \n";

    return 0;
}
