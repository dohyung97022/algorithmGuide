//stack uses deque in c++
// deque doesn't double the stack when it is full
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;
    stk.empty(); // returns 1 or 0
    stk.size();  // returns the size
    stk.top();   // returns the reference of the top stack
    stk.push(1); // pushes 1 at the top
    stk.pop();   // pops at the top
    stk.push(1); // pushes 1 at the top
    // stack can not be iterated like stk[1]
}