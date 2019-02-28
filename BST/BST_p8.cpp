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


void tree_display(Node *head, int level)
{
    int i;
    struct Node *root;
    if (head != NULL)
    {
        tree_display(head->right, level+1);
        cout<<endl;
        if (head == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<head->key;
        tree_display(head->left, level+1);
    }
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

    tree_display(root1,1);
    cout<<"\n";

    return 0;
}
