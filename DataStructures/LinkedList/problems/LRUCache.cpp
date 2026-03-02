

#include <iostream>
#include <unordered_map>

using namespace std;

/* 
The idea is to maintain a unordered map and a Doubly linked list
Linkedlist is to store the data in order and map is used to get the data

Note: you need to clear map before removing the link

*/

class LRUCache {
public:

    class Node {
        public:
            int key, val;
            Node* prev;
            Node* next;

            Node(int k, int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode){ //O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;

    }

    void deleteNode(Node* oldNode){ //O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
       if(m.find(key) == m.end()){
        return -1;
       }

       Node* ansNode = m[key];
       int ans = ansNode->val;
       
       m.erase(key);
       deleteNode(ansNode);

       addNode(ansNode);
       m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) { //O(1)
        // check if already exist
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        // Capacity reached
        if(m.size() == limit){
            // delete LRU data
            m.erase(tail->prev->key);
            deleteNode(tail->prev);

        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */