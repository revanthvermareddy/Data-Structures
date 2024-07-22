# python3 code for segment tree with sum
# range and update query
A = []
ST = []

# T.C: O(N)  # The building operation takes O(N) time
def build(node: int, start: int, end: int):
    global A, ST

    # Leaf node where start == end
    if (start == end):
        ST[node] = A[start]
    else:
        # Find the middle element to split the array into two halves
        mid = (start + end) // 2
        # Recursively travel the left half
        build(2 * node, start, mid)
        # Recursively travel the right half
        build(2 * node + 1, mid + 1, end)
        # Storing the sum of both the children into the parent
        ST[node] = ST[2 * node] + ST[2 * node + 1]

# T.C: O(logN)  # The query operation takes O(logN) time
def query(node: int, start: int, end: int, l: int, r: int):
    global A, ST
    
    # range represented by a node is completely outside the given range
    if(r < start or end < l):
        return 0
    
    # range represented by a node is completely inside the given range
    if(l <= start and end <= r):
        return ST[node]
    
    # range represented by a node is partially inside and partially outside the given range, then recursively traverse left and right and find the node
    mid = (start + end) // 2
    p1 = query(2*node, start, mid, l, r)
    p2 = query(2*node+1, mid+1, end, l, r)
    return (p1 + p2)

# T.C: O(logN)  # Each update is performed in O(logN) time
def update(node: int, start: int, end: int, index: int, increment: int):
    global A, ST
    
    # Find the lead node and update its value
    if (start == end):
        A[index] += increment
        ST[node] += increment
    else:
        # Find the mid
        mid = (start + end) // 2
 
        # If node value index is at the left part then update the left part
        if (start <= index and index <= mid):
            update(2 * node, start, mid, index, increment)
        # If node value index is at the right part then update the right part
        else:
            update(2 * node + 1, mid + 1, end, index, increment)
 
        # Store the information in parents
        ST[node] = ST[2 * node] + ST[2 * node + 1]

# Driver code
# T.C: O(N)
# S.C: O(4*N) i.e, in total 2*n leaf nodes & As the total number of nodes is about twice the number of leaf nodes, the total space complexity of the segment tree is O(4n)
if __name__ == "__main__":
 
    n = 6
    A = [0, 1, 3, 5, -2, 3]
    print(f'Given array: {A}')
    
    # Create a segment tree of size 4*n
    ST = [0 for _ in range(4*n)]
 
    # Build a segment tree
    build(node=1, start=0, end=n-1)
    print(f"Sum of values in range 0-4 are: {query(node=1, start=0, end=n-1, l=0, r=4)}")
 
    # Update the value at idx = 1 by 100 thus becoming 101
    update(node=1, start=0, end=n-1, index=1, increment=100)
    print(f'Updated array: {A}')
    print("Value at index 1 increased by 100")
    print(f"sum of value in range 1-3 are: {query(node=1, start=0, end=n-1, l=1, r=3)}")