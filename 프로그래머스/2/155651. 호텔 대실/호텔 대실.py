import heapq

def time_to_minutes(time):
    hours, minutes = map(int, time.split(":"))
    return hours * 60 + minutes

def solution(book_time):
    intervals = [(time_to_minutes(start), time_to_minutes(end) + 10) for start, end in book_time]
    intervals.sort()

    room_heap = []
    for start, end in intervals:
        if room_heap and room_heap[0] <= start:
            heapq.heappop(room_heap)
        heapq.heappush(room_heap, end)
    
    return len(room_heap)
