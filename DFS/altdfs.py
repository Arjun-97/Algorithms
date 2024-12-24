graph = [
    [0,1,0,1,0],
    [1,0,1,0,0],
    [0,1,0,0,0],
    [1,0,0,0,1],
    [0,0,0,1,0]
        ]

graph2 = [
    [0,1,1,0,0],
    [1,0,1,1,0],
    [1,1,0,1,1],
    [0,1,1,0,1],
    [0,0,1,1,0]
        ]

graph3 = [
    [1,1,1,1,1],
    [1,1,1,1,1],
    [1,1,1,1,1],
    [1,1,1,1,1],
    [1,1,1,1,1]
        ]

stack = []
visited = []

check = [-1, -1, -1, -1, -1]

def dfs(visited, graph, node):
    stack.append(node)
    check[node] = 1

    while stack:
        temp = stack.pop()
        visited.append(temp)

        for i in range(len(graph)):
            if graph[temp][i] == 1 and check[i] == -1:
                stack.append(i)
                check[i] = 1

    print("DFS Traversal: ", end = "")
    for i in visited:
        print(i, end = " ")

if __name__ == "__main__":
    dfs(visited, graph, 0)
    print()

    stack, visited, check = [],[],[-1,-1,-1,-1,-1]

    dfs(visited, graph2, 0)
    print()

    stack, visited, check = [],[],[-1,-1,-1,-1,-1]

    dfs(visited, graph3, 0)
