#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 /* 
 
 Approach 1 -
 Loop through all elements and find the size
 Traverse through each node and reach the one before to remove
 Set the next node to avoid loosing
 NOw update the next node and delete the tmp node

 TC- O(2n)


 Approach 2: Same as before but we dont have to loop through entire list 
 we can just loop till target and continue another node address iterator from there
 
 
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* it_node = head;
        
        // find the index
        int total = 0;
        while(it_node != NULL){
            total++;
            it_node = it_node->next;
        }

        //if we need to delete the head
        if (n == total) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

        // Traverse the nodes
        it_node = head;
        ListNode* newNext = NULL;
        for(int i=0; i< total-n-1; i++){
            it_node= it_node->next;
        }

        //Delete target Node
        ListNode* toDelete = it_node->next;
        it_node->next = toDelete->next;
        delete toDelete;


        return head;


    }