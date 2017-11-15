def sortByHeight(a):    
    
    lst = sorted([x for x in a if x > 0])
    for n,i in enumerate(a):
        if i == -1:
            lst.insert(n,i)
    return lst
        
