# Array-Based Circular Queue Implementation in C++

A robust, template-driven, and capacity-optimized implementation of a Circular Queue data structure written in C++. This implementation leverages a dynamically allocated fixed-size array combined with modular index arithmetic to achieve optimal resource reuse, making it highly suitable for high-performance applications and competitive programming.

---

## Introduction to Circular Queues

A **Circular Queue** is an advanced variation of the standard linear queue data structure designed to solve the memory efficiency limitations of static arrays. In a standard array-based queue, once elements are removed from the front, the vacated slots become unusable dead spaces unless all remaining items are costly shifted backward.

This implementation circumvents that limitation by treating the underlying fixed array as a continuous loop. Utilizing a specialized indexing mechanism, the tracking registers transition seamlessly from the absolute terminal boundary of the allocation back to the initial starting index. This architecture enables:
* **Index Wraparound:** The collection reclaims previously freed front storage slots automatically as long as the total current element volume does not exceed the initialized maximum capacity.
* **Predictable Boundaries:** The queue maintains a strict state tracking map using internal tracking markers for the absolute head, the current trailing insertion node, and the active collection density count.

---

## Operations & Complexity Analysis

### 1. Core State & Utility Operations

These low-level operations monitor structural saturation and calculate structural boundaries across the circular data boundary.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`empty`** | Validates if the active collection density count is exactly zero. | O(1) | O(1) |
| **`isFull`** | Validates if the current internal element count matches the maximum allocated array capacity limit. | O(1) | O(1) |
| **`next`** | Performs standard modular wraparound math using the total size configuration to shift a given index reference forward safely. | O(1) | O(1) |
| **`getCount`** | Directly returns the total number of items currently resident inside the active circular sequence. | O(1) | O(1) |

### 2. Insertion & Enqueue Operations

These methods manage appending incoming items into the queue structure, validating resource headroom prior to insertion.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`enQueue`** | Appends a single item to the rear tracking index by advancing the boundary wrapper, if the buffer is not saturated. | O(1) | O(1) |
| **`enQueueN`** | Evaluates a vector container of input values and appends them in sequential succession if total combined slot capacity allows. | O(M) | O(1) |

### 3. Dequeue & Evacuation Operations

These variations handle item removal and structural clearance, supporting bulk extractions and custom terminal formatting.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`deQueue`** | Extracts and purges the single oldest active item resting at the front boundary by shifting the tracking register forward. | O(1) | O(1) |
| **`deQueueN`** | Quietly purges up to a user-specified number of elements from the front of the queue without outputting their values. | O(M) | O(1) |
| **`deQueueN_withDisplay`** | Purges elements from the front up to a specific threshold, while immediately streaming their values to the standard console. | O(M) | O(1) |
| **`dequeueN_elements`** | Extracts a specific volume of elements out of the front boundary, returning them packaged inside an isolated standard vector array. | O(M) | O(M) |

### 4. Inspection & Search Utilities

These methods facilitate item localization and structure scanning without causing structural modification to the underlying array.

| Operation / Method | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **`Front`** | Safely peeks at the value residing at the current front index. Automatically safely aborts execution if called on empty storage. | O(1) | O(1) |
| **`display`** | Iterates through the active circular layout from front to rear, rendering the exact current sequence to the console. | O(N) | O(1) |
| **`searchItem`** | Linearly scans active memory positions starting from the front element, returning a relative 0-indexed layout position if found, or -1 if absent. | O(N) | O(1) |

---

## Memory Safety & Resource Management

This structure uses clean, automated allocations to preserve runtime predictability and defend against resource allocation vulnerabilities.

### Contiguous Heap Lifecycle
Upon instantiation, the class constructor accepts a fixed target size parameter and assigns a single, contiguous block of heap memory using native array allocation patterns. This minimizes heap fragmentation by localizing all elements together in standard hardware configurations.

### Deterministic Deallocation Cleanup
The class destructor guarantees deterministic garbage collection. When the instantiation scope terminates or the object lifecycle ends, the layout invokes an explicit array pointer block deletion, successfully returning the allocated memory block back to the host operating system.

---

## Project Execution Guide

### Prerequisite Environment
To compile and build this code package, ensure your local development system is equipped with a modern toolchain supporting C++11 up to C++23 standards.

### Compilation Command
Compile your main operational file through any standard bash console using optimized compilation routines:
**g++ -O3 -std=c++17 main.cpp -o static_queue_demo**

### Execution Tracking
Launch the generated binary output execution file directly inside your terminal tree:
**./static_queue_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**