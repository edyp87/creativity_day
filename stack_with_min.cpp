#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class StackWithMin
{
    void push(int value);
    void pop();
    int top();
    int min();

private:
    std::stack<int> stack;
    std::stack<int> minValues;
};

int main()
{

}

void StackWithMin::push(int value)
{
    stack.push(value);

    if (stack.empty() || value < minValues.top())
    {
        minValues.push(value);
    }
    else
    {
        minValues.push(minValues.top());
    }
}

void StackWithMin::pop()
{
    stack.pop();
    minValues.pop();
}

int StackWithMin::top()
{
    return stack.top();
}

int StackWithMin::min()
{
    return minValues.top();
}
