# Graph Class with Operator Overloading

This project focuses on operator overloading for a Graph class, represented by an adjacency matrix. The following operators are implemented:

## Arithmetic Operators
- `+`
- `+=`
- `-`
- `-=`
- `++`: Increment operator (prefix and postfix)
- `--`: Decrement operator (prefix and postfix)
- `Unary +`: Unary plus operator
- `Unary -`: Unary minus operator

The implementation of these operators follows the definition of matrix addition and subtraction. Therefore, they are only defined when the graphs have the same number of vertices. Additionally, addition and subtraction between two edges are not allowed when the resulting edge weight becomes zero or a new edge is added as a result of the operation. These restrictions apply to assignment operators (+=, -=, ++, --). When the result of the operation is stored in a third graph, these restrictions do not apply.

## Comparison Operators
- `>` 
- `<`
- `==`
- `!=`
- `>=`
- `<=`

The comparison is determined by the number of edges in the graphs. If the number of edges is equal, the comparison is based on the number of vertices.

Two graphs are considered equal if they have exactly the same vertices and edges, or if neither of them is greater than the other.

## Multiplication Operators
- Scalar Multiplication: Multiplication of a graph by a scalar value
- Graph Multiplication: Multiplication of two graphs, performed according to the definition of matrix multiplication

## Output Operator
- The output operator (`<<`) is overloaded to print the adjacency matrix representing the graph.
