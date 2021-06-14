# ref: https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

def minimumBribes(q):
    swaps = 0
    A = range(len(q))
    
    for i in range(len(q) - 1, 0, -1):
        if q[i] == i + 1:
            continue
        if q[i-1] == i + 1:
            q[i-1], q[i] = q[i], q[i-1]
            swaps += 1
        elif i > 0 and q[i - 2] == i + 1:
            q[i-2], q[i-1] = q[i-1], q[i-2]
            q[i-1], q[i] = q[i], q[i-1]
            swaps += 2
        else:
            print("Too chaotic")
            return
        
    print(swaps)

