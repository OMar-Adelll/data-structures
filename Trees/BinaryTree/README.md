# 🌳 Binary Tree (BT) – C++ Implementation

## 📌 Overview

This project is a **complete Binary Tree implementation in C++** using **templates**.  
It is designed to build strong fundamentals in:

- Tree data structures  
- Recursive problem solving  
- Core tree algorithms  

This implementation is ideal for **learning**, **practice**, and **technical interview preparation**.

---

## 🌱 What is a Binary Tree?

A **Binary Tree** is a hierarchical data structure where each node has **at most two children**:

- Left child  
- Right child  

⚠️ There are **no ordering rules** in a general Binary Tree (unlike BSTs).

---

## 🧱 Project Structure

The project is built around a **single generic `BinaryTree<T>` class** that:

- Stores values of **any data type**
- Dynamically manages nodes
- Supports traversal, analysis, and validation
- Handles memory safely using recursive cleanup

---

## 🌿 Tree Initialization & Control

The tree supports flexible root management:

- Create an **empty tree**
- Initialize the tree with a **root value**
- Set the root **only if it does not already exist**
- Reset the value of an **existing root**

This allows full control over how and when the tree starts.

---

## ➕ Node Insertion Strategy

Nodes are inserted using a **path-based approach**:

- Each insertion follows a sequence of:
  - `Left`
  - `Right`
- The tree shape is **fully controlled by the user**
- No automatic ordering or balancing is applied

📌 This design emphasizes **tree structure understanding**, not value ordering.

---

## 🔁 Tree Traversals

Traversal is the core focus of this implementation.

### 🌲 Depth-First Search (DFS)

Supported DFS traversal methods:

- **In-order**  
  - Left → Root → Right
- **Pre-order**  
  - Root → Left → Right
- **Post-order**  
  - Left → Right → Root

These highlight how naturally **recursion** fits tree problems.

---

### 🌊 Breadth-First Search (BFS)

- **Level-order traversal**
- Visits nodes **level by level**
- Implemented using a **queue**
- Helps visualize the tree structure clearly

---

## 📏 Tree Measurements & Analysis

The following analytical operations are supported:

- Calculate **tree height**
- Count **total nodes**
- Count **leaf nodes**
- Find the **maximum value** in the tree

All operations are implemented recursively to reinforce tree decomposition.

---

## 🔍 Searching

- Searches for a value using **DFS**
- Returns whether the value exists anywhere in the tree
- Works regardless of tree shape or insertion order

---

## ✅ Tree Validation

The tree can verify special structural properties:

### Perfect Binary Tree Check

Ensures that:
- Every internal node has **two children**
- All leaf nodes are at the **same depth**

This helps in understanding strict tree constraints.

---

## 🧭 Boundary Traversals

The implementation supports printing:

- **Left boundary**
- **Right boundary**

These traversals analyze the **external shape** of the tree.

---

## 📐 Tree Diameter

- Computes the **diameter of the tree**
- Defined as the **longest path between any two nodes**
- Implemented in **O(n)** time
- Combines height calculation with recursive traversal

💡 A very common **interview problem**.

---

## 🧹 Memory Management

- All nodes are dynamically allocated
- A recursive destructor ensures:
  - No memory leaks
  - Safe cleanup of all nodes
- Memory is fully freed when the tree object is destroyed

---

## ⚠️ Important Notes

- ❌ This is **NOT** a Binary Search Tree (BST)
- ❌ No ordering constraints on values
- ❌ No self-balancing
- ✅ Focus is on **structure**, **recursion**, and **traversals**

---

## 🚀 What to Learn Next

After mastering this Binary Tree implementation, move on to:

- Binary Search Tree (BST)
- Binary Heap
- AVL Tree
- Segment Tree

---

> **"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**  
