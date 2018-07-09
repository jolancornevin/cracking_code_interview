"""
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'

/!\ ASSERTIONS: 
  - I can use regex.
"""
import re

RE_NODE_PATTERN = re.compile('\[(.*?), (\[.*\]|\(None\)), (\[.*\]|\(None\))\]')
NO_NODE = '(None)'

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        return "{}: ({}, {})".format(self.val, self.left, self.right)

def serialize(node):
    """
    Serializes the tree into a string. The format is (val, (right_node), (left_node)) recursivly.
    """
    return '[{}, {}, {}]'.format(node.val, serialize(node.left) if node.left else NO_NODE, serialize(node.right) if node.right else NO_NODE)

def extract_val_from_str(str):
    if not  RE_NODE_PATTERN.match(str):
        print str

    return RE_NODE_PATTERN.match(str).groups()

def recursive_deserialize(val, left, right):
    right = recursive_deserialize(*extract_val_from_str(right)) if right and right != NO_NODE else None
    left =  recursive_deserialize(*extract_val_from_str(left)) if left and left != NO_NODE else None

    return Node(val, left, right)

def deserialize(str):
    """
    Deserialize a string into a tree.
    """
    val, left, right = extract_val_from_str(str)
    return recursive_deserialize(val, left, right) 
    
def main():
    print "Starting script"

    node = Node('root', Node('left', Node('left.left')), Node('right'))

    assert deserialize(serialize(node)).left.left.val == 'left.left'

    print "Success !"

if __name__ == "__main__":
    main()
