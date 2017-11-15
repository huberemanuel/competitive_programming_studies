def reverseParentheses(s):

    while ')' in s:
        j = s.index(')')
        i = s.rfind('(',0,j)
        s = s[:i]+s[j-1:i:-1]+s[j+1:]
    return s