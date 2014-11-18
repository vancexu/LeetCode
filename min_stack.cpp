/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> s_min;
public:
    void push(int x) {
        s.push(x);
        if (s_min.empty()) {
            s_min.push(x);
        } else {
            int tmp = s_min.top();
            if (x <= tmp)
                s_min.push(x);
        }
    }

    void pop() {
        int tmp = s.top();
        s.pop();
        if (tmp == s_min.top())
            s_min.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return s_min.top();
    }

};

int main() {
    MinStack s;
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(1);
    s.push(6);
    cout << "Top is: " << s.top() << endl;
    cout << "Min is: " << s.getMin() << endl;
    s.pop();
    cout << "Top is: " << s.top() << endl;
    cout << "Min is: " << s.getMin() << endl;
    cout << endl;
}
