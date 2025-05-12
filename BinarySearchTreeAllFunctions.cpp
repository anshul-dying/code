// Lab 5

// Binary Search Tree -

// Insert,  Delete node &

// A. Recursive

// Inorder Tree Traversal
// Preorder Tree Traversal
// Postorder Tree Traversal
// various Tree functions like mirror image,count

// B. Non Recursive traversal for all traversal

#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class BST
{
private:
    Node<T> *root;

    Node<T> *insertRec(Node<T> *node, T value)
    {
        if (node == nullptr)
            return new Node<T>(value);
        if (value < node->data)
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);
        return node;
    }

    Node<T> *deleteRec(Node<T> *node, T value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = deleteRec(node->left, value);
        else if (value > node->data)
            node->right = deleteRec(node->right, value);
        else
        {
            if (node->left == nullptr)
            {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            Node<T> *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    Node<T> *minValueNode(Node<T> *node)
    {
        Node<T> *current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    // Recursive Traversals
    void inorderRec(Node<T> *node)
    {
        if (node)
        {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node<T> *node)
    {
        if (node)
        {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node<T> *node)
    {
        if (node)
        {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }

    // Utility Functions
    Node<T> *mirrorRec(Node<T> *node)
    {
        if (node)
        {
            swap(node->left, node->right);
            mirrorRec(node->left);
            mirrorRec(node->right);
        }
        return node;
    }

    int countRec(Node<T> *node)
    {
        if (!node)
            return 0;
        return 1 + countRec(node->left) + countRec(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(T value)
    {
        root = insertRec(root, value);
    }

    void remove(T value)
    {
        root = deleteRec(root, value);
    }

    // Recursive Traversals
    void inorder()
    {
        inorderRec(root);
        cout << endl;
    }

    void preorder()
    {
        preorderRec(root);
        cout << endl;
    }

    void postorder()
    {
        postorderRec(root);
        cout << endl;
    }

    // Non-Recursive Traversals
    void inorderIter()
    {
        stack<Node<T> *> s;
        Node<T> *curr = root;
        while (curr || !s.empty())
        {
            while (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    void preorderIter()
    {
        if (!root)
            return;
        stack<Node<T> *> s;
        s.push(root);
        while (!s.empty())
        {
            Node<T> *node = s.top();
            s.pop();
            cout << node->data << " ";
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
        cout << endl;
    }

    void postorderIter()
    {
        if (!root)
            return;
        stack<Node<T> *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            Node<T> *node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }

    void mirror()
    {
        root = mirrorRec(root);
    }

    int count()
    {
        return countRec(root);
    }
};

int main()
{
    BST<int> tree;
    int choice, value;

    while (true)
    {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder (Recursive)\n";
        cout << "4. Preorder (Recursive)\n";
        cout << "5. Postorder (Recursive)\n";
        cout << "6. Inorder (Iterative)\n";
        cout << "7. Preorder (Iterative)\n";
        cout << "8. Postorder (Iterative)\n";
        cout << "9. Mirror Tree\n";
        cout << "10. Count Nodes\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.remove(value);
            break;
        case 3:
            cout << "Inorder (Recursive): ";
            tree.inorder();
            break;
        case 4:
            cout << "Preorder (Recursive): ";
            tree.preorder();
            break;
        case 5:
            cout << "Postorder (Recursive): ";
            tree.postorder();
            break;
        case 6:
            cout << "Inorder (Iterative): ";
            tree.inorderIter();
            break;
        case 7:
            cout << "Preorder (Iterative): ";
            tree.preorderIter();
            break;
        case 8:
            cout << "Postorder (Iterative): ";
            tree.postorderIter();
            break;
        case 9:
            tree.mirror();
            cout << "Tree mirrored successfully\n";
            break;
        case 10:
            cout << "Number of nodes: " << tree.count() << endl;
            break;
        case 11:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}