# Singly Linked List Implementation in C++

A robust, fully optimized template-based implementation of a Singly Linked List data structure. This project provides a scalable foundation for managing dynamically allocated sequences of nodes using clean pointer manipulation, strict memory leak defenses, and comprehensive sequence analysis operations.

---

## Introduction to Singly Linked Lists

A Singly Linked List is a fundamental linear data structure where elements are not stored in contiguous memory locations like arrays. Instead, each element exists as an independent object called a Node. 

Each node carries two structural identities:
* **The Value:** The raw data block assigned to the node.
* **The Next Pointer:** A memory address pointing toward the subsequent node in the sequence.

The structural entry point to the list is governed by a dedicated pointer named the Head. When the list is initialized empty, the head securely registers a null pointer state. Unlike traditional arrays, a linked list grows and shrinks seamlessly at runtime without triggering heavy memory reallocations or copy overheads.

---

## Operations & Complexity Analysis

### 1. Insertion Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Insert Front** | Pushes a new node to the absolute start of the sequence, updating the head. | $O(1)$ | $O(1)$ |
| **Insert Back** | Traverses forward across the elements to register a new node at the terminal tail. | $O(N)$ | $O(1)$ |
| **Insert at Index** | Step-tracks forward to place a node precisely within a target 0-indexed offset. | $O(N)$ | $O(1)$ |
| **Insert Sorted** | Iterates through a pre-sorted sequence to place an item into its correct numerical position. | $O(N)$ | $O(1)$ |

### 2. Deletion Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Delete Front** | Shifts the main head address forward and immediately frees the initial block allocation. | $O(1)$ | $O(1)$ |
| **Delete Back** | Scans sequentially to the second-to-last node to pop and clear the tail cleanly. | $O(N)$ | $O(1)$ |
| **Delete at Index** | Seeks the specific offset and redirects local node addresses to bridge over the dropped target. | $O(N)$ | $O(1)$ |
| **Delete Specific Value** | Searches the list and extracts the first matching value block instance it encounters. | $O(N)$ | $O(1)$ |

### 3. Searching and Querying Utilities

| Utility | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Is Empty Check** | Validates whether the head pointer is currently registering a null address space. | $O(1)$ | $O(1)$ |
| **Update at Index** | Traverses to a target index position and overwrites its historical payload value. | $O(N)$ | $O(1)$ |
| **Get Nth Node** | Traverses structural blocks sequentially to return a concrete address reference. | $O(N)$ | $O(1)$ |
| **Search Item** | Scans values to return the respective index offset, resolving to negative one if not found. | $O(N)$ | $O(1)$ |
| **Get Max / Get Min** | Scans linear allocations to isolate pointers identifying absolute extreme bounds. | $O(N)$ | $O(1)$ |
| **Count Occurrence** | Tallies the total structural frequency of identical elements inside the list. | $O(N)$ | $O(1)$ |

### 4. Advanced Processing Algorithms

| Algorithm | Strategy & Implementation Mechanics | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Get Midpoint** | **Tortoise and Hare Strategy:** Finds the absolute middle node in a single pass without using the length tracking property. This is achieved by advancing two discrete tracking pointers down the line concurrently—one traveling at a single step interval and the other executing double-step jumps. | $O(N)$ | $O(1)$ |
| **Reverse List** | **In-Place Pointer Reversal:** Inverts the directional orientation of the entire linked list without allocating external tracking nodes. It shifts individual trailing references backward in a single linear pass using three localized state registers. | $O(N)$ | $O(1)$ |
| **Sort List** | **Hybrid Sequence Aggregation:** Extracts node values into a contiguous vector container, applies highly optimized quicksort adjustments via standard library mechanics, and transfers the sorted data back into the existing list layout. | $O(N \log N)$ | $O(N)$ |

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
**g++ -std=c++17 main.cpp -o linked_list_demo**

### Execution
Launch the generated binary file directly within the host console tree:
**./linked_list_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**