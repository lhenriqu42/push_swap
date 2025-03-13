# Push Swap

Push Swap is a sorting algorithm project implemented in C. The goal is to sort a stack of integers using a limited set of operations. The project includes a main program (`push_swap`) and a checker program (`checker`) to verify the correctness of the sorting.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/push_swap.git
    cd push_swap
    ```

2. Build the project:
    ```sh
    make
    ```

3. To build the bonus checker program:
    ```sh
    make bonus
    ```

## Usage

### Push Swap

The `push_swap` program takes a list of integers as arguments and outputs the sequence of operations needed to sort the stack.

```sh
./push_swap 3 2 5 1 4
```

### Checker

The `checker` program takes a list of integers and reads operations from the standard input to verify if the stack is sorted correctly.

```sh
./checker 3 2 5 1 4
```

You can then input the operations manually or pipe them from a file:

```sh
./checker 3 2 5 1 4 < operations.txt
```

## Commands

The following commands are used to manipulate the stack:

- `sa` : Swap the first two elements of stack A.
- `sb` : Swap the first two elements of stack B.
- `ss` : Swap the first two elements of both stacks A and B.
- `pa` : Push the top element from stack B to stack A.
- `pb` : Push the top element from stack A to stack B.
- `ra` : Rotate stack A (shift up all elements by 1).
- `rb` : Rotate stack B (shift up all elements by 1).
- `rr` : Rotate both stacks A and B.
- `rra` : Reverse rotate stack A (shift down all elements by 1).
- `rrb` : Reverse rotate stack B (shift down all elements by 1).
- `rrr` : Reverse rotate both stacks A and B.