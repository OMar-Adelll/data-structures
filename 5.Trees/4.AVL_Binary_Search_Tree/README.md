# Self-Balancing AVL Tree Implementation in C++

A robust, fully optimized template-based implementation of an AVL (Adelson-Velsky and Landis) Tree written in C++. This data structure is a self-balancing Binary Search Tree (BST) that automatically maintains structural equilibrium during element insertion. It guarantees efficient logarithmic time bounds for all lookup and search utilities while utilizing a generic template architecture.

---

## Introduction to AVL Trees

An **AVL Tree** is a specialized Binary Search Tree designed to overcome the critical performance limitations of standard unbalanced BSTs. In a traditional BST, inserting elements in a pre-sorted or sequential order forces the tree to degenerate into a linear, single-chain structure resembling a linked list. This layout completely destroys efficiency, collapsing performance from logarithmic to linear time.

This implementation circumvents that limitation by enforcing a strict structural constraint based on heights:
* **The Balancing Factor:** For every single node inside the tree structure, the absolute difference between the height of its left subtree and the height of its right subtree must never exceed one.
* **Proactive Structural Correction:** If an insertion causes this balance factor to drift outside the safe bounds of `[-1, 1]`, a localized rearrangement is triggered immediately. The tree updates internal heights and executes strategic pointer adjustments—known as node rotations—restoring perfect balance without scrambling the underlying search order.

---

## Operations & Complexity Analysis

### 1. Internal Helper & Balancing Mechanics

These private routines handle sub-tree height evaluation, calculation of structural factors, and local pointer re-orientations to heal unbalanced segments.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`getHeight`** | Safely reads and reads out the exact height state registered inside a node, returning zero if the reference points to a null space. | O(1) | O(1) |
| **`getBalancedFactor`** | Computes the height delta between the left and right subtrees to evaluate node saturation. | O(1) | O(1) |
| **`updateHeight`** | Evaluates structural boundaries by identifying the highest sub-branch layer below a target node and adding one to update its state. | O(1) | O(1) |
| **`rightRotate`** | **Left-Left (LL) Correction:** Handles single right rotations. Shifts an unbalanced parent node downward to become the right child of its former left-hand child. | O(1) | O(1) |
| **`leftRotate`** | **Right-Right (RR) Correction:** Handles single left rotations. Pulls a node down to become the left-hand child of its former right-hand child. | O(1) | O(1) |
| **`insert (Private)`** | Traverses recursive paths down the tree to drop an element, then retraces its steps upward to update node heights and process rotations (`LL`, `RR`, `LR`, `RL`). | O(log N) | O(log N) |
| **`inorder (Private)`** | Recursively traverses the tree structure via a Left-Node-Right strategy, printing elements in sorted, ascending order. | O(N) | O(log N) |

### 2. High-Level Public Abstraction Utilities

These public interfaces allow developers to initialize structures, append values, and print data stores without dealing with complex pointer details.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`AVL (Constructor)`** | Instantiates a clean, stable tree container, safely initializing the primary root tracking address to a null pointer state. | O(1) | O(1) |
| **`insert (Public)`** | Gateway routine that manages item entry. Allocates a root node directly if the tree is empty, or invokes recursive structural insertion. | O(log N) | O(log N) |
| **`display`** | Executes an ascending Inorder sequence traversal to cleanly print the entire tree data store onto the console. | O(N) | O(log N) |

---

## Rotations & Balancing Invariants

When an element is introduced into a node's subtree, the balance factor can shift to unbalanced extremes (`+2` or `-2`). The system instantly tracks down and corrects these scenarios through four distinct, elegant rotation maneuvers:

1. **Left-Left (LL) Case:** Triggered when a node becomes left-heavy (`factor > 1`) and the new item is pushed into the left-hand child's left subtree. Resolved cleanly by a single **Right Rotation**.
2. **Right-Right (RR) Case:** Occurs when a node becomes right-heavy (`factor < -1`) and the incoming item sits inside the right child's right subtree. Resolved instantly via a single **Left Rotation**.
3. **Left-Right (LR) Case:** Occurs when a node becomes left-heavy (`factor > 1`) but the item settles inside the left child's right subtree. Resolved by executing a **Left Rotation** on the child node first, followed by a **Right Rotation** on the parent.
4. **Right-Left (RL) Case:** Occurs when a node becomes right-heavy (`factor < -1`) but the item settles inside the right child's left subtree. Resolved by executing a **Right Rotation** on the child node first, followed by a **Left Rotation** on the parent.

---

## Project Execution Guide

### Prerequisite Environment
To compile and execute this tree component package, establish a workspace featuring a modern compiler toolchain supporting standard C++11 distributions or newer versions.

### Compilation Command
Compile your primary operational source file using optimized compilation routines:
**g++ -O3 -std=c++17 main.cpp -o avl_tree_demo**

### Execution Tracking
Launch the generated binary executable output natively within your active terminal tree:
**./avl_tree_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**