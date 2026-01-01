# 🌳 Binary Search Tree (BST)

## 📌 Overview

This section focuses on **Binary Search Trees (BSTs)**, a specialized type of binary tree that allows **efficient searching, insertion, and deletion**.  
Mastering BSTs will make learning AVL trees, Red-Black trees, and other balanced trees much easier.

---

## 🌱 What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a binary tree with the following property:

* For every node:
  * All nodes in the **left subtree** have values **less than** the current node
  * All nodes in the **right subtree** have values **greater than** the current node

This ordering rule enables **efficient searching**.

---

## 🧩 Basic Terminology

* **Root**: The topmost node of the BST  
* **Parent**: A node that has children  
* **Child**: A node connected below a parent  
* **Leaf**: A node with no children  
* **Subtree**: A tree formed from any node and its descendants  
* **BST Property**: Ordering constraint that defines the structure

---

## 📏 Height, Depth, and Level

* **Height of a node**: Number of edges on the longest path from that node to a leaf  
* **Height of a BST**: Height of the root node  
* **Depth of a node**: Number of edges from the root to the node  
* **Level of a node**: Depth + 1  

> ⚠️ In a BST, height affects efficiency:  
> - **Balanced BST**: Height ≈ log₂(n) → optimal operations  
> - **Skewed BST**: Height ≈ n → worst-case operations

---

## 🔁 Tree Traversals

BSTs can be traversed the same way as binary trees.

### Depth-First Search (DFS)

* **In-order (LVR)** → **Sorted Order in BST**  
  Left subtree → Current node → Right subtree

* **Pre-order (VLR)**  
  Current node → Left subtree → Right subtree

* **Post-order (LRV)**  
  Left subtree → Right subtree → Current node

### Breadth-First Search (BFS)

* **Level-order traversal**  
  Visits nodes level by level from left to right

---

## 🧠 Recursive Nature of BSTs

BSTs naturally lend themselves to recursion for most operations:

Typical recursive steps:

1. Handle the base case (null node)  
2. Compare value with current node  
3. Recurse to the **left subtree** if smaller, **right subtree** if larger  

---

## ⚠️ Important Notes

* A **BST is a Binary Tree with an ordering property**  
* Searching, insertion, and deletion rely on this property  
* Efficiency depends on **tree height**  
  - Balanced: O(log n)  
  - Skewed: O(n)

---

## 🧪 Common BST Operations

* **Search** → Check if a value exists  
* **Insert** → Add a new node while maintaining BST property  
* **Delete** → Remove a node while maintaining BST property  
* **Find min / max** → Leftmost / rightmost node  
* **Find predecessor / successor** → Previous / next node in sorted order  
* **Tree traversals** → In-order, pre-order, post-order, level-order  
* **Check if balanced** → Optional, for advanced BSTs  

---

## 🎯 Why BSTs Matter

* Efficient searching, insertion, and deletion  
* Foundation for balanced trees (AVL, Red-Black)  
* Core data structure in databases, maps, and sets  
* Appears frequently in coding interviews  

---

## 🚀 What to Learn Next

After mastering BSTs, move to:

* **AVL Tree** → Self-balancing BST  
* **Red-Black Tree** → Efficient balanced BST  
* **Binary Heap** → Priority queues  

---

> "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"  

