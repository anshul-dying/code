#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function declarations
Node *insertNode(Node *root, int value);
Node *deleteNode(Node *root, int value);
Node *findMin(Node *root);
Node *findMax(Node *root);
bool searchNode(Node *root, int value);
void inOrder(Node *root);
void preOrder(Node *root);
void postOrder(Node *root);
void displayMenu();

int main()
{
    Node *root = nullptr;
    int choice, value;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "Inserted " << value << " into the BST.\n";
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (searchNode(root, value))
                cout << value << " found in the BST.\n";
            else
                cout << value << " not found in the BST.\n";
            break;
        case 4:
            cout << "In-order traversal:\n";
            inOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Pre-order traversal:\n";
            preOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Post-order traversal:\n";
            postOrder(root);
            cout << endl;
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

// Insert node into BST
Node *insertNode(Node *root, int value)
{
    if (root == nullptr)
        return new Node(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}

// Find minimum node in BST (used during deletion)
Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Find maximum node in BST
Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

// Delete node from BST
Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
    {
        cout << value << " not found in BST.\n";
        return root;
    }

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else
    {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr)
        {
            cout << "Deleted " << value << " from BST.\n";
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            cout << "Deleted " << value << " from BST.\n";
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            cout << "Deleted " << value << " from BST.\n";
            delete root;
            return temp;
        }
        // Case 3: Two children
        else
        {
            Node *temp = findMin(root->right);                  // Get inorder successor
            root->value = temp->value;                          // Copy value
            root->right = deleteNode(root->right, temp->value); // Delete duplicate
        }
    }
    return root;
}

// Search for a value in BST
bool searchNode(Node *root, int value)
{
    if (root == nullptr)
        return false;
    if (root->value == value)
        return true;
    else if (value < root->value)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

// In-order traversal (Left - Root - Right)
void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

// Pre-order traversal (Root - Left - Right)
void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal (Left - Right - Root)
void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}

// Display menu options
void displayMenu()
{
    cout << "1. Insert Node\n";
    cout << "2. Delete Node\n";
    cout << "3. Search Node\n";
    cout << "4. In-order Traversal\n";
    cout << "5. Pre-order Traversal\n";
    cout << "6. Post-order Traversal\n";
    cout << "0. Exit\n";
}