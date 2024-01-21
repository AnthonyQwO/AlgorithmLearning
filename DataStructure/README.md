# Data Structure

### Segment Tree with Lazy Propagation

This C++ code defines a segment tree with lazy propagation. The segment tree is used to efficiently perform range queries and updates on an array. Lazy propagation is employed to optimize the update and cover operations.

#### Segment Tree Structure
```cpp
struct segmentTree {
    int n;
    vector<int> seg, tag, cov;

    segmentTree(int _n) : n(_n) {
        seg = tag = cov = vector<int>(n * 4, 0);
    }

    // ... (functions omitted for brevity)
};
```

#### Functions and Operations
- **push(int i, int L, int R)**: Applies lazy propagation to the node at index `i` in the segment tree.
- **pull(int i, int L, int R)**: Updates the node at index `i` based on its children.
- **build(vector<int>& arr, int i=1, int L=1, int R=-1)**: Builds the segment tree from the given array.
- **query(int rL, int rR, int i=1, int L=1, int R=-1)**: Performs a range query in the segment tree.
- **update(int rL, int rR, int val, int i=1, int L=1, int R=-1)**: Updates a range in the segment tree with a given value.
- **cover(int rL, int rR, int val, int i=1, int L=1, int R=-1)**: Covers a range in the segment tree with a given value.

#### Usage
The main function initializes the segment tree, builds it with the input array, and then processes queries based on the operation type.

```cpp
int main()
{
    int n, q;
    cin >> n;
    segmentTree SMT(n);
    vector<int> arr(n + 1);
    
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    
    SMT.build(arr);

    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c;

        if (a == 1) {
            cin >> d;
            SMT.update(b, c, d);
        } else if (a == 3) {
            cin >> d;
            //SMT.cover(b, c, d);
        } else {
            cout << SMT.query(b, c) << '\n';
        }
    }

    return 0;
}
```

This segment tree is capable of handling various types of queries, including updates and covers, with the help of lazy propagation for efficient range modifications.

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