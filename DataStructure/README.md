# Data Structure

### Treap Data Structure

This C++ code defines a data structure called Treap, which is a combination of a binary search tree (BST) and a max-heap. The Treap maintains a set of elements with associated priorities. Each node in the Treap has a key (value), priority, size, sum, and tags for tree operations. The key is the element value, priority is a randomly generated value, size represents the number of nodes in the subtree rooted at the current node, sum is the sum of values in the subtree, and tag is a flag for lazy propagation.

#### Treap Node Structure
```cpp
struct Treap {
    int key, pri, sz, tag, sum;
    Treap *L, *R;   
    Treap( int val ) {
        sum = key = val, pri = gen(), sz = 1, tag = 0;
        L = R = NULL;
    }; 
};
```

#### Functions and Operations
- **Size(Treap *a)**: Returns the size of the subtree rooted at node `a`.
- **pull(Treap *a)**: Updates the size and sum attributes of node `a` based on its children.
- **push(Treap *a)**: Applies lazy propagation by swapping the left and right children and toggling their tags.
- **merge(Treap *a, Treap *b)**: Merges two treaps `a` and `b` into a new treap, maintaining the heap property based on priority.
- **print(Treap *a)**: Prints the keys of the treap in an in-order traversal.
- **build(int n)**: Builds a treap by merging `n` nodes with randomly generated values.
- **splitbyk(Treap *x, int k, Treap *&a, Treap *&b)**: Splits the treap `x` into two treaps `a` and `b` such that all keys in `a` are less than or equal to `k`.
- **splitByTh(Treap *x, int k, Treap *&a, Treap *&b)**: Splits the treap `x` into two treaps `a` and `b` based on the size `k` of the left subtree.

#### Usage
Example usage might involve building a treap, performing splits and merges, and printing the resulting treap.

```cpp
int main() {
    Treap *root = build(5);
    print(root);

    Treap *left, *right;
    splitbyk(root, 3, left, right);
    print(left);
    print(right);

    Treap *newRoot = merge(left, right);
    print(newRoot);

    return 0;
}
```

This Treap data structure can be useful for various applications where both search and priority-based operations are required.