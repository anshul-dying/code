#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    // Constructor
    Node(int val)
    {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function declarations
void insertAtBeginning(Node *&head, Node *&tail, int value);
void insertAtEnd(Node *&head, Node *&tail, int value);
void insertAtPosition(Node *&head, Node *&tail, int value, int pos);
void deleteFromBeginning(Node *&head, Node *&tail);
void deleteFromEnd(Node *&head, Node *&tail);
void deleteByValue(Node *&head, Node *&tail, int value);
void search(Node *head, int value);
void displayForward(Node *head);
void displayBackward(Node *tail);
void displayMenu();

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int choice, value, pos;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            insertAtBeginning(head, tail, value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            insertAtEnd(head, tail, value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            insertAtPosition(head, tail, value, pos);
            break;
        case 4:
            deleteFromBeginning(head, tail);
            break;
        case 5:
            deleteFromEnd(head, tail);
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteByValue(head, tail, value);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            search(head, value);
            break;
        case 8:
            displayForward(head);
            break;
        case 9:
            displayBackward(tail);
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

// Insert at beginning
void insertAtBeginning(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "Inserted " << value << " at beginning.\n";
}

// Insert at end
void insertAtEnd(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (!tail)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Inserted " << value << " at end.\n";
}

// Insert at position
void insertAtPosition(Node *&head, Node *&tail, int value, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning(head, tail, value);
        return;
    }

    Node *newNode = new Node(value);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i)
        temp = temp->next;

    if (!temp || !temp->next)
    {
        if (!temp->next && temp)
            insertAtEnd(head, tail, value);
        else
            cout << "Position out of bounds.\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Inserted " << value << " at position " << pos << ".\n";
}

// Delete from beginning
void deleteFromBeginning(Node *&head, Node *&tail)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Deleted " << temp->value << " from beginning.\n";
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;

    delete temp;
}

// Delete from end
void deleteFromEnd(Node *&head, Node *&tail)
{
    if (!tail)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = tail;
    cout << "Deleted " << temp->value << " from end.\n";
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete temp;
}

// Delete by value
void deleteByValue(Node *&head, Node *&tail, int value)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->value == value)
        return deleteFromBeginning(head, tail);

    if (tail->value == value)
        return deleteFromEnd(head, tail);

    Node *temp = head;
    while (temp && temp->value != value)
        temp = temp->next;

    if (!temp)
    {
        cout << value << " not found in list.\n";
        return;
    }

    cout << "Deleted " << value << " from list.\n";
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
}

// Search for element
void search(Node *head, int value)
{
    Node *temp = head;
    int pos = 1;
    bool found = false;
    while (temp)
    {
        if (temp->value == value)
        {
            cout << value << " found at position " << pos << ".\n";
            found = true;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        cout << value << " not found in list.\n";
}

// Display list forward
void displayForward(Node *head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Doubly Linked List (Forward):\n";
    while (temp)
    {
        cout << temp->value << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Display list backward
void displayBackward(Node *tail)
{
    if (!tail)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = tail;
    cout << "Doubly Linked List (Backward):\n";
    while (temp)
    {
        cout << temp->value << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// Display menu options
void displayMenu()
{
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert at Position\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from End\n";
    cout << "6. Delete by Value\n";
    cout << "7. Search for Element\n";
    cout << "8. Display Forward\n";
    cout << "9. Display Backward\n";
    cout << "0. Exit\n";
}