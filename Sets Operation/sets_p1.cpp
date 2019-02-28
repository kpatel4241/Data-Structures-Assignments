#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


void insert_node(struct Node **head,int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}


void display(struct Node *head)
{
    struct Node *temp;
    temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


void is_element_of(struct Node *head,int num)
{
    struct Node *temp;
    temp = head;

    while(temp!=NULL)
    {
        if(temp->data == num)
        {
            cout<<"\n Element is present in the Set.\n";
            break;
        }
        else
        {
            cout<<"\n Element is present in the Set.\n";
            break;
        }

        temp=temp->next;
    }
}


void is_empty(struct Node *head)
{
    if(head == NULL)
    {
        cout<<"\n Set is Empty\n";
    }
    else cout<<"\n Set is not-empty\n";
}


void cardinality(struct Node *head)
{
    struct Node *temp;
    temp = head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"\n Cardinality/Size of the Set = "<<count<<endl;
}


int main()
{
    struct Node *root=NULL;
    int ele,i;
    char ch;

    do
    {
        cout<<"\n Enter the Element you want to insert : ";
        cin>>ele;
        insert_node(&root,ele);
        cout<<"\n Do you want to insert more [Y/N]: ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');

    cout<<"\n Set : \n";
    display(root);

    int x;
    cout<<"\n Enter the Element you want to Search : ";
    cin>>x;
    is_element_of(root,x);

    is_empty(root);

    cardinality(root);

    struct Node *built=NULL;
    int a[] = {10,20,30,40,50};

    cout<<"\n Implementing built(x1,x2,...,xn) \n";

    for(i=0;i<5;i++)
    {
        insert_node(&built,a[i]);
    }
    display(built);

    return 0;
}
