#include "stack.h"
using namespace std;

Stack::Stack() : top(-1) {}

Stack::~Stack() {}

void Stack::Push(int value)
{
    if (top < maxSize - 1)
    {
        data[++top] = value;
    }
    else
    {
        cout << "Stack overflow!" << endl;
    }
}

int Stack::Pop()
{
    if (top >= 0)
    {
        return data[top--];
    }
    else
    {
        cout << "Stack underflow!" << endl;
        return -1; // Placeholder value for underflow
    }
}

void Stack::Print() const
{
    cout << "Stack: ";
    for (int i = 0; i <= top; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}