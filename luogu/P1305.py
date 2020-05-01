class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


mapping = {'*': None}


def print_(root):
    if root:
        print(root.value, end='')
        print_(root.left)
        print_(root.right)


if __name__ == "__main__":
    n = int(input())

    root = None

    for i in range(n):
        string = input()
        r, left, right = string[0], string[1], string[2]
        if r not in mapping:
            mapping[r] = Node(r)

        if left not in mapping:
            mapping[left] = Node(left)
        mapping[r].left = mapping[left]

        if right not in mapping:
            mapping[right] = Node(right)
        mapping[r].right = mapping[right]

        if i == 0:
            root = mapping[r]

    print_(root)
