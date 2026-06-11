# Generic Queue based on LinkedList Implementation in C++

A robust, fully optimized template-based implementation of a Generic Queue data structure backed by a custom Singly Linked List. This project provides a scalable foundation for managing dynamically allocated FIFO (First-In, First-Out) sequences using clean pointer manipulation, strict memory leak defenses, and clear separation of structural layers.

---

## Introduction to Queue & Singly Linked Lists

A **Singly Linked List** is a linear data structure where elements are not stored in contiguous memory locations. Instead, each element exists as an independent object called a **Node**. Each node carries a data payload and a pointer linking it to the subsequent node in the sequence. 

A **Queue** leverages this architecture to implement a strict **FIFO (First-In, First-Out)** access policy. By encapsulating the linked list, the queue ensures that elements are appended exclusively at the back (tail) and removed exclusively from the front (head). This bypasses static array sizing boundaries, allowing the queue to grow and shrink seamlessly at runtime.

---

## Operations & Complexity Analysis

### 1. LinkedList Core Operations

The underlying `LinkedList` class acts as the data container, managing memory allocation, node stepping, and low-level sequence traversal.

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **IsEmpty Check** | Validates whether the head pointer is currently registering a null address space (`head == nullptr`). | O(1) | O(1) |
| **Insert Back** | Dynamically allocates a new node and traverses forward across existing elements to attach it at the terminal tail. | O(N) | O(1) |
| **Get Front** | Safely evaluates and returns the value stored at the root head node. Returns a default-initialized type if empty. | O(1) | O(1) |
| **Delete Front** | Shifts the main head address forward to the next node and immediately frees the previous node's memory allocation. | O(1) | O(1) |
| **Display List** | Iterates sequentially from head to tail, outputting all node values to the standard console stream. | O(N) | O(1) |
| **Search Item** | Scans values linearly to return its respective 0-indexed offset. Terminates the program safely if called on an empty sequence or returns -1 if not found. | O(N) | O(1) |

### 2. High-Level Queue Operations

The `Queue` class exposes a clean, industry-standard interface that wraps the underlying list mechanics to enforce proper queue constraints.

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **enQueue** | Pushes a new element onto the back of the queue by invoking the underlying sequential tail insertion. | O(N) | O(1) |
| **deQueue** | Dispatches and pops the oldest active item at the front of the queue by advancing the root boundary. | O(1) | O(1) |
| **front** | Inspects and reads the payload value located at the absolute front of the queue without extracting it. | O(1) | O(1) |
| **empty** | Queries the queue's state to return a boolean status indicating if any elements are actively queued. | O(1) | O(1) |
| **display** | Visualizes the internal state of the queue by streaming elements from front to back. | O(N) | O(1) |

---

## Memory Safety & Resource Management

This structure incorporates strict defensive programming practices to ensure total system stability and prevent runtime vulnerabilities.

### Automated Garbage Collection
The class destructor is explicitly engineered to handle recursive heap cleanup. When the queue or list object falls out of scope, a specialized linear sweep runs through every allocated node block, capturing local pointers in temporary registers and safely deallocating them via the native `delete` construct until a terminal null pointer state is achieved.

### Copy Semantics Restraints
Shallow copying of dynamic memory references can cause severe double-free errors and undefined behavior. To protect the structural integrity of your allocations, both the **Copy Constructor** and the **Copy Assignment Operator** are explicitly disabled (`= delete`), making the container entirely leak-safe.

---

## Project Execution Guide

### Prerequisite Environment
To compile and run this code, use a development environment equipped with a compiler toolchain supporting standard C++11 distributions or newer.

### Compilation Command
Compile your implementation using standard optimization configurations:
**g++ -O3 -std=c++17 main.cpp -o queue_demo**

### Execution
Launch the generated binary file directly within your host console environment:
**./queue_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**