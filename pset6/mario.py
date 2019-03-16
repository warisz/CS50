while True:
    times = input("Height: ")
    if times.isdigit() and int(times)>0 and int(times)<=8:
        times = int(times)
        break

ws = times-1
for i in range(times):

    #left
    print(" "*ws + "#"*(i+1), end="  ")

    #right
    print("#"*(i+1))

    ws-=1

