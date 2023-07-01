# https://leetcode.com/problems/linked-list-cycle/

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        '''
        1. Two pointer approach (fast and slow pointer)
        '''
        
        if not head: return False
        if not head.next: return False

        slow = head
        fast = head.next

        while(slow!=fast):
            if not fast or not fast.next: return False
            slow = slow.next  # Increment pointer by one
            fast = fast.next.next  # Increment pointer by two
        
        return True
    
        '''
        2. Dictionary approach
        '''

        # dictionary = {}
        # while head:
        #     if head in dictionary: return True
        #     else: dictionary[head]= True
        #     head = head.next
        # return False

def createLinkedList(values):
    head = ListNode(x=values[0])
    temp = head
    for i in range(1, len(values)):
        new_node = ListNode(x=values[i])
        temp.next = new_node
        temp = temp.next
    return head

def printLinkedList(head):
    if not head: return
    while(head):
        print(head.val)
        head = head.next

if __name__ == "__main__":
    
    values = [1, 2, 3, 4, 5]
    head = createLinkedList(values)
    
    printLinkedList(head)
    
    sol = Solution()
    res = sol.hasCycle(head)
    
    print(f'\nHas cycle: {res}')
