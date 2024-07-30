#include <iostream>
#include <vector>
using namespace std;

class TreeNode 
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


class Heap 
{
public:
    vector<int> array;

    void insertHeap(int val) 
    {
        array.push_back(val);
        int i = array.size() - 1;
        while (i > 0 && array[(i - 1) / 2] > array[i]) 
	   {
            swap(array[(i - 1) / 2], array[i]);
            i = (i - 1) / 2;
        }
    }

    void buildHeap(vector<int>& data) 
    {
        array = data;
        for (int i = array.size() / 2 - 1; i >= 0; i--) 
	   {
            heapify(i);
        }
    }

    void heapify(int i) 
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < array.size() && array[left] < array[smallest])
            smallest = left;
        if (right < array.size() && array[right] < array[smallest])
            smallest = right;
        if (smallest != i) 
	   {
            swap(array[i], array[smallest]);
            heapify(smallest);
        }
    }

    void displayHeap() 
    {
        for (int val : array) 
	   {
            cout << val << " ";
        }
        cout << endl;
    }
};

TreeNode* insert(TreeNode* root, int val) 
{
    if (!root) 
    {
        cout << "Inserting " << val << " as root node." << endl;
        return new TreeNode(val);
    }
    if (val < root->value) 
    {
        cout << "Inserting " << val << " as left child of " << root->value << "." << endl;
        root->left = insert(root->left, val);
    } 
    else 
    {
        cout << "Inserting " << val << " as right child of " << root->value << "." << endl;
        root->right = insert(root->right, val);
    }
    return root;
}

void postOrder(TreeNode* root, vector<int>& result) 
{
    if (!root) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->value);
}

void preOrder(TreeNode* root, vector<int>& result) 
{
    if (!root) return;
    result.push_back(root->value);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

void inOrder(TreeNode* root, vector<int>& result) 
{
    if (!root) return;
    inOrder(root->left, result);
    result.push_back(root->value);
    inOrder(root->right, result);
}

int main() {
    vector<int> data;
    int n, val;

    cout << "Enter the number of nodes you want to insert into BST: ";
    cin >> n;

    cout << "Enter the nodes: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> val;
        data.push_back(val);
    }

    TreeNode* root = nullptr;

    for (int val : data) {
        root = insert(root, val);
    }

    vector<int> inOrderResult;
    inOrder(root, inOrderResult);
    cout << "In-Order Traversal: ";
    for (int val : inOrderResult) 
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> preOrderResult;
    preOrder(root, preOrderResult);
    cout << "Pre-Order Traversal: ";
    for (int val : preOrderResult) 
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> postOrderResult;
    postOrder(root, postOrderResult);
    cout << "Post-Order Traversal: ";
    for (int val : postOrderResult) 
    {
        cout << val << " ";
    }
    cout << endl;

    Heap postOrderHeap;
    for (int val : postOrderResult) 
    {
        postOrderHeap.insertHeap(val);
    }
    cout << "Min-Heap from Post-order Traversal: ";
    postOrderHeap.displayHeap();

    Heap preOrderHeap;
    preOrderHeap.buildHeap(preOrderResult);
    cout << "Min-Heap from Pre-order Traversal: ";
    preOrderHeap.displayHeap();

    return 0;
}

