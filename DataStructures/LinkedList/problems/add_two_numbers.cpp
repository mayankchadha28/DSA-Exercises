/* 

Leetcode: 

*/


// Always prefer using a dummy node while creating a new list





/* 
This solution does not work as after a large number conversions are difficult to and from string


Note: You cannot use to_string as it i
string a;
a[iterator] = to_string(currNode->val);

as to_string returns string but we need to insert char

'0' + a[i] add like this

*/


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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