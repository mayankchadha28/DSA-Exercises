/* 
Leetcode: https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


*/
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
Solution 2: Iterative approach (More optimized for space)



SC - O(n)


*/

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
       
       ListNode* newHead = new ListNode(-1);
       ListNode* prev= newHead;


       while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                prev->next= head1; 
                head1=head1->next;
            }else{
                prev->next = head2;
                head2 = head2->next;
            }
            prev= prev->next;
       }
       prev->next = head1 ? head1 : head2;
       return newHead->next;

    }


/* 

Solution 1

// Merge Two Sorted Lists — Recursion
// At each call, compare both heads → smaller node wins current position
// Set winner->next = recurse(winner->next, other) then return winner
// Base case: either list is NULL → return the other
// Note: Links are SET on the way back up (after recursion returns), not on the way down

TC - O(m+n)
SC - O(n)

*/
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
       
       if(head1 == NULL || head2 == NULL){
        return head1 == NULL ? head2 : head1;
       }

    // case
    if(head1->val <= head2->val){
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }

    }
};


