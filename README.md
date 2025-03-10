# MyCipherProject 🚀  

### About  
This is my implementation of **Block and Stream Ciphers** for **CS 356: Computer Security** at **Colorado State University**. The program supports **file encryption and decryption** using:  
- **Block Cipher**: 16-byte XOR encryption with byte swapping & padding.  
- **Stream Cipher**: XOR-based encryption with a repeating key.  

It’s a simple command-line tool that takes an input file, encrypts or decrypts it, and saves the output.  

---

### 📂 Project Structure  
```
MyCipherProject/
├── Makefile        # Compiles the project
├── main.cpp        # Handles command-line input & runs the cipher
├── block.cpp/.h    # Block cipher encryption & decryption logic
├── stream.cpp/.h   # Stream cipher encryption & decryption logic
├── utility.cpp/.h  # Helper functions for file handling
```

---

### 🔧 How to Build  
Make sure you have a **C++ compiler** installed, then just run:  
```sh
make
```
This compiles everything and creates an executable called **cipher**.

---

### 🛠️ How to Use  
Run the program from the terminal with:  
```sh
./cipher <CipherType> <InputFile> <OutputFile> <KeyFile> <Mode>
```
#### 🔹 Arguments:  
1️⃣ **Cipher Type:**  
   - `B` → Block Cipher  
   - `S` → Stream Cipher  

2️⃣ **Input File:** The plaintext file you want to encrypt/decrypt.  
3️⃣ **Output File:** The result file (encrypted/decrypted).  
4️⃣ **Key File:** A text file containing the symmetric key.  
5️⃣ **Mode:**  
   - `E` → Encrypt  
   - `D` → Decrypt  

#### 🔹 Example Commands:
**Block Cipher Encryption:**
```sh
./cipher B input.txt output.txt key.txt E
```
**Stream Cipher Decryption:**
```sh
./cipher S input.txt output.txt key.txt D
```

---

### 🚨 Error Handling  
If something goes wrong, the program exits with `status 1` and shows an error:  
- `"Invalid Function Type"` → Wrong cipher type  
- `"Input File Does Not Exist"` → Missing input file  
- `"Key File Does Not Exist"` → Missing key file  
- `"Invalid Mode Type"` → Wrong mode (E/D only)  

---

### 📌 Why I Built This  
- To **understand cryptographic algorithms** better.  
- To **get hands-on experience with encryption & decryption**.  
- To complete my **CS 356 assignment** (and maybe help others who need a reference).  

---

### 📜 License  
**For educational purposes only!** If you're in CS 356, use this as a reference but **write your own code**. 🚀  

---
