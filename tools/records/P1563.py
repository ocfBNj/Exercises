if __name__ == "__main__":
    person_count, command_count = map(int, input().split())
    arr = [None] * person_count

    for i in range(person_count):
        coor, name = input().split()
        arr[i] = (1 if coor == '0' else -1, name)
    
    index = 0

    for _ in range(command_count):
        coor, count = input().split()
        if coor == '0':
            index = (index + person_count - arr[index][0]*int(count)) % person_count
        else:
            index = (index + person_count + arr[index][0]*int(count)) % person_count

    print(arr[index][1])
