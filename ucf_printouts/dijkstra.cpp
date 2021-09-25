// dijkstra
vi dist(V, INF); dist[s] = 0;
priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, s));
while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < (int) adjlist[u].size(); j++) {
        ii v = adjlist[u][j];
        if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second;
            pq.push(ii(dist[v.first], v.first));
        }
    }
}
