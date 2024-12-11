# Skiplist-Implementation

A skip list is a probabilistic data structure that allows for efficient search, insertion, and deletion of elements in a sorted list. This project demonstrates a simple implementation of a **Skip List** in C++.

## Features

- **Efficient Operations**:
  - Average time complexity for insertion, deletion, and search is **O(log n)**.
- **Levels in Skip List**:
  - Multiple levels allow skipping over large portions of the data, resulting in faster operations compared to standard linked lists.
- **Dynamic Levels**:
  - Levels are determined probabilistically using a "coin toss" mechanism.
    
### Functions Implemented:
1. **Insert**: Adds an element to the skip list.
2. **Remove**: Deletes an element from the skip list.
3. **Search**: Finds an element in the skip list.
4. **Display**: Visualizes the skip list by levels.

### Example Operations:

```cpp
skipList SkipList;

SkipList.insert(10);
SkipList.insert(20);
SkipList.insert(30);

SkipList.display(); // Displays elements by levels

SkipList.search(20); // Searches for an element

SkipList.remove(20); // Removes an element
