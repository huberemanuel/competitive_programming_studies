# ref: https://www.hackerrank.com/challenges/alternating-characters/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

def alternatingCharacters(s):
    # naive solution
    last = s[0]
    cnt = 0
    for i in range(1, len(s)):
        if s[i] == last:
            cnt += 1
        else:
            last = s[i]
    return cnt
