PQ = []
graph = {
    'S': [('A', 2), ('C', 5)],
    'A': [('G', 1)],
    'B': [('A', 4)],
    'C': [('A', 5), ('D', 2), ('G', 6)],
    'D': [('B', 4), ('E', 3)],
    'E': [('B', 6), ('G', 3)]
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

def ucs(graph, start, goal):
    enqueue(0, start, [start])
    cost = {start: 0}

    while PQ:
        current_cost, current_node, current_path = dequeue()

        if current_node == goal:
            return current_path, current_cost

        for i, j in graph.get(current_node):
            new_cost = current_cost + j

            if i not in cost or new_cost < cost[i]:
                cost[i] =  new_cost
                new_path = current_path + [i]
                enqueue(new_cost, i, new_path)

    return None, float('inf')

if __name__ == "__main__":
    start = 'S'
    end = 'G'
    path, cost = ucs(graph, start, end)
    print("Path is: ", path)
    print("Cost is: ", cost)
