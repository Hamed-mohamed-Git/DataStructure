# Data Structures Documentation

## Table of Contents
1. [Overview](#overview)
2. [Program Structure](#program-structure)
3. [Node Class](#node-class)
4. [List Class](#list-class)
5. [CursorList Class](#cursorlist-class)
6. [Utility Functions](#utility-functions)
7. [Usage Examples](#usage-examples)

---

## Overview

This project implements two different linked list data structures in C++:
- **List**: A traditional linked list with head and tail pointers
- **CursorList**: A cursor-based linked list that maintains a current position (cursor) for navigation

Both implementations provide comprehensive operations for insertion, deletion, searching, and traversal of linked lists.

---

## Program Structure

### Main Program (`main.cpp`)

The main program provides a menu-driven interface that allows users to interact with either the `List` or `CursorList` implementations.

**Features:**
- Interactive menu system
- Option to switch between List and CursorList
- Clean exit mechanism

**Menu Options:**
1. Work with List
2. Work with CursorList
0. Exit Program

---

## Node Class

**Location:** `Node/Node.h`

The `Node` class is the fundamental building block for both list implementations.

### Structure
```cpp
class Node {
public:
    int data;      // The data stored in the node
    Node *next;    // Pointer to the next node
    Node();        // Default constructor
};
```

### Constructor
- Initializes `data` to 0 and `next` to `nullptr`

### Helper Function
- `createNewNode(int data)`: Creates a new node with the specified data value

---

## List Class

**Location:** `List/List.h` and `List/List.cpp`

A traditional singly linked list implementation with head and tail pointers.

### Private Members
- `Node *head`: Pointer to the first node in the list
- `Node *tail`: Pointer to the last node in the list
- `int index`: Tracks the current size/index of the list

### Public Methods

#### Construction & State
- **`List()`**: Constructor - initializes an empty list
- **`~List()`**: Destructor - cleans up all nodes
- **`bool search(int data) const`**: Searches for a value in the list
    - Returns `true` if found, `false` otherwise
- **`bool isEmpty() const`**: Checks if the list is empty
- **`int size() const`**: Returns the number of elements in the list

#### Insertion Operations
- **`void insert(int data)`**: Inserts an element at the end of the list
- **`void insertFirst(int data)`**: Inserts an element at the beginning of the list
- **`void insertAt(int data, int index)`**: Inserts an element at a specific index
    - If index is out of bounds, appends to the end
    - If index is 0, inserts at the beginning

#### Deletion Operations
- **`void deleteFirst()`**: Removes the first element
- **`void deleteLast()`**: Removes the last element
- **`void deleteAt(int index)`**: Removes an element at a specific index
- **`void makeListEmpty()`**: Removes all elements from the list

#### Display & Interaction
- **`void traverse() const`**: Displays all elements in the list (comma-separated)
- **`void handleSelection(int selection)`**: Handles menu selections and executes corresponding operations
- **`static void displayMenu()`**: Displays the interactive menu

### Menu Options (List)
1. Add element
2. Add element at beginning
3. Add element at Index
4. Remove element at Index
5. Remove first element
6. Remove last element
7. Remove all elements
8. Display list
9. Display size
10. Search
11. Is Empty
0. Exit

### Time Complexity
- **Insertion at end**: O(1) - uses tail pointer
- **Insertion at beginning**: O(1)
- **Insertion at index**: O(n) - requires traversal
- **Deletion**: O(n) for arbitrary position, O(1) for first element
- **Search**: O(n)
- **Traversal**: O(n)

---

## CursorList Class

**Location:** `cursorList/CursorList.h` and `cursorList/CursorList.cpp`

A cursor-based linked list that maintains a current position (cursor) for efficient navigation and operations relative to the cursor position.

### Private Members
- `NodePointer head`: Pointer to the first node
- `NodePointer cursor`: Pointer to the current node (cursor position)
- `NodePointer prev`: Pointer to the node before the cursor

### Public Methods

#### Construction & State
- **`CursorList()`**: Constructor - initializes an empty list with null pointers
- **`~CursorList()`**: Destructor - cleans up all nodes
- **`bool listIsEmpty() const`**: Checks if the list is empty
- **`bool curIsEmpty() const`**: Checks if the cursor is null (no current position)

#### Navigation Operations
- **`void toFirst()`**: Moves cursor to the first node
- **`bool atFirst() const`**: Checks if cursor is at the first node
- **`void advance()`**: Moves cursor to the next node
- **`void toEnd()`**: Moves cursor to the last node
- **`bool atEnd() const`**: Checks if cursor is at the end of the list

#### Metrics & Updates
- **`int listSize() const`**: Returns the number of elements in the list
- **`void updateData(int data) const`**: Updates the data at the cursor position

#### Insertion Operations
- **`void insertFirst(const int &data)`**: Inserts at the beginning and sets cursor
- **`void insertAfter(const int &data)`**: Inserts after the cursor position
- **`void insertBefore(const int &data)`**: Inserts before the cursor position
- **`void insertEnd(const int &data)`**: Inserts at the end of the list
- **`void orderInsert(const int &data)`**: Inserts in sorted order (ascending)

#### Deletion Operations
- **`void deleteNode()`**: Deletes the node at the cursor position
- **`void deleteFirst()`**: Deletes the first node
- **`void deleteEnd()`**: Deletes the last node
- **`void makeListEmpty()`**: Removes all elements from the list

#### Search & Traversal
- **`bool search(int data)`**: Searches for a value in the list
    - Moves cursor to the found element if successful
- **`void traverse()`**: Displays all elements (one per line)
- **`void handleSelection(int selection)`**: Handles menu selections
- **`static void displayMenu()`**: Displays the interactive menu

### Menu Options (CursorList)
1. Insert first
2. Insert after cursor
3. Insert before cursor
4. Insert at end
5. Ordered insert
6. Move cursor to first
7. Move cursor to end
8. Advance cursor
9. Update cursor data
10. Delete cursor node
11. Delete first node
12. Delete last node
13. Make list empty
14. Display list
15. Display size
16. Search
17. Is list empty
18. Is cursor empty
0. Exit

### Key Features
- **Cursor-based navigation**: Efficient operations relative to current position
- **Ordered insertion**: Maintains sorted order automatically
- **Position-aware operations**: Insert/delete relative to cursor position

### Time Complexity
- **Insertion at cursor**: O(1) - cursor already positioned
- **Navigation**: O(1) for advance, O(n) for toEnd
- **Ordered insert**: O(n) - requires finding correct position
- **Search**: O(n)
- **Traversal**: O(n)

---

## Utility Functions

**Location:** `utils/InputHelper.h`

### Functions
- **`int cinListElement(const char *message)`**: Prompts user and reads an integer input
- **`void showProgramMenu()`**: Displays the main program menu
- **`void runListProgram()`**: Runs the interactive List program
- **`void runCursorListProgram()`**: Runs the interactive CursorList program

---

## Usage Examples

### Example 1: Using List Class

```cpp
List myList;

// Insert elements
myList.insert(10);
myList.insert(20);
myList.insertFirst(5);
myList.insertAt(15, 2);

// Display
myList.traverse();  // Output: 5, 10, 15, 20

// Search
bool found = myList.search(15);  // Returns true

// Delete
myList.deleteAt(1);
myList.deleteFirst();
```

### Example 2: Using CursorList Class

```cpp
CursorList myCursorList;

// Insert elements
myCursorList.insertFirst(10);
myCursorList.insertAfter(20);
myCursorList.toFirst();
myCursorList.insertAfter(15);

// Navigate
myCursorList.toEnd();
myCursorList.advance();

// Update cursor data
myCursorList.updateData(25);

// Ordered insert
myCursorList.orderInsert(12);  // Automatically finds correct position
```

### Example 3: Running the Program

1. Compile the program using CMake
2. Run the executable
3. Select option 1 for List or option 2 for CursorList
4. Follow the menu prompts to perform operations
5. Enter 0 to exit or return to main menu

---

## Differences Between List and CursorList

| Feature | List | CursorList |
|---------|------|------------|
| **Navigation** | Index-based | Cursor-based |
| **Current Position** | No | Yes (cursor) |
| **Insertion** | Index or position | Relative to cursor |
| **Ordered Insert** | No | Yes |
| **Update Data** | No | Yes (at cursor) |
| **Tail Pointer** | Yes | No |
| **Use Case** | Simple operations | Position-aware operations |

---

## Building and Running

### Build Instructions
```bash
mkdir build
cd build
cmake ..
make
```

### Run
```bash
./linkedList
```

---

## Notes

- Both implementations use dynamic memory allocation
- Proper cleanup is handled in destructors
- Input validation is minimal - users should provide valid indices
- The `List::size()` method has a bug: it returns `index + 1` which may not be accurate after deletions
- The `CursorList::atEnd()` method has a logical issue in its condition

---

## Author

Created by Hamed Mohamed on 11/27/25 - 11/28/25

