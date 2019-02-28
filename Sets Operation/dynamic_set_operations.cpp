#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node()
    {
        this->data=data;
        next = NULL;
    }
};


void create(struct Node **head,int new_data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
}


void display(struct Node *head)
{
    struct Node *temp;
    temp = head;

    cout<<"\n Linked List : \n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


void remove(struct Node **head, int position)
{
   if (*head == NULL)
      return;

   struct Node* temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    if (temp == NULL || temp->next == NULL)
         return;

    struct Node *next = temp->next->next;

    free(temp->next);

    temp->next = next;
}


void capacity(struct Node *head)
{
    struct Node *temp = head;
    int count=0;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"\n Toal Elements in the List = "<<count<<endl;
}


int main()
{
    struct Node *root=NULL;
    int n,i,ele,pos;
    char ch;

    cout<<"\n Enter the Size : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\n Enter the Element in a set : ";
        cin>>ele;
        create(&root,ele);
    }

    display(root);

    do
    {
        cout<<"\n Enter the position from where you want to delete the node : ";
        cin>>pos;
        remove(&root,pos);

        cout<<"\n Set after deletion : \n";
        display(root);
        capacity(root);
        cout<<"\n Do you want to delete more nodes [Y/N]: ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');

    capacity(root);

    return 0;
}
