# Simple Expression Compiler
**Goal:** Build a compiler that takes arithmetic expressions and generates executable code.

**What I'll Build:**
- Lexer to tokenize input (numbers, operators, parentheses)
- Parser to build Abstract Syntax Tree (AST)
- Code generator targeting LLVM IR or custom bytecode
- Simple interpreter or JIT executor

**Example Input/Output:**
Input:  (3 + 5) * 2 - 4 / 2
Output: LLVM IR or bytecode that evaluates to 14
Tech Stack:

**Language:** C++ or Rust

**Tools:** LLVM, Flex/Bison

**Build:** CMake or Cargo

**Learning Outcomes:**

- Lexical analysis and tokenization
- Parsing techniques (recursive descent, operator precedence)
- AST construction and traversal
- Basic code generation
- LLVM IR basics

**Extensions:**

- Add variables and assignment
- Implement functions with parameters
- Add type checking (int, float, bool)
- Optimize constant folding
- Add control flow (if/else, loops)
