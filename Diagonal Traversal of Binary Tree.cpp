//Method 1:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

vector <vector <int>> result;
void diagonalPrint(Node* root)
{
	if(root == NULL)
		return;

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int size = q.size();
		vector <int> answer;

		while(size--)
		{
			Node* temp = q.front();
			q.pop();

			// traversing each component;
			while(temp)
			{
				answer.push_back(temp->data);

				if(temp->left)
					q.push(temp->left);

				temp = temp->right;
			}
		}
		result.push_back(answer);
	}
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	
	diagonalPrint(root);

	for(int i=0 ; i<result.size() ; i++)
	{
		for(int j=0 ; j<result[i].size() ; j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}

//Method 2:

// C++ program for diagnoal traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node
{
	int data;
	Node *left, *right;
};

void diagonalPrint(Node *root){
    queue<Node*> q;
//  vector<int> ans;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
       Node *p = q.front();
       q.pop();
       if(p == NULL){
           cout<<endl;
           q.push(NULL);
           p = q.front();
           q.pop();
           if(p == NULL) break;
       }
       while(p != NULL){
           cout<<p->data<<" ";
        //    ans.push_back(p->data);
           if(p->left){
               q.push(p->left);
           }
           p = p->right;
       }
   }
//    for(int i = 0; i<ans.size(); i++){
//        cout<<ans[i]<<" ";
//    }
}

/* root - root of the binary tree
d - distance of current line from rightmost-topmost slope.
diagonalPrint - multimap to store Diagonal elements (Passed by Reference) */

// void diagonalPrintUtil(Node* root, int d, map<int, vector<int>> &diagonalPrint)
// {
// 	// Base case
// 	if (!root)
// 		return;

// 	// Store all nodes of same line together as a vector
// 	diagonalPrint[d].push_back(root->data);

// 	// Increase the vertical distance if left child
// 	diagonalPrintUtil(root->left, d + 1, diagonalPrint);

// 	// Vertical distance remains same for right child
// 	diagonalPrintUtil(root->right, d, diagonalPrint);
// }

// // Print diagonal traversal of given binary tree
// void diagonalPrint(Node* root)
// {
	
// 	// create a map of vectors
// 	// to store Diagonal elements
// 	map<int, vector<int> > diagonalPrint;
// 	diagonalPrintUtil(root, 0, diagonalPrint);

// 	cout << "Diagonal Traversal of binary tree : \n";
// 	for (auto it :diagonalPrint)
// 	{
// 		vector<int> v=it.second;
// 		for(auto it:v)
// 		cout<<it<<" ";
// 		cout<<endl;
// 	}
// }

// Utility method to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Driver program
int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	/* Node* root = newNode(1);
		root->left = newNode(2);
		root->right = newNode(3);
		root->left->left = newNode(9);
		root->left->right = newNode(6);
		root->right->left = newNode(4);
		root->right->right = newNode(5);
		root->right->left->right = newNode(7);
		root->right->left->left = newNode(12);
		root->left->right->left = newNode(11);
		root->left->left->right = newNode(10);*/

	diagonalPrint(root);

	return 0;
}
