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


void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++)
  {
    cout<<ints[i]<<" ";
  }
  cout<<"\n";
}


void print_path(struct Node* node, int path[], int pathLen)
{
  if (node==NULL) 
    return;

  path[pathLen] = node->key;
  pathLen++;

  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    print_path(node->left, path, pathLen);
    print_path(node->right, path, pathLen);
  }
}


void print_paths(struct Node* node)
{
  int path[100];
  print_path(node, path, 0);
}


int main()
{
    struct Node *root1 = NULL;
    root1 = insert(root1,81);
    insert(root1,56);
    insert(root1,62);
    insert(root1,90);
    insert(root1,27);
    insert(root1,72);
    insert(root1,40);

    print_paths(root1);
    cout<<"\n";

    return 0;
}
