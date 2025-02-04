# 🔍 Word Search Solver (C++)
A powerful and efficient C++ program that finds words in a grid of letters using DFS (Depth-First Search) and Trie (Prefix Tree). This program efficiently identifies words from a given list, searching in all 8 directions within the grid.

🚀 Features
✔️ Finds words in a grid (horizontal, vertical, diagonal)
✔️ Optimized using Trie for fast lookups
✔️ Backtracking ensures efficiency
✔️ Handles large grids and word lists
✔️ Interactive CLI-based execution


---


📂 Project Structure

📦 Word Search Solver
 📜 word_search.cpp  # Main source code

 --- 
 
🛠 How to Run the Program

1️⃣ Compile the Code

Use a C++ compiler like g++ to compile the program:
g++ word_search.cpp -o word_search

2️⃣ Run the Executable

🛠 How It Works

1️⃣ Code Explanation

This program is based on Trie & Backtracking to efficiently search for words in the grid.

📌 Trie Data Structure
A Trie (Prefix Tree) is used to store words, enabling quick lookups while exploring the grid.

📌 Depth-First Search (DFS) with Backtracking
Each cell in the grid is explored in 8 directions, and backtracking ensures optimal performance.

---

📌 Example Usage
Input Grid:

C A T
<br>
X Z T
<br>
Y O G

Word List:
["CAT", "TOY", "DOG"]

Expected Output:

Words found: CAT, TOY

---
📧 Contact & Contribution
📩 surajpratap469@gmail.com
<br>
🤝 Contribute: Fork the repository & submit a pull request!
<br>
⭐ Support: If you like this project, give it a ⭐ on GitHub! 🚀
