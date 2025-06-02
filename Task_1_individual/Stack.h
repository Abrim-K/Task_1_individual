#ifndef STACK_H
#define STACK_H

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    Stack();
    ~Stack();
    void push(int value);
    int pop();
    bool isEmpty() const;
};

#endif