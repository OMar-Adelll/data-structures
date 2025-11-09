# 🚀 MyVector<T> - Custom Dynamic Array Implementation in C++

This is a custom implementation of a generic dynamic array (similar to `std::vector`) in C++. It manages memory automatically using a raw array (`T* arr`) and handles resizing (expansion/shrinking) to efficiently store and manipulate elements of any type `T`.

The implementation includes fundamental vector operations, operator overloading, and iterators.

## 🧭 Table of Contents

* [🔒 Private Members & Capacity Management](#-private-members--capacity-management)
    * [Private Data Members](#private-data-members)
    * [Helper Methods (Resizing)](#helper-methods-resizing)
* [🏗️ Constructors, Destructor, and Assignment](#️-constructors-destructor-and-assignment)
* [⚙️ Access and Utility Methods](#️-access-and-utility-methods)
* [➕➖ Modification Methods](#️-modification-methods)
* [🔄 Shift and Rotation Methods](#-shift-and-rotation-methods)
* [🔢 Operator Overloading](#-operator-overloading)
* [🧭 Iterators](#-iterators)

---

## 🔒 Private Members & Capacity Management

The core of the dynamic array is managed by three private members and two helper functions for resizing.

### Private Data Members

| Member | Type | Description |
| :--- | :--- | :--- |
| `arr` | `T*` | Pointer to the dynamically allocated array that holds the elements. |
| `size` | `int` | The number of elements currently stored in the vector. |
| `capacity` | `int` | The total number of elements the internal array can hold before resizing. |

### Helper Methods (Resizing)

| Method | Description | Time Complexity |
| :--- | :--- | :--- |
| `expand_capacity()` | Doubles the internal array capacity and copies elements. | $O(n)$ (Amortized $O(1)$ for `pushBack`) |
| `shrink_capacity()` | Halves the internal array capacity and copies elements. | $O(n)$ |

---

## 🏗️ Constructors, Destructor, and Assignment

| Method | Description | Time Complexity |
| :--- | :--- | :--- |
| `MyVector()` | Default constructor. Initializes with `size = 0` and `capacity = 10`. | $O(1)$ |
| `MyVector(int size)` | Parameterized constructor. Initializes array with a specified `size` and `capacity = size + 10`. | $O(1)$ (Excluding potential default element initialization) |
| `MyVector(const MyVector &other)` | **Copy Constructor**. Performs a deep copy of the other vector's state and data. | $O(n)$ |
| `~MyVector()` | **Destructor**. Frees the dynamically allocated memory (`delete[] arr`). | $O(1)$ |
| `operator=(const MyVector<T> &other)` | **Assignment Operator**. Performs a deep copy and handles self-assignment. | $O(n)$ |

---

## ⚙️ Access and Utility Methods

These methods provide basic inspection and data retrieval functionalities.

| Method | Description | Time Complexity |
| :--- | :--- | :--- |
| `set(T val, int idx)` | Sets the value at a specified index (`assert`s valid index). | $O(1)$ |
| `get(int idx)` | Returns the value at a specified index (`assert`s valid index). | $O(1)$ |
| `getFront()` | Returns the first element (`assert`s non-empty). | $O(1)$ |
| `getBack()` | Returns the last element (`assert`s non-empty). | $O(1)$ |
| `find(T val)` | Finds the first occurrence of `val` and returns its index, or $-1$ if not found. | $O(n)$ |
| `getSize()` | Returns the current number of elements (`size`). | $O(1)$ |
| `getCapacity()` | Returns the current capacity. | $O(1)$ |
| `getMax()` | Returns the maximum element in the vector. | $O(n)$ |
| `getMin()` | Returns the minimum element in the vector. | $O(n)$ |
| `print()` | Prints all elements to the console. | $O(n)$ |
| `isempty()` | Checks if the vector is empty (`size == 0`). | $O(1)$ |

---

## ➕➖ Modification Methods

| Method | Description | Time Complexity | Notes |
| :--- | :--- | :--- | :--- |
| `pushBack(T val)` | Appends `val` to the end. Expands capacity if full. | $O(1)$ Amortized | $O(n)$ in worst-case (expansion). |
| `popBack()` | Removes the last element (`assert`s non-empty). Shrinks capacity if below threshold. | $O(1)$ Amortized | $O(n)$ in worst-case (shrinking). |
| `pushFront(T val)` | Inserts `val` at the beginning. Requires shifting all existing elements. | $O(n)$ | |
| `popFront()` | Removes the first element. Requires shifting all subsequent elements. | $O(n)$ | |
| `insertAt(T item, int idx)` | Inserts `item` at `idx`. Requires shifting elements. | $O(n)$ | |
| `deleteAt(int idx)` | Deletes element at `idx`. Requires shifting elements. | $O(n)$ | |
| `Clear()` | Resets the `size` to 0. | $O(1)$ | Memory is not released; capacity remains the same. |
| `Sooort()` | Sorts the elements using `std::sort`. | $O(n \log n)$ | |
| `Reverse()` | Reverses the order of the elements. | $O(n)$ | Implemented by copying to a temporary array. |

---

## 🔄 Shift and Rotation Methods

| Method | Description | Time Complexity | Notes |
| :--- | :--- | :--- | :--- |
| `shiftRight()` | Rotates the array one position to the right (last element becomes first). | $O(n)$ | |
| `shiftLeft()` | Rotates the array one position to the left (first element becomes last). | $O(n)$ | |
| `shiftLeft_times(int n)` | Rotates the array `n` times to the left (using a temporary array). | $O(n)$ | Handles $n \ge size$ by using $n \pmod{size}$. |
| `shiftRight_times(int n)` | Rotates the array `n` times to the right (using a temporary array). | $O(n)$ | Handles $n \ge size$ by using $n \pmod{size}$. |

---

## 🔢 Operator Overloading

| Operator | Signature | Description | Time Complexity |
| :--- | :--- | :--- | :--- |
| Subscript | `T &operator[](int idx)` | Access element at `idx` (for non-const objects). | $O(1)$ |
| Const Subscript | `const T &operator[](int idx) const` | Access element at `idx` (for const objects). | $O(1)$ |

---

## 🧭 Iterators

The class provides basic raw pointer iterators to allow use in C++ range-based for loops and standard algorithms:

| Method | Type | Description |
| :--- | :--- | :--- |
| `begin()` | `T*` | Returns a pointer to the first element (`arr`). |
| `end()` | `T*` | Returns a pointer to one past the last element (`arr + size`). |