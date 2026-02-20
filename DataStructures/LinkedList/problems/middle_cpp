#include <iostream>

/* 

Leetcode: https://leetcode.com/problems/middle-of-the-linked-list/

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* 
the idea is to maintain 2 indexes
slow, fast pointer

k = no of operations
N = length of list

fast-> 2k = N
k = N/2

slow-> k 
N/2 (middle)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL || fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};