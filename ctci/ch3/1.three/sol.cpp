#include <iostream>
#include <algorithm>
#include <vector>

template <typename T> class Stack
{
    private:
        std::vector<T> stack;
    public:
        void push(T v, int index) {
            int temp_index = index;
            auto it = this->stack.begin() + 3;
            while (temp_index >= 0) {
                it += this->stack[temp_index--];
            }
            this->stack.insert(it, v);
            ++this->stack[index];
        }
        T pop(int index) {

            if (this->stack[index] == 0) {
                std::cout << "Your trying to pop from an empty stack" << std::endl;
            }

            int temp_index = index;
            int target_index = 2;
            while (temp_index >= 0) {
                target_index += this->stack[temp_index--];
            }
            std::copy(this->stack.begin() + target_index + 1, this->stack.begin() + this->stack.size(), this->stack.begin() + target_index);
            --this->stack[index];
        }
        void print() {
            int last = 3;

            for (int i = 0; i < 3; last+=this->stack[i++]) {
                std::cout << "Stack " << i << '\t';
                for (int j = 0; j < this->stack[i]; ++j) {
                    std::cout << this->stack[last+j] << '\t';
                }
                std::cout << std::endl;
            }
        }
        Stack()
        {
            stack = std::vector<T>(3, 0);
        }
};

int main()
{
    Stack<int> s;
    int n_1, n_2, n_3, aux;
    std::cin >> n_1;
    for (size_t i = 0; i < n_1; ++i) {
        std::cin >> aux;
        s.push(aux, 0);
    }
    std::cin >> n_2;
    for (size_t i = 0; i < n_2; ++i) {
        std::cin >> aux;
        s.push(aux, 1);
    }
    std::cin >> n_3;
    for (size_t i = 0; i < n_3; ++i) {
        std::cin >> aux;
        s.push(aux, 2);
    }
    s.print();

    while (true) {
        int stack_pop;
        std::cin >> stack_pop;
        s.pop(stack_pop);
        s.print();
    }

    return 0;
}
