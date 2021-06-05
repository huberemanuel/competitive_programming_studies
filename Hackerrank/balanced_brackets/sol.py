# ref: https://www.hackerrank.com/challenges/balanced-brackets/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues

def match(a, b):
    if a == "{" and b == "}":
        return True
    elif a == "(" and b == ")":
        return True
    elif a == "[" and b == "]":
        return True
    return False

def isBalanced(s):
    Q = []
    open_b = ["{", "[", "("]
    for c in s:
        if c in open_b:
            Q.append(c)
        else:
            if not Q:
                return "NO"
            else:
                open_c = Q.pop(-1)
                if not match(open_c, c):
                    return "NO"
    if not Q:
        return "YES"
    else:
        return "NO"

