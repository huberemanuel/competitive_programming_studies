def matrixElementsSum(matrix):
    soma = 0
    
    rows = len(matrix)
    columns = len(matrix[0])
    flags = dict()
    
    for i in range(rows):
        for j in range(columns):
            if i == 0 or (matrix[i - 1][j] != 0 and j not in flags):
                soma += matrix[i][j]
            else:
                print(flags)
                print(matrix[i][j])
                flags[j] = True
            
    
    
    return soma
