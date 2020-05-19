if __name__ == "__main__":
    n = int(input())
    arr = []
    for _ in range(n):
        start, end = map(int, input().split())
        arr.append({"start": start, "end": end})
    arr.sort(key=lambda item: item["end"])
    
    end = 0
    count = 0
    for item in arr:
        if end <= item["start"]:
            count += 1
            end = item["end"]

    print(count)
