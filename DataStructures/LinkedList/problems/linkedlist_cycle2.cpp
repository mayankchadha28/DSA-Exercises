
#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *detectCycle(ListNode *head) {
        ListNode *sp = head;
        ListNode *fp = head;

        while(fp != NULL && fp->next != NULL){
            sp = sp->next;
            fp = fp->next->next;

            if(sp == fp){
                sp = head;
                while(sp != fp){
                    sp = sp->next;
                    fp = fp->next;
                }
                return sp;
            }
        }

      return NULL;
    }


    ListNode *detectCycle_slightlyoptimized(ListNode *head) {
        ListNode *sp = head;
        ListNode *fp = head;

        bool hasCycle = false;

        while(fp != NULL && fp->next != NULL){
            sp = sp->next;
            fp = fp->next->next;

            if(sp == fp){
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle){
            return NULL;
        }

        sp = head;
        ListNode *prev = NULL;
        while(sp != fp){
            sp = sp->next;
            prev = fp; //if we want to remove cycle
            fp = fp->next;
        }

        prev->next = NULL; //removing cycle
        return sp;
    }