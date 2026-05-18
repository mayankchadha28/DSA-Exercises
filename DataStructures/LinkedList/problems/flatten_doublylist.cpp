/* 
Leetcode: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/


You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.


*/



#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


/* 
As we observe each iteration needs a same iteration. this could be a good candidate for recursion

step 1 - flatten child nodes recursively (return the next); make sure you're storing the next or you will loose

step 2 - now we need to connect the last flattened list to next node

step 3 - once we reach tail node we need to attach the next

return the head - this is called recursively in step 1

*/


class Solution {
public:
    Node* flatten(Node* head) {

        if(head == NULL){
            return head;
        }
        
       Node *currNode = head;

       while(currNode != NULL){

            if(currNode->child != NULL){
                // step 1 - flatten child nodes
                Node *next = currNode->next;
                currNode->next = flatten(currNode->child);

                currNode->next->prev = currNode;
                currNode->child = NULL;

                // step 2 - find tail of linked list
                while(currNode->next != NULL){
                    currNode = currNode->next;
                }

                // step 3 - attach tail with next ptr
                if(next != NULL){
                    currNode->next = next;
                    next->prev = currNode;
                }
            }

            currNode = currNode->next;

       } 

       return head;

    }
};