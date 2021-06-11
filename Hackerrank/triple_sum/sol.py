# ref: https://www.hackerrank.com/challenges/triple-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search

from bisect import bisect_left

def triplets(a, b, c):
    a = sorted(set(a))
    b = sorted(set(b))
    c = sorted(set(c))
    total = 0

    for q in b:
        p = bisect_left(a, q)
        if (p == 0 and a[0] != q):
            continue
        elif p == len(a) or a[p] != q:
            p -= 1
        p += 1

        r = bisect_left(c, q)
        if (r == 0 and c[0] != q):
            continue
        elif r == len(c) or c[r] != q:
            r -= 1
        r += 1

        total += p * r

    return total

