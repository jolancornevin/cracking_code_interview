/**
 * Problem: A binary search tree has 3 characteristics:
 *  - A node's left subtree has a lower value.
 *  - A node's right subtree has greater values.
 *  - The value of every node is distinct.
 *
 * We need to find out if a Tree given in parameter is a valid BST.
 *
 * Solution: Looping through a Tree is easily done by recursion.
*/

/*
The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/

bool checkBST(Node* root) {
    int imax = (int) ((~((unsigned int) 0)) >> 1);
    int imin = ~imax;
    return checkBSTRecursive(root, imin, imax);
}

bool checkBSTRecursive(Node* node, const int minInterval, const int maxInterval) {
    bool is_bt = true;

    if (node->data < minInterval || node->data > maxInterval)
        return false;

    if (node->left != NULL) {
        if (node->left->data >= node->data) {
            return false;
        }
        is_bt = checkBSTRecursive(node->left, minInterval, node->data);
    }
    // we don't want to keep looking if the left is false
    if (is_bt == true && node->right != NULL) {
        if (node->right->data <= node->data) {
            return false;
        }
        is_bt = checkBSTRecursive(node->right, node->data, maxInterval);
    }
    return is_bt;
}
