#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <class T>
Node<T>* insert(Node<T>* root, T value) {
    if (root == nullptr) {
        return new Node<T>(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

template <class T>
void displayInorder(Node<T>* root) {
    if (root != nullptr) {
        displayInorder(root->left);
        cout << root->data << " ";
        displayInorder(root->right);
    }
}

template <class T>
void displayPreorder(Node<T>* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

template <class T>
void displayPostorder(Node<T>* root) {
    if (root != nullptr) {
        displayPostorder(root->left);
        displayPostorder(root->right);
        cout << root->data << " ";
    }
}

template <class T>
bool search(Node<T>* root, T value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

int main() {
    Node<int>* root = nullptr;  // Using int as template parameter
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Display Inorder\n";
        cout << "3. Display Preorder\n";
        cout << "4. Display Postorder\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                displayInorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                displayPreorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                displayPostorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value found in the tree.\n";
                } else {
                    cout << "Value not found in the tree.\n";
                }
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}