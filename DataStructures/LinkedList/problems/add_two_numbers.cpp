/* 

Leetcode: 

*/

#include <string>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Always prefer using a dummy node while creating a new list
/* 
This solution creates a new List with a dummy node to track

add the number and store the carry in a variable and add to the sum

then store the 0th index as the node

make sure to check if the linked list is NULL as there may not be equal number of elements

In the last there may be sum carry left out which we need to add so do that and return the output removing the dummy node


*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr_a = l1;
        ListNode* curr_b = l2;
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* currNode = dummyNode;

        int carry = 0;

        while(curr_a != NULL || curr_b != NULL){
            int sum = carry;

            if(curr_a != NULL) sum += curr_a->val;
            if(curr_b != NULL) sum += curr_b->val;
            
            carry = sum / 10;
            
            ListNode* newNode = new ListNode(sum % 10);
            
            currNode->next = newNode;
            currNode = currNode->next;

            if(curr_a) curr_a = curr_a->next;
            if(curr_b) curr_b = curr_b->next;

        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            currNode->next = newNode;
        }


        
        dummyNode = dummyNode->next;
        return dummyNode;
    
    }



/* 
This solution does not work as after a large number conversions are difficult to and from string


Note: You cannot use to_string as it i
string a;
a[iterator] = to_string(currNode->val);

as to_string returns string but we need to insert char

'0' + a[i] add like this

*/


ListNode* addTwoNumbers_strversion(ListNode* l1, ListNode* l2) {
        string a;
        string b;
        ListNode* currNode = l1;

        while(currNode != NULL){
            a += ('0'+ currNode->val);
            // a[iterator] = to_string(currNode->val);
            currNode = currNode->next; 
            
        }

        reverse(a.begin(), a.end());

 
        currNode = l2;
        while(currNode != NULL){
            b += ('0'+ currNode->val);
            currNode = currNode->next; 
         
        }

        reverse(b.begin(), b.end());

        long long int sum = stoll(a)+stoll(b);

        string total = to_string(sum);

        reverse(total.begin(), total.end());

        int it = 1, n = total.size();
        ListNode* head = new ListNode(total[0] - '0');
        ListNode* curr = head;
        while(it < n){
            
            ListNode* newNode = new ListNode(total[it] - '0');
            curr->next = newNode;
            curr = curr->next;
            it++;

        }

        return head;

    }