<div align="center">

# 🏆 CP_Templates

### A Lightning-Fast Competitive Programming Arsenal

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)

*Battle-tested templates engineered for speed, efficiency, and contest victories* 🚀

[Quick Start](#-quick-start) • [Templates](#-template-library) • [Documentation](#-usage-guide) • [Contributing](#-contributing)

</div>

---

## 🎯 Why CP_Templates?

In competitive programming, **speed is everything**. This repository provides:

- ⚡ **Pre-optimized** data structures and algorithms
- 🎨 **Clean, readable** code that's easy to modify under pressure
- 🔧 **Plug-and-play** templates for common contest patterns
- 🏅 **Battle-tested** across Codeforces, AtCoder, CodeChef, and more
- 📦 **Zero dependencies** except standard C++17

> *"Don't reinvent the wheel during a contest. Use proven templates and focus on problem-solving."*

---

## 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/mahmoudabozied4/CP_Templates.git
cd CP_Templates

# Copy the base template
cp templates/base_template.cpp solution.cpp

# Start coding!
```

### ⚙️ Compilation

```bash
# Development (with debugging)
g++ -std=c++17 -O2 -Wall -Wextra solution.cpp -o solution

# Contest (maximum speed)
g++ -std=c++17 -O3 -march=native solution.cpp -o solution
```

---

## 📚 Template Library

### 🗂️ Data Structures

<table>
<tr>
<td>

**Structure**

</td>
<td>

**Time Complexity**

</td>
<td>

**Best For**

</td>
</tr>

<tr>
<td>

**Fenwick Tree (BIT)**

</td>
<td>

`O(log n)` update/query

</td>
<td>

Prefix sums, frequency tables

</td>
</tr>

<tr>
<td>

**Segment Tree**

</td>
<td>

`O(log n)` with lazy prop

</td>
<td>

Range updates, RMQ

</td>
</tr>

<tr>
<td>

**Sparse Table**

</td>
<td>

`O(1)` query, `O(n log n)` build

</td>
<td>

Static range queries (RMQ, GCD)

</td>
</tr>

<tr>
<td>

**Ordered Set (PBDS)**

</td>
<td>

`O(log n)` all operations

</td>
<td>

k-th element, order statistics

</td>
</tr>

<tr>
<td>

**Merge Sort Tree**

</td>
<td>

`O(log² n)` query

</td>
<td>

Range order statistics

</td>
</tr>

<tr>
<td>

**Monotonic Stack/Queue**

</td>
<td>

`O(n)` amortized

</td>
<td>

Sliding window problems

</td>
</tr>

<tr>
<td>

**Disjoint Set Union**

</td>
<td>

`O(α(n))` ~ constant

</td>
<td>

Connected components, MST

</td>
</tr>

<tr>
<td>

**Trie**

</td>
<td>

`O(L)` where L = length

</td>
<td>

String prefix queries, XOR problems

</td>
</tr>

</table>

### 🧮 Algorithms

<details>
<summary><b>🌐 Graph Algorithms</b></summary>

- **Traversal**: DFS, BFS, Multi-source BFS
- **Shortest Paths**: Dijkstra, Bellman-Ford, Floyd-Warshall, 0-1 BFS
- **Minimum Spanning Tree**: Kruskal, Prim
- **Advanced**: Topological Sort, SCC (Kosaraju, Tarjan), Bridges & Articulation Points
- **Flows**: Dinic's Algorithm, Min-Cost Max-Flow

</details>

<details>
<summary><b>🔢 Number Theory</b></summary>

- **GCD/LCM**: Euclidean algorithm, Extended GCD
- **Primes**: Sieve of Eratosthenes, Segmented Sieve, Prime factorization
- **Modular Arithmetic**: Fast exponentiation, Modular inverse, Chinese Remainder Theorem
- **Combinatorics**: Factorial, nCr with/without modulo

</details>

<details>
<summary><b>🎯 Dynamic Programming</b></summary>

- Classic DP patterns (Knapsack, LIS, LCS, Edit Distance)
- Digit DP
- Bitmask DP
- DP on Trees
- Convex Hull Trick optimization

</details>

<details>
<summary><b>📝 String Algorithms</b></summary>

- **Pattern Matching**: KMP, Z-algorithm
- **Hashing**: Polynomial rolling hash, Double hashing
- **Advanced**: Suffix Array, Manacher's Algorithm
- **Trie**: Standard and Compressed

</details>

<details>
<summary><b>🔍 Search & Optimization</b></summary>

- Binary Search (variants)
- Ternary Search
- Meet in the Middle
- Greedy algorithms patterns

</details>

### ⚡ Core Utilities

```cpp
// Fast I/O optimization
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);

// Vector I/O operators
template<typename T = int>
istream& operator>>(istream &in, vector<T> &v);

template<typename T = int>
ostream& operator<<(ostream &out, const vector<T> &v);

// Debugging macro
#define dbg(x) cout << #x << ": " << (x) << "\n";

// Grid navigation (8 directions)
enum dir { d, r, u, l, ul, dr, ur, dl };
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

// Useful macros
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(s) int32_t(s.size())
#define pb push_back
```

---

## 💻 Base Template

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
typedef unsigned long long ull;
#define endl '\n'
typedef pair<int, int> pii;
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int64_t(s.size())
#define dbg(x) cout << #x << ": " << (x) << "\n";
// #define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
#define sub_mod(a, b) (((a % M) - (b % M) + M) % M)
const int N = 2e5 + 10, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
vector<string> RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void Zied() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int>
istream &operator >>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator <<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

template<typename A, typename B>
istream &operator>>(istream &fin, pair<A, B> &p) {
    fin >> p.X >> p.Y;
    return fin;
}

template<typename A, typename B>
std::ostream &operator<<(std::ostream &fout, const std::pair<A, B> &p) {
    fout << p.first << " " << p.second;
    return fout;
}

enum dir { d, r, u, l, ul, dr, ur, dl };

int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};


void preprocessing() {
}


auto Solve(const int &n) -> void {

}

bool solve_test(const int test_number) {
    int n = 1;
    // string n;
    if (!(cin >> n))
        return false;
    Solve(n);
    // auto ans = Solve(n);
    // cout << ans << endl;
    return true;
}

void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}

int32_t main() {
    Zied();
    Stress();
    // freopen("input.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        // cout << "Case " << tc << ": ";
        // cout << "Case #" << tc << ": ";
        if (!solve_test(tc))break;
        // cout << endl;
    }
    kill;
    //    Time
}

/*
  _____       _ _                      _______
 |  ___|     (_) |                    |___  (_)        | |
 | |__ _ __  _| |_ ___  _ __ ___   ___   / / _  ___  __| |
 |  __| '_ \| | __/ _ \| '_ ` _ \ / _ \ / / | |/ _ \/ _` |
 | |__| |_) | | || (_) | | | | | |  __/  /__| |  __/ (_| |
 \____/ .__/|_|\__\___/|_| |_| |_|\___ \_____/_|\___|\__,_|
      | |
      |_|
*/```

---

## 📖 Usage Guide

### 🎯 Single Test Case

```cpp
void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;  // Uses overloaded operator>>
    
    // Solution logic
    sort(all(a));
    
    cout << a << endl;  // Uses overloaded operator<<
}

int32_t main() {
    setup();
    solve();
    return 0;
}
```

### 🔄 Multiple Test Cases

```cpp
int32_t main() {
    setup();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
```

### 🎮 Interactive Problems

```cpp
void solve() {
    int n;
    cin >> n;
    
    // Query
    cout << "? " << query << endl;
    cout.flush();  // IMPORTANT!
    
    int response;
    cin >> response;
    
    // Answer
    cout << "! " << answer << endl;
    cout.flush();
}
```

### 🌳 Graph Template

```cpp
vector<vi> adj;
vector<bool> visited;
vector<int> dist;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
```

### 🎲 Dynamic Programming

```cpp
vvi dp;

int solve_dp(int i, int j) {
    // Base case
    if (i < 0 || j < 0) return 0;
    
    // Memoization
    if (dp[i][j] != -1) return dp[i][j];
    
    // Recurrence
    int option1 = solve_dp(i-1, j) + cost[i][j];
    int option2 = solve_dp(i, j-1) + cost[i][j];
    
    return dp[i][j] = min(option1, option2);
}
```

---

## 🔥 Advanced Features

### 📊 Policy-Based Data Structures

```cpp
ordered_set<int> os;

// Insert element
os.insert(x);

// Find position (0-indexed)
int pos = os.order_of_key(x);

// Find k-th element
int kth = *os.find_by_order(k);

// Erase element
os.erase(x);

// Count elements less than x
int count = os.order_of_key(x);
```

### 🗜️ Coordinate Compression

```cpp
vi values = {100, 5, 1000, 5, 7};

// Compress
sort(all(values));
values.erase(unique(all(values)), values.end());

auto compress = [&](int x) {
    return lower_bound(all(values), x) - values.begin();
};

// Usage: compress(100) returns the compressed index
```

### 🔍 Binary Search Template

```cpp
// Find minimum x where condition(x) is true
auto binary_search = [&](int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (condition(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```

### ⚡ Modular Arithmetic

```cpp
const int MOD = 1'000'000'007;

// Safe operations
#define mul_mod(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define add_mod(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define sub_mod(a, b) (((a % MOD) - (b % MOD) + MOD) % MOD)

// Fast exponentiation
int power(int base, int exp, int mod = MOD) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Modular inverse
int mod_inverse(int a, int mod = MOD) {
    return power(a, mod - 2, mod);
}
```

---

## 🏅 Performance Optimization Tips

### ⚡ Speed Hacks

1. **Define `int` as `long long`** for contest safety
   ```cpp
   #define int long long
   ```

2. **Use `'\n'` instead of `endl`** (100x faster)
   ```cpp
   cout << answer << '\n';  // Fast
   // cout << answer << endl;  // Slow (flushes buffer)
   ```

3. **Reserve vector capacity** when size is known
   ```cpp
   vi v;
   v.reserve(n);  // Avoids reallocations
   ```

4. **Pass by reference** to avoid copying
   ```cpp
   void process(const vi& arr) { /* ... */ }
   ```

5. **Use `emplace_back` over `push_back`**
   ```cpp
   v.emplace_back(x, y);  // Constructs in-place
   ```

### 🧠 Memory Optimization

- Use `vector<bool>` carefully (it's bitpacked but slow)
- Prefer `deque` over `vector` for front insertions
- Clear vectors after use in multiple test cases: `v.clear(); v.shrink_to_fit();`

### 🎯 Contest-Specific

```cpp
// Disable sync for faster I/O
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

// For file I/O
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
```

---

## 🏆 Tested Platforms

<div align="center">

| Platform | Status | Notes |
|:--------:|:------:|:------|
| ![Codeforces](https://img.shields.io/badge/Codeforces-✅-brightgreen) | ✅ Verified | All templates work |
| ![AtCoder](https://img.shields.io/badge/AtCoder-✅-brightgreen) | ✅ Verified | C++17 compatible |
| ![CodeChef](https://img.shields.io/badge/CodeChef-✅-brightgreen) | ✅ Verified | Tested extensively |
| ![LeetCode](https://img.shields.io/badge/LeetCode-✅-brightgreen) | ✅ Verified | Remove includes |
| ![HackerRank](https://img.shields.io/badge/HackerRank-✅-brightgreen) | ✅ Verified | Works perfectly |
| ![SPOJ](https://img.shields.io/badge/SPOJ-✅-brightgreen) | ✅ Verified | Classic problems tested |

</div>

---

## 📚 Learning Resources

### 📖 Essential Reading

- **[Competitive Programming 4](https://cpbook.net/)** by Steven & Felix Halim
  - *The Bible of competitive programming*
  
- **[CP-Algorithms](https://cp-algorithms.com/)**
  - Detailed algorithm explanations with implementations
  
- **[USACO Guide](https://usaco.guide/)**
  - Structured learning path from Bronze to Platinum

### 🎓 Video Courses

- **[Errichto YouTube](https://www.youtube.com/c/Errichto)** - Advanced techniques
- **[William Lin](https://www.youtube.com/c/WilliamLin168)** - Contest screencasts
- **[Algorithms Live](https://www.youtube.com/c/AlgorithmsLive)** - Live problem solving

### 💪 Practice Platforms

| Platform | Best For | Difficulty |
|----------|----------|------------|
| [Codeforces](https://codeforces.com/) | Regular contests, rating system | ⭐⭐⭐ |
| [AtCoder](https://atcoder.jp/) | High-quality problems | ⭐⭐⭐⭐ |
| [CSES](https://cses.fi/problemset/) | Learning fundamentals | ⭐⭐ |
| [USACO](http://www.usaco.org/) | Olympiad preparation | ⭐⭐⭐⭐⭐ |

---

## 🤝 Contributing

Contributions are what make the open-source community amazing! Any contributions you make are **greatly appreciated**.

### How to Contribute

1. **Fork** the repository
2. **Create** your feature branch
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. **Commit** your changes
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```
4. **Push** to the branch
   ```bash
   git push origin feature/AmazingFeature
   ```
5. **Open** a Pull Request

### Contribution Guidelines

- ✅ Add comments explaining complex logic
- ✅ Include time/space complexity
- ✅ Test on multiple platforms
- ✅ Follow existing code style
- ✅ Add example usage

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🌟 Show Your Support

If this repository helped you in contests, please consider:

- ⭐ **Starring** the repository
- 🔄 **Sharing** with fellow competitive programmers
- 🐛 **Reporting** bugs or suggesting improvements
- 🤝 **Contributing** your own templates

---

## 📬 Contact

**Mahmoud Abozied**

- GitHub: [@mahmoudabozied4](https://github.com/mahmoudabozied4)
- LinkedIn: [Connect with me](https://www.linkedin.com/in/mahmoudabozied4)

---

<div align="center">

### 🎯 Remember

> *"The only way to learn a new programming language is by writing programs in it."* - Dennis Ritchie

**Keep coding, keep competing, keep improving!** 🚀

Made with ❤️ by competitive programmers, for competitive programmers

</div>

---

## 🎨 ASCII Art Credit

```
              ,   .-'"'=;_  ,
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
              `.`.       .'.'        
                `'"'---'"'`
```

*Competitive Programming Mascot - Bringing good luck to your contests!* 🦉

</div>
