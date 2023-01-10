#include <iostream>


//Exercice 1 TP00

class Node {
    public:
        int data;
        Node* next;
        Node(int data): data(data), next(nullptr) {}
};

class Stack {
    private:
        Node* head;
    public:
        Stack(): head(nullptr) {}
        ~Stack() {
            while (!is_empty()) {
                pop();
            }
        }
        void push(int data) {
            auto new_node = new Node(data);
            new_node->next = head;
            head = new_node;
        }
        int pop() {
            if (is_empty()) {
                throw std::out_of_range("Stack is empty");
            }
            auto data = head->data;
            auto temp = head;
            head = head->next;
            delete temp;
            return data;
        }
        int peek() {
            if (is_empty()) {
                throw std::out_of_range("Stack is empty");
            }
            return head->data;
        }
        bool is_empty() {
            return head == nullptr;
        }
};


int main() {
    Stack stack;
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(8);
    stack.push(4);
    stack.push(0);
    std::cout << "Peek: " << stack.peek() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    return 0;
}

