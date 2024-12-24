import math as m
samples = []
centroids = []

n = int(input("Enter number of samples: "))

for i in range(n):
    a = int(input("Enter X-coordinate: "))
    b = int(input("Enter Y-coordinate: "))
    c = input("Is it a centroid?(Y/N): ").lower()
    if c == 'y' and len(centroids) < 2:
        centroids.append((a,b))
    elif c == 'y' and len(centroids) == 2:
        print("Max is 2, not adding")
    samples.append((a,b))

prev1 = []
prev2 = []

while True:
    c1x, c1y, c2x, c2y = (0, 0, 0, 0)
    group1 = []
    group2 = []
    for i in range(n):
        d1 = m.sqrt((centroids[0][0] - samples[i][0])**2 + (centroids[0][1] - samples[i][1])**2)
        d2 = m.sqrt((centroids[1][0] - samples[i][0])**2 + (centroids[1][1] - samples[i][1])**2)
        if d1 <= d2:
            group1.append(samples[i])
            c1x += samples[i][0]
            c1y += samples[i][1]
        else:
            group2.append(samples[i])
            c2x += samples[i][0]
            c2y += samples[i][1]

    c1x, c1y, c2x, c2y = (c1x/len(group1), c1y/len(group1), c2x/len(group2), c2y/len(group2))
    centroids = [(c1x,c1y), (c2x,c2y)]
    if prev1 == group1 and prev2 == group2:
        break
    prev1 = group1
    prev2 = group2

print(centroids)
print(f"Group 1: {group1}\nGroup 2: {group2}")
