
def minimumIslandSize(matrix):
    
    '''
    T.C : O(rc)
    S.C : O(rc)
    where 
    r = # rows
    c = # cols
    '''
    
    smallest = float('inf')
    visited = set()
    
    rows = len(matrix)
    cols = len(matrix[0])
    
    for row in range(rows):
        for col in range(cols):
            # increment count only for a new visited land
            size = exploreSize(matrix, row, col, visited)
            if size > 0 and size < smallest:
                smallest = size
    
    return smallest

def exploreSize(matrix, row, col, visited):  # DFS traversal
    
    # check for row bounds and col bounds
    rowInbounds = True if (0 <= row) and (row < len(matrix)) else False
    colInbounds = True if (0 <= col) and (col < len(matrix[0])) else False
    if not rowInbounds or not colInbounds: return 0
    
    # skip Waters
    if matrix[row][col] == 'W': return 0
    
    # skip visited Lands
    pos = f'{row},{col}'
    if pos in visited: return 0
    
    # add unvisited Land with its position
    visited.add(pos)
    size = 1
    
    # 4 options to traverse in 4 directions as similar to undirected graph and collect sizes to add it to the overall island size
    size += exploreSize(matrix, row - 1, col, visited)
    size += exploreSize(matrix, row + 1, col, visited)
    size += exploreSize(matrix, row, col - 1, visited)
    size += exploreSize(matrix, row, col + 1, visited)
    
    # return after exploring a new Land
    return size

# driver code
if __name__ == "__main__":
    
    # Test Case-1
    
    matrix = [
        ['W', 'L', 'W', 'W', 'W'],
        ['W', 'L', 'W', 'W', 'W'],
        ['W', 'W', 'W', 'L', 'W'],
        ['W', 'W', 'L', 'L', 'W'],
        ['L', 'W', 'W', 'L', 'L'],
        ['L', 'L', 'W', 'W', 'W']
    ]
    
    count = minimumIslandSize(matrix)
    print(f'The size of the minimum island is: {count} in the grid graph / matrix')