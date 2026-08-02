/* 
Leetcode: https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

*/

// #include <iostream>
#include <stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 /* 
 
 A stack reverses whatever order you push in. Push a list front-to-back, and popping gives you the list back-to-front.
So: pass 1 — push every node's val onto the stack (no popping, no comparing yet).
Pass 2 — walk the list front-to-back again; at each node, pop one value and compare it to currNode->val.
currNode->val = forward order
s.pop() = reverse order
If every position matches, forward == reverse == palindrome.
If any comparison fails, return false immediately. If you get through the whole list without a mismatch, return true.
 
 */

    bool isPalindrome(ListNode* head) {
        stack<int> s;
        
        ListNode* currNode = head;

        // push everything to stack
        while(currNode != NULL){
            s.push(currNode->val);
            currNode= currNode->next;
        }

        currNode = head;
        while(currNode != NULL){
            int val = currNode->val;

            if(val == s.top()){
                s.pop();
            }else{
                return false;
            }

            currNode = currNode->next;
        }

        return true;

    }
