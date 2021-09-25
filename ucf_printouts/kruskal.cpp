// kruskal
vector<pair<int, ii>> edgelist;
int mst_cost = 0;
ufds uf(V);
for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    edgelist.push_back(make_pair(w, ii(u, v)));
}
sort(edgelist.begin(), edgelist.end());
for (int i = 0; i < E; i++) {
    pair<int, ii> front = edgelist[i];
    if (!uf.same_set(front.second.first, front.second.second)) {
        mst_cost += front.first;
        uf.union_set(front.second.first, front.second.second);
    }
}
