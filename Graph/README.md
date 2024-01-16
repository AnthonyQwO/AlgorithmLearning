# Graph Introduction

A graph is a mathematical representation of a set of objects where some pairs of the objects are connected by links. These objects, often referred to as nodes or vertices, can be connected by edges. Graphs are widely used in various fields such as computer science, data analysis, social network analysis, and transportation planning.

## Types of Graphs

Graphs can be categorized into two main types based on the presence or absence of direction in the edges:

1. **Undirected Graphs:** In an undirected graph, edges have no direction. The connection between nodes is symmetric, meaning that if node A is connected to node B, then node B is also connected to node A.

2. **Directed Graphs (Digraphs):** In a directed graph, edges have a direction. Each edge is directed from one node to another, indicating a one-way relationship. This introduces the concepts of "source" and "destination" nodes.

Graphs can also be classified based on whether or not multiple edges and self-loops are allowed.

## Components of a Graph

1. **Nodes (Vertices):** The fundamental entities of a graph. Nodes represent the objects, and they are connected by edges.

2. **Edges:** The connections between nodes. Edges may be directed or undirected, and they can carry additional information such as weights.

## Graph Representations

There are different ways to represent a graph:

1. **Adjacency Matrix:** A two-dimensional matrix where each cell at the intersection of row i and column j represents whether there is an edge between node i and node j. This representation is efficient for dense graphs.

2. **Adjacency List:** A collection of lists or arrays where each list corresponds to a node, and it contains the nodes that are adjacent to the corresponding node. This representation is efficient for sparse graphs.

## Graph Applications

Graphs find applications in various domains, including:

- **Social Networks:** Nodes represent individuals, and edges represent relationships between them.
  
- **Transportation Networks:** Nodes represent locations, and edges represent roads or connections between locations.

- **Computer Networks:** Nodes represent devices, and edges represent communication links.

- **Recommendation Systems:** Nodes represent users or items, and edges represent preferences or connections.

Understanding and analyzing graphs play a crucial role in solving real-world problems, making them a fundamental concept in the field of computer science and mathematics.