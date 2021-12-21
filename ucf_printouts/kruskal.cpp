// kruskal
vector<tuple<int, int, int>> edgelist;
int mst_cost = 0;
ufds uf(V);
for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    edgelist.push_back(make_pair(w, ii(u, v)));
}
sort(edgelist.begin(), edgelist.end());
for (auto &[w, u, v] : edgelist[i]) {
    if (!uf.same_set(u, v)) {
        mst_cost += w;
        uf.union_set(u, v);
    }
    if (uf.num_sets == 1) break;
}
