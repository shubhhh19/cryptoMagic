#include "cryptoMagic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile, *outputFile;
    char line[121]; // 120 characters plus '\0' for safety

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            // Removing newline character
            line[len - 1] = '\0';
        }

        // Processing each character in the line
        for (size_t i = 0; i < len; i++) {
            if (line[i] == '\t') {
                // Replacing tabs with "TT"
                fputs("TT", outputFile);
            } else if (line[i] == '\r') {
                fputc(line[i], outputFile);
            } else {
                fprintf(outputFile, "%02X", (unsigned char)line[i]);
            }
        }
        fputc('\n', outputFile); 
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Function to check if the buffer contains "TT"
int isTTSequence(const char *buffer) {
    return buffer[0] == 'T' && buffer[1] == 'T';
}

// Function to decrypt a file
void decryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    char buffer[3]; 
    buffer[2] = '\0'; 

    int firstChar;

    while (fread(buffer, sizeof(char), 2, inputFile) == 2) {
        sscanf(buffer, "%2x", &firstChar);

        // Decrypt the character
        firstChar += 16;

        if (firstChar > 127) {
            firstChar = (firstChar - 144) + 32;
        }

        if (firstChar == '\r') {
            fprintf(outputFile, "\n"); // Convert carriage return to newline

            // Read the next character and check for errors
            if (fread(buffer, sizeof(char), 1, inputFile) != 1) {
                perror("Error reading from input file");
                fclose(inputFile);
                fclose(outputFile);
                exit(EXIT_FAILURE);
            }

            continue; 
        }

        // Output the decrypted character
        fputc((char)firstChar, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}
