#include "stack.h"
#include <iostream>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1; // ���������� -1 ��� ������� ������ (���������)
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}