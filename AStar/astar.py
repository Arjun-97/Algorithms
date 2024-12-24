PQ = []
graph = {
    'S': [('B', 4), ('C', 3)],
    'B': [('E', 12), ('F', 5)],
    'C': [('D', 7), ('E', 10)],
    'D': [('E', 2)],
    'E': [('G', 5)],
    'F': [('G', 16)]
}
heuristic = {
    'S': 14,
    'B': 12,
    'C': 11,
    'D': 6,
    'E': 4,
    'F': 11,
    'G': 0
}

def enqueue(priority, node, path):
    PQ.append((priority, node, path))

def dequeue():
    index = 0

    if len(PQ) == 0:
        print("Queue is empty")
        return 0

    for i in range(1, len(PQ)):
        if PQ[i][0] < PQ[index][0]:
            index = i
    temp = PQ.pop(index)
    return temp

def astar(graph, start, goal):
    enqueue(heuristic.get(start), start, [start])
    cost = {start: 0}

    while PQ:
        current_cost, current_node, current_path = dequeue()
        current_cost -= heuristic.get(current_node)

        if current_node == goal:
            return current_path, current_cost

        for i, j in graph.get(current_node):
            new_cost = current_cost + j

            if i not in cost or new_cost < cost[i]:
                cost[i] = new_cost
                priority = new_cost + heuristic.get(i)
                new_path = current_path + [i]
                enqueue(priority, i, new_path)


if __name__ == "__main__":
    start = 'S'
    end = 'G'
    path, cost = astar(graph, start, end)
    print("Path is: ", path)
    print("Cost is: ", cost)
