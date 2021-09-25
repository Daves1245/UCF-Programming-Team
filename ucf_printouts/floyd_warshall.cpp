// floyd warshall
const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow
const int MAX_V = 450; // if |V| > 450, you cannot use Floyd Washall's
int AM[MAX_V][MAX_V]; // it is better to store a big array in the heap
int main() {
  int V, E; scanf("%d %d", &V, &E);
  for (int u = 0; u < V; ++u) {
    for (int v = 0; v < V; ++v)
      AM[u][v] = INF;
    AM[u][u] = 0;
  }
  for (int i = 0; i < E; ++i) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    AM[u][v] = w;// directed graph
  }
  for (int k = 0; k < V; ++k) // loop order is k->u->v
    for (int u = 0; u < V; ++u)
      for (int v = 0; v < V; ++v)
        AM[u][v] = min(AM[u][v], AM[u][k]+AM[k][v]);
  for (int u = 0; u < V; ++u)
    for (int v = 0; v < V; ++v)
      printf("APSP(%d, %d) = %d\n", u, v, AM[u][v]);

  return 0;
}
