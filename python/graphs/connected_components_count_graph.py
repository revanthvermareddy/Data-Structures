
def countConnectedComponents(graph):
    
    count = 0
    visited = set()
    
    for node in graph:
        if explore(graph, node, visited):
            count += 1
    
    return count

def explore(graph, node, visited):  # DFS traversal
    
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    
    if node in visited: return False
    
    visited.add(node)
    
    for neighbour in graph[node]:
        explore(graph, neighbour, visited)
    
    return True

# driver code
if __name__ == "__main__":
    
    graph = {
        '0': ['8', '1', '5'],
        '1': ['0'],
        '5': ['0', '8'],
        '8': ['0', '5'],
        '2': ['3', '4'],
        '3': ['2', '4'],
        '4': ['3', '2'],
    }
    
    # Test Case-1
    
    count = countConnectedComponents(graph)
    print(f'There a {count} connected components')