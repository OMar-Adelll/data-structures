# Advanced 32-Bit Binary Trie Implementation in C++

A highly optimized, template-free bitwise prefix tree (Binary Trie) written in C++. This data structure is specifically engineered for high-performance bitwise queries and competitive programming contexts. It maps out integer paths from the Most Significant Bit (MSB) down to the Least Significant Bit (LSB) to solve complex prefix-matching and maximum XOR calculations with extreme efficiency.

---

## Introduction to Binary Tries

A **Binary Trie** is a specialized variant of a retrieval tree (Trie) where the alphabet size is strictly bounded to two characters: `0` and `1`. Instead of text strings, it processes the binary representations of integers. Each path from the root node down to a leaf corresponds to a unique sequence of bits representing an unassigned value.

### Key Architectural Pillars:
* **Fixed-Width Bit Deep Traversal:** The tree evaluates integers uniformly across a 32-bit depth plane (processing bits from position 31 down to 0). This consistency eliminates structural balance requirements and guarantees predictable lookup heights.
* **Greedy Bitwise Pathing:** By traversing alternative bit routes dynamically, the Trie can evaluate binary configurations immediately, making it the premier data structure choice for handling continuous bitwise interactions.
* **Frequency-Driven Reference Counting:** Nodes carry a frequency matrix that tracks how many active integers share a specific prefix path. This tracking functions as an automated indicator to support safe path removals and real-time cleanup operations.

---

## Operations & Complexity Analysis

Given that the bit-width is fixed to a constant size (32 bits), the time complexities for all primary manipulations remain strictly bounded by an absolute constant factor, denoted below as O(B) where B represents the bit depth.

### 1. Internal Structural Utilities

These low-level operations monitor prefix reference counts and process path cleanups recursively when frequencies hit zero.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`Node (Constructor)`** | Sets up binary branch markers, initializing child node locations and branch frequency tracking fields cleanly to empty states. | O(1) | O(1) |
| **`erase (Private Helper)`** | Traverses deep paths recursively to update structural reference fields, executing explicit structural removals the moment a prefix path becomes vacant. | O(B) | O(B) |

### 2. Public Bitwise Application Interface

These public wrappers allow users to register integers, wipe references, and run fast query checks over current memory configurations.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`insert`** | Evaluates individual bits of an incoming integer from position 31 to 0, instantiating new node addresses as needed while incrementing prefix frequency counters. | O(B) | O(B) |
| **`erase (Public Wrapper)`** | Initiates path unlinking by calling the recursive private lookup routine from the root position down to clear a target integer sequence. | O(B) | O(B) |
| **`mxXor`** | **Greedy Maximum XOR Resolver:** Scans the bits of a given integer and tries to move down the exact opposite bit path (`bit ^ 1`) at each step. If available, it captures that optimal path to maximize the resulting XOR value. | O(B) | O(1) |

---

## Memory Safety & Prefix Reclamation Policy

Unlike loose prefix trackers that leave dead paths hanging in memory, this implementation applies a strict reference counting strategy to guarantee memory safety:

1. **Active Frequency Down-Counting:** When an integer is cleared via the `erase` wrapper, the structure steps down the path bit-by-bit. It decrements the frequency count for each corresponding branch, recording exactly how many items continue to rely on that specific node configuration.
2. **Defensive Structural Pruning:** The moment a branch's reference count drops to zero, the layout triggers an explicit `delete` operation on that child branch. This frees the associated heap memory instantly and clips the dead branch from the tree, preventing dangling pointers and structural bloat.

---

## Project Execution Guide

### Prerequisite Environment
To compile and build this bitwise component package, make sure your development environment includes a C++ compiler supporting standard C++11 distributions or newer.

### Compilation Command
Compile your primary operational source file using standard optimization flags:
**g++ -O3 -std=c++17 main.cpp -o binary_trie_demo**

### Execution Tracking
Launch the compiled binary executable output natively within your active terminal tree:
**./binary_trie_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**