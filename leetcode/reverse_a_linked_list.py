# https://leetcode.com/problems/reverse-linked-list/

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        '''
        # 1. Iterative approach
        '''

        # if not head: return head

        # # example = [1, 2, 3, 4, 5]
        # # head -> 1 -> 2 -> 3 -> 4 -> 5 -> null

        # prev = None
        # curr = head

        # while curr:
        #     temp = curr.next
        #     curr.next = prev
        #     prev = curr
        #     curr = temp

        # return prev


        '''
        2. Recursive Approach
        '''

        # example = [1, 2, 3, 4, 5]
        # example = [1] -> [2, 3, 4, 5]

        def helper(head: Optional[ListNode]):
            if not head or not head.next: return head
            res = helper(head.next)
            head.next.next = head
            head.next = None
            return res
        
        if not head: return head
        return helper(head)

def createLinkedList(values):
    prev = None
    head = None
    for val in reversed(values):
        head = ListNode(val, next=prev)
        prev = head
    return head

def printLinkedList(head):
    if not head: return
    while(head):
        print(head.val)
        head = head.next
     

if __name__ == "__main__":
    
    values = [1, 2, 3, 4, 5]
    head = createLinkedList(values)
    
    print('\nBefore:')
    printLinkedList(head)
    
    sol = Solution()
    head = sol.reverseList(head)
    
    print('\nAfter:')
    printLinkedList(head)









        