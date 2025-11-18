function < void(int) > dfs = [&](int u){
      vis[u] = 1;
      for ( auto v : grid[u] ){
          if ( !vis[v] ){
              dfs(v);
          }
      }
  };
