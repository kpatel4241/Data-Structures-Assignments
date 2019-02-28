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


bool path_sum(struct Node* node, int sum)
{
  if (node == NULL)
  {
     return (sum == 0);
  }
  else
  {
    bool ans = 0;

    int sub_sum = sum - node->key;

    // When we reach to a leaf node and sum becomes 0 then it returns true
    if ( sub_sum == 0 && node->left == NULL && node->right == NULL )
      return 1;

    if(node->left)
      ans = ans || path_sum(node->left, sub_sum);
    if(node->right)
      ans = ans || path_sum(node->right, sub_sum);

    return ans;
  }
}




int main()
{
    struct Node *root1 = NULL;
    int s;

    root1 = insert(root1,81);
    insert(root1,56);
    insert(root1,62);
    insert(root1,90);
    insert(root1,27);
    insert(root1,72);
    insert(root1,40);

    cout<<"\n Enter the Sum Value : ";
    cin>>s;

    if(path_sum(root1,s)==1)
        cout<<"\n True"<<endl;
    else
        cout<<"\n False"<<endl;

    return 0;
}
