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
int height(Node *node);
int getBalanceFactor(Node *node);
Node *rotateRight(Node *y);
Node *rotateLeft(Node *x);
Node *insertNode(Node *node, int value);
Node *deleteNode(Node *root, int value);
Node *findMin(Node *node);
bool searchNode(Node *root, int value);
void inOrder(Node *root);
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
            cout << "Inserted " << value << " into AVL tree.\n";
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
                cout << value << " found in the AVL tree.\n";
            else
                cout << value << " not found in the AVL tree.\n";
            break;
        case 4:
            cout << "In-order traversal:\n";
            inOrder(root);
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

// Get height of node
int height(Node *node)
{
    if (!node)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

// Get balance factor of node
int getBalanceFactor(Node *node)
{
    if (!node)
        return 0;
    return height(node->left) - height(node->right);
}

// Right rotation
Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    return x;
}

// Left rotation
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    return y;
}

// Insert node and rebalance
Node *insertNode(Node *node, int value)
{
    if (!node)
        return new Node(value);

    if (value < node->value)
        node->left = insertNode(node->left, value);
    else if (value > node->value)
        node->right = insertNode(node->right, value);
    else
        return node; // No duplicates allowed

    // Update height
    int lh = height(node->left);
    int rh = height(node->right);

    // Rebalance
    int balance = getBalanceFactor(node);

    // Left Heavy
    if (balance > 1)
    {
        if (value < node->left->value)
        {
            // Left-Left
            return rotateRight(node);
        }
        else
        {
            // Left-Right
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right Heavy
    if (balance < -1)
    {
        if (value > node->right->value)
        {
            // Right-Right
            return rotateLeft(node);
        }
        else
        {
            // Right-Left
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

// Find minimum node in subtree
Node *findMin(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

// Delete node and rebalance
Node *deleteNode(Node *root, int value)
{
    if (!root)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else
    {
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;

            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if (!root)
        return root;

    // Rebalance
    int balance = getBalanceFactor(root);

    int lh = height(root->left);
    int rh = height(root->right);

    // Rebalancing cases
    if (balance > 1)
    {
        if (getBalanceFactor(root->left) >= 0)
            return rotateRight(root);
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balance < -1)
    {
        if (getBalanceFactor(root->right) <= 0)
            return rotateLeft(root);
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// Search for a value in AVL tree
bool searchNode(Node *root, int value)
{
    if (!root)
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
    if (root)
    {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

// Display menu options
void displayMenu()
{
    cout << "1. Insert Node\n";
    cout << "2. Delete Node\n";
    cout << "3. Search Node\n";
    cout << "4. In-order Traversal\n";
    cout << "0. Exit\n";
}