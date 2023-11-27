#include "shadow_stack.h"
using namespace std;

ShadowStack::ShadowStack() : top(-1)
{
    srand(static_cast<unsigned>(time(0)));

    // allocate space on heap for data
    data = new int[maxSize];

    // create an array of int*  on the heap
    heapLocations = new int*[heapMaxSize];
    
    // choosing random spot in heapLocations to store data
    RandomizeStackAddress();
}

ShadowStack::~ShadowStack() {
    delete[] data;
    delete[] heapLocations;
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
    int index = rand() % heapMaxSize;
    heapLocations[index] = data;
}
