#include "stack.h"
#include "shadow_stack.h"
#include "shadow_stack_LL.h"
#include <chrono>
#include <iostream>
#include <functional>
using namespace std;

// prototypes, Stack demos are all identical except for the type of stack used
void measureTime(const char* operation, function<void()> function);
void regularStackDemo();
void shadowStackDemo();
void shadowStackLLDemo();

int main()
{  
    // initializing the necessary components to test execution times for the different types of stacks
    const int numOperations = 3;
    const char* operations[numOperations] = {
        "regular stack demo",
        "shadow stack demo",
        "shadow stack using linked lists demo"
    };

    function<void()> functions[numOperations] = {
        regularStackDemo,
        shadowStackDemo,
        shadowStackLLDemo
    };

    // measuring the execution times
    for (int i = 0; i < numOperations; ++i) {
        measureTime(operations[i], functions[i]);
    }

    return 0;
}

// using chrono to measure execution time of each demo here
void measureTime(const char* operation, function<void()> function) {
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    function();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken for " << operation << ": " << duration.count() << " microseconds" << endl << endl;
}

// different class demos
void regularStackDemo() {
    Stack regularStack;
    regularStack.Push(10);
    regularStack.Push(20);
    regularStack.Push(30);
    regularStack.Print();
    int poppedValue = regularStack.Pop();
    regularStack.Print();
}

void shadowStackDemo() {
    ShadowStack shadowStack;
    shadowStack.Push(10);
    shadowStack.Push(20);
    shadowStack.Push(30);
    shadowStack.Print();
    int poppedValue = shadowStack.Pop();
    shadowStack.Print();
}

void shadowStackLLDemo() {
    ShadowStackLL shadowStackLL;
    shadowStackLL.Push(10);
    shadowStackLL.Push(20);
    shadowStackLL.Push(30);
    shadowStackLL.Print();
    int poppedValue = shadowStackLL.Pop();
    shadowStackLL.Print();
}
