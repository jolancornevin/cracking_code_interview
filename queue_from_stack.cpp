#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void transferStack(stack<int> *stack_ori, stack<int> *stack_dest) {
            // Push every element of the stack_ori stack to the stack_dest, which transforms a FIFO to a LIFO.
            while(!stack_ori->empty()) {
                stack_dest->push(stack_ori->top());
                stack_ori->pop();
            }
        }

        void pop() {
            if (stack_oldest_on_top.empty())
                transferStack(&stack_newest_on_top, &stack_oldest_on_top);
            
            if (!stack_oldest_on_top.empty())
                stack_oldest_on_top.pop();
        }

        int front() {
            if (stack_oldest_on_top.empty())
                transferStack(&stack_newest_on_top, &stack_oldest_on_top);
            
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
