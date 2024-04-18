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
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    struct Node* ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Print the first and last elements
    cout << "\nFirst element: " << head->data << endl;
    cout << "Last element: " << ptr->data << endl;
}

void printElementAtPosition(int position) {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    if (position <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    struct Node* ptr = head;
    int count = 1;

    while (ptr != NULL && count < position) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        cout << "Position exceeds the length of the list." << endl;
        return;
    }

    cout << "Element at position " << position << ": " << ptr->data << endl;
}

void addElementAtPosition(int position, int new_data) {
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        cout << "Memory allocation failed." << endl;
        return;
    }
    new_node->data = new_data;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct Node* ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Position exceeds the length of the list." << endl;
        return;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
}

void insertBeforeOddDoubles() {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    struct Node* current = head;

    while (current != NULL) {
        if (current->data % 2 != 0) {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            if (new_node == NULL) {
                cout << "Memory allocation failed." << endl;
                return;
            }
            new_node->data = 2 * current->data;

            new_node->next = current;
            if (current == head) {
                head = new_node;
            } else {
                struct Node* prev = head;
                while (prev->next != current) {
                    prev = prev->next;
                }
                prev->next = new_node;
            }
            current = current->next;
        } else {
            current = current->next;
        }
    }
}

int main() {
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout << "The linked list is: ";
    display();
    insertBeforeOddDoubles();
    cout << "The linked list is: ";
    display();
    
    return 0;
}