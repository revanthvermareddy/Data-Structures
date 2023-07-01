
def usingDFS(graph, src, dst, visited):
    
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    
    if src == dst: return True
    
    if src in visited: return False
    visited.add(src)
    
    for neighbour in graph[src]:
        if usingDFS(graph, neighbour, dst, visited):
            return True
    
    return False
    

def usingBFS(graph, src, dst):
    
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    
    queue = [src]
    visited = set()
    
    while (len(queue)>0):
        curr = queue.pop(0)
        if curr == dst: return True
        if curr not in visited: visited.add(curr)
        
        for neighbour in graph[curr]:
            if neighbour in visited: continue
            queue.append(neighbour)
    
    return False


# method to convert edges into adjacency list
def buildGraph(edges):
    graph = {}
    for edge in edges:
        _from, _to = edge
        if _from not in graph: graph[_from] = []
        if _to not in graph: graph[_to] = []
        graph[_from].append(_to)
        graph[_to].append(_from)
    return graph


# driver code
if __name__ == "__main__":
    
    edges = [
        ['i', 'j'],
        ['k', 'i'],
        ['m', 'k'],
        ['k', 'l'],
        ['o', 'n']
    ]
    
    graph = buildGraph(edges)
    print('graph: ', graph)
    
    # Test Case-1
    
    src = 'j'
    dst = 'm'
    
    visited = set()
    # res = usingDFS(graph, src, dst, visited)
    res = usingBFS(graph, src, dst)
    
    if res: print(f'There exists a path from src: {src} to dst: {dst}')
    else: print(f'There exists no path from src: {src} to dst: {dst}')
    
    # Test Case-2
    
    src = 'j'
    dst = 'o'
    
    visited = set()
    # res = usingDFS(graph, src, dst, visited)
    res = usingBFS(graph, src, dst)
    
    if res: print(f'There exists a path from src: {src} to dst: {dst}')
    else: print(f'There exists no path from src: {src} to dst: {dst}')