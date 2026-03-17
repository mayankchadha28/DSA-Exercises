

/* 
Travel the tree
example - count the nodes of a tree, or sum of nodes

Traversal Algorithms - 3 recursion based (preorder, inorder, post order traversal), 1 iterative(level order) 

Trick to remember (pre) - root first
(in) - root in between
(post) - root at the end

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/* 
Create a basic Node structure
*/
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data= val;
            left = right = NULL;
        }
};

/* 
Preorder Sequence - [1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1]

So this is an example every node goes from root - left, right until -1 is reached

example 2, -1, 3 - here 2 is root then left is NULL and right is 3

then we go to node (3) left and right

pre order -  root, left, right travel in order
 1
/ \
2  3
    /  \
    4   5
   
   sequence -  1, 2, 3, 4, 5


    current node is the highest priority and we need to print it. we use recursion here



Time Complexity O(n)

*/
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

/* 
Inorder Sequence

So this is an example every node goes from left - root - right until -1 is reached

 1
/ \
2  3
    /  \
    4   5
   sequence - 2, 1, 4, 3, 5


Time Complexity O(n)

*/
void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}


/* 
postorder Sequence

So this is an example every node goes from left - right - root until -1 is reached

 1
/ \
2  3
    /  \
    4   5
   sequence - 2, 4, 5, 3, 1



Time Complexity O(n)

*/
void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}



/* 
Level Order traversal

traverse in each levels of treee

Sequence - 1, 2, 3, 4, 5

idea is use a queue to do that

1. q.push(root) push the node
2. loop through each node until the queue returns null
check the front element
if left is not null then push the value to queue
if right is not null then push the value to queue

Time Complexity - O(n)

To print each level in a new line we can use the NULL node. 
useful for problems like where you want to calculate sum of each level.

*/
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL); //push to add in new lines

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        // for adding in new line

         if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
         }

        cout << curr->data << " ";

       

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }

    }

    cout << endl;

}



// build tree
static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); //LEFT
    root->right = buildTree(preorder); //RIGHT

    return root;
}



int main(){

    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    // preOrder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // postOrder(root);
    // cout << endl;

    levelOrder(root);

    

    return 0;
}

