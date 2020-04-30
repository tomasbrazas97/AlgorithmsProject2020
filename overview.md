
# Overview Documentation
### G00349242 TOMAS BRAZAS
### Content headings:
1. Introduction
2. Run
3. Test
4. Algorithm
5. Complexity
6. References
7. Conclusion
### Introduction
  This project is focused on hashing. Hashing is the process of taking an input of any length and converting it into a fixed size
length using mathematical functions. This repository consits of my project for **"Theory of Algorithms"** module.The message to be hashed is called "Input", the algorithm that does the hashing is called "Hash function" and the output is called the "hash value". **Each hash value has to be unique**. This means it is almost impossible to re-produce the same hash value entering different inputs. The hash function should be quick to produce a hash value. A slighest change to an input should produce a completely different hash value. Hashing is widely used for passwords and other security measures so if that any stolen data cannot be used in malicious manner. The algorithm that is used in this project is **MD5**. The application is essentially a MD5 hash generator.
The appplication takes in a string input of any length from the user that's specified when the application is ran. It is then encoded into a **128-bit "fingerprint"**. This is a **32 character hexadecimal string**.A MD5 hash is **NOT** encryption. It is simply a fingerprint of the given input. ![Hash](https://miro.medium.com/max/1400/1*aZh9gQlawdGcwSrCO0KOeA.png)

Main files in the repository:
* md5.c - contains the hash application, main file
* README.md - brief introduction to the repository
* overview.md - documentation

The application is programmed in C programming language, while using SSH editor and coded inside a Google Cloud Virtual Machine instance as requested. The md5.c contains the hash application that takes a string input, runs the algorithm and produces a unique hash value.

### Run
The steps to successfully compile and run the application: <br>
1. Clone the respository/download the repository through github.
2. The compiler for C programming language that is used is GCC. To download GCC compiler onto your hardware, open command prompt, check if the version of GCC using the command: **gcc --version**. If not found, to install GCC type: **sudo apt install build-essential**.
3. Navigate to the downloaded folder using the **cd** command for an example: **cd/desktop/AlgorithmsProject2020**
4. To run the application, the md5.c file needs to be compiled using the command: **gcc -o md5 -O3 -lm md5.c**. A successful compile should prompt a new line. <br>
Definition of command line arguments: 
* -o : Specifies the output of of the file name for the executable.
* -O3 : Optimization more for code size and execution time
* -lm : Linking the math library.
5. Upon a succesful compile, the user can run the application using the following command: **./md5 --run "Your String Here"** which then should output a hash value according to your string input.
6. For more information the user can access more information using the command: **./md5 --help
