graph = dict()

visited = []
queue = []

def bfs(visited, graph, node):
    queue.append(node)

    while queue:
        temp = queue.pop(0)
        visited.append(temp)

        for neighbour in graph[temp]:
            if neighbour not in visited and neighbour not in queue:
                queue.append(neighbour)

    print("BFS Traversal: ", end = "")
    for i in visited:
        print(i, end = " ")

if __name__ == "__main__":
    num = int(input("Enter number of nodes in graph: "))

    for i in range(num):
        connections = input("Enter connections with a space: ").split()
        graph[chr(65 + i)] = connections

    print("The graph is: ")
    for i in graph:
        print(i, graph[i], sep = ": ")

    bfs(visited, graph, 'A')
