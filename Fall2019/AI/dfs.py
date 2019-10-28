graph = {
    'A' : ['B','C','D'],
    'B' : ['E','F','G'],
    'C' : ['G'],
    'D' : ['H','I'],
    'E' : ['J','K','L'],
    'F' : ['A','L'],
    'G' : ['H','M','N'],
    'H' : ['O','P','A'],
    'I' : ['P','R'],
    'J' : [],
    'K' : [],
    'L' : [],
    'M' : [],
    'N' : [],
    'O' : [],
    'P' : [],
    'R' : [],

}

def dfs(graph, node, visited):
    if node not in visited:
        visited.append(node)
        print(visited)
        for n in graph[node]:
            dfs(graph,n, visited)
    return visited

visited = dfs(graph,'A', [])


 