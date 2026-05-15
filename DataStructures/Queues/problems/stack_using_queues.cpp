/* 
Leetcode: https://leetcode.com/problems/implement-stack-using-queues/

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

*/


#include <queue>

using namespace std;


/* 
To implement a stack (LIFO) using Queue (FIFO) we can either implement at push end or pop end

We create 2 queues; whenever a new data arrives

1. copy q1 elements to q2
2. push to q1
3. copy elements back

this way it reverses the elements each time



*/

class MyStack {
public:

    queue<int> q_main, q_help;

    MyStack() {
        
    }
    
    void push(int x) { //O(n)
        
            while(!q_main.empty()){
                int data = q_main.front();
                q_help.push(data);
                q_main.pop();
            }
            q_main.push(x);

            while(!q_help.empty()){
                int data = q_help.front();
                q_main.push(data);
                q_help.pop();
            }
        
    }
    
    int pop() { //O(1)
        int top = q_main.front();
        q_main.pop();
        return top;
    }
    
    int top() { //O(1)
        return q_main.front();
    }
    
    bool empty() { //O(1)
        return q_main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */