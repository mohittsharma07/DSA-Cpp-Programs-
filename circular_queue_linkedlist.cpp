#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct que{
    int count;
    struct node * rear;
}que;

void create(que*q){
    q->count = 0;
    q->rear = NULL;
}

node *MakeNewNode(int x){
    node *q = new node;
    if(q){
        q->data = x;
        q->next = NULL;
    }
    else{
        cout <<"MEMORY NOT AVAILABLE FOR NEW NODE" << endl;
    }
    return q;
}

void Display(que*q){
    if(q->rear == NULL){
        cout << "QUEUE IS EMPTY" << endl;
        return;
    }

    node *current = q->rear->next;
    cout << "QUEUE ELEMENTS: ";
    do {
        cout << current->data << " ";
        current = current->next;
    } while(current != q->rear->next);
    cout << endl;
}

void Insert(int x, que*q){
    node *newnode = MakeNewNode(x);
    if(q->rear == NULL){
        q->rear = newnode;
        newnode->next = newnode;
    }
    else{
        newnode->next = q->rear->next;
        q->rear->next = newnode;
        q->rear = newnode;
    }
    q->count++;
}

void Delete(que *q) {
    if (q->rear == NULL) {
        cout << "QUEUE IS EMPTY" << endl;
        return;
    }

    node *front = q->rear->next; 

    if (q->rear == front) { 
        q->rear = NULL;
    } else {
        q->rear->next = front->next;
    }

    cout << "DELETED ELEMENT: " << front->data << endl;
    delete front;
    q->count--;
}

int main(){
    que q;
    create(&q);

    Insert(10,&q);
    Insert(20,&q);
    Insert(30,&q);
    Display(&q);

    Delete(&q);
    Display(&q);

    Delete(&q);
    Display(&q);

    Delete(&q);
    Display(&q);

    return 0;

} 
