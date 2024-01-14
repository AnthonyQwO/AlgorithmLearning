# Linked List Program Documentation

This documentation provides an overview of the linked list program written in C. The program utilizes a linked list data structure to implement various operations on a collection of named lists, each containing integer values.

## Table of Contents
- [Introduction](#introduction)
- [Data Structures](#data-structures)
  - [Node](#node)
  - [NodeList](#nodelist)
- [Functions](#functions)
  - [NodeList Functions](#nodelist-functions)
  - [Node Functions](#node-functions)
  - [Other Functions](#other-functions)
- [Main Function](#main-function)

## Introduction
The program implements a linked list structure to manage collections of integer values. Each collection is represented by a NodeList structure, and each element in a collection is represented by a Node structure. The program provides various operations such as appending, deleting, sorting, merging, reversing, printing, updating, inserting, and deleting elements in the collections.

## Data Structures

### Node
```c
typedef struct Node {
    int value;
    struct Node *next;
} Node;
```
The `Node` structure represents an element in a collection, containing an integer value and a pointer to the next node in the collection.

### NodeList
```c
typedef struct NodeList {
    char name[11];
    struct Node *head;
    struct NodeList *next;
} NodeList;
```
The `NodeList` structure represents a collection of integer values, identified by a name. It contains a pointer to the head of the linked list of nodes and a pointer to the next NodeList, allowing for a linked list of collections.

## Functions

### NodeList Functions

#### `void appendList(NodeList *head, char name[])`
Appends a new NodeList with the given name to the end of the existing list.

#### `void deleteList(NodeList *head, char name[])`
Deletes the entire NodeList with the specified name, freeing memory.

#### `void nameList(NodeList *head, char name[], char newName[])`
Changes the name of a NodeList with the specified name to a new name.

#### `void sort(NodeList *head, char name[])`
Sorts the NodeList with the specified name in ascending order.

#### `void merge(NodeList *head, char targetName[], char dataName[])`
Merges two NodeLists: the target NodeList and the data NodeList.

#### `void reverse(NodeList *head, char name[])`
Reverses the order of elements in the NodeList with the specified name.

#### `void printall(NodeList *head)`
* **EXTRA PART**
Prints all NodeLists and their respective elements.

#### `Node* findList(NodeList *head, char name[])`
Finds and returns the head of the NodeList with the specified name.

#### `int NodeListSize(NodeList *head)`
* **EXTRA PART**
Calculates and returns the number of NodeLists in the linked list program.

### Node Functions

#### `void print(NodeList *head, char name[])`
Prints all elements in the NodeList with the specified name.

#### `void append(NodeList *head, char name[], int data)`
Appends a new node with the given data to the end of the NodeList with the specified name.

#### `void update(NodeList *head, char name[], int target, int data)`
Updates the value of a node with the specified target value in the NodeList with the given name.

#### `void insert(NodeList *head, char name[], int target, int data)`
Inserts a new node with the given data before the node with the specified target value in the NodeList with the given name.

#### `void delete(NodeList *head, char name[], int target)`
Deletes the node with the specified target value from the NodeList with the given name.

### Other Functions

#### `int min(int a, int b)`
Returns the minimum of two integers.

#### `int errorCheck(int command, char *firstparam, char *secondparam, char *thirdparam)`
Checks the validity of parameters for different commands. Returns 0 if parameters are correct, and 1 if there is an error.

#### `int intRange(char *s)`
Checks if the parameter is in the range of an integer. Returns 0 if the parameter is correct, and 1 if there is an error.

#### `int stoi(char *s)`
Converts a string to an integer and checks for errors. Returns 0 if the conversion is successful, and 1 if there is an error.

#### `void helper()`
* **EXTRA PART**
Prints a list of commands and their formats for the linked list program.

## Main Function
The main function reads commands from the standard input, parses them, and calls the corresponding functions based on the command. It continues reading and executing commands until the end of the input. The available commands include `appendList`, `deleteList`, `nameList`, `sort`, `merge`, `reverse`, `print`, `append`, `update`, `insert`, `delete`, and `printall`. If a command is not recognized, a syntax error is displayed.