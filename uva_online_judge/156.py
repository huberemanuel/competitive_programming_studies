original = []
lowerCase = []
solution = []
ananagram = dict()

inputt = input()
if inputt == "#":
	exit
read = [x for x in inputt.split(" ")]
while read != '#':
	
	for word in read:
		
		original.append(word)
		aux = ""
		for i in range(len(word)):
			if word[i].isalpha():
				aux += word[i].lower()
				
		aux = ''.join(sorted(aux))
		lowerCase.append(aux)
		
		if aux in ananagram:
			ananagram[aux] += 1
		else:
			ananagram[aux] = 1
	
	inputt = input()
	if inputt == "#":
		break
	
	read = [x for x in inputt.split(" ")]
	
for i in range(len(lowerCase)):
	word = lowerCase[i]
	if ananagram[word] == 1:
		solution.append(original[i])
	
solution.sort()
	
for word in solution:
	print(word)

	
