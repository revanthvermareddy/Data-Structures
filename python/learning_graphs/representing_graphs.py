# Adjacency List (we use HashMap Data Structure)


graph = {
    'a': ['b', 'c'],
    'b': ['d'],
    'c': ['e'],
    'd': [],
    'e': ['b'],
    'f': ['d']
}

def depthFirstStack(graph, source):
    
    stack = [source]
    
    visted = set()
    
    while len(stack) > 0:
        current = stack.pop()
        
        if current in visted: continue
        
        print(current)
        
        # add the neighbours into stack
        for neighbour in graph[current]:
            stack.append(neighbour)
        
        visted.add(current)

# depthFirstStack(graph, 'a') 



def depthFirstStack(graph, source):
    print(source)
    for neighbour in graph[source]:
        depthFirstStack(graph, neighbour)

        
depthFirstStack(graph, 'a')   
        
        