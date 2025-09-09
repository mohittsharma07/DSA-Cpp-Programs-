#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;

    return newNode;
}

void linklistTraversal(struct Node* ptr){
    while(ptr != NULL){
        cout << ptr -> data << endl;
        ptr = ptr -> next;
    }
}

//  INSERTION AT BEGINING......

struct Node* inserATFirst(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));

    ptr -> data = data;
    ptr -> next = head;

    return ptr;
}

// INSERTION AT BETWEEN INDEX...........

struct Node* insertatindex(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));

    struct Node* p = head;

    int i = 0;

    while(i != index -1 ){ 
        p = p -> next;
        i++;
    }

    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;

        return head;
}

//  INSERTION AT ENDING...............

struct Node* insertatend(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));

    struct Node* p = head;

    while(p -> next != NULL){
        p = p -> next;
    }

    ptr -> data = data;
    p -> next = ptr;
    ptr -> next = NULL;

    return head;
}

// INSERT AT AFTER NODE...........

struct Node* insertatafterNode(struct Node* head, struct Node* prvNode, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));

    struct Node* p = head;

    ptr -> data = data;
    ptr -> next = prvNode -> next;
    prvNode -> next = ptr;

    return head;
}

int main(){
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);


    head -> next = second;
    second -> next = third;
    third -> next = NULL;

    linklistTraversal(head);
    // head = inserATFirst(head,50);
    // head = insertatindex(head,555,1);
    // head = insertatend(head,250);
    head = insertatafterNode(head, second, 330);
    linklistTraversal(head);
    return 0;
}