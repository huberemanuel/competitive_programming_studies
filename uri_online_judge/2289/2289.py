
while True:

    st = input()

    X, Y = [int(x) for x in st.split(" ")]

    if X == 0 and Y == 0:
        break

    i = 0
    dist = 0

    while i < 64:
        if (X & (1 << i)) ^ (Y & (1 << i)):
            dist += 1
        i += 1

    print(dist)
