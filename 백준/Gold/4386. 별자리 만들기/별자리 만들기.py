import math

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            return True
        return False

def kruskal(n, edges):
    uf = UnionFind(n)
    mst_cost = 0
    mst_edges = 0
    
    for cost, u, v in edges:
        if uf.union(u, v):
            mst_cost += cost
            mst_edges += 1
            if mst_edges == n - 1:
                break
    
    return mst_cost

def solve():
    n = int(input())
    stars = [tuple(map(float, input().split())) for _ in range(n)]
    
    edges = []
    
    for i in range(n):
        for j in range(i + 1, n):
            x1, y1 = stars[i]
            x2, y2 = stars[j]
            distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
            edges.append((distance, i, j))
    
    edges.sort()
    
    mst_cost = kruskal(n, edges)
    
    print(f"{mst_cost:.2f}")

solve()
