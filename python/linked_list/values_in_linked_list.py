# node class for a linkedlist
class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.next = None

# iterative approach
def printLinkedList(head):
    '''
    T.C: O(n)
    S.C: O(1)
    '''
    curr = head
    while(curr!=None):
        print(curr.val)
        curr = curr.next

# recursive approach
def printLinkedList(head):
    '''
    T.C: O(n)
    S.C: O(n)
    '''
    if head == None: return
    print(head.val)
    printLinkedList(head.next)

# driver
if __name__ == "__main__":
    
    a = Node('A')
    b = Node('B')
    c = Node('C')
    d = Node('D')

    a.next = b;
    b.next = c;
    c.next = d;

    # A -> B -> C -> D -> NULL
    
    printLinkedList(a)