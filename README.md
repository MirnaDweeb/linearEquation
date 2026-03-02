# Linear Equation Solver (C++)

## Overview

This project is a C++ implementation of a Linear Equation System Solver using Cramer's Rule.  
The program reads a system of linear equations, converts them to proper form, and allows the user to perform multiple operations on the system until the `quit` command is entered.

The program follows all given constraints:
- No extra prompts
- No extra text in output
- All results are printed directly

---

## Project Description

The program performs the following steps:

1. Reads an integer `n` representing the number of equations (up to 100).
2. Reads `n` linear equations.
3. Converts each equation to proper form:
   - Variables are ordered from x1 to xn.
   - Each variable appears only once.
   - All constants are moved to the right-hand side.
4. Accepts commands from the user.
5. Executes operations and prints results.
6. Stops execution when `quit` is entered.

All values are handled as float data types.

---

## Proper Form Rules

Each equation must satisfy:

1. Variables are sorted in increasing order (x1, x2, x3, ...).
2. Each variable appears only once.
3. Only one constant term appears and it is on the right-hand side.
4. Coefficient 1 or -1 may be written as:
   - x1 instead of 1x1
   - -x1 instead of -1x1

Example:

Input:
3x2 + 2x1 + 4x3 = 16

Converted to:
2x1 + 3x2 + 4x3 = 16

---

## Supported Commands

### Level 1 Operations

- `num_vars`  
  Prints the number of variables in the system.

- `equation i`  
  Prints equation number i in proper form.

- `column xk`  
  Prints the column of coefficients for variable xk.

---

### Level 2 Operations

- `add i j`  
  Adds equation i and equation j and prints the result.

- `subtract i j`  
  Subtracts equation j from equation i and prints the result.

- `substitute xk i j`  
  Substitutes variable xk in equation i using equation j and prints the result.

---

### Level 3 Operations (Cramer's Rule)

- `D`  
  Prints the coefficient matrix.

- `D xk`  
  Prints the Cramer matrix for variable xk (replace column xk with RHS).

- `D_value`  
  Prints the determinant of the coefficient matrix.

- `solve`  
  Solves the system using Cramer's Rule.

If determinant D = 0, the program prints:
No Solution

- `quit`  
  Ends the program.

---

## Solving Method

The system is solved using Cramer's Rule:

xi = D(xi) / D

Where:
- D is the determinant of the coefficient matrix.
- D(xi) is the determinant after replacing column i with the RHS column.

If D = 0, the system has no unique solution.

---

## Example

Input:
```
3
2x1+3x2+4x3=16
1x1+2x2+1x3=8
3x1+1x2+2x3=13
solve
```

Output:
```
x1=3
x2=2
x3=1
```

---

## Project Structure

```
Equation.h
Equation.cpp
System.h
System.cpp
main.cpp
README.md
```

---

## Compilation

Using g++:

```
g++ main.cpp System.cpp Equation.cpp -o solver
./solver
```

---

## Concepts Used

- Object-Oriented Programming (OOP)
- Maps and Vectors
- String Parsing
- Recursion (Determinant calculation)
- Cramer's Rule
- Matrix Manipulation
- Dynamic Data Structures

---

## Author

Mirna Shawky  
Haidy sobhy
 Mohamed Ahmed Zaghlol
Software Engineering Student
