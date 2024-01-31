# Data Structure

## Binary Indexed Tree (BIT)

The provided code defines a data structure known as Binary Indexed Tree (BIT) and includes various operations for updating and querying the BIT.

```cpp
#define lowbit(x) (x&-x)

struct BIT {
    int n;
    vector<int> bit;

    // Constructor to initialize the BIT with size _n
    BIT(int _n):n(_n), bit(n+1) {}

    // Update the BIT at index x by adding val
    void update( int x, int val ) {
        for(;x <= n; x += lowbit(x)) bit[x] += val;
    }

    // Update the range [L, R] in the BIT by adding val to L and subtracting val from R+1
    void range_update( int L, int R, int val ) {
        update(L, val);
        update(R+1, -val);
    }

    // Query the BIT up to index x, returning the cumulative sum
    int query( int x ) {
        int res = 0;
        for(;x; x -= lowbit(x)) res += bit[x];
        return res;
    }

    // Query the range [L, R] in the BIT, returning the sum within the specified range
    int range_query( int L, int R ) {
        return query(R) - query(L-1);
    }
};
```

### Explanation

- **BIT Structure**: The structure named `BIT` represents a Binary Indexed Tree. It consists of an array `bit` to store cumulative sums and an integer `n` indicating the size of the array.

- **Constructor**: The constructor initializes the BIT with a specified size `_n`. The `bit` array is initialized with a size of `n+1`.

- **Update Operation**: The `update` function adds a given value `val` to the BIT at a specific index `x`. It iteratively updates the cumulative sums by traversing the tree using the `lowbit` function.

- **Range Update Operation**: The `range_update` function updates a range [L, R] in the BIT. It adds `val` to index `L` and subtracts `val` from index `R+1`.

- **Query Operation**: The `query` function calculates the cumulative sum up to a specified index `x` by traversing the BIT using the `lowbit` function.

- **Range Query Operation**: The `range_query` function calculates the sum within a specified range [L, R] in the BIT by subtracting the cumulative sum at index `L-1` from the cumulative sum at index `R`.

This data structure is useful for efficiently maintaining and querying cumulative sums, making it particularly efficient for tasks such as range updates and range queries in a sequence of values.

The `lowbit` function is a common utility function used in the context of Binary Indexed Trees (BIT) or Fenwick Trees. Its purpose is to efficiently calculate the least significant bit that is set (i.e., the rightmost set bit) in a binary representation of a given integer.

Here's the explanation:

```cpp
#define lowbit(x) (x & -x)
```

- The `&` operator performs a bitwise AND operation.
- The `-x` expression represents the two's complement of `x` (negation).

The `lowbit` function is used to find the least significant bit that is set in the binary representation of the integer `x`. In other words, it returns a value that represents the rightmost 1-bit in the binary representation of `x`.

For example, let's consider a few cases:

- If `x` is 12 (binary: 1100), `lowbit(12)` would be 4 (binary: 100).
- If `x` is 7 (binary: 0111), `lowbit(7)` would be 1 (binary: 001).
- If `x` is 16 (binary: 10000), `lowbit(16)` would be 16 (binary: 10000).

In the context of a BIT, the `lowbit` function is often used in the update and query operations to efficiently traverse the tree structure. Specifically, in the update operation, it helps in identifying the next node to be updated in the tree, and in the query operation, it helps in determining the nodes to be included in the cumulative sum calculation.


## Segment Tree with Lazy Propagation

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

## Treap Data Structure

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