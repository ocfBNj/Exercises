if __name__ == "__main__":
    elements = list(map(int, input().split()))
    print(2**(len(elements) - 1) * sum(elements))
