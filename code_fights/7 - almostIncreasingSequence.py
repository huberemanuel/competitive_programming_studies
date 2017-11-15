def almostIncreasingSequence(sequence):

    count = 0
    tam = len(sequence)
    
    for i in range(tam - 1):
        if (sequence[i] >= sequence[i + 1]):
            count += 1
        if (i + 2 < tam and sequence[i] >= sequence[i + 2]):
            count += 1
            
    return count <= 2

