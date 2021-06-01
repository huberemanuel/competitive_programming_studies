# ref: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs

import queue

class Graph:
    def __init__(self, n: int):
        self.n = n 
        self.nodes = range(n)
        self.edges = []
        for i in range(n):
            self.edges.append([])
        
    def connect(self, origin: int, destiny: int):
        self.edges[origin].append(destiny)
        self.edges[destiny].append(origin)
            
    def bfs(self, origin: int):
        Q = queue.Queue()
        Q.put(origin) 
        costs = [-1 for x in range(self.n)]
        costs[origin] = 0
        
        while not Q.empty():
            actual = Q.get()
    
            for neighbor in self.edges[actual]:
                if costs[neighbor] == -1:
                    costs[neighbor] = costs[actual] + 6
                    Q.put(neighbor) 
    
        return costs
            
    def find_all_distances(self, s: int):
        costs = self.bfs(s)
        costs.pop(s)
        print(" ".join(map(str, costs)))

t = int(input())
for i in range(t):
    n,m = [int(value) for value in input().split()]
    graph = Graph(n)
    for i in range(m):
        x,y = [int(x) for x in input().split()]
        graph.connect(x-1,y-1) 
    s = int(input())
    graph.find_all_distances(s-1)
