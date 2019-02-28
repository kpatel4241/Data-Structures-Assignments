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


bool check_BST(Node* root, Node* l=NULL, Node* r=NULL)
{
    if (root == NULL)
        return true;
    if (l != NULL and root->key < l->key)
        return false;
    if (r != NULL and root->key > r->key)
        return false;

    return (check_BST(root->left, l, root) and check_BST(root->right, root, r));
}



int main()
{
    struct Node *root1 = NULL;
    root1 = insert(root1,23);
    insert(root1,56);
    insert(root1,45);
    insert(root1,78);
    insert(root1,89);
    insert(root1,85);
    insert(root1,69);

    int _check_BST = check_BST(root1,NULL,NULL);

    if( _check_BST == 1)
    cout<<"\n True "<<endl;
    else
    cout<<"\n False "<<endl;

    return 0;
}
