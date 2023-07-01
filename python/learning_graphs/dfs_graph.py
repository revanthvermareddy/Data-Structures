# Adjacency List (we use HashMap Data Structure)

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

# driver code
if __name__ == "__main__":
    graph = {
        'a': ['b', 'c'],
        'b': ['d'],
        'c': ['e'],
        'd': [],
        'e': ['b'],
        'f': ['d']
    }
    depthFirstStack(graph, 'a') 
