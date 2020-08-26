import heapq

food_times = [3, 1, 2]
k = 5
result = 0

def solution(food_times, k):
    q = []

    for i in range(len(food_times)):
        heapq.heappush(q, (food_times[i], i+1))

solution(food_times, k)