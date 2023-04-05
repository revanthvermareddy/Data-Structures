from collections import defaultdict

class Graph():
    def __init__(self, vertices) -> None:
        self.graph = defaultdict(list)
        self.V = vertices
    
    def addEdge(self, u, v):
        # add edge from u -> v
        self.graph[u].append(v)
    
    def isCyclicUtil(self, v, visited, recStack):
        visited[v]  = True
        recStack[v] = True
        
        for neighbour in self.graph[v]:
            if visited[neighbour] == False:
                if self.isCyclicUtil(neighbour, visited, recStack):
                    return True
            elif visited[neighbour] == True:
                return True
        
        recStack[v] = False
        return False
    
    def isCyclic(self):
        '''
        T.C: O(V+E)
        S.C: O(V)
        '''
        visited  = [False] * (self.V+1)  # mark all the vertices as unvisited
        recStack = [False] * (self.V+1)
        for node in range(self.V):
            if visited[node] == False:
                if self.isCyclicUtil(node, visited, recStack):
                    return True

# driver code
def main():
    g = Graph(4)
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(3, 3)
    
    if g.isCyclic(): print("Graph contains cycle")
    else: print("Graph doesn't contains cycle")

if __name__ == "__main__":
    main()