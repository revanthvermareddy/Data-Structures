
def countIslands(matrix):
    
    '''
    where 
    r = # rows
    c = # cols
    T.C : O(rc)
    S.C : O(rc)
    '''
    
    count = 0
    visited = set()
    
    rows = len(matrix)
    cols = len(matrix[0])
    
    for row in range(rows):
        for col in range(cols):
            # increment count only for a new visited land
            if explore(matrix, row, col, visited):
                count += 1
    
    return count

def explore(matrix, row, col, visited):  # DFS traversal
    
    # check for row bounds and col bounds
    rowBounds = True if (0 <= row) and (row < len(matrix)) else False
    colBounds = True if (0 <= col) and (col < len(matrix[0])) else False
    if not rowBounds or not colBounds: return False
    
    # skip Waters
    if matrix[row][col] == 'W': return False
    
    # skip visited Lands
    pos = f'{row},{col}'
    if pos in visited: return False
    
    # add unvisited Land with its position
    visited.add(pos)
    
    # 4 options to traverse in 4 directions as similar to undirected graph
    explore(matrix, row - 1, col, visited)
    explore(matrix, row + 1, col, visited)
    explore(matrix, row, col - 1, visited)
    explore(matrix, row, col + 1, visited)
    
    # return after exploring a new Land
    return True

# driver code
if __name__ == "__main__":
    
    matrix = [
        ['W', 'L', 'W', 'W', 'W'],
        ['W', 'L', 'W', 'W', 'W'],
        ['W', 'W', 'W', 'L', 'W'],
        ['W', 'W', 'L', 'L', 'W'],
        ['L', 'W', 'W', 'L', 'L'],
        ['L', 'L', 'W', 'W', 'W']
    ]
    
    # Test Case-1
    
    count = countIslands(matrix)
    print(f'There a {count} islands in the graph')