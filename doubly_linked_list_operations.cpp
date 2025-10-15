#include <iostream>
using namespace std;

typedef int position;

typedef struct DlistNode {
    int data;
    DlistNode *prev, *next;
} DlistNode;

typedef struct List {
    int count;
    int currentpos;
    DlistNode *current, *head;
} List;

// Create a new node......
DlistNode *MakeNewNode(int data) {
    DlistNode *q = new DlistNode;
    if (q) {
        q->data = data;
        q->prev = NULL;
        q->next = NULL;
    } else {
        cout << "MEMORY NOT AVAILABLE FOR NEW NODE" << endl;
    }
    return q;
}

// Move current pointer to position p.....
void SetPosition(position p, List *list) {
    if (p < 0 || p >= list->count) {
        cout << "INVALID POSITION" << endl;
        return;
    }
    if (p < list->currentpos) {
        while (list->currentpos != p) {
            list->current = list->current->prev;
            list->currentpos--;
        }
    } else if (p > list->currentpos) {
        while (list->currentpos != p) {
            list->current = list->current->next;
            list->currentpos++;
        }
    }
}

// Insert a new node.....
void InsertList(position p, int data, List *list) {
    DlistNode *newnode, *following;

    if (p < 0 || p > list->count) {
        cout << "INVALID POSITION" << endl;
        return;
    }

    newnode = MakeNewNode(data);

    if (p == 0) { // Insert at head...
        newnode->next = list->head;
        if (list->head != NULL) {
            list->head->prev = newnode;
        }
        list->head = newnode;
        list->currentpos = 0;
        list->current = newnode;
    } else { // Insert at middle or end....
        SetPosition(p - 1, list);
        following = list->current->next;
        newnode->next = following;
        newnode->prev = list->current;
        list->current->next = newnode;
        if (following)
            following->prev = newnode;
        list->current = newnode;
        list->currentpos = p;
    }

    list->count++;
}

// Delete a node at position p....
void DeleteList(position p, List *list) {
    DlistNode *temp;

    if (p < 0 || p >= list->count) {
        cout << "INVALID POSITION" << endl;
        return;
    }

    if (list->head == NULL) {
        cout << "EMPTY LIST" << endl;
        return;
    }

    if (p == 0) { // Delete head....
        temp = list->head;
        list->head = temp->next;
        if (list->head != NULL)
            list->head->prev = NULL;
        delete temp;
    } else { // Delete middle or end....
        SetPosition(p - 1, list);
        temp = list->current->next;
        list->current->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = list->current;
        delete temp;
    }

    list->count--;
}

// Display list forward....
void DisplayForward(List *list) {
    DlistNode *temp = list->head;
    cout << "\nLIST CONTENT (FORWARD): ";
    if (temp == NULL) {
        cout << "EMPTY LIST" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\nTOTAL NUMBER OF NODES = " << list->count << endl;
}

// Display list backward....
void DisplayBackward(List *list) {
    DlistNode *temp = list->head;
    cout << "\nLIST CONTENT (BACKWARD): ";
    if (temp == NULL) {
        cout << "EMPTY LIST" << endl;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\nTOTAL NUMBER OF NODES = " << list->count << endl;
}

// Main function...
int main() {
    List list;
    list.count = 0;
    list.currentpos = 0;
    list.current = NULL;
    list.head = NULL;

    cout << "=== Doubly Linked List Program ===" << endl;

    // Insert some elements...
    InsertList(0, 10, &list);
    InsertList(1, 20, &list);
    InsertList(2, 30, &list);
    InsertList(3, 40, &list);
    InsertList(2, 25, &list);

    // Display list...
    DisplayForward(&list);
    DisplayBackward(&list);

    // Delete one element...
    cout << "\nDeleting node at position 2..." << endl;
    DeleteList(2, &list);

    // Display again...
    DisplayForward(&list);
    DisplayBackward(&list);

    return 0;
}
