//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int p) {
        return parent[p] == p ? p : parent[p] = findParent(parent[p]);
    }

    void Union(int u, int v) {
        int pu = findParent(u), pv = findParent(v);
        parent[pu] = pv;
    }
};

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pscritical;

        // Step 1: Attach the original edge index to each edge
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        // Step 2: Sort edges based on their weights
        sort(edges.begin(), edges.end(), cmp);

        int mstwt = findMST(n, edges, -1, -1); // Step 3: Compute initial MST weight

        for (int i = 0; i < edges.size(); i++) {
            // Step 5: Check if the edge is critical
            if (mstwt < findMST(n, edges, i, -1))
                critical.push_back(edges[i][3]);
            // Step 6: Check if the edge is pseudo-critical
            else if (mstwt == findMST(n, edges, -1, i))
                pscritical.push_back(edges[i][3]);
        }

        return {critical, pscritical};
    }

private:
    int findMST(int& n, vector<vector<int>>& edges, int block, int e) {
        UnionFind uf(n);
        int weight = 0;

        // Include the edge 'e' if it's valid
        if (e != -1) {
            weight += edges[e][2];
            uf.Union(edges[e][0], edges[e][1]);
        }

        // Construct the MST
        for (int i = 0; i < edges.size(); i++) {
            if (i == block)
                continue;
            if (uf.findParent(edges[i][0]) == uf.findParent(edges[i][1]))
                continue;
            uf.Union(edges[i][0], edges[i][1]);
            weight += edges[i][2];
        }

        // Check if all vertices are included in the MST
        for (int i = 0; i < n; i++) {
            if (uf.findParent(i) != uf.findParent(0))
                return INT_MAX;
        }

        return weight;
    }
};
