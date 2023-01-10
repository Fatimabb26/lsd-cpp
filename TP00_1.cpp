#include <iostream>
using namespace std;
//Exercice 2 TP00
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct Node* reverseInGroups(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL) 
        head->next = reverseInGroups(next, k); 
 
    return prev;
}

int main() {
    struct Node* head = NULL;
    for (int i = 8; i >= 1; i--)
        push(&head, i);
    cout << "Original Linked List: ";
    printList(head);
    head = reverseInGroups(head, 2);
    cout << "Reversed Linked List: ";
    printList(head);
    return 0;
}

