
# Overview Documentation
### G00349242 TOMAS BRAZAS
### Content headings:
1. Introduction
2. Run
3. Test
4. Algorithm
5. Complexity
6. References
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
6. For more information the user can access more information using the command: **./md5 --help**
<pre> 
tomasbrazas@algoproject:~/AlgorithmsProject2020$ gcc -o md5 -O3 -lm md5.c </pre>

### Test
The application consists of two main tests. Time trial of the MD5 hash algorithm with the user specified input and RFC 1321 MD5 test suite. <br>
The time trial calculates the time in seconds using the time library in C libraries. To record the hashing time of the hash input the following command is used: **./md5 --t "Your String Here"**<br>
Example:
<pre>
tomasbrazas@algoproject:~/AlgorithmsProject2020$ ./md5 --t "I am very fast"
Time taken to hash the string:  0.000067 </pre>

The MD5 test suite is used to produce md5 hash values of the given text that is stored in an array. The string inputs are ran through the MD5 algorithm twice and the associated hash value of the second loop is compared to the hash value of the first loop.
If the two hash values match with the same input, "pass" is outputted, if not then "failed" is outputted beside according test input. To run this test: **./md5 --x** <br>
An example:
<pre>
MD5 test suite:
MD5 ("") = d41d8cd98f00b204e9800998ecf8427e pass
MD5 ("a") = 0cc175b9c0f1b6a831c399e269772661 pass
MD5 ("abc") = 900150983cd24fb0d6963f7d28e17f72 pass
MD5 ("message digest") = f96b697d7cb7938d525a2f31aaf161d0 pass
MD5 ("abcdefghijklmnopqrstuvwxyz") = c3fcd3d76192e4007dfb496cca67e13b pass
MD5 ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789") =
d174ab98d277d9f5a5611c2c9f419d9f pass
MD5 ("123456789012345678901234567890123456789012345678901234567890123456 pass
78901234567890") = 57edf4a22be3c955ac49da2e2107b67a pass
</pre>

### Algorithm
The main algorithm used in this project is MD5 Hashing Algorithm. Message Digest Algorithm is a cryptographic hash function.
Instead of confirming that two sets of data are identical by comapring the raw data, MD5 uses checksum to make sure it's identical or not. MD5 message digests the hashing algorithm processes data in 512-bit blocks that are broken down into 16 words that are composed of 32-bits each and then outputs a 128-bits message digest value also known as a hash value. The main idea of the algorithm is to take random input data and generate a fixed size hash value, 32 characters long in this case. The input can be any size and/or any length. ![diagram](https://player.slideplayer.com/33/8199039/data/images/img3.jpg)<br>
The proccesing steps of the algorithm: 
* Append padding bits
* Append length
* MD buffer
* Process message in 512-bit blocks
* Output

Pad the message so its length is 448 mod 512. Padding is always added. The number of padding bits is in the range of 1 to 512.<br>
Appending length, is done by appending to 64 bit of the original message. If original's length is greater than 2^64 only low-order 64 bits of the length are used. The MD buffer is a 128-bit buffer. It is used too hold the final results of the hash function, 4 32-bit registers. Stored in little-edian format. Then the message is processed in 512bit blocks. Consists of 4 "rounds" of processing, 16 steps each. Each of the rounds a similar structure wise but have different logical functions.The output from the previous stage is the 128-bit message digest.

### Complexity
The MD5 algorithm is one of the fastest hashing algorithms comparing it to SHA-1, SHA-256 and SHA-512. It is on par with SHA-1 but both have been compromised (have been broken and are not deemed secure). MD5 is one of the faster ones because it produces a 128-bit hash value which is 32 characters long, in comparison to SHA-512's 128 character hash value. SHA-512 is approximately 33% slower. MD5 can perform 1 million calculations in 627.4ms meanwhile, SHA-512 calculates the same amount of calculations in 1056.4ms.<br>
<br>
MD5 is not widely used anymore, due to searching common hash value on Google sometimes gives the plain text. The most efficient way to break a MD5 hash value and revert it to an input is using the Brute Force algorithm. Hashcat can run the attack on GPU's making it possible to perform many hash calculations in parrallel. A brute-force attack consits of an attacker who has bad intentions and has your login creditentials. The person submits many password phrases of hope getting one correct eventually. Systematically checking until correct one is found. A tool that can be used for their advantage is HashCat. Hashcat is an open source password recovery tool. It supports the algorithms of MD4, MD5 and SHA-family. This is why passwords have recently became very strict, must constist the use of uppercase letters, symbols, lowercase letters and numbers. Sometimes they cannot be closely related to the login. Companies are taking this measures to prevent consumers data being stolen by brute force attackers.
<br>

In conclusion, the MD5 algorithm should not be used in any security applications because collisions can be generated. Although it is very fast, not always secure. MD5 has joined the graveyard of broken hash functions, examples of other broken hash functions that should be avoided are SHA-1, MD4, LAN Manager and Message Authenticator Algorithm. An example of a better hashing algorithm is SHA3, it is believed to be very secure.
