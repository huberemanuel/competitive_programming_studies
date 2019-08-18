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
        void removeDuplicates1()
        {
            Node<T> *actual = this->first, *last = nullptr;
            std::set<T> unique_nodes;
            if (actual == nullptr) {
                return;
            }
            while (actual != nullptr) {
                if (unique_nodes.find(actual->value) == unique_nodes.end()) {
                    unique_nodes.insert(actual->value);
                }
                else {
                    last->next = actual->next;
                    actual = last;
                }
                last = actual;
                actual = actual->next;
            }
        }
        void removeDuplicates2()
        {
            Node<T> *actual = this->first, *aux = nullptr;
            while (actual != nullptr) {
                if (actual->next != nullptr) {
                    aux = actual->next;
                }
                while (aux != nullptr && actual->value == aux->value) {
                    aux = aux->next;
                }
                actual->next = aux;
                actual = actual->next;
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
    list.removeDuplicates2();
    list.print();

    return 0;
}
