# Data Structures in C++

A comprehensive, production-grade collection of core data structures implemented from scratch in C++. This repository serves as an algorithmic sandbox demonstrating strict resource management, pointer manipulation, complexity optimization, and modern software design principles.

---

## 📂 Repository Structure & Module Overview

The project is systematically organized into distinct modules, each focusing on a fundamental category of data structures. Each subdirectory isolates its specific structural variations and implementations.

| Top-Level Module | Sub-Classifications / Variations | Description |
| :--- | :--- | :--- |
| **1. Dynamic Array** | • Generic Dynamic Vector | Re-implements continuous resizing mechanics, capacity doublings, and amortized boundary shifts. |
| **2. Linked List** | • Singly Linked List<br>• Doubly Linked List<br>• Circular Singly Linked List | Covers foundational point-mutation structures using custom forward, backward, and cyclic memory link behaviors. |
| **3. Stack** | • Static Stack<br>• Dynamic Stack<br>• Stack Real Applications | Demonstrates Last-In, First-Out (LIFO) access policies using both fixed buffers and dynamic pointers, along with real-world parsing use cases. |
| **4. Queue** | • Static Queue (Circular Array)<br>• Dynamic Queue (Linked List) | Implements First-In, First-Out (FIFO) access tracks, comparing contiguous index arithmetic against dynamic heap boundaries. |
| **5. Trees** | • Heap Tree (Min/Max Binary Heap)<br>• AVL Tree (Self-Balancing BST) | Covers hierarchical data structures, showcasing balanced logarithmic lookups and priority retrieval mechanics. |
| **6. Letter Tree** | • Trie (26-Way Alphabet)<br>• Binary Trie (32-Bit Integer) | Implements specialized bitwise and string-based prefix retrieval systems optimized for rapid dictionary indexing and maximum XOR queries. |

---

## 📊 Algorithmic Complexity Map

Below is a consolidated reference map of the theoretical time and space complexities for the core operations across each primary data structure contained in this repository.

### Sequential & Linear Containers

| Structure | Operation | Best Case | Average Case | Worst Case | Space Complexity |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **Dynamic Array** | Access by Index | O(1) | O(1) | O(1) | O(1) |
| | Insertion (Back) | O(1) | O(1) *Amortized* | O(N) | O(1) |
| **Singly / Doubly List** | Search / Value Lookup | O(1) | O(N) | O(N) | O(1) |
| | Insertion (Tail) | O(1) | O(N) | O(N) | O(1) |
| **Stack (Static/Dynamic)** | Push / Pop | O(1) | O(1) | O(1) | O(1) |
| **Queue (Static/Dynamic)** | Enqueue / Dequeue | O(1) | O(1) / O(N) | O(1) / O(N) | O(1) |

### Non-Linear & Prefix Tree Containers
*Note: For Trie structures, **L** denotes the maximum string length, and **B** represents the bit depth (32 bits for integers).*

| Structure / Tree | Operation | Average Case | Worst Case | Space Complexity | Performance Notes |
| :--- | :--- | :---: | :---: | :---: | :--- |
| **Binary Heap** | Push / Pop Root | O(log N) | O(log N) | O(1) | Achieved via partial ordering invariants. |
| | Heap Construction | O(N) | O(N) | O(1) | Built efficiently using Floyd's algorithm. |
| **AVL Tree** | Insert / Search | O(log N) | O(log N) | O(log N) | Strictly maintained via single/double node rotations. |
| **Trie (26-Way)** | Insert / Word Count | O(L) | O(L) | O(L) | Performance scales strictly with string length. |
| **Binary Trie** | Insert / Max XOR | O(B) | O(B) | O(B) | Solves priority bit paths in constant runtime. |

---

## 🔒 Memory Safety & Engine Guidelines

This library is engineered using defensive programming architectures to enforce stability and eliminate modern resource layout issues:

1. **Explicit RAII Resource Scoping:** Every custom container manages its own heap layout natively. Class destructors safely execute linear or recursive deep deletions to guarantee memory cleanups immediately when an object goes out of scope.
2. **Copy Boundary Restraints:** Where shallow copies would risk accidental duplicate references and double-free vulnerabilities, the copy constructors and assignment operators are explicitly deleted via `= delete`.
3. **Competitive Programming Ready:** Code templates are pre-configured with high-capacity integer shortcuts (`long long`), fixed formatting precision controls, and optimized input/output streams to process intensive data sequences at maximum speed.

---

## 🚀 Environment Setup & Compilation

### Requirements
A modern development workspace with a `GCC / G++` toolchain or a compiler infrastructure that supports standard specifications from `C++11` up to `C++23`.

### Compilation
To test any individual component, navigate to its respective directory and compile using strict optimization configurations:
```bash
g++ -O3 -std=c++17 Vector.cpp -o implementation_demo