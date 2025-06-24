# 🧮 Expression Evaluator in C++

This is a C++ project that takes a mathematical infix expression (like `2 + 3 * (4 - 1)`) and:

1. Converts it to **postfix (Reverse Polish Notation)** format  
2. Evaluates the postfix expression using a **stack**

It's basically how calculators or compilers handle expressions behind the scenes.

---

## 🚀 Features

- 🔄 Infix ➡️ Postfix conversion
- 🧠 Stack-based RPN evaluation
- ✍️ Handles brackets and operator precedence
- ⚙️ Uses STL (`stack`, `vector`, `string`)
- 💡 Modular code with clean function design

---

## 📸 Example

**Input Expression:**
2 + 2 * (1 * 2 - 4 / 2) * 1

**Postfix (RPN):**
2 2 1 2 * 4 2 / - * 1 * +

**Evaluation Result:**
0


---

## 🛠️ How to Run

### 🔧 Compile:
```bash
g++ src/main.cpp -o evaluator

./evaluator
expression-evaluator/
├── README.md
└── src/
    └── main.cpp
