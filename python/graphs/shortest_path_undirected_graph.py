'''
We need to use BFS and not DFS
'''


def shortestPath(graph, start, end):
    
    queue = [(start, 0)]
    visited = set([start])
    
    while(len(queue)>0):
        node, dist = queue.pop(0)
        if node == end: return dist
        
        for neighbour in graph[node]:
            if neighbour not in visited:
                visited.add(node)
                queue.append((neighbour, dist+1))
    
    return -1


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
        ['w', 'x'],
        ['x', 'y'],
        ['z', 'y'],
        ['z', 'v'],
        ['w', 'v']
    ]
    
    graph = buildGraph(edges)
    
    start = 'w'
    end = 'z'
    
    dist = shortestPath(graph, start, end)
    print(f'The shortest dist from start: {start} to end: {end} is dist: {dist}')