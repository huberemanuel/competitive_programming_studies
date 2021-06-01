# ref: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

def isValid(s):
    c = Counter(s)
    v = c.values()
    k = set(v)

    if len(k) > 2:
        return "NO"
    elif len(k) == 1:
        return "YES"
    else:
        # len(k) == 2
        x = Counter(v)
        first, second = x.keys()
        if first > second and x[second] - 1 == 1:
            return "NO"
        elif second > first and x[first] - 1 == 1:
            return "NO"
        if min(x.values()) == 1:
            return "YES"

    return "NO"

