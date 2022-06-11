vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs_traversal;
        vector<bool> visited(V, false);
      
        queue<int> q;
        visited[0] = true;
        q.push(0);
                
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bfs_traversal.push_back(u);
            
            for (int it : adj[u]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                        }
                    }
                }
        return bfs_traversal;
    }
}
