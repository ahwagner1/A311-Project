#include "shadow_stack_LL.h"
using namespace std;

ShadowStackLL::ShadowStackLL() : heapLocations(nullptr), head(nullptr), tail(nullptr) {
    srand(static_cast<unsigned>(time(0)));
    // initializing 1000 possible spots on heap for potential storage of stack data
    heapLocations = new Node[1000];
}

ShadowStackLL::~ShadowStackLL() {
    delete[] heapLocations; // freeing memory used
}

void ShadowStackLL::Push(int value) { // push new values to end of linked list since tail == top
    Node* newNode = new Node;
    if (!newNode) {
        cerr << "Memory allocation failed" << endl;
        return;
    }

    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        RandomizeStackAddress();
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

int ShadowStackLL::Pop() { // always removing the tail node
    if (head == nullptr) {
        cout << "Shadow stack underflow!" << endl;
        return -1;
    }
    
    int nodeData = tail->data;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    return nodeData;
}

void ShadowStackLL::Print() const {
    if (head == nullptr) { // no data to output
        return;
    }
    Node* temp = head;
    cout << "Shadow Stack LL: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ShadowStackLL::RandomizeStackAddress() {
    // chooses a random spot of the previously allocated array on the heap to store the linked list
    int index = rand() % 1000;
    head = tail = &heapLocations[index];
}
