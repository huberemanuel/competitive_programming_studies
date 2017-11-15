def allLongestStrings(inputArray):

    max_length = len(inputArray[0])
    words = []
    
    for word in inputArray:
        if len(word) == max_length:
            words.append(word)
        elif len(word) > max_length:
            max_length = len(word)
            words = [word]
            
    return words
    
    
