n, m = map(int, input().split())

nodes = [i for i in range(n + 1)]
edges = []


def find_set(num):
    if nodes[num] != num:
        nodes[num] = find_set(nodes[num])
    return nodes[num]


for i in range(m):
    x, y, z = map(int, input().split())
    edges.append((x, y, z))

edges.sort(key=lambda item: item[2])

res = 0
count = 0

for edge in edges:
    lp = find_set(edge[0])
    rp = find_set(edge[1])

    if lp != rp:
        nodes[lp] = rp
        res += edge[2]
        count += 1
        if count == n - 1:
            break

print(res)
