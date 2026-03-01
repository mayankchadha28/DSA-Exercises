/* 

Leetcode Problem 138: Copy List with Random Pointer
link - https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Example 1: 
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]


*/



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/* 
Explanation: 
The idea is to use a hash map to store the mapping between the original nodes and the copied nodes. 
First we create a new head node and then we iterate through original list and link the new nodes
then we also store hash map of original node and new node. 
Then we iterate through the original list again and link the random pointers of the new nodes using the hash map. 
Finally we return the new head node.

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL){
            return NULL;
        }
        
        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        m[head] = newHead;

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            
            m[oldTemp] = copyNode;
            
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;

        }

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL){
           newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;

        }

        return newHead;
    }
};