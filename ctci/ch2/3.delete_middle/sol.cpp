#include <iostream>
#include <set>
// #include <cstddef>

template <class T>
struct Node {
    T value;
    struct Node<T>* next;
    Node<T>() { next = nullptr; }
    Node<T>(int v) { next = nullptr; value = v; }
};

template <typename T>
class LinkedList
{
    Node<T>* findLast() {
        Node<T> *actual = this->first;
        while (actual != nullptr) {
            if (actual->next == nullptr) {
                break;
            }
            actual = actual->next;
        }
        return actual;
    }
    public:
        struct Node<T> *first;
        void append(Node<T> *node) {
            Node<T> *last = findLast();
            if (last != nullptr) {
                last->next = node;
                node->next = nullptr;
            }
            else {
                this->first = node;
            }
        }
        void print() {
            Node<T> *actual = this->first;
            if (actual == nullptr)  {
                return;
            }
            std::cout << actual->value;
            while (actual != nullptr && actual->next != nullptr){
                actual = actual->next;
                std::cout << " -> " << actual->value;
            }
            std::cout << std::endl;
        }
        void remove(T val) {
            Node<T> *actual = this->first, *last = nullptr;
            if (actual == nullptr)  {
                return;
            }
            while (actual != nullptr) {
                if (actual->value == val) {
                    if (last == nullptr) {
                        actual = actual->next;
                        this->first = actual;
                    }
                    else {
                        last->next = actual->next;
                    }
                }
                last = actual;
                if (actual != nullptr) {
                    actual = actual->next;
                }
            }
        }
        LinkedList()
        {
            this->first = nullptr;
        }
};

int main()
{
    int n;
    LinkedList<int> list;
    std::cin >> n;
    struct Node<int>* s;
    while (n--) {
        int aux; 
        std::cin >> aux;
        s = new Node<int>(aux);
        list.append(s);
    }
    int val;
    std::cin >> val;
    list.remove(val);
    list.print();

    return 0;
}
