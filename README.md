push_swap

push_swap is a project designed to sort data on a stack using a limited set of operations.
The goal is to sort numbers efficiently with as few instructions as possible, simulating a stack manipulation algorithm.

🧠 Objective

The project aims to:

Understand algorithm optimization and sorting strategies.

Implement and manipulate linked lists as stacks.

Learn to minimize operations under strict constraints.

Develop problem-solving skills and algorithmic thinking in C.

⚙️ Usage
Compilation

Compile the program with:

make


This will generate the push_swap executable.

Example
./push_swap 3 2 5 1 4


Output might look like:

pb
pb
sa
pa
pa


The sequence shows the operations needed to sort the given numbers using the stack rules.

🔧 Allowed Operations

The program can only use the following operations:

sa, sb — swap the first two elements of stack A or B.

ss — swap both stacks at the same time.

pa, pb — push the top element from one stack to the other.

ra, rb — rotate the stack up.

rr — rotate both stacks up.

rra, rrb — rotate the stack down.

rrr — rotate both stacks down.

🧹 Makefile Rules
Command	Description
make	Compile the executable
make clean	Remove object files
make fclean	Remove objects and the executable
make re	Rebuild everything
make help	Show a brief help hint of available rules
⚡ Key Points

Uses linked lists to implement stacks.

Optimizes for minimal number of operations.

Handles any number of integers as input.

Includes error handling for invalid input, duplicates, or non-integer values.

Complies with the 42 Norm.

👨‍💻 Author

By kebris-c
