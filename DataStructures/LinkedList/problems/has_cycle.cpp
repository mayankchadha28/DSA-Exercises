
/* 
Leetcode: https://leetcode.com/problems/linked-list-cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

*/


#include <iostream>



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

/* 
maintain two pointers, slow and fast
slow + 1
fast+2
at some point if there is a cycle. slow == fast

Floyds Algorithm
*/
    bool hasCycle(ListNode *head) {
        ListNode* sp = head;
        ListNode* fp = head;

        while(fp!=NULL && fp->next!=NULL){
            sp = sp->next;
            fp = fp->next->next;

            if(sp == fp){
                return true;
            }
        }
        return false;
    }
};