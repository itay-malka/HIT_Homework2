# 📘 C Programming Project – String Manipulation & File Analysis

### 👨‍💻 Authors
- **Itay Malka** 
- **Felix Melamed**

---

## 📌 Project Overview

This C project is a menu-based application that demonstrates core programming concepts such as:

- **String parsing and processing**
- **Dynamic memory allocation**
- **File input/output**
- **Simple decryption algorithms**

The program offers three interactive exercises, each showcasing a different skill set in C.

---

## 🧠 Features

### 1. 🔠 Split Words by First Letter (`Ex1`)
- Prompts user for a letter and a sentence.
- Dynamically identifies all words that **start with the given letter** (case-insensitive).
- Prints the matched words using a dynamically allocated array.

### 2. 📂 Create File & Analyze Most Common Letter (`Ex2`)
- Allows user to enter text which is saved to a file (`input.txt`).
- Scans the file to determine the **most frequent alphabet character**.
- Ignores case and non-letter characters.

### 3. 🔓 Decode an Encrypted String (`Ex3`)
- Decrypts a hardcoded encrypted sentence using a shifting cipher.
- The shifting value increases with each character and resets at each space.
- Displays the original and decoded message.

---

## 🛠️ How to Compile and Run

### 💻 Requirements
- C Compiler (GCC, Clang, or similar)
- Standard C library

### 🧪 Compilation

```bash
gcc final.c -o project
