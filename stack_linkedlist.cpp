#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

node *MakeNewNode(int info)
{
    node *p = new node;
    if (p)
    {
        p->data = info;
        p->next = NULL;
    }
    else
    {
        cout << "MEMORY NOT AVAILABLE FOR NEW ADDITION=" << endl;
    }
    return p;
}

void push(int data, stack *s)
{
    node *newnode = MakeNewNode(data);
    newnode->next = s->top;
    s->top = newnode;
}

void pop(stack *s)
{
    if (s->top == NULL)
    {
        cout << "STACK IS UNDERFLOW" << endl;
    }
    else
    {
        node *del = s->top;
        s->top = del->next;
        cout << "POPPED=" << del->data << endl;
        delete del;
    }
}

void peek(stack *s)
{
    if (s->top == NULL)
    {
        cout << "EMPTY STACK" << endl;
    }
    else
    {
        cout << "TOP ELEMENT =" << s->top->data << endl;
    }
}

void isEmpty(stack *s)
{
    if (s->top == NULL)
    {
        cout << "STACK IS EMPTY" << endl;
    }
    else
    {
        cout << "STACK IS NOT EMPTY" << endl;
    }
}

int main()
{
    stack s;
    s.top = NULL;

    push(10, &s);
    push(20, &s);
    push(30, &s);

    peek(&s);
    pop(&s);
    pop(&s);
    isEmpty(&s);
    pop(&s);
    isEmpty(&s);

    return 0;
}
