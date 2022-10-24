def bfs(n, M, key):
    dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]
    ed = [[False] * n for i in range(n)]
    q = [(0, 0, 0)]
    for i, j, step in q:
        for di, dj in dirs:
            ni, nj = i + di, j + dj
            if (0 <= ni < n and 0 <= nj < n and not ed[ni][nj]
                    and abs(M[ni][nj] - M[i][j]) <= key):
                if (ni, nj) == (n - 1, n - 1): return step + 1
                ed[ni][nj] = 1
                q.append((ni, nj, step + 1))
    return -1


def getEdges(n, M):
    edges = []
    for i in range(n):
        for j in range(n):
            if i > 0:
                u = i * n + j
                v = (i - 1) * n + j
                w = abs(M[i][j] - M[i - 1][j])
                edges.append([w, u, v])
            if j > 0:
                u = i * n + j
                v = i * n + (j - 1)
                w = abs(M[i][j] - M[i][j - 1])
                edges.append([w, u, v])
    return edges


def getKey(n, M, edges):
    edges.sort()

    par = [i for i in range(n * n)]

    def find(u):
        par[u] = u if par[u] == u else find(par[u])
        return par[u]

    src, dst = 0, n * n - 1
    for [w, u, v] in edges:
        if find(u) != find(v):
            par[find(u)] = find(v)
        if find(src) == find(dst):
            return w

def main():
    n = int(input())
    M = [list(map(int, input().split())) for _ in range(n)]
    edges = getEdges(n, M)
    key = getKey(n, M, edges)
    ans = bfs(n, M, key)
    print(key, ans, sep='\n')

main()
