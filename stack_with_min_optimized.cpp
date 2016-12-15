#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class StackWithMin_optimized
{
    void push(int value);
    void pop();
    int top();
    int min();

private:
    std::stack<int> stack;
    int minValue;
};

int main()
{

}

void StackWithMin_optimized::push(int value)
{
    if (not stack.empty())
    {
        stack.push(value);
        minValue = value;
    }
    else if (value >= minValue)
    {
        stack.push(value);
    }
    else
    {
        stack.push(2 * value - minValue);
        minValue = value;
    }
}

void StackWithMin_optimized::pop()
{
    if (stack.top() < minValue)
    {
        minValue = 2 * minValue - stack.top();
    }
    stack.pop();
}

int StackWithMin_optimized::top()
{
    int topValue = stack.top();
    if(topValue < minValue)
    {
        topValue = minValue;
    }
    return topValue;
}

int StackWithMin_optimized::min()
{
    return minValue;
}
