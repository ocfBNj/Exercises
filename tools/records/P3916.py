from collections import deque


class Node:
    def __init__(self):
        self.v = 0
        self.nexts = []  # list[int]


def bfs(node: Node, value: int):
    global nodes

    if node.v:
        return

    que = deque()
    que.append(node)

    while (len(que)):
        node_ = que.popleft()
        if not node_.v:
            node_.v = value

            for i in node_.nexts:
                que.append(nodes[i])


if __name__ == "__main__":
    n, m = map(int, input().split())
    nodes = [Node() for i in range(n + 1)]

    for _ in range(m):
        u, v = map(int, input().split())
        nodes[v].nexts.append(u)

    for i in range(n, 0, -1):
        node = nodes[i]
        bfs(node, i)

    for i in range(1, n + 1, 1):
        node = nodes[i]
        print(node.v, end=' ')

    print()
