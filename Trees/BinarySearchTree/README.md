# 🌳 MyBST — Binary Search Tree Implementation in C++

This repository contains a **Binary Search Tree (BST) implementation in C++**. It supports **insertion, deletion, searching, and traversal** operations. This BST is **generic** and designed to work with any comparable data type, while **avoiding duplicate values**.

---

## 📌 Key Features

* **Generic Design:** Works with integers, floats, strings, or any type that can be compared.  
* **No Duplicates Allowed:** Automatically ignores duplicate values.  
* **Traversals Supported:** In-order, pre-order, and post-order traversal methods.  
* **Minimum and Maximum Queries:** Quickly retrieve the smallest or largest value.  
* **Search Functionality:** Check whether a value exists in the tree.  
* **Safe Memory Management:** Automatically cleans up all nodes when the BST is destroyed.  
* **Robust Deletion:** Handles removal of leaf nodes, nodes with one child, and nodes with two children correctly.

---

## 🌱 Core Concepts

### Binary Search Tree (BST)

A BST is a type of binary tree that maintains an **ordering property**:

* All nodes in the left subtree have smaller values than the current node.  
* All nodes in the right subtree have larger values than the current node.  

This property allows **efficient searching, insertion, and deletion**.

---

### Traversals

BST operations often rely on **tree traversal**:

* **In-order Traversal:** Visits nodes in ascending order.  
* **Pre-order Traversal:** Visits the current node before its children.  
* **Post-order Traversal:** Visits the current node after its children.  

These traversals help with operations like printing, copying, or deleting nodes.

---

### Node Deletion

Deleting nodes is handled carefully depending on the situation:

* **Leaf Node:** Simply removed.  
* **Node with One Child:** Child replaces the deleted node.  
* **Node with Two Children:** The in-order successor is used to maintain the BST property.

---

### Searching and Min/Max Queries

* **Search:** Efficiently checks if a value exists by leveraging the BST ordering.  
* **Minimum Value:** The leftmost node in the tree.  
* **Maximum Value:** The rightmost node in the tree.  

These operations are recursive and depend on the tree’s structure.

---

## ⚙️ Implementation Highlights

* **Recursive Design:** Most operations are implemented recursively for clarity.  
* **Template-Based:** Supports a wide variety of data types.  
* **Automatic Cleanup:** Prevents memory leaks by deleting all nodes when the BST is destroyed.  
* **Duplicate Handling:** Ensures the tree contains unique values.  

---

## ⏱ Time Complexity

| Operation        | Average Case | Worst Case |
|-----------------|--------------|------------|
| Search           | O(log n)     | O(n)       |
| Insertion        | O(log n)     | O(n)       |
| Deletion         | O(log n)     | O(n)       |
| Traversals       | O(n)         | O(n)       |
| Find Min / Max   | O(log n)     | O(n)       |

> Worst-case occurs when the BST becomes skewed (all nodes on one side), creating a structure similar to a linked list.

---

## 🌟 Benefits

* Efficient searching, insertion, and deletion for sorted data.  
* Provides a solid foundation for advanced trees like **AVL Trees** and **Red-Black Trees**.  
* Helps develop a deeper understanding of **recursive data structures**.  
* Ideal for learning, educational projects, and small-scale applications.

---

## 🚀 Next Steps

After mastering this BST, you can explore:

* **Balanced BSTs:** Ensure O(log n) operations even in the worst case.  
* **AVL Trees:** Self-balancing BSTs with strict height constraints.  
* **Red-Black Trees:** Balanced BSTs used in standard libraries and databases.  
* **Binary Heaps:** Specialized tree for efficient priority-based operations.

---

> "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
