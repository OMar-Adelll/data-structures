# Template-Based Dynamic Binary Heap Implementation in C++

A robust, highly optimized, and configurable Binary Heap data structure written in C++. This implementation supports both **Min-Heap** and **Max-Heap** structural topologies via a compile-time boolean template parameter. It offers an efficient alternative to traditional sorted arrays or linked lists for tracking priority elements, maintaining a balanced tree structure dynamically within a contiguous underlying memory footprint.

---

## Introduction to Binary Heaps

A **Binary Heap** is a specialized, complete binary tree data structure that satisfies the heap property. In a complete binary tree, every level is fully saturated except possibly the lowest level, which is filled progressively from left to right. This structural invariant guarantees that the height of the tree is always bounded by logarithmic limits relative to the element count.

### Real-world Problem & Solution Mechanics:
* **The Slicing Overhead Problem:** If data must remain constantly ordered, inserting a new element into its correct structural sequence within a standard array requires expensive element shifts. Conversely, using a linked list avoids element shifts but requires linear scanning time to locate the target position.
* **The Heap Advantage:** A Binary Heap addresses this tradeoff efficiently. Instead of enforcing absolute total ordering across every element, it enforces a partial ordering relationship between parent nodes and child nodes.
* **Heap Properties:** In a **Min-Heap**, the payload value of every parent node is less than or equal to the values of its children, rendering the root the absolute minimum element. In a **Max-Heap**, parent node values are greater than or equal to their children, making the root the absolute maximum element.
* **Contiguous Memory Array Mapping:** Rather than using a complex web of individual node structures and heap pointer components, the tree configuration is stored inside a flat, sequential array layout. Elements are mathematically linked together using strict index calculations based on their position from the root.

---

## Operations & Complexity Analysis

### 1. Low-Level Structural Mechanics

These private operations handle implicit array-to-tree index translations, heap condition checks, and recursive structural restorations.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`left`** | Calculates the left-hand child index location using modular boundary tracking. Returns negative one if the calculated index steps past structural bounds. | O(1) | O(1) |
| **`right`** | Calculates the right-hand child index location based on relative node positions. Returns negative one if it overflows current allocation limits. | O(1) | O(1) |
| **`parent`** | Computes the immediate ancestral index position using fractional floor truncation, returning negative one if called on the root element. | O(1) | O(1) |
| **`better`** | A polymorphic evaluation shortcut that evaluates element dominance based on whether the heap is compiled as a Min-Heap or a Max-Heap. | O(1) | O(1) |
| **`HeapfiyUp`** | Progressively swaps a newly appended element with its parent up the tree until the core structural ordering property is fully satisfied. | O(log N) | O(1) |
| **`HeapfiyDown`** | Compares an out-of-place root node with its direct children, shifting it downward to its correct location to rebuild order after extraction. | O(log N) | O(1) |

### 2. High-Level Public Application Utilities

These public interfaces allow developers to construct heaps, insert data points, purge priority nodes, and safely inspect boundaries.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`Heap (Vector Constructor)`** | **Floyd's Heap Construction Algorithm:** Efficiently converts an unordered vector into a validated heap by executing bottom-up down-heap operations starting from the lowest non-leaf node. | O(N) | O(1) |
| **`push`** | Appends a new item to the absolute end of the contiguous array structure and executes up-heap operations to preserve ordering. | O(log N) | O(1) |
| **`pop`** | Removes the priority root node by replacing its value with the trailing leaf item, dropping the final vector index, and sinking the new root down. | O(log N) | O(1) |
| **`empty`** | Returns a fast boolean status indicating whether the underlying array contains zero active elements. | O(1) | O(1) |
| **`size`** | Directly reads and queries the overall capacity footprint mapping out the exact number of active nodes. | O(1) | O(1) |
| **`top`** | Safely reads the extreme element value situated at the root (minimum for Min-Heap, maximum for Max-Heap) without removing it. | O(1) | O(1) |

---

## Memory Safety & Resource Management

This structure leverages systematic modern allocation safety rules to keep data isolated and eliminate traditional pointer vulnerabilities.

### Dynamic Vector Encapsulation
By utilizing a dynamic vector container internally instead of unmanaged raw pointers, memory reallocations and capacity growths are managed automatically by standard library allocation policies. This prevents manual out-of-bounds pointer overwrites.

### Automated Lifecycle Cleanups
The structure relies on deterministic RAII (Resource Acquisition Is Initialization) design. When the heap object falls out of scope, the underlying container invokes its implicit destruction sequences, safely freeing the contiguous buffer from the heap and preventing memory leaks without requiring manual garbage collection sweeps.

---

## Project Execution Guide

### Prerequisite Environment
To compile and execute this program, your development platform must feature an optimization toolkit supporting standard C++11 toolchains or newer versions.

### Compilation Command
Compile the target implementation through any standard command console utilizing optimized processing flags:
**g++ -O3 -std=c++17 main.cpp -o heap_tree_demo**

### Execution Tracking
Launch the compiled binary file natively inside your system's console environment:
**./heap_tree_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**