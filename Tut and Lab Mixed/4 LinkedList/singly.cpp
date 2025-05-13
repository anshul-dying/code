#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int value;
    Node *next;

    // Public constructor for easy initialization
    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

// Function declarations
void insertAtBeginning(Node *&head, int value);
void insertAtEnd(Node *&head, int value);
void insertAtPosition(Node *&head, int value, int pos);
void deleteFromBeginning(Node *&head);
void deleteFromEnd(Node *&head);
void deleteByValue(Node *&head, int value);
void search(Node *head, int value);
void display(Node *head);
void displayMenu();

int main()
{
    Node *head = nullptr;
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
            insertAtBeginning(head, value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            insertAtEnd(head, value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            insertAtPosition(head, value, pos);
            break;
        case 4:
            deleteFromBeginning(head);
            break;
        case 5:
            deleteFromEnd(head);
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteByValue(head, value);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            search(head, value);
            break;
        case 8:
            display(head);
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
void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at beginning.\n";
}

// Insert at end
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at end.\n";
}

// Insert at position
void insertAtPosition(Node *&head, int value, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node *newNode = new Node(value);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Position out of bounds.\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at position " << pos << ".\n";
}

// Delete from beginning
void deleteFromBeginning(Node *&head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Deleted " << temp->value << " from beginning.\n";
    head = head->next;
    delete temp;
}

// Delete from end
void deleteFromEnd(Node *&head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    if (!head->next)
    {
        cout << "Deleted " << head->value << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next)
        temp = temp->next;

    cout << "Deleted " << temp->next->value << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}

// Delete by value
void deleteByValue(Node *&head, int value)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->value == value)
    {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = head;
    while (temp->next && temp->next->value != value)
        temp = temp->next;

    if (!temp->next)
    {
        cout << value << " not found in list.\n";
        return;
    }

    Node *toDelete = temp->next;
    cout << "Deleted " << value << " from list.\n";
    temp->next = toDelete->next;
    delete toDelete;
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

// Display list
void display(Node *head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Linked List:\n";
    while (temp)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
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
    cout << "8. Display List\n";
    cout << "0. Exit\n";
}