import math

result = math.inf


class Node:
    def __init__(self, value=None, left=None, right=None, parent=None):
        self.left = left
        self.right = right
        self.value = value
        self.parent = parent

    def cacl(self) -> int:
        return Node.cacl_down(self, 0) + Node.cacl_up(self, 0)

    @staticmethod
    def cacl_up(node, dis: int) -> int:
        if node == None:
            return 0

        temp = node.value * dis
        down = 0
        if node.parent:
            temp += Node.cacl_up(node.parent, dis + 1)
            if node == node.parent.left:
                down = Node.cacl_down(node.parent.right, dis + 2)
            else:
                down = Node.cacl_down(node.parent.left, dis + 2)

        return temp + down

    @staticmethod
    def cacl_down(node, dis: int) -> int:
        if node == None:
            return 0

        return node.value * dis + Node.cacl_down(node.left, dis + 1) \
            + Node.cacl_down(node.right, dis + 1)


if __name__ == "__main__":
    n = int(input())
    nodes = [Node() for _ in range(n)]

    for node in nodes:
        value, left, right = map(int, input().split())
        node.value = value

        if left:
            node.left = nodes[left - 1]
            nodes[left - 1].parent = node
        if right:
            node.right = nodes[right - 1]
            nodes[right - 1].parent = node

    for node in nodes:
        result = min(result, node.cacl())

    print(result)
