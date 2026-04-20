#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 100005

int disc[MAXV], low[MAXV], parent[MAXV];
int visited[MAXV];
int isAP[MAXV];
int timer_val;

void dfs(int u, List** adj) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer_val;
    int children = 0;

    /* Access neighbors via adj[u]->arr[j] and adj[u]->size */
    for (int j = 0; j < adj[u]->size; j++) {
        int v = adj[u]->arr[j];

        /* Skip self-loops */
        if (v == u) continue;

        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v, adj);

            if (low[v] < low[u])
                low[u] = low[v];

            /* Root of DFS tree with 2+ children */
            if (parent[u] == -1 && children > 1)
                isAP[u] = 1;

            /* Non-root: subtree of v can't reach above u */
            if (parent[u] != -1 && low[v] >= disc[u])
                isAP[u] = 1;

        } else if (v != parent[u]) {
            /* Back edge */
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int* articulationPoints(int V, List** adj, int* returnSize) {
    timer_val = 0;

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        isAP[i]    = 0;
        parent[i]  = -1;
        disc[i]    = 0;
        low[i]     = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj);
    }

    int* result = (int*)malloc((V + 1) * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < V; i++) {
        if (isAP[i])
            result[(*returnSize)++] = i;
    }

    if (*returnSize == 0) {
        result[0] = -1;
        *returnSize = 1;
    }

    return result;
}
