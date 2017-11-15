def makeArrayConsecutive2(statues):
    a = max(statues)
    b = min(statues)
    return a - b - len(statues) + 1
