#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
void insertAtHead(Node<T>*& head, T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

template <class T>
void insertAtTail(Node<T>*& head, T val) {
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <class T>
void insertAtPos(Node<T>*& head, T val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }
    Node<T>* newNode = new Node<T>(val);
    Node<T>* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

template <class T>
void deleteAtPos(Node<T>*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node<T>* temp = head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Node<T>* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

template <class T>
void display(Node<T>* head) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
void deleteList(Node<T>*& head) {
    Node<T>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node<int>* head = nullptr;
    int choice, value, position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(head, value);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertAtTail(head, value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                insertAtPos(head, value, position);
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAtPos(head, position);
                break;
            case 5:
                display(head);
                break;
            case 6:
                deleteList(head);
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
