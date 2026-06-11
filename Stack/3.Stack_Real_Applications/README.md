# Infix, Prefix & Postfix Notation

## 1. Basic Definitions

| Notation      | Operator Position                  | Example (2 + 3)     | Also Called          |
|---------------|------------------------------------|---------------------|----------------------|
| **Infix**     | Operator between operands          | `2 + 3`             | Normal math notation |
| **Prefix**    | Operator before operands           | `+ 2 3`             | Polish Notation (PN) |
| **Postfix**   | Operator after operands            | `2 3 +`             | Reverse Polish Notation (RPN) |

- No parentheses needed in Prefix/Postfix → unambiguous evaluation.
- Very useful for computers (stack-based evaluation).

## 2. Evaluation Rules

### Postfix (RPN) Evaluation (Left → Right)
1. Use a **stack**.
2. Scan from left to right:
   - If operand → push to stack
   - If operator → pop two operands (right first, then left), apply operator, push result
3. Final result is the only value left on the stack.

### Prefix (Polish) Evaluation (Right → Left)
1. Use a **stack**.
2. Scan from right to left:
   - If operand → push to stack
   - If operator → pop two operands (left first, then right), apply operator, push result
3. Final result is the only value left on the stack.

## 3. Conversion Examples

### Example 1: `(1 + 2) * (6 - 4)` = 6

| Notation | Expression                  | Step-by-step Evaluation                          | Result |
|----------|-----------------------------|--------------------------------------------------|--------|
| Infix    | `(1 + 2) * (6 - 4)`         |                                                  | 6      |
| Postfix  | `1 2 + 6 4 - *`             | `3` → `3 6 4 -` → `3 2` → `6`                    | **6**  |
| Prefix   | `* + 1 2 - 6 4`             | `3` → `3 2` → `6` (right→left)                   | **6**  |

### Example 2: `((2 + 3) * 4 - (7 - 5)) * (6 + 3)` = 162

| Notation | Expression                                          | Final Result |
|----------|-----------------------------------------------------|--------------|
| Infix    | `((2 + 3) * 4 - (7 - 5)) * (6 + 3)`                 | 162          |
| Postfix  | `2 3 + 4 * 7 5 - - 6 3 + *`                         | **162**      |
| Prefix   | `* - * + 2 3 4 - 7 5 + 6 3`                         | **162**      |



## 4. Advantages Comparison

| Feature                     | Infix      | Prefix     | Postfix       |
|-----------------------------|------------|------------|---------------|
| Human readable              | Yes        | No         | No            |
| Needs parentheses           | Yes        | No         | No            |
| Stack-based evaluation      | Hard       | Easy       | Easiest       |
| Used in old HP calculators  |            |            | Yes (RPN)     |
| Used in compilers           |            | Yes        | Yes           |

## 5. Quick Conversion Cheat Sheet

| Infix                | Prefix              | Postfix            |
|----------------------|---------------------|--------------------|
| `A + B`              | `+ A B`             | `A B +`            |
| `A + B * C`          | `+ A * B C`         | `A B C * +`        |
| `(A + B) * C`        | `* + A B C`         | `A B + C *`        |
| `A * B + C`          | `+ * A B C`         | `A B * C +`        |

## That's It!
You now have everything you need to understand, convert, and evaluate **Infix**, **Prefix**, and **Postfix** expressions in one single README!

**Author: Omar Adel**