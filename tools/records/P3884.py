class Node:
    def __init__(self, left=None, right=None, parent=None):
        self.left = left
        self.right = right
        self.parent = parent


nodes = {}
count = [0 for _ in range(100)]
depth = 0


def search(node: Node, h: int) -> None:
    global depth
    if node == None:
        if h > depth:
            depth = h
    else:
        count[h] += 1
        search(node.left, h + 1)
        search(node.right, h + 1)


def find(root: Node, des: Node, h: int) -> (int, bool):
    if root == None:
        return (-1, False)
    elif root is des:
        return (h, True)
    else:
        left = find(root.left, des, h + 1)
        right = find(root.right, des, h + 1)

        return (max(left[0], right[0]), left[1] or right[1])


def distence(u: Node, v: Node, h: int) -> int:
    ret = find(u, v, 0)
    if not ret[1]:
        return distence(u.parent, v, h + 1)
    return h * 2 + ret[0]


if __name__ == "__main__":
    n = int(input())

    root = None

    # 构造二叉树
    for _ in range(n - 1):
        parent, child = map(int, input().split())
        if parent not in nodes:
            nodes[parent] = Node()
        if child not in nodes:
            nodes[child] = Node()

        if child == 1 or nodes[parent].left and nodes[parent].right:
            parent, child = child, parent

        if not nodes[parent].left:
            nodes[parent].left = nodes[child]
        else:
            nodes[parent].right = nodes[child]

        nodes[child].parent = nodes[parent]

        if parent == 1:
            root = nodes[parent]

    u, v = map(int, input().split())

    search(root, 0)
    print(depth)
    print(max(count))
    print(distence(nodes[u], nodes[v], 0))
