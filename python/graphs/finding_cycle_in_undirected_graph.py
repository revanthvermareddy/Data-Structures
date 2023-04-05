from collections import defaultdict

class Graph():
    def __init__(self, vertices) -> None:
        self.graph = defaultdict(list)
        self.V = vertices
    
    def addEdge(self, u, v):
        # add edge from u -> v
        self.graph[u].append(v)
        # add edge from v -> u
        self.graph[v].append(u)
    
    def isCyclicUtil(self, v, visited, parent):
        visited[v] = True
        
        for neighbour in self.graph[v]:
            if visited[neighbour] == False:
                if self.isCyclicUtil(neighbour, visited, v):
                    return True
            elif neighbour != parent:
                return True
        
        return False
    
    def isCyclic(self):
        '''
        T.C: O(V+E)
        S.C: O(V)
        '''
        visited  = [False] * (self.V+1)  # mark all the vertices as unvisited
        for node in range(self.V):  # T.C: O(V+E)
            if visited[node] == False:
                if self.isCyclicUtil(node, visited, -1):
                    return True

# driver code
def main():
    g = Graph(5)
    g.addEdge(1, 0)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(0, 3)
    g.addEdge(3, 4)
    
    if g.isCyclic(): print("Graph contains cycle")
    else: print("Graph doesn't contains cycle")
    
    g1 = Graph(3)
    g1.addEdge(0, 1)
    g1.addEdge(1, 2)
    
    if g1.isCyclic(): print("Graph contains cycle")
    else: print("Graph doesn't contains cycle")

if __name__ == "__main__":
    main()