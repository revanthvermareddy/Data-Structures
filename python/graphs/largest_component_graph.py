
def largestComponent(graph):
    
    largest = 0
    visited = set()
    
    for node in graph:
        size = exploreSize(graph, node, visited)
        if size > largest:
            largest = size
    
    return largest

def exploreSize(graph, node, visited):  # DFS traversal
    
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    
    if node in visited: return 0
    
    visited.add(node)
    
    size = 1
    
    for neighbour in graph[node]:
        size += exploreSize(graph, neighbour, visited)
    
    return size

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
    
    count = largestComponent(graph)
    print(f'The largest components size is: {count}')