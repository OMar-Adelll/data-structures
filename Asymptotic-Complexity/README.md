# Algorithmic Complexity Reference — C++ Examples (using namespace std)

[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Language: C++](https://img.shields.io/badge/language-C%2B%2B-lightgrey.svg)]()
[![Status: Draft](https://img.shields.io/badge/status-draft-orange.svg)]()

A professional, compact reference of asymptotic (Big‑O) time and space complexity for common algorithms with concise C++ examples.

Purpose
- Provide readable complexity notes you can paste into a repository README.
- Give short C++ code snippets that demonstrate the algorithm.
- Provide Best / Average / Worst time complexities (when they differ), auxiliary space, and a one-line reasoning.

Table of contents
- Summary at a glance
- Detailed entries (code + analysis)
  - linearSearch
  - binarySearch (iterative)
  - quickSort (in-place)
  - mergeSort
  - std::sort (note)
  - BFS
  - DFS (recursive)
  - Dijkstra (binary heap)
  - unordered_map::find (hash lookup)
  - priority_queue operations
  - naive matrixMultiply
  - KMP (Knuth–Morris–Pratt)
- Visual cheat‑sheets and design tips
- How to use & contribution notes

---

## Summary at a glance

| Algorithm | Time (Best / Avg / Worst) | Space (aux) | Input notation |
|---|---:|---:|---|
| linearSearch | O(1) / O(n) / O(n) | O(1) | n = array length |
| binarySearch | O(1) / O(log n) / O(log n) | O(1) | sorted array |
| quickSort | O(n log n) / O(n log n) / O(n^2) | O(log n) avg stack | n = array length |
| mergeSort | O(n log n) / O(n log n) / O(n log n) | O(n) | |
| std::sort (introsort) | O(n log n) / O(n log n) / O(n log n) | O(log n) | |
| BFS | O(V + E) | O(V) | V vertices, E edges |
| DFS | O(V + E) | O(V) stack | |
| Dijkstra (binary heap) | O((V + E) log V) ≈ O(E log V) | O(V) | |
| unordered_map::find | O(1) / O(1) / O(n) | O(1) aux | n = elements |
| heap push/pop | O(1) / O(log n) / O(log n) | O(1) aux | |
| matrixMultiply (naive) | O(n^3) | O(n^2) | n x n matrices |
| KMP | O(n + m) | O(m) | n=text, m=pattern |

---

## Detailed entries (C++ snippets with using namespace std;)

Notes:
- Each snippet is minimal and focuses on the algorithm.
- All snippets include `using namespace std;` near the top as requested.

### 1) linearSearch
```cpp
#include <vector>
using namespace std;

// linearSearch: return index or -1
int linearSearch(const vector<int>& a, int target) {
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] == target) return (int)i;
    return -1;
}
```
Analysis:
- Time: Best O(1); Average O(n); Worst O(n).
- Space: O(1) auxiliary.
- Reason: Single pass through array.

---

### 2) binarySearch (iterative)
```cpp
#include <vector>
using namespace std;

int binarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```
Analysis:
- Time: Best O(1); Average/Worst O(log n).
- Space: O(1).
- Reason: Interval halves each iteration.

---

### 3) quickSort (in-place, Lomuto partition)
```cpp
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; ++j)
        if (a[j] < pivot) swap(a[i++], a[j]);
    swap(a[i], a[hi]);
    quickSort(a, lo, i - 1);
    quickSort(a, i + 1, hi);
}
```
Analysis:
- Time: Best/Average O(n log n); Worst O(n^2) (bad pivots).
- Space: O(log n) average recursion; O(n) worst.
- Suggestion: randomize pivot or use std::sort to avoid worst-case.

---

### 4) mergeSort
```cpp
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int m, int r, vector<int>& tmp) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int t = l; t <= r; ++t) a[t] = tmp[t];
}
void mergeSortRec(vector<int>& a, int l, int r, vector<int>& tmp) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, l, m, tmp);
    mergeSortRec(a, m + 1, r, tmp);
    merge(a, l, m, r, tmp);
}
void mergeSort(vector<int>& a) {
    vector<int> tmp(a.size());
    mergeSortRec(a, 0, (int)a.size() - 1, tmp);
}
```
Analysis:
- Time: O(n log n) all cases.
- Space: O(n) auxiliary.
- Reason: log n levels × O(n) merge per level.

---

### 5) std::sort (note)
Use `std::sort(a.begin(), a.end());` — typically implemented as introsort (quicksort + heap sort fallback).
- Time: Average & Worst O(n log n).
- Space: O(log n) auxiliary.
- Reason: Fast average-case and worst-case safe.

---

### 6) BFS (breadth-first search)
```cpp
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0; q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}
```
Analysis:
- Time: O(V + E).
- Space: O(V).
- Reason: Each node and edge processed once.

---

### 7) DFS (recursive)
```cpp
#include <vector>
using namespace std;

void dfsRec(int u, const vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfsRec(v, adj, vis);
}
void dfs(int start, const vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    dfsRec(start, adj, vis);
}
```
Analysis:
- Time: O(V + E).
- Space: O(V) worst-case recursion stack.
- Reason: Visits each reachable vertex and edge.

---

### 8) Dijkstra (binary heap)
```cpp
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using PII = pair<long long,int>;

vector<long long> dijkstra(int n, const vector<vector<pair<int,int>>>& adj, int src) {
    const long long INF = (1LL<<60);
    vector<long long> dist(n, INF);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v,w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```
Analysis:
- Time: O((V + E) log V) ≈ O(E log V).
- Space: O(V).
- Reason: Heap operations for relaxations.

---

### 9) unordered_map::find (hash lookup)
```cpp
#include <unordered_map>
using namespace std;

bool containsKey(const unordered_map<int,int>& m, int key) {
    return m.find(key) != m.end();
}
```
Analysis:
- Time: Average O(1); Worst O(n) (pathological collisions).
- Space: O(1) auxiliary.
- Reason: Hash indexing; buckets scanned on collisions.

---

### 10) priority_queue push/pop (heap)
```cpp
#include <queue>
using namespace std;

void heapExamples() {
    priority_queue<int> pq;
    pq.push(10); // O(log n)
    pq.push(5);
    int top = pq.top(); // O(1)
    pq.pop(); // O(log n)
}
```
Analysis:
- Time: push/pop O(log n); top O(1).
- Space: O(1) auxiliary; O(n) total for heap.

---

### 11) naive matrixMultiply (square n×n)
```cpp
#include <vector>
using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& A,
                             const vector<vector<int>>& B) {
    int n = (int)A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          C[i][j] += A[i][k] * B[k][j];
    return C;
}
```
Analysis:
- Time: O(n^3).
- Space: O(n^2) for result.
- Reason: Triple nested loops.

---

### 12) KMP (Knuth–Morris–Pratt) pattern search
```cpp
#include <vector>
#include <string>
using namespace std;

vector<int> buildLPS(const string& p) {
    int m = (int)p.size();
    vector<int> lps(m);
    for (int i = 1, len = 0; i < m; ) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}
int kmpSearch(const string& s, const string& p) {
    if (p.empty()) return 0;
    vector<int> lps = buildLPS(p);
    int i = 0, j = 0;
    while (i < (int)s.size()) {
        if (s[i] == p[j]) { ++i; ++j; if (j == (int)p.size()) return i - j; }
        else if (j) j = lps[j-1];
        else ++i;
    }
    return -1;
}
```
Analysis:
- Time: O(n + m).
- Space: O(m).
- Reason: Precompute LPS and scan text once.

---

## Visual cheat‑sheet (quick reference)

- Constant time: O(1) — array access, stack top
- Logarithmic: O(log n) — binary search
- Linear: O(n) — single loop
- n log n: O(n log n) — efficient sorts (std::sort, mergesort)
- Quadratic: O(n^2) — nested loops (selection sort, naive pair comparisons)
- Cubic: O(n^3) — naive matrix multiplication
- Exponential: O(2^n) — brute-force subset enumeration

Design tips
- Prefer std::sort over custom quicksort unless you need a specialized comparator or stability (use stable_sort).
- For heavy recursion on large inputs, consider iterative or tail-recursive designs to limit stack usage.
- Use unordered_map for average O(1) lookups; reserve bucket count if you know expected size to avoid rehash cost.
- For Dijkstra on dense graphs, consider using a Fibonacci heap variant theoretically; in practice binary heap (priority_queue) is fast and simple.

---
## Appendix — Notation checklist for reviewers

- O(...) — upper bound (commonly worst-case)
- Ω(...) — lower bound
- Θ(...) — tight bound (both O and Ω)
- When you claim Θ, supply both upper and lower bound reasoning.

## How to integrate into your repo

1. Add this file as `README_COMPLEXITIES.md` in the repository root.
2. In main `README.md` add a short link:
   - "See [Algorithmic Complexity Reference](README_COMPLEXITIES.md) for per-function Big‑O and C++ examples."
3. Keep entries minimal; update the corresponding snippet when code changes.
4. Optional: add a CI check that detects large functions and prompts for complexity documentation (manual review is recommended).

Contribution & style guidelines
- Use `n`, `m`, `V`, `E` to denote input sizes consistently.
- Keep code snippets short (< 40 lines).
- Add Best/Avg/Worst only when they differ — otherwise state a single complexity.
- Mark any assumptions (e.g., "array is sorted", "hash has good distribution").

---
## Design tips & best practices

- Prefer std::sort (introsort) over custom quicksort unless you need a special behavior.
- Declare complexity assumptions in comments (e.g., "assumes graph is adjacency list; V vertices, E edges").
- When using unordered_map, note average-case O(1) behavior and worst-case O(n) for pathological collisions.
- State whether space counts input memory or only auxiliary memory.

---

## Commit instructions & integration

- Filename suggestion: `README_COMPLEXITIES.md` (place at repository root).
- Add a one-line pointer in your main README.md:
  - See [Algorithmic Complexity Reference](README_COMPLEXITIES.md) for per-function Big‑O/Θ/Ω and C++ examples.
- Keep entries short and update when functions change.

---


---


## License
This document is provided under the MIT license. Include an appropriate LICENSE file in your repository.


