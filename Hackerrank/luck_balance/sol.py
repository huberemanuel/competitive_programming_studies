# ref: https://www.hackerrank.com/challenges/luck-balance/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms

def luckBalance(k, contests):
    contests.sort(reverse=True)
    sm = 0

    for i in range(len(contests)):
        if contests[i][1] == 0:
            sm += contests[i][0]
        elif k > 0:
            k -= 1
            sm += contests[i][0]
        else:
            sm -= contests[i][0]
    return sm

