#include <iostream>
using namespace std;

typedef char ListEntry;
typedef struct listnode{
    ListEntry data;
    struct listnode *next;
}ListNode;

typedef int position;
typedef struct list{
    int count;
    ListNode *head;
}List;

void SetPosition(position p, List*list, ListNode **current){
    ListNode *q;

    if(p < 0 || p >= list -> count){
        cout << "INVALID POSITION" << endl;
    }

    else{
        q = list -> head;

        for(int count = 0; count < p; count++){
            q = q -> next;
        }
        *current = q;
    }
}


    ListNode *MakeNewNode(ListEntry x) { 
        ListNode *q = new ListNode;

        if(q){
            q -> data = x;
            q -> next = NULL;
        }
        else{
            cout <<"MEMORY NOT AVAILABLE FOR NEW NODE" << endl;
        }
        return q;

    }

    void InsertList(position p, ListEntry data, List*list){
        ListNode *newnode,*current;

        if(p < 0 || p > list -> count){
            cout << "INVALID POSITION" << endl;
        }
        else{
            newnode = MakeNewNode(data);

        if(p == 0){
            newnode -> next = list -> head;
            list -> head = newnode;
        }
        else{
            SetPosition(p -1 , list , &current);
                newnode -> next = current -> next;
                current -> next = newnode;
            }
            list -> count++;
        }
    }

    void DeleteList(position p, ListEntry *x, List*list){
        ListNode *temp,*current;

        if(p < 0 || p >= list -> count){
            cout << "INVALID POSITION" << endl;
        }

        else {
            
            if(p == 0){
                temp = list -> head;
                *x = temp -> data;
                list -> head = list -> head -> next;
                delete temp;
            }

            else{
                SetPosition(p - 1, list, &current);
                temp = current -> next;
                *x = temp -> data;
                current -> next = temp -> next;
                delete temp;

                }
                list -> count--;
        }
    }

    void Display(List*list){ 
    ListNode *temp;
    temp = list -> head;
    cout <<"LIST CONTENT" << endl;
    if(temp == NULL){
        cout << "LIST EMPTY" << endl;
    }
    else{
        while(temp != NULL){
            cout << temp -> data << endl;
            temp = temp -> next;
        }
        cout << endl;
    }
        cout << "TOTAL NUMBERS OF NODES" << list -> count <<endl;
    }
    
    int main(){
        List mylist;
        mylist.count = 0;
        mylist.head = NULL;

        InsertList(0,'A',&mylist);
        InsertList(1,'B',&mylist);
        InsertList(1,'C',&mylist);
        InsertList(2,'D',&mylist);
        InsertList(3,'E',&mylist);

        cout << "BEFORE DELETION" << endl;
        Display(&mylist);

        ListEntry deleted;

        DeleteList(3,&deleted, &mylist);
        cout << "DELETED ELEMENT" << deleted << endl;

        DeleteList(2, &deleted ,&mylist);
        cout << "DELETED ELEMENT" << deleted << endl;

        cout << "AFTER DELETION" << endl;
        Display(&mylist);

        return 0;
    }


