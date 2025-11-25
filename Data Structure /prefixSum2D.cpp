int m = n, q;
cin >> q;

// 0-based matrix
vector<vector<int>> matrix(n, vector<int>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        char x;
        cin >> x;
        matrix[i][j] = (x == '*') ? 1 : 0;
    }
}

// 1-based prefix sum matrix
vector<vector<int>> g(n + 1, vector<int>(m + 1));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        g[i][j] = g[i][j - 1] + matrix[i - 1][j - 1];

for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
        g[i][j] += g[i - 1][j];

while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << g[c][d] + g[a - 1][b - 1] - g[a - 1][d] - g[c][b - 1] << endl;
}