#include <iostream>
#include <vector>

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




*/
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
    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    return 0;
}