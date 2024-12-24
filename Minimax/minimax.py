class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def maxDepth(node):
    if node is None:
        return 0

    lDepth = maxDepth(node.left)
    rDepth = maxDepth(node.right)

    return max(lDepth, rDepth) + 1

def insertNode(root, val, left_right):
    if left_right == 'L':
        root.left = Node(val)
    elif left_right == 'R':
        root.right = Node(val)

def buildTree():
    root_val = int(input("Enter the value for the root node: "))
    root = Node(root_val)

    n = int(input("Enter the number of nodes to add: "))

    for _ in range(n):
        parent_val = int(input("Enter the value of the parent node: "))
        child_val = int(input("Enter the value of the child node: "))
        left_right = input("Left child or right child (L/R): ").upper()

        parent_node = findNode(root, parent_val)
        if parent_node:
            insertNode(parent_node, child_val, left_right)
        else:
            print(f"Parent node with value {parent_val} not found.")

    return root

def findNode(node, val):
    if node is None:
        return None
    if node.data == val:
        return node

    found_node = findNode(node.left, val)
    if found_node is None:
        found_node = findNode(node.right, val)

    return found_node

def minimax(node, depth, maxPlayer):
    if depth == 0:
        return node.data
    if maxPlayer:
        maxEva = float('-inf')
        eva1 = minimax(node.left, depth-1, False)
        maxEva = max(maxEva, eva1)
        eva2 = minimax(node.right, depth-1, False)
        maxEva = max(maxEva, eva2)
        return maxEva
    if not maxPlayer:
        minEva = float('inf')
        eva1 = minimax(node.left, depth-1, True)
        minEva = min(minEva, eva1)
        eva2 = minimax(node.right, depth-1, True)
        minEva = min(minEva, eva2)
        return minEva

if __name__ == "__main__":
    root = buildTree()
    depth = maxDepth(root) - 1
    print("Max depth of the tree is:", depth+1)
    val = minimax(root, depth, True)
    print("Value:", val)
