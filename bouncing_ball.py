def find_overlap(m, n, p1, d1, p2, d2):
    steps = 0

    while True:
        n1 = (p1[0] + d1[0], p1[1] + d1[1])

        
        if n1[0] < 0 or n1[0] >= m or n1[1] < 0 or n1[1] >= n:
            d1 = (-d1[0], -d1[1])

        p1 = n1

        
        n2 = (p2[0] + d2[0], p2[1] + d2[1])

        
        if n2[0] < 0 or n2[0] >= m or n2[1] < 0 or n2[1] >= n:
            d2 = (-d2[0], -d2[1])

        p2 = n2

        
        if p1 == p2:
            return steps

        steps += 1

    return "never"

m, n = map(int, input().split())
p1 = tuple(map(int, input().split()))
d1 = tuple(map(int, input().split()))
p2 = tuple(map(int, input().split()))
d2 = tuple(map(int, input().split()))

steps = find_overlap(m, n, p1, d1, p2, d2)
try:
    num = int(steps)
    print (steps+1)
except:
    print ("Never")

