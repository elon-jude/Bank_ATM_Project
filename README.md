# Simple ATM in C
A minimal console-based ATM simulator written in **C** — designed to be as simple as possible while still showing real file-
based persistence.
## What it does
- Shows current account balance  
- Lets the user deposit money  
- Automatically saves the balance to `user.txt`  
- Loads the previous balance when the program starts again
##Purpose / Learning value
- Very first example of file reading and writing in C
- Basic user input handling
- Simple floating-point money representation
- Minimal error checking (intentional — to keep code short)

##Requirements
Any C compiler (gcc, clang, tcc, Visual Studio, etc.)
No libraries, no dependencies

Tiny C ATM — balance + deposit • saves to text file •  file I/O 

## Example run
Current: 0.00
Deposit amount: 450
New balance: 450.00
textNext time you run it:
Current: 450.00
Deposit amount: 1200
New balance: 1650.00

text## How to compile and run
```bash
gcc atm.c -o atm
./atm                # Linux / macOS
# or
atm.exe              # Windows
Files


