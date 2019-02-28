#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    struct Node *left,*right;
};

struct Node *new_node(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->key=data;
    temp->right = temp->left = NULL;
    return temp;

}

 void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

struct Node* insert(struct Node* node, int key) 
{ 
	if (node == NULL) return new_node(key); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	return node; 
}


bool comparasion(struct Node *_root1,struct Node *_root2)
{
    if(_root1 == NULL && _root2 == NULL)
        return true;

    else if(_root1!=NULL && _root2!=NULL)
    {

        return(
        comparasion(_root1->left,_root2->left) && 
        comparasion(_root1->right,_root2->right));
    }
    return false;
}

int main()
{
    struct Node *root1 = NULL;
    root1 = insert(root1,23);
    insert(root1,65);
    insert(root1,45);
    insert(root1,78);
    insert(root1,89);
    insert(root1,85);
    insert(root1,69);

    struct Node *root2 = NULL;
    root2 = insert(root2,23);
    insert(root2,56);
    insert(root2,45);
    insert(root2,78);
    insert(root2,89);
    insert(root2,85);
    insert(root2,69);
    insert(root2,80);

    int l = comparasion(root1,root2);
    if( l == 1)
    cout<<"\n True "<<endl;
    else 
    cout<<"\n False "<<endl;

    return 0;
}