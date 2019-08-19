#include <iostream>
#include <stack>

class MyQueue
{
    private:
        std::stack<int> left_stack, right_stack;
    public:
        void push(int value)
        {
            left_stack.push(value);
        }
        int pop()
        {
            int removed;

            if (left_stack.empty()) {
                std::cout << "Trying to remove from an empty queue" << std::endl;
                return -1;
            }

            while (!left_stack.empty()) {
                right_stack.push( left_stack.top() );
                left_stack.pop();
            }
            removed = right_stack.top();
            right_stack.pop();
            while (!right_stack.empty()) {
                left_stack.push( right_stack.top() );
                right_stack.pop();
            }

            return removed;
        }
        bool empty()
        {
            return (left_stack.empty() && right_stack.empty());
        }
        MyQueue()
        {
        }
};

int main()
{
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty()) {
        std::cout << q.pop() << std::endl;
    }

    return 0;
}
