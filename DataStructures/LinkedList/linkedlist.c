#include <stdio.h>
#include <stdlib.h>


#define SUCCESS 0
#define ERROR 1

struct Node {
    int val;
    struct Node* next;
};

static struct Node *head, *tail;

struct Node* create_node(int val){

    struct Node* newNode = malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("ERROR: Cannot allocate memory");
        return NULL;
    }

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

int push_front(int val){

    struct Node* newNode = create_node(val);
 
    if(newNode != NULL){

        if(head == NULL){
            head = tail = newNode;
        }else{

            newNode->next = head;
            head = newNode;
        }

        return SUCCESS;
    }else{
        return ERROR;
    }

}

int push_back(int val){

    struct Node* newNode = create_node(val);

    if(newNode != NULL){
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

        return SUCCESS;
    }

    return ERROR;
}

void pop_back(){

    if(head == NULL){
        printf("LL is empty");
        return;
    }

    if(head == tail){
        free(head);
        head = tail = NULL;
        return;    
    }

    struct Node* tmpNode = head;

    while(tmpNode->next != tail){
        tmpNode = tmpNode->next;
    }
    free(tail);
    tmpNode->next = NULL;
    tail = tmpNode;
}

void pop_front(){

    if(head == NULL){
        printf("LL is empty");
        return;
    }

    struct Node* tmpNode = head;

    if(head == tail){
        head = tail = NULL;
    }else{
        head = head->next;
    }
    
    free(tmpNode);

}

void print_LL(struct Node* head){
    // struct Node* tmpNode = create_node
    struct Node* tmpNode = head;
    
    while(tmpNode != NULL){

        printf("%d -> ", tmpNode->val);

        tmpNode= tmpNode->next;
    }
    printf("NULL\n");
}

void free_ll(){

    struct Node* tmpNode = head;

    struct Node* nextNode;

    while(tmpNode != NULL){
        nextNode = tmpNode->next;
        free(tmpNode);
        tmpNode = nextNode;
    }

    head = tail = NULL;
}



void LL_init(){
    head = tail = NULL;
}


int main(){

    LL_init();

    for(int i=1; i< 10; i++){
        push_back(i);
    }
    push_front(0);

    print_LL(head);


    return 0;
}
