M, N = map(int, input().split())
data = list(map(int, input().split()))
result = 0

data.sort()

for i in range(M):
    for j in range(i+1, M):
        if data[i] != data[j]:
            result += 1
        else:
            continue
print(result)