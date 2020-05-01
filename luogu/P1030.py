class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


last = ""


def construct(node: Node, mid: str) -> None:
    global last

    value = last[-1]
    node.value = value

    value_index = mid.index(value)
    left = mid[:value_index]
    right = mid[value_index + 1:]

    last = last[:-1]

    if len(last) and last[-1] in right:
        node.right = Node()
        construct(node.right, right)

    if len(last) and last[-1] in left:
        node.left = Node()
        construct(node.left, left)


def print_(node: Node) -> None:
    if node:
        print(node.value, end='')
        print_(node.left)
        print_(node.right)


if __name__ == "__main__":
    mid = input()
    last = input()

    root = Node()
    construct(root, mid)
    print_(root)
