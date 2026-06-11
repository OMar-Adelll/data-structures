# Doubly Linked List Implementation in C++

A robust, fully optimized template-based implementation of a Doubly Linked List data structure. This project provides a scalable foundation for managing dynamically allocated sequences of nodes using bidirectional pointer manipulation, strict memory leak defenses, and comprehensive sequence cleanup operations.

---

## Introduction to Doubly Linked Lists

A Doubly Linked List is an advanced linear data structure that improves upon the Singly Linked List model by enabling bidirectional traversal. Instead of tracking only the succeeding elements, each node maintains two independent pointer links.

Each node carries three structural identities:
* **The Value:** The raw data block assigned to the node.
* **The Next Pointer:** A memory address pointing toward the subsequent node in the sequence.
* **The Previous Pointer:** A memory address pointing toward the preceding node in the sequence.

The entry point to the list is managed by a single Head pointer. When the structure is empty, the head securely registers a null pointer state. The inclusion of the previous pointer eliminates the limitation of forward-only traversal, allowing for more intuitive node updates and structural modifications.

---

## Operations & Complexity Analysis

### 1. Insertion Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Insert Front** | Pushes a new node to the absolute start of the sequence, linking it with the current head and isolating its previous reference. | $O(1)$ | $O(1)$ |
| **Insert Back** | Traverses forward across the elements to register a new node at the terminal tail, establishing a two-way link with the old tail. | $O(N)$ | $O(1)$ |
| **Insert at Index** | Step-tracks forward to place a node precisely within a target 0-indexed offset, realigning both forward and backward pointer paths. | $O(N)$ | $O(1)$ |

### 2. Deletion Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Delete Front** | Shifts the head address forward, breaks the trailing link of the new head node, and frees the initial block allocation. | $O(1)$ | $O(1)$ |
| **Delete Back** | Scans sequentially to the second-to-last node to pop and clear the tail node cleanly. | $O(N)$ | $O(1)$ |
| **Delete at Index** | Seeks the specific offset and redirects adjacent forward and backward pointer paths to bridge over the dropped target. | $O(N)$ | $O(1)$ |

### 3. Searching, Querying, & Modification Utilities

| Utility | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Is Empty Check** | Validates whether the head pointer is currently registering a null address space. | $O(1)$ | $O(1)$ |
| **Update at Index** | Traverses to a target index position and overwrites its historical payload value. | $O(N)$ | $O(1)$ |
| **Display List** | Iterates forward from the head, streaming every element to standard output in linear order. | $O(N)$ | $O(1)$ |

### 4. Advanced Processing Algorithms

| Algorithm | Strategy & Implementation Mechanics | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Delete All Nodes With Key** | **Targeted Extraction Sweep:** Iterates through the entire structure to identify and erase every single node matching a target search key. It handles specific structural edge cases automatically, adapting pointer re-linkage depending on whether the matching node is the head, the tail, or locked within an internal segment. | $O(N)$ | $O(1)$ |

---

## Memory Safety & Resource Management

This structure uses strict defensive programming principles to maintain runtime durability and eliminate memory vulnerabilities.

### Automated Garbage Collection
The class destructor is explicitly engineered to handle sequential data cleanups. When the parent object goes out of scope, a trailing loop walks through every allocated node block to call memory deallocations, safely wiping the heap segments.

### Copy Semantics Restraints
Shallow copying of active structures often leaves multiple variables tracking a single set of heap objects, causing severe double-free crashes. To enforce structural integrity, the class explicitly deletes both the copy constructor and the copy assignment operator.

---

## Project Execution Guide

### Prerequisite Environment
To compile this code, use an environment that supports standard C++11 distributions or newer versions.

### Compilation Command
Compile your execution file using any terminal wrapper with standard optimization settings:
**g++ -std=c++17 main.cpp -o doubly_list_demo**

### Execution
Launch the generated binary file directly within the host console tree:
**./doubly_list_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**