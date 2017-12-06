n = int(input())
cont = n
contadorEscala = []
notas = {0: "do", 1: "do#", 2: "re", 3: "re#", 4: "mi", 5: "fa", 6: 
"fa#", 7: "sol", 8: "sol#", 9: "la", 10: "la#", 11: "si"}

for i in range(0, 12):
    contadorEscala.append(0)

escalas = []

for i in range(0, 12):
    escalas.append([])
    for j in range(0, 12):
        escalas[i].append(False)

for i in range(0, 12):
    escalas[i][i] = True
    escalas[i][(i + 2) % 12] = True
    escalas[i][(i + 4) % 12] = True
    escalas[i][(i + 5) % 12] = True
    escalas[i][(i + 7) % 12] = True
    escalas[i][(i + 9) % 12] = True
    escalas[i][(i + 11) % 12] = True

while n:
    n -= 1
    aux = int(input())

    aux = aux % 12 if aux % 12 != 0 else 12

    for i in range(0, 12):
        if escalas[i][aux - 1]:
            contadorEscala[i] += 1

if max(contadorEscala) == cont:
    print(notas[contadorEscala.index(max(contadorEscala))])
else:
    print("desafinado")

