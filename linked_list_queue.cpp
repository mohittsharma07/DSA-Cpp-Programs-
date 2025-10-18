#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct que{
    node *front;
    node *rear;
}que;

void create(que*q){
    q -> front = NULL;
    q -> rear = NULL;
}

node *MakeNewNode(int x){
    node *q = new node;
    if(q){
        q -> data = x;
        q -> next = NULL; 
    }
    else{
        cout << "MEMORY NOT AVAILABLE FOR NEW ADDITION" << endl;
    }
    return q;
}

void Insert(int data, que*q){
    node *newnode = MakeNewNode(data);
    if(q -> front == NULL){
        q -> front = newnode;
        q -> rear = newnode;
    }
    else{
        q -> rear -> next = newnode;
        q -> rear = newnode;
    }
}

void Delete(int *x,que*q){
    if(q -> front == NULL){
        cout << "QUE IS EMPTY" << endl;
    }
    else{
        node *temp = q -> front;
        *x = temp -> data;
        q -> front = q -> front -> next;
        if(q -> front == NULL){
            q -> rear = NULL;
        }
        delete temp;
    }
}

int main() {
    que q;
    create(&q);

    cout << "INSERT ELEMENT IS =" << endl;

    Insert(10, &q);
    Insert(20, &q);
    Insert(30, &q);

    int deleted;
    Delete(&deleted, &q);
    cout << "Deleted: " << deleted << endl;

    Delete(&deleted, &q);
    cout << "Deleted: " << deleted << endl;

    Delete(&deleted, &q);
    cout << "Deleted: " << deleted << endl;

    Delete(&deleted, &q); 

    return 0;
}
