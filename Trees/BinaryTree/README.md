# 🌳 Binary Tree

## 📌 Overview

This section focuses **only on Binary Trees**, which are the foundation of all tree-based data structures.
Understanding binary trees deeply will make learning BSTs, Heaps, AVL trees, and other advanced trees much easier.

---

## 🌱 What is a Binary Tree?

A **Binary Tree** is a tree data structure in which each node has **at most two children**:

* Left child
* Right child

There are **no ordering rules** in a general binary tree.

---

## 🧩 Basic Terminology

* **Root**: The topmost node of the tree
* **Parent**: A node that has children
* **Child**: A node connected below a parent
* **Leaf**: A node with no children
* **Subtree**: A tree formed from any node and its descendants

---

## 📏 Height, Depth, and Level

* **Height of a node**: Number of edges on the longest path from that node to a leaf
* **Height of a tree**: Height of the root node
* **Depth of a node**: Number of edges from the root to the node
* **Level of a node**: Depth + 1

---

## 🔁 Tree Traversals

Traversal is the most important concept in binary trees.

### Depth-First Search (DFS)

DFS explores as deep as possible before backtracking.

* **In-order (LVR)**
  Left subtree → Current node → Right subtree

* **Pre-order (VLR)**
  Current node → Left subtree → Right subtree

* **Post-order (LRV)**
  Left subtree → Right subtree → Current node

### Breadth-First Search (BFS)

* **Level-order traversal**
  Visits nodes level by level from left to right

---

## 🧠 Recursive Nature of Binary Trees

Binary trees are naturally solved using recursion.

Typical recursive steps:

1. Handle the base case (null node)
2. Process the current node
3. Recurse on the left subtree
4. Recurse on the right subtree

---

## ⚠️ Important Notes

* A **Binary Tree is NOT a Binary Search Tree**
* There is no rule such as left < root < right
* Traversals define how the tree is processed

---

## 🧪 Common Binary Tree Operations

* Tree traversals
* Find height of tree
* Count total nodes
* Count leaf nodes
* Check if tree is empty
* Mirror / invert tree
* Check if tree is balanced

---

## 🎯 Why Binary Trees Matter

* Foundation of advanced tree structures
* Improves recursive thinking
* Appears frequently in interviews
* Used in parsing, expression trees, and more


---

## 🚀 What to Learn Next

After mastering Binary Trees, move to:

* Binary Search Tree (BST)
* Binary Heap
* AVL Tree

---

> "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"

**Master the basics. Everything builds on them. 🌱**
