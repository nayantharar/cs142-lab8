#include 
	using namespace std;
	
	class Node
	{
		public:
		int data;
		// Children
		Node *left;
		Node *right;
		Node *parent;
	
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
	};
	
	class BiST
	{
		public:
		Node *root;
		int Height;
		BiST()
		{
			root = NULL;
			Height=0;
		}
	
		void insert(int value)
		{ insertHelper(root, value,1);}
	
		void insertHelper(Node *curr, int value, int branch_length)
		{
			if (root == NULL)
			{
				root = new Node(value);
				Height=1;
			}
			// Else compare the curr data with value
			else if (value < curr->data)
			{
				// else move left and call insertH
				if (curr->left == NULL)
				{
					curr->left = new Node(value);
					curr->left->parent=curr;
					if(branch_length==Height){Height++;}
				}
				else
				{
					branch_length++;
					insertHelper(curr->left, value,branch_length);
				}
			}
			else
			{
				// Else move right and call insertH
				if (curr->right == NULL)
				{
					curr->right = new Node(value);
					curr->right->parent=curr;
					if(branch_length==Height){Height++;}
				}
				else
				{
					branch_length++;
					insertHelper(curr->right, value,branch_length);
				}
			}
	  	}
	
		Node* find_max(Node * curr)
		{
			if(root==NULL)
			{
				return NULL;
			}
			if(curr->right!=NULL)
			{
				return find_max(curr->right);
			}
			else
			{
				return curr;
			}
		}
	
		Node* find_min(Node * curr)
		{
			if(root==NULL)
			{
				return NULL;
			}
			if(curr->left!=NULL)
			{
				return find_min(curr->left);
			}
			else
			{
				return curr;
			}
		}
	
		int rangeSearch(int k1, int k2)
		{
			return rsHelper(root,k1,k2,0);
		}
	
		int rsHelper(Node * curr,int k1, int k2,int c)
		{
			int a=0,b=0;
			if(curr->left!=NULL)
			{
				a=rsHelper(curr->left,k1,k2,0);
			}
			if(curr->data<=k2 && curr->data>=k1)
			{
				cout<<curr->data<<",";
				c++;
			}
			if(curr->right!=NULL)
			{
				b=rsHelper(curr->right,k1,k2,0);
			}
			if(curr->data==find_max(root)->data)
			{
				cout<<endl;
			}
			return a+b+c;
		}
	
		int count(Node* curr)
		{
			return counthelper(curr,0);
		}
	
		int counthelper(Node* curr, int c)
		{
			int a=0,b=0;
			c++;
			if(curr->left!=NULL)
			{
				a=counthelper(curr->left,0);
			}
			if(curr->right!=NULL)
			{
				b=counthelper(curr->right,0);
			}
				return c+a+b;
		}
	
		int height(Node * curr)
		{
			return Height;
		}
	
	  	void display()
		{displayHelper(root);}
	
	  	void displayHelper(Node *curr)
		{
			// Base condition
			if (curr == NULL)
				return;
			// Display left.
			displayHelper(curr->left);
			// Display current
			cout << curr->data << ",";
			// Display right
			displayHelper(curr->right);
		}
	
		void displayFancy()
		{
			displayFancyHelper(root,0);
		}
	
		void displayFancyHelper(Node * cur,int s)
		{
			//when at the end of a trail return
			if(cur==NULL)
			{return;}
			//go left and increase the number of spaces
			displayFancyHelper(cur->left,s+1);
			//print the spaces
			for(int i=0;i<4*s;i++){cout<<" ";}
			//print the data
			cout<<cur->data<<endl;
			//go right and increase the number of spaces
			displayFancyHelper(cur->right,s+1);
		}
	
		Node* search(Node * cur,int value)
		{
			if(cur==NULL)
			{return NULL;}
			if(cur->data==value)
			{return cur;}
			if(cur->data<value)
			{return search(cur->right,value);}
			else
			{return search(cur->left,value);}
		}
	};
	
	int main()
	{
		BiST bst;
		bst.insert(4);
		bst.insert(8);
		bst.insert(2);
		bst.insert(3);
		bst.insert(15);
		bst.insert(98);
		bst.insert(45);
		bst.insert(4);
		bst.insert(6);
		bst.displayFancy();
		if ( bst.search ( bst.root , 2) == NULL)
		{
			cout << "Not Found"<<endl;
		}
		else
		{
			cout<<"Found"<<endl;
		}
		cout<<bst.count(bst.root)<<endl;
		cout<<"height="<<bst.height(bst.root)<<endl;
		cout<<bst.rangeSearch(1,49)<<endl;
	}


