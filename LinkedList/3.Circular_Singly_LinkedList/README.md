# Circular Singly Linked List Implementation in C++

A robust, fully optimized template-based implementation of a Circular Singly Linked List data structure. This project provides a scalable foundation for managing dynamically allocated nodes connected in a continuous ring configuration using smart pointer cycling, clean boundary management, and automated resource cleanup.

---

## Introduction to Circular Singly Linked Lists

A Circular Singly Linked List is a variations of the classical linear linked list data structure. Instead of ending with a final terminal node that targets a null address space, the last node in this architecture redirects its forwarding link right back to the initial starting block.

Each node carries two structural identities:
* **The Value:** The raw data block assigned to the node.
* **The Next Pointer:** A memory address pointing toward the subsequent node in the sequence.

Because the final item links back to the entry point, the sequence forms a closed loop. This structural design eliminates traditional boundaries, meaning no node ever naturally evaluates to a null state. This loop structure requires iterative cycles or specialized evaluations to read, parse, and process the items without generating infinite loops during structural executions.

---

## Operations & Complexity Analysis

### 1. Insertion Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Insert Front** | Adds a new node before the current head. Requires traversing the entire ring to identify the tail node so its trailing reference can be updated to link back to the newly established head position. | $O(N)$ | $O(1)$ |
| **Insert Back** | appends a node to the terminal point of the ring. This operation steps through the layout to expose the tail, binds it to the incoming block, and safely wraps the new node's reference around to point to the head. | $O(N)$ | $O(1)$ |
| **Insert at Index** | Step-tracks forward to place a node precisely within a target 0-indexed offset, altering localized node directions seamlessly. | $O(N)$ | $O(1)$ |

### 2. Deletion Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Delete Front** | Locates the structural tail node via sequence traversal, shifts the main head pointer forward to the next index, updates the tail to match the new head, and drops the old head allocation. | $O(N)$ | $O(1)$ |
| **Delete Back** | Loops sequentially to pinpoint the second-to-last node, safely drops the existing tail item, and bends the new tail's forward connection back into the head pointer. | $O(N)$ | $O(1)$ |
| **Delete at Index** | Seeks the specific offset position and re-links adjacent forward pointer paths to bridge cleanly over the deleted target block. | $O(N)$ | $O(1)$ |

### 3. Searching, Querying, & Modification Utilities

| Utility | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Is Empty Check** | Validates whether the root head pointer is currently registering an inactive null address space. | $O(1)$ | $O(1)$ |
| **Update at Index** | Traverses straight to a target index position and overwrites its historical payload value with the incoming data. | $O(N)$ | $O(1)$ |
| **Display List** | Leverages a specialized execution state to securely parse and read nodes in order, safely terminating the layout readout exactly when the loop shifts back onto the head reference. | $O(N)$ | $O(1)$ |

---

## Memory Safety & Circular Loop Management

Operating on circular lists introduces unique memory allocation challenges. Traditional linear data structure loops terminate naturally when encountering null addresses, whereas an unmanaged loop inside a circular structure can trigger catastrophic infinite iterations or memory leakage.

### Ring-Aware Garbage Collection
The standard class destructor uses explicit ring-aware traversal logic. When the data structure falls out of local operational scope, the cleanup engine uses temporary variables to systematically decouple the nodes one by one. It records succeeding addresses before safely freeing current heap block resources, continuing until the tracking reference returns to the starting head position.

### Structural Integrity Constraints
To prevent dangerous double-free runtime segmentation faults caused by shallow object copies, both the class copy constructor and the assignment operators are safely restricted. This forces cleaner scoping behaviors across processing operations.

---

## Project Execution Guide

### Prerequisite Environment
To compile this code base, use a developer compilation toolchain that fully supports current C++11 standard configurations or newer versions.

### Compilation Command
Compile your execution file using any terminal wrapper with standard optimization settings:
**g++ -std=c++17 main.cpp -o circular_list_demo**

### Execution
Launch the generated binary file directly within the host console tree:
**./circular_list_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**