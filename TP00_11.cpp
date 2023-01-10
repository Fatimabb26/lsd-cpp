#include <iostream>
using namespace std;

// Exercice 3 TP00
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

void eliminateDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;
    if (current == NULL)
        return;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

// Driver code
int main() {
    struct Node* head = NULL;
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    cout << "Original Linked List: ";
    printList(head);
    eliminateDuplicates(head);
    cout << "Linked List without duplicates: ";
    printList(head);
    return 0;
}

