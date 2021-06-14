# ref: https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&page=9

def minimumSwaps(arr):
    v_k = {v:i for i,v in enumerate(arr)}
    
    swap = 0
    
    for i in range(len(arr)):
        if arr[i] == i + 1:
            continue
        ori_i = arr[i]
        value_aux = i+1 # 
        pos_aux = v_k[i+1] # 3
        arr[v_k[i+1]], arr[i] = arr[i], arr[v_k[i+1]] # 1 3 4 2 5
        v_k[ori_i] = pos_aux
        v_k[value_aux] = i
	# Do not uncomment the following line, it will haunt you.
        # print(arr, v_k)
        
        swap += 1
    
    return swap

