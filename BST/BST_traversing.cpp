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


int main()
{
    struct Node *root = NULL;
    root = insert(root,23);
    insert(root,56);
    insert(root,45);
    insert(root,78);
    insert(root,89);
    insert(root,85);
    insert(root,69);

    cout<<"\n Inorder traversal of BST : ";
    inorder(root);
    cout<<"\n";
    return 0;
}