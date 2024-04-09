#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void printFirstAndLast() {
    // Check if the linked list is empty
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    // Start from the head of the list
    struct Node* ptr = head;

    // Traverse the list until the last node
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Print the first and last elements
    cout << "\nFirst element: " << head->data << endl;
    cout << "Last element: " << ptr->data << endl;
}

void printElementAtPosition(int position) {
    // Check if the linked list is empty
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    // Check if the position is valid
    if (position <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    // Start from the head of the list
    struct Node* ptr = head;
    int count = 1;

    // Traverse the list until the desired position or end of list
    while (ptr != NULL && count < position) {
        ptr = ptr->next;
        count++;
    }

    // Check if position is beyond the end of the list
    if (ptr == NULL) {
        cout << "Position exceeds the length of the list." << endl;
        return;
    }

    // Print the element at the desired position
    cout << "Element at position " << position << ": " << ptr->data << endl;
}

void addElementAtPosition(int position, int new_data) {
    // Check if the position is valid
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        cout << "Memory allocation failed." << endl;
        return;
    }
    new_node->data = new_data;

    // If position is 1, insert at the beginning of the list
    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    // Traverse the list to find the node at (position - 1)
    struct Node* ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    // Check if position is beyond the end of the list
    if (ptr == NULL) {
        cout << "Position exceeds the length of the list." << endl;
        return;
    }

    // Insert the new node after the node at (position - 1)
    new_node->next = ptr->next;
    ptr->next = new_node;
}

int main() {
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout << "The linked list is: ";
    display();
    printFirstAndLast();
    printElementAtPosition(1);
    addElementAtPosition(4, 0);
    display();

    return 0;
}