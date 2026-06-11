# Array-Based Static Stack Implementation in C++

A robust, fully optimized template-based implementation of a Static Stack data structure using sequential array allocation. This project highlights foundational Last-In, First-Out (LIFO) operational flow, bounds constraint management, recursive stack reorientation, and linear memory safety.

---

## Introduction to Array-Based Static Stacks

A Stack is a linear data structure governed strictly by the **Last-In, First-Out (LIFO)** structural paradigm. This principle ensures that the final data element committed to the structure is consistently the initial element targeted for extraction or removal.

Each stack manages data elements through two primary constraints:
* **The Static Array Backbone:** A contiguous memory buffer fixed in size at the moment of object initialization.
* **The Top Index Tracker:** A specialized relative memory pointer offset tracking the upper boundary element. It initializes at negative one, signifying an empty condition, and acts as the gatekeeper for element adjustments.

Unlike dynamic data structures, static array stacks operate within hard allocation bounds. This predictability offers exceptionally low memory overhead and predictable instruction caching, but it requires runtime checking to handle stack overflow and underflow risks cleanly.

---

## Operations & Complexity Analysis

### 1. Primary Stack Operations

| Operation | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Is Full Check** | Interrogates the top pointer offset to verify if it matches the maximal allocated capacity threshold minus one. | $O(1)$ | $O(1)$ |
| **Is Empty Check** | Determines whether the top pointer resides at its baseline initialization state of negative one. | $O(1)$ | $O(1)$ |
| **Push** | Safely increments the top pointer reference and inserts an item into the updated index, provided the stack is not full. | $O(1)$ | $O(1)$ |
| **Pop** | Decrements the upper pointer tracking index to effectively remove the topmost element, provided the stack contains active elements. | $O(1)$ | $O(1)$ |
| **Peek** | Directly references and returns the current element situated at the top tracking index without mutating structural states. | $O(1)$ | $O(1)$ |

### 2. Specialized & Non-Standard Utilities

| Utility | Description | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Display Stack** | Traverses downward linearly from the current top index to zero, displaying active elements in stack priority order. | $O(N)$ | $O(1)$ |
| **Reversed Display** | Traverses upward from index zero to the current top tracking offset, displaying items in order of original entry. | $O(N)$ | $O(1)$ |
| **Print and Pop** | Combined compound operation that captures the value of the top element, drops the tracker index, and returns the data block. | $O(1)$ | $O(1)$ |
| **Pop and Push** | Performs an in-place value replacement at the current top tracking index, updating the newest item without modifying structural depth. | $O(1)$ | $O(1)$ |
| **Search Item** | Scans items downward from the top to find a target value. Returns its relative 0-based distance from the top element if found, or negative one if missing. | $O(N)$ | $O(1)$ |

### 3. Advanced Core Algorithms

| Algorithm | Strategy & Implementation Mechanics | Time Complexity | Space Complexity |
| :--- | :--- | :---: | :---: |
| **Push Bottom** | **Linear Boundary Modification:** Forces an element into the baseline index zero position. To achieve this, it increments the structural top tracker and shifts all pre-existing elements up by one index offset to make room for the new entry. | $O(N)$ | $O(1)$ |
| **Reverse Stack** | **Pure Functional Recursion:** Reorients the stack items without relying on external loops or secondary data containers. It unwinds the elements onto the function call stack recursively, strips the stack structure empty, and utilizes the localized linear shifting mechanics of push-bottom to reconstruct the sequence upside down. | $O(N^2)$ | $O(N)$ |

---

## Memory Safety & Bounds Engineering

Operating on fixed-size array buffers requires disciplined resource allocation and boundary guarding to prevent fatal system runtime violations.

### Resource Acquisition Is Initialization (RAII)
The stack architecture embraces native RAII tenets. Dynamic buffer allocation happens exactly at initialization on the heap segment via explicit sizing constructors. 

### Automated Deallocation
To guarantee protection against silent memory leaks or orphaned allocations, the standard destructor maps directly to an explicit array delete statement. When the stack goes out of active operational scope, the entire underlying heap array block is safely reclaimed by the operating system.

---

## Project Execution Guide

### Prerequisite Environment
To compile this code base, utilize an execution wrapper toolchain matching standard C++11 distributions or newer versions.

### Compilation Command
Compile the target source using your favorite console compiler wrapper with conventional optimization parameters:
**g++ -std=c++17 main.cpp -o static_stack_demo**

### Execution
Run the compiled machine binary directly inside your local environment host tree:
**./static_stack_demo**

---
**"وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"**