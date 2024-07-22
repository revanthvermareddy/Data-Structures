# Definition of a binary tree node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

"""
Approach
T.C: O(N) - where n is the number of nodes in binary tree
S.C: O(N) - auxilary space complexity


# Function to print the right boundary nodes of a binary tree
def printRightBoundary(root):
    if not root:
        return
    if root.right:
        printLeftBoundary(root.right)
        print(root.data, end=" ")
    elif root.left:
        printLeftBoundary(root.left)
        print(root.data, end=" ")

# Function to print the leaves of a binary tree
def printLeaves(root):
    if not root:
        return
    printLeaves(root.left)
    if not root.left and not root.right:
        print(root.data, end=" ")
    printLeaves(root.right)

# Function to print the left boundary nodes of a binary tree
def printLeftBoundary(root):
    if not root:
        return
    if root.left:
        print(root.data, end=" ")
        printLeftBoundary(root.left)
    elif root.right:
        print(root.data, end=" ")
        printLeftBoundary(root.right)

# Function to print the boundary nodes of a binary tree in anticlockwise order
def printBoundary(root):
    if not root:
        return
    print(root.data, end=" ")
    printLeftBoundary(root.left)
    printLeaves(root.left)
    printLeaves(root.right)
    printRightBoundary(root.right)

"""

"""
Approach using Morris Traversal
"""

# Function to print the right boundary nodes of a binary tree
def printRightBoundary(root):
    if not root:
        return
    if root.right:
        printLeftBoundary(root.right)
        print(root.data, end=" ")
    elif root.left:
        printLeftBoundary(root.left)
        print(root.data, end=" ")

# Function to print the leaves of a binary tree
def printLeaves(root):
    if not root:
        return
    printLeaves(root.left)
    if not root.left and not root.right:
        print(root.data, end=" ")
    printLeaves(root.right)

# Function to print the left boundary nodes of a binary tree
def printLeftBoundary(root):
    if not root:
        return
    if root.left:
        print(root.data, end=" ")
        printLeftBoundary(root.left)
    elif root.right:
        print(root.data, end=" ")
        printLeftBoundary(root.right)

# Function to print the boundary nodes of a binary tree in anticlockwise order
def printBoundary(root):
    if not root:
        return
    print(root.data, end=" ")
    printLeftBoundary(root.left)
    printLeaves(root.left)
    printLeaves(root.right)
    printRightBoundary(root.right)





# Driver code
if __name__ == '__main__':
    # Creating the binary tree
    root = Node(20)
    root.left = Node(8)
    root.left.left = Node(4)
    root.left.right = Node(12)
    root.left.right.left = Node(10)
    root.left.right.right = Node(14)
    root.right = Node(22)
    root.right.right = Node(25)

    # Printing the boundary nodes of the binary tree
    printBoundary(root)
