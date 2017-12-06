import math
import sys

class Node:
    def __init__(self, index, w):
        self.index = index
        self.w = w


def min_cost(ini, N, C, visiteds, city_banks, nodes):
    total = 0
    visiteds[ini] = True

    for neighbor in nodes[ini]:
        if not visiteds[neighbor.index]:
            total += min_cost(neighbor.index, N, C, visiteds, 
city_banks, nodes)
            total += math.ceil(city_banks[neighbor.index] / C) * 2 * 
neighbor.w
            city_banks[ini] += city_banks[neighbor.index]

    return total

N, C = [int(x) for x in input().split(" ")]

sys.setrecursionlimit(N + 2)

E = dict()

aux = [x for x in input().split(" ")]

for i in range(1, N + 1):
    E[i] = int(aux[i - 1])

nodes = [[] for i in range(N + 1)]

for i in range(N - 1):
    origin, destiny, v = [int(x) for x in input().split(" ")]
    nodes[origin].append(Node(destiny, v))
    nodes[destiny].append(Node(origin, v))

visiteds = [False] * (N + 1)

print(min_cost(1, N, C, visiteds, E, nodes))
