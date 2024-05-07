# cryptoMagic

### Description:
I've developed cryptoMagic, a utility written in C for encrypting and decrypting ASCII files in Linux. It offers a simple yet effective way to secure sensitive data by transforming it into an unreadable format, which can only be decoded back by the same utility.

### Tools Used:
For this project, I utilized a text editor Visual Studio Code for coding in C. I relied on GCC for compiling the C code into an executable binary. Additionally, I used Git for version control and GitHub for hosting the repository online.

### Features:
cryptoMagic provides two main features: encryption and decryption of ASCII files. It supports command-line switches (-encrypt and -decrypt) to specify the operation. If no switch is provided, it defaults to encryption. The utility takes the name of the input file to process as an argument, ensuring flexibility in file handling.

### Install and Run Instructions:
To use cryptoMagic, clone the repository from GitHub using the provided link. Compile the source files using GCC, ensuring no debug flags are enabled. Once compiled, execute the binary file from the terminal, passing the appropriate command-line switches and file name as arguments. For example:
```
gcc -o cryptoMagic cryptoMagic.c helperFunctions.c
./cryptoMagic -encrypt inputFile.txt
./cryptoMagic -decrypt encryptedFile.crp
```

### Interesting Parts during the Build Process:
One interesting aspect was designing the encryption and decryption algorithms to ensure robust data security while maintaining efficiency. Additionally, implementing modular techniques to organize the codebase into separate source files and headers added clarity and ease of maintenance.

### Difficulties we had and how we overcame them:
One challenge was handling file I/O operations and ensuring seamless processing of ASCII files line by line. I overcame this by carefully studying and implementing C's file handling functions, ensuring proper error checking and handling edge cases. Additionally, debugging and testing played a crucial role in identifying and resolving any issues that arose during development.

### Future Updates and Fixes:
In the future, I plan to enhance the utility by adding support for more encryption algorithms, providing users with options for increased security. Additionally, I aim to improve the user interface by implementing more informative error messages and possibly adding a progress indicator for larger files. Regular updates and bug fixes will ensure cryptoMagic remains a reliable tool for data encryption and decryption on the Linux platform.
