# Dynamic Stack Linked List-Based Implementation in C++

A robust, fully optimized template-based implementation of a Dynamic Stack data structure using an underlying Singly Linked List backbone. This project highlights the implementation of the Last-In, First-Out (LIFO) operational flow using dynamic heap allocation, freeing the stack from fixed capacity limits while ensuring complete memory safety.

---

## Introduction to Linked List-Based Stacks

A Stack is a linear data structure governed strictly by the **Last-In, First-Out (LIFO)** structural paradigm. This principle ensures that the final data element added to the structure is consistently the first element targeted for extraction or removal.

While static stacks rely on a fixed contiguous array, a dynamic stack achieves structural flexibility by utilizing a chain of independent, dynamically allocated elements called Nodes:
* **The Value:** The raw data block assigned to the node.
* **The Next Pointer:** A memory address pointing toward the node directly beneath it in the stack hierarchy.

The entry point of this structure is governed by a single **Head** pointer, which always anchors the topmost element of the stack. Pushing a new item links it to the front of the chain, and popping an item shifts the head pointer down to the next node. This dynamic layout permits endless runtime expansion up to available system memory limits, entirely avoiding stack overflow conditions without requiring costly full-array reallocations.

---

## Operations & Complexity Analysis

### 1. Primary Stack Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Is Empty Check** | Determines whether the head pointer resides at its baseline state of null, signifying an empty condition. | $O(1)$ | $O(1)$ |
| **Push** | Instantly allocates a new node on the heap, sets its forwarding reference to the current head, and re-assigns the head to this new node. | $O(1)$ | $O(1)$ |
| **Pop** | Safely captures the address of the topmost element, updates the head pointer to the subsequent node, and frees the deleted node's memory. | $O(1)$ | $O(1)$ |
| **Top** | Direct-reads and returns the value situated within the node marked by the head pointer without modifying the stack depth. | $O(1)$ | $O(1)$ |

### 2. Searching, Querying, & Modification Utilities

| Utility | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Display Stack** | Traverses downward sequentially from the current head pointer to print active elements in true stack priority order. | $O(N)$ | $O(1)$ |
| **Get Size** | Iterates from the head to the terminal node to count total elements. Built specifically for traversal tracking practice rather than using an auxiliary counter variable. | $O(N)$ | $O(1)$ |
| **Search Item** | Scans the node sequence downward from the top to isolate a target value, returning its 0-based distance index from the top node if found, or negative one if missing. | $O(N)$ | $O(1)$ |

---

## Memory Safety & Resource Management

Operating with individual dynamic heap allocations requires disciplined object management to prevent system memory leaks and segmentation violations.

### Automated Garbage Collection
Unlike an array backbone that can be reclaimed with a single statement, a linked structure requires clean node-by-node deallocation. The class destructor utilizes an explicit loop that continually checks stack status, iteratively invoking the constant-time `pop` sequence until every node is wiped and its resources are safely returned to the operating system.

### Copy Semantics Restraints
Shallow copying of active structures often leaves multiple variables tracking a single set of heap objects, causing severe double-free crashes. To enforce structural integrity, the class explicitly disables both the copy constructor and the copy assignment operator.

---

## Project Execution Guide

### Prerequisite Environment
To compile this code base, utilize an execution wrapper toolchain matching standard C++11 distributions or newer versions.

### Compilation Command
Compile the target source using your favorite console compiler wrapper with conventional optimization parameters:
**g++ -std=c++17 main.cpp -o dynamic_stack_demo**

### Execution
Run the compiled machine binary directly inside your local environment host tree:
**./dynamic_stack_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**