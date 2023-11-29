#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    Node* next;
    int data;
};

class ShadowStackLL {
public:
    ShadowStackLL();
    ~ShadowStackLL();

    void Push(int value);
    int Pop();
    void Print() const;

private:
    Node* heapLocations;
    Node* head;
    Node* tail;

    void RandomizeStackAddress();
};

