# ref: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

def lca(root, v1, v2):
    actual = root
    while True:
        if v1 < actual.info:
            if v2 >= actual.info:
                return actual
            else:
                actual = actual.left
        elif v1 > actual.info:
            if v2 < actual.info:
                return actual
            else:
                actual = actual.right
        else:
            return actual

