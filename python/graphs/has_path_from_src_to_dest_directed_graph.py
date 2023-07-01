
def usingDFS(graph, src, dst):
    
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    
    if src == dst: return True
    
    for neighbour in graph[src]:
        if usingDFS(graph, neighbour, dst):
            return True
    
    return False
    

def usingBFS(graph, src, dst):
    
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    
    queue = [src]
    
    while (len(queue)>0):
        curr = queue.pop(0)
        if curr == dst: return True
        
        for neighbour in graph[curr]:
            queue.append(neighbour)
    
    return False


# driver code
if __name__ == "__main__":
    
    graph = {
        'f': ['g', 'i'],
        'g': ['h'],
        'i': ['g', 'k'],
        'j': ['i'],
        'k': [],
        'h': []
    }
    
    # Test Case-1
    
    src = 'f'
    dst = 'k'
    
    res = usingDFS(graph, src, dst)
    # res = usingBFS(graph, src, dst)
    
    if res: print(f'There exists a path from src: {src} to dst: {dst}')
    else: print(f'There exists no path from src: {src} to dst: {dst}')
    
    # Test Case-2
    
    src = 'j'
    dst = 'f'
    
    # res = usingDFS(graph, src, dst)
    res = usingBFS(graph, src, dst)
    
    if res: print(f'There exists a path from src: {src} to dst: {dst}')
    else: print(f'There exists no path from src: {src} to dst: {dst}')