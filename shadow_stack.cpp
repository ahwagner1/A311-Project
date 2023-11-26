#include "shadow_stack.h"
using namespace std;

ShadowStack::ShadowStack() : top(-1), data(nullptr), heapLocations(nullptr)
{
    srand(static_cast<unsigned>(time(0)));
    
    // initializing 1000 possible spots on heap for potential storage of stack data
    heapLocations = new int[1000];
    for (int i = 0; i < 1000; ++i) {
        heapLocations[i] = reinterpret_cast<int>(malloc(maxSize * sizeof(int)));
    }

    // choose spot on heap for the stack
    RandomizeStackAddress();
    data = reinterpret_cast<int*>(malloc(maxSize * sizeof(int))); // creates an array of size maxSize in the location chosen by RandomizeStackAddress()
}

ShadowStack::~ShadowStack() 
{
    delete[] heapLocations;
    free(data);
}

void ShadowStack::Push(int value)
{
    if (top < maxSize - 1)
    {
        data[++top] = value;
    }
    else
    {
        cout << "Shadow stack overflow!" << endl;
    }
}

int ShadowStack::Pop()
{
    if (top >= 0)
    {
        return data[top--];
    }
    else
    {
        cout << "Shadow stack underflow!" << endl;
        return -1; // Placeholder value for underflow
    }
}

void ShadowStack::Print() const
{
    cout << "Shadow Stack: ";
    for (int i = 0; i <= top; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void ShadowStack::RandomizeStackAddress() 
{
    int index = rand() % 1000;
    data = reinterpret_cast<int*>(heapLocations[index]);
}

