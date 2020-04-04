def dis(h1, h2):
    return (h1 - h2)**2


if __name__ == "__main__":
    n = int(input())
    H = [0] + list(map(int, input().split()))
    H.sort()
    
    res = 0
    i, j = 0, n
    while True:
        if i >= j:
            break
        res += dis(H[i], H[j])
        i += 1
        if i >= j:
            break
        res += dis(H[i], H[j])
        j -= 1

    print(res)
