/*
	290721
	https://www.hackerrank.com/challenges/tree-preorder-traversal/problem
	Solution
*/
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
    public:
	Node* insert(Node* root, int data) {
		if(root == NULL) {
			return new Node(data);
            } else {
			Node* cur;
			if(data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
                } else {
				cur = insert(root->right, data);
				root->right = cur;
			}
			
			return root;
		}
	}
	
	/* you only have to complete the function given below.  
		Node is defined as  
		
		class Node {
		public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
        }
		};
		
	*/
	
    void preOrder(Node *root) {
		
        Node *node=root;
		/*
			Recursive
		*/
        if (node == NULL)
		return; 
        /* first print data of node */
        cout << node->data << " ";
		
        /* then recur on left sutree */
        preorder(node->left);
		
        /* now recur on right subtree */
        preOrder(node->right);
		
		/*
			//Iterative
			
			if(root == NULL)
            return;
			Node *curr = root;
			while(curr != NULL)
			{
			if(curr->left == NULL)
			{
			cout<<curr->data<<" ";
			curr = curr->right;
			}
			else
			{
			pre = curr->left;
			while(pre->right !=NULL && pre->right != curr)
			pre = pre->right;
			if(pre->right == NULL)
			{
			pre->right = curr;
			cout<<curr->data<<" ";
			curr = curr->left;
			}
			else
			{
			pre->right=NULL;
			curr=curr->right;
			}
			}
			}
		*/
	}
	
}; //End of Solution

int main() {
	
    Solution myTree;
    Node* root = NULL;
    
int t;
int data;

std::cin >> t;

while(t-- > 0) {
std::cin >> data;
root = myTree.insert(root, data);
}

myTree.preOrder(root);
return 0;
}
