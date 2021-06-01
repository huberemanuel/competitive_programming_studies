# ref: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

from collections import Counter

def makeAnagram(a, b):
    c1 = Counter(a)
    c2 = Counter(b)
    diff = 0
    
    for key, value in c1.items():
        if not key in c2.keys():
            diff += value
        elif c2[key] != value:
            diff += abs(value - c2[key])
            
    for key, value in c2.items():
        if not key in c1.keys():
            diff += value
        
    return diff
