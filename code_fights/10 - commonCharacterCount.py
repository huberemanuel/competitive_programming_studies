def commonCharacterCount(s1, s2):
    
    resp = 0
    
    for i in range(len(s1)):
        if s1[i] in s2:
            resp += 1
            s2 = s2.replace(s1[i], "", 1)
        
    return resp
