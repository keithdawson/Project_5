//Binary Search Tree Program by Blake Mizzell

#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	node* left;
	node* right;
	int data;
};

class BST
{
private:
	node* sortedArrayToBST(int a[], int, int);
	node* root = new node;
	node* newNode(int);
	bool isEmpty() const { return root==NULL; }
	void inorderTrav(node*);
	void preorderTrav(node*);
	void postorderTrav(node*);
public:
	BST()
	{
		root = NULL;
	}
	BST(int a[], int);
	void inorder();
	void inorder(node*);
	void preorder();
	void preorder(node*);
	void postorder();
	void postorder(node*);
	void insert(int);
	bool remove (int);
	bool remove(int, char);
	node * search(int);
};

node * BST::newNode(int data) {
	node * tNode = new node;
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	return tNode;
}

node * BST::sortedArrayToBST(int a[], int start, int end){
	if (start > end)
		return NULL;
	int mid = (start + end + 1) / 2;
	node * localRoot = newNode(a[mid]);
	localRoot->left = sortedArrayToBST(a, start, mid-1);
	localRoot->right = sortedArrayToBST(a, mid+1, end);
	return localRoot;
}

BST::BST(int a[], int len) {
	int start = 0;
	root = sortedArrayToBST(a, start, len-1);
}

void BST::insert(int d)
{
	node* t = new node;
	node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	// is this a new tree?
	if(isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		node* curr;
		curr = root;
		// Find the Node's parent
		while(curr)
		{
			parent = curr;
			if(t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if(t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}

bool BST::remove(int d)
{
	char c = 'p';
	//Locate the element
	bool found = false;
	if(isEmpty())
	{
		cout<<" This Tree is empty! "<<endl;
		return NULL;
	}

	node* curr;
	node* parent;
	curr = root;

	while(curr != NULL)
	{
		if(curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if(d>curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if(!found)
	{
		return false;
	}


	// 3 cases :
	// 1. We're removing a leaf node
	// 2. We're removing a node with a single child
	// 3. we're removing a node with 2 children

	// Node with single child
	if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
	                                                  && curr->right == NULL))
	{
		if(curr->left == NULL && curr->right != NULL)
		{
			if(parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else // left child present, no right child
		{
			if(parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return true;
	}

	//We're looking at a leaf node
	if( curr->left == NULL && curr->right == NULL)
	{
		if(parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;
		return true;
	}


	//Node with 2 children and c == p
	// replace node with smallest value in left subtree

	if (curr->left != NULL && curr->right != NULL)
	{
		node* chkl;
		chkl = curr->left;
		if((chkl->right == NULL) && (chkl->left == NULL))
		{
			curr = chkl;
			delete chkl;
			curr->left = NULL;
		}
		else // left child has children
		{
			//if the node's left child has a right child
			// Move all the way down right to locate smallest element

			if((curr->left)->right != NULL)
			{
				node* rcurr;
				node* rcurrp;
				rcurrp = curr->left;
				rcurr = (curr->left)->right;
				while(rcurr->right != NULL)
				{
					rcurrp = rcurr;
					rcurr = rcurr->right;
				}
				curr->data = rcurr->data;
				if (rcurr->left != NULL) rcurrp->right = rcurr->left;
				else rcurrp->right = NULL;
				delete rcurr;
			}
			else
			{
				node* tmp;
				tmp = curr->left;
				curr->data = tmp->data;
				curr->left = tmp->left;
				delete tmp;
			}

		}
		return true;
	}

}

bool BST::remove(int d, char c)
{
	//Locate the element
	bool found = false;
	if(isEmpty())
	{
		cout<<" This Tree is empty! "<<endl;
		return NULL;
	}

	node* curr;
	node* parent;
	curr = root;

	while(curr != NULL)
	{
		if(curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if(d>curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if(!found)
	{
		return false;
	}


	// 3 cases :
	// 1. We're removing a leaf node
	// 2. We're removing a node with a single child
	// 3. we're removing a node with 2 children

	// Node with single child
	if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
	                                                  && curr->right == NULL))
	{
		if(curr->left == NULL && curr->right != NULL)
		{
			if(parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else // left child present, no right child
		{
			if(parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return true;
	}

	//We're looking at a leaf node
	if( curr->left == NULL && curr->right == NULL)
	{
		if(parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;
		return true;
	}


	//Node with 2 children and c == s
	// replace node with smallest value in right subtree
	if (curr->left != NULL && curr->right != NULL && c == 's')
	{
		node* chkr;
		chkr = curr->right;
		if((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element

			if((curr->right)->left != NULL)
			{
				node* lcurr;
				node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while(lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				if (lcurr->right != NULL) lcurrp->left = lcurr->right;
				else lcurrp->left = NULL;
				delete lcurr;
			}
			else
			{
				node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}

		}
		return true;
	}
	if (curr->left != NULL && curr->right != NULL && c == 'p')
	{
		node* chkl;
		chkl = curr->left;
		if((chkl->right == NULL) && (chkl->left == NULL))
		{
			curr = chkl;
			delete chkl;
			curr->left = NULL;
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element

			if((curr->left)->right != NULL)
			{
				node* rcurr;
				node* rcurrp;
				rcurrp = curr->left;
				rcurr = (curr->left)->right;
				while(rcurr->right != NULL)
				{
					rcurrp = rcurr;
					rcurr = rcurr->right;
				}
				curr->data = rcurr->data;
				if (rcurr->left != NULL) rcurrp->right = rcurr->left;
				else rcurrp->right = NULL;
				delete rcurr;
			}
			else
			{
				node* tmp;
				tmp = curr->left;
				curr->data = tmp->data;
				curr->left = tmp->left;
				delete tmp;
			}

		}
		return true;
	}

}

node* BST::search(int val){
	//Locate the element
	if(isEmpty())
	{
		cout<<" This Tree is empty! "<<endl;
		return NULL;
	}

	node* curr;
	curr = root;

	while(curr != NULL)
	{
		if(curr->data == val)
		{
			return curr;
		}
		else
		{

			if(val>curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
}

void BST::inorderTrav(node* p)
{
	if(p != NULL)
	{
		if(p->left) inorderTrav(p->left);
		cout<<p->data<<" ";
		if(p->right) inorderTrav(p->right);
	}
	else return;
}

void BST::inorder()
{
	node * p = root;
	if(p != NULL)
	{
		if(p->left) inorderTrav(p->left);
		cout<<p->data<<" ";
		if(p->right) inorderTrav(p->right);
	}
	cout<<endl;
	return;
}

void BST::inorder(node* p)
{
	if(p != NULL)
	{
		if(p->left) inorderTrav(p->left);
		cout<<p->data<<" ";
		if(p->right) inorderTrav(p->right);
	}
	cout<<endl;
	return;
}

void BST::preorder()
{
	node * p = root;
	if(p != NULL)
	{
		cout<<p->data<<" ";
		if(p->left) preorderTrav(p->left);
		if(p->right) preorderTrav(p->right);
	}
	cout<<endl;
	return;
}

void BST::preorderTrav(node* p)
{
	if(p != NULL)
	{
		cout<<p->data<<" ";
		if(p->left) preorderTrav(p->left);
		if(p->right) preorderTrav(p->right);
	}
	else return;
}

void BST::preorder(node* p)
{
	if(p != NULL)
	{
		cout<<p->data<<" ";
		if(p->left) preorderTrav(p->left);
		if(p->right) preorderTrav(p->right);
	}
	cout<<endl;
	return;
}

void BST::postorder()
{
	node * p = root;
	if(p != NULL)
	{
		if(p->left) postorderTrav(p->left);
		if(p->right) postorderTrav(p->right);
		cout<<p->data<<" ";
	}
	cout<<endl;
	return;
}

void BST::postorderTrav(node* p)
{
	if(p != NULL)
	{
		if(p->left) postorderTrav(p->left);
		if(p->right) postorderTrav(p->right);
		cout<<p->data<<" ";
	}
	else return;
}

void BST::postorder(node* p)
{
	if(p != NULL)
	{
		if(p->left) postorderTrav(p->left);
		if(p->right) postorderTrav(p->right);
		cout<<p->data<<" ";
	}
	cout<<endl;
	return;
}