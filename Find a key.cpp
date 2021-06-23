#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

struct Node* getNode(int data)
{
	struct Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

bool findakey(Node* root, int key){
    if(root == NULL) return false;

    if(root->data == key) return true;

    return(findakey(root->left, key) || findakey(root->right, key));
}


int main()
{
	// binary tree formation
	struct Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
		
	int data = 5;
	if(findakey(root, data)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
	return 0;
}
