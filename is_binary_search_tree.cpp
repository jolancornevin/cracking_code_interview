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
	return checkBSTRecursive(root);
}

bool checkBSTRecursive(Node* node) {
	bool is_bt = true;
	if (node->left != NULL) {
		if (node->left->data >= node->data) {
			return false;
		}
		is_bt = checkBSTRecursive(node->left);
	}
	// we don't want to keep looking if the left is false
	if (is_bt == true && node->right != NULL) {
		if (node->right->data <= node->data) {
			return false;
		}
		is_bt = checkBSTRecursive(node->right);
	}
	return is_bt;
}


	
					3
			2				6
		1		4		5		7

		
						20
					10
				3		15
			2				30		
		1		4				