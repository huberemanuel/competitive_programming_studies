# ref: https://www.hackerrank.com/challenges/tree-huffman-decoding/problem

# The main tip for this problem is to pay attention when the problem statement
# says that the node will contain a null value, it is not a None value,
# it is literally the null character from the unicode table.
# ref: https://en.wikipedia.org/wiki/List_of_Unicode_characters

def decodeHuff(root, s):
    
    i = 0
    while i < len(s):
        actual = root
    
        while not actual is None:
            if i < len(s):
                actual_ch = s[i]
            if ord(actual.data) == 0: # check if is unicode null char
                if actual_ch == "0":
                    actual = actual.left
                else:
                    actual = actual.right
            else:
                print(actual.data, end="")
                break
            i += 1
