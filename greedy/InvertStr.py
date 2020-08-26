data = input()
temp = data[0]
count = 1

for i in range(1, len(data)):
    if temp != data[i]:
        count += 1
        temp = data[i]
print(int(count/2))