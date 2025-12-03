# Queue Data Structure

## 📌 Introduction
This README explains **how a Queue works**, the **cycle (circular behavior)** of a queue implemented with arrays, and why we **cannot use a normal linear array** for a queue but **CAN use a circular array**. It also includes tables, diagrams, and links to your implementations of:
- **Circular Array Queue**
- **Linked List Based Queue**

---

## 🔄 What Is the Queue Cycle?
A **Queue (FIFO: First In First Out)** inserts elements from the **rear** and removes elements from the **front**.

In a normal array implementation:
- You increment `front` when dequeuing
- You increment `rear` when enqueuing

But eventually, `rear` reaches the end of the array, even if the front part still has empty spaces.

This creates the **Queue Overflow Problem**.

### ❌ Problem With Linear Array Queue
| Operation | front | rear | Array State | Can Add New? |
|----------|--------|-------|--------------|----------------|
| Start | 0 | -1 | `[ _ _ _ _ ]` | Yes |
| enqueue 10 | 0 | 0 | `[10 _ _ _ ]` | Yes |
| enqueue 20 | 0 | 1 | `[10 20 _ _ ]` | Yes |
| dequeue → 10 | 1 | 1 | `[10 20 _ _ ]` | Yes |
| enqueue 30 | 1 | 2 | `[10 20 30 _ ]` | Yes |
| enqueue 40 | 1 | 3 | `[10 20 30 40]` | Yes |
| dequeue → 20 | 2 | 3 | `[10 20 30 40]` | Yes |
| enqueue 50 | 2 | 4 ❗ | `[10 20 30 40 50]` | **No (Overflow)** |

Even though indexes `0` and `1` are empty, we **cannot use them** because `rear` cannot move past the array.

This is why **normal arrays fail** for queues.

---

## 🔁 Why Circular Arrays Fix This Problem
A **Circular Queue** connects the end of the array back to the beginning:
```
rear = (rear + 1) % size
front = (front + 1) % size
```

This allows the queue to cycle around and reuse freed spaces.

### ✔ Circular Array Behavior
| Operation | front | rear | Array State | Full? |
|----------|--------|-------|--------------|--------|
| Start | 0 | 0 | `[ _ _ _ _ ]` | No |
| enqueue 10 | 0 | 1 | `[10 _ _ _ ]` | No |
| enqueue 20 | 0 | 2 | `[10 20 _ _ ]` | No |
| dequeue → 10 | 1 | 2 | `[10 20 _ _ ]` | No |
| enqueue 30 | 1 | 3 | `[10 20 30 _ ]` | No |
| enqueue 40 | 1 | 4 | `[10 20 30 40]` | No |
| enqueue 50 | 1 → stays, rear = (4+1)%4 = 1 | `[50 20 30 40]` | Yes |

Now `rear` moved back to index `0` because of modulo operation.

**No wasted space.**

### 🔥 Key Advantages of Circular Array Queue
- Efficient use of array space  
- No shifting needed  
- Simple O(1) operations  

---

## 📚 Circular Array Queue vs Linked List Queue

| Feature | Circular Array Queue | Linked List Queue |
|---------|------------------------|----------------------|
| Space | Fixed | Dynamic (grows automatically) |
| Overflow | Possible | Impossible unless memory full |
| Speed | O(1) | O(1) |
| Implementation | Harder (mod logic) | Easier |

---

# ⭐ Priority Queue

## 📌 What Is a Priority Queue?
A **Priority Queue** is a special type of queue where **elements are not served in FIFO order**, but instead based on their **priority**.

- Higher priority elements are removed first (Max-Heap)
- Or lower priority elements are removed first (Min-Heap)

## ✔ Characteristics
- Implemented using **Heap** (binary heap is most common)
- Insert → O(log n)
- Remove highest priority → O(log n)
- Access top priority → O(1)

## 📘 Example Use Cases
- Task scheduling
- Dijkstra’s shortest path algorithm
- CPU job scheduling
- Event simulation systems

----

## 📂 Code Implementations
Below are links to your queue implementations:

### 🔗 Circular Array Queue
[View Circular Array Queue Implementation](https://github.com/OMar-Adelll/data-structures/blob/main/Queue/Circular_Array_Queue.cpp)
### 🔗 Linked List Queue 
[View Linked List Queue Implementation](https://github.com/OMar-Adelll/data-structures/blob/main/Queue/Queue.cpp)
### 🔗 Linked List Priority Queue 
[View Linked List Priority Queue Implementation](https://github.com/OMar-Adelll/data-structures/blob/main/Queue/PriorityQueue.cpp)


---

## 📝 Summary
- Normal array queue fails because **rear cannot reuse empty space**.
- Circular array solves the problem using **modulo arithmetic**.
- Linked list queue is fully dynamic.
- Both implementations are valid, but circular queue is more memory-efficient when the max size is known.

---




