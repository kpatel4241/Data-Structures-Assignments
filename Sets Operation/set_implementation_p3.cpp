#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node()
    {
        this->data = data;
        next = NULL;
    }
};


void insert(struct Node **head,int new_data)
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

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


bool is_present (struct Node *head, int data)
{
    struct Node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}


struct Node *setunion(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    while (t1 != NULL)
    {
        insert(&result, t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        if (!is_present(result, t2->data))
            insert(&result, t2->data);
        t2 = t2->next;
    }

    return result;
}


struct Node *setintersection(struct Node *head1,struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1;

    while (t1 != NULL)
    {
        if (is_present(head2, t1->data))
            insert(&result, t1->data);
        t1 = t1->next;
    }

    return result;
}


bool subset(Node* first, Node* second)
{
    Node* ptr1 = first, *ptr2 = second;

    if (first == NULL && second == NULL)
        return true;

    if ( first == NULL || (first != NULL && second == NULL))
        return false;

    while (second != NULL)
    {
        ptr2 = second;

        while (ptr1 != NULL)
        {
            if (ptr2 == NULL)
                return false;

            else if (ptr1->data == ptr2->data)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else break;
        }
        if (ptr1 == NULL)
            return true;

        ptr1 = first;
        second = second->next;
    }
    return false;
}


int main()
{
    struct Node *head1=NULL, *head2 =NULL;
    struct Node *_union = NULL , *_intersection = NULL;

     insert(&head1,25);
     insert(&head1,58);
     insert(&head1,89);
     insert(&head1,69);
     insert(&head1,96);

     cout<<"\n Set-1 : ";
     display(head1);

     insert(&head2,12);
     insert(&head2,45);
     insert(&head2,56);
     insert(&head2,23);
     insert(&head2,78);
     insert(&head2,58);
     insert(&head2,69);

     cout<<"\n Set-2 : ";
     display(head2);

     _union = setunion(head1,head2);
     _intersection = setintersection(head1,head2);

     cout<<"\n Union = ";
     display(_union);

     cout<<"\n Intersection  = ";
     display(_intersection);

     subset(head1,head2) ? cout<<"\n SUBET \n" : cout<<"\n Not a SUBSET\n";

     return 0;
}
