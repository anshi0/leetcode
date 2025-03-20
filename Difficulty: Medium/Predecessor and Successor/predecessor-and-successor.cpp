//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends

/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void Traversal(Node* root, vector<Node*>& inorder) {
    if (root == NULL) return;
    Traversal(root->left, inorder);
    inorder.push_back(root);
    Traversal(root->right, inorder);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    vector<Node*> inorder;
    Traversal(root, inorder);
    int n = inorder.size();
    
    int low = 0, high = n - 1, mid;
    
    // Edge cases when the key is smaller than the smallest node or larger than the largest node
    if (key < inorder[low]->key) {
        pre = NULL;
        suc = inorder[low];
        return;
    }
    if (key > inorder[high]->key) {
        pre = inorder[high];
        suc = NULL;
        return;
    }

    // Binary Search to find the key or its closest position
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (inorder[mid]->key == key) {
            // If key is found, set pre and suc accordingly
            pre = (mid > 0) ? inorder[mid - 1] : NULL;
            suc = (mid < n - 1) ? inorder[mid + 1] : NULL;
            return;
        }
        else if (inorder[mid]->key < key) {
            pre = inorder[mid];  // Update predecessor
            low = mid + 1;
        }
        else {
            suc = inorder[mid];  // Update successor
            high = mid - 1;
        }
    }
}

};


//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends