from collections import deque

def using_dfs(graph, src, dst):
    '''
    T.C : O(e)
    S.C : O(n)
    '''
    if src == dst: return True
    for neighbor in graph[src]:
        if using_dfs(graph, neighbor, dst):
            return True
    return False

def using_dfs_with_visited_array(graph, src, dst, visited=None):
    if visited is None: visited = set()
    if src == dst: return True
    visited.add(src)
    for neighbor in graph[src]:
        if neighbor not in visited:
            if using_dfs_with_visited_array(graph, neighbor, dst, visited):
                return True
    return False


def using_bfs(graph, src, dst):
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

def using_bfs_with_visited_set(graph, src, dst):
    visited = set()
    queue = deque([src])
    
    while queue:
        current = queue.popleft()
        if current == dst:
            return True
        if current not in visited:
            visited.add(current)
            queue.extend(neighbor for neighbor in graph[current] if neighbor not in visited)
    
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
    
    # res = using_dfs(graph, src, dst)
    res = using_dfs_with_visited_array(graph, src, dst)
    
    if res: print(f'There exists a path from src: {src} to dst: {dst}')
    else: print(f'There exists no path from src: {src} to dst: {dst}')
    
    # Test Case-2
    
    src = 'j'
    dst = 'f'
    
    # res = using_bfs(graph, src, dst)
    res = using_bfs_with_visited_set(graph, src, dst)
    
    if res: print(f'There exists a path from src: {src} to dst: {dst}')
    else: print(f'There exists no path from src: {src} to dst: {dst}')