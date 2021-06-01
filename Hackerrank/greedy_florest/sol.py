# ref: https://www.hackerrank.com/challenges/greedy-florist/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms

def getMinimumCost(k, c):
    c.sort(reverse=True)
    k_i = 0
    total = 0
    for i in range(len(c)):
        total += (math.floor(k_i/k) + 1) * c[i]
        k_i += 1
    return total

