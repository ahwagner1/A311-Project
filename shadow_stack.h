#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class ShadowStack
{
public:
    ShadowStack();
    ~ShadowStack();

    void Push(int value);
    int Pop();
    void Print() const;

private:
    static const int maxSize = 100;
    static const int heapMaxSize = 1000;
    int* data;
    int top;
    int** heapLocations;

    void RandomizeStackAddress();
};
