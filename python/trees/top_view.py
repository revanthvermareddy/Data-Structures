class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def __init__(self, root) -> None:
        self.root = root
    
    def printTopView(self):
        """
        T.C: O(n)
        S.C: O(n)
        """
        if not self.root:
            return
        
        hd = 0
        queue = []
        queue.append((root, hd))
        
        result = {}
        
        while(len(queue) > 0):
            node, hd = queue[0]  # take the first element

            if hd not in result:
                result[hd] = node.data
            
            if node.left:
                queue.append((node.left, hd-1))
            
            if node.right:
                queue.append((node.right, hd+1))
            
            queue.pop(0)
        
        for key, value in sorted(result.items()):
            # print(f"key: {key} -> {value}")
            print(value)


# -- driver code --
if __name__ == "__main__":
    
    """ Create following Binary Tree
         1
        / \
       2   3
        \
         4
          \
           5
            \
             6
    """
    
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.left.right.right = Node(5)
    root.left.right.right.right = Node(6)
    
    tree = Tree(root)
    
    # Ans: 2, 1, 3, 6
    tree.printTopView()
    
