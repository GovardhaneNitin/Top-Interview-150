#include <iostream>
#include <cassert>
#include <stack>
#include <limits.h>
#include <stdexcept>
using namespace std;

class MinStack
{
private:
    stack<int> stk1; // Main stack
    stack<int> stk2; // Stack to keep track of minimum values

public:
    MinStack()
    {
        // ...write your code here...
        stk2.push(INT_MAX);
    }

    void push(int val)
    {
        // ...write your code here...
        stk1.push(val);
        stk2.push(min(val, stk2.top()));
    }

    void pop()
    {
        // ...write your code here...
        stk1.pop();
        stk2.pop();
    }

    int top()
    {
        // ...write your code here...
        return stk1.top();
    }

    int getMin()
    {
        // ...write your code here...
        return stk2.top();
    }
};

/**
 * Test cases for MinStack
 */
int main()
{
    MinStack *obj = new MinStack();

    // Test Case 1: Basic functionality
    obj->push(5);
    obj->push(3);
    obj->push(7);
    assert(obj->getMin() == 3); // Expected: 3
    obj->pop();
    assert(obj->top() == 3);    // Expected: 3
    assert(obj->getMin() == 3); // Expected: 3
    obj->pop();
    assert(obj->getMin() == 5); // Expected: 5

    // Test Case 2: Single element
    obj->push(10);
    assert(obj->top() == 10);    // Expected: 10
    assert(obj->getMin() == 10); // Expected: 10
    obj->pop();

    // Test Case 3: Negative numbers
    obj->push(-2);
    obj->push(-3);
    obj->push(0);
    assert(obj->getMin() == -3); // Expected: -3
    obj->pop();
    assert(obj->getMin() == -3); // Expected: -3
    obj->pop();
    assert(obj->getMin() == -2); // Expected: -2

    // Test Case 4: Repeated values
    obj->push(1);
    obj->push(1);
    obj->push(1);
    assert(obj->getMin() == 1); // Expected: 1
    obj->pop();
    assert(obj->getMin() == 1); // Expected: 1
    obj->pop();
    assert(obj->getMin() == 1); // Expected: 1
    obj->pop();

    // Test Case 5: Empty stack operations
    try
    {
        obj->pop(); // Should handle gracefully
    }
    catch (...)
    {
        cout << "Handled empty stack pop" << endl;
    }
    try
    {
        obj->top(); // Should handle gracefully
    }
    catch (...)
    {
        cout << "Handled empty stack top" << endl;
    }
    try
    {
        obj->getMin(); // Should handle gracefully
    }
    catch (...)
    {
        cout << "Handled empty stack getMin" << endl;
    }

    cout << "All test cases passed!" << endl;
    delete obj;
    return 0;
}