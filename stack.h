#pragma once

#include <iostream>

class Stack
{
public:
    Stack();
    ~Stack();

    void Push(int value);
    int Pop();
    void Print() const;

private:
    static const int maxSize = 100;
    int data[maxSize];
    int top;
};