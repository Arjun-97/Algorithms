graph = dict()

visited = []
stack = []

def dfs(visited, graph, node):
    stack.append(node)

    while stack:
        temp = stack.pop()
        visited.append(temp)

        for neighbour in graph[temp]:
            if neighbour not in visited and neighbour not in stack:
                stack.append(neighbour)

    print("DFS Traversal: ", end = "")
    for i in visited:
        print(i, end = " ")

if __name__ == "__main__":
    num = int(input("Enter number of nodes in graph: "))

    for i in range(num):
        connections = input("Enter connections with a space: ").split()
        graph[chr(65+i)] = connections

    print("The graph is: ")
    for i in graph:
        print(i, graph[i], sep=": ")

    dfs(visited, graph, 'A')

