#include <iostream>
#include <string>

struct Node {
    int id;
    std::string title;
    Node* prev;
    Node* next;

    Node(int id, const std::string& title) : id(id), title(title), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int id, const std::string& title) {
        Node* new_node = new Node(id, title);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void deleteNode(int id) {
        Node* current = head;
        while (current) {
            if (current->id == id) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void display() const {
        Node* current = head;
        while (current) {
            std::cout << "ID: " << current->id << ", Title: " << current->title << std::endl;
            current = current->next;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    DoublyLinkedList list;

    list.append(1, "The Catcher in the Rye");
    list.append(2, "To Kill a Mockingbird");
    list.append(3, "1984");

    std::cout << "List after adding 3 books:" << std::endl;
    list.display();

    list.deleteNode(2);

    std::cout << "List after deleting the book with ID 2:" << std::endl;
    list.display();

    return 0;
}
