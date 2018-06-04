struct Node
{
     vector<int> adj;
};
Node graf[MAX_N];

struct TreeNode
{
     int parent;
     int depth;
     int chainTop;
     int subTreeSize;
};
TreeNode T[MAX_N];

int DFS(int root, int parent, int depth)
{
     T[root].parent = parent;
     T[root].depth = depth;
     T[root].subTreeSize = 1;
     for (int i=0;i<graf[root].adj.size();i++)
     {
          int xt = graf[root].adj[i];
          if (xt == parent) continue;
          T[root].subTreeSize += DFS(xt, root, depth+1);
     }
     return T[root].subTreeSize;
}

void HLD(int root, int parent, int chainTop)
{
     T[root].chainTop = chainTop;
     
     for (int i=0;i<graf[root].adj.size();i++)
     {
          int xt = graf[root].adj[i];
          if (xt == parent) continue;
          if (T[xt].subTreeSize*1.0 > T[root].subTreeSize*0.5) HLD(xt, root, chainTop);
          else HLD(xt, root, xt);
     }
}

inline int LCA(int u, int v)
{
     while (T[u].chainTop != T[v].chainTop)
     {
          if (T[T[u].chainTop].depth < T[T[v].chainTop].depth) v = T[T[v].chainTop].parent;
          else u = T[T[u].chainTop].parent;
     }
     
     if (T[u].depth < T[v].depth) return u;
     else return v;
}
