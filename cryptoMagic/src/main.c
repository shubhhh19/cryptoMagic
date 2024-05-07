#include "cryptoMagic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc < 2 || argc > 4) {
        fprintf(stderr, "Usage: %s [-encrypt | -decrypt] inputFileName\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Extract the input file name
    const char *inputFileName = argv[argc - 1];
    char outputFileName[256];

    char fullInputPath[512];
    char fullOutputPath[512];

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile != NULL) {
        fclose(inputFile);
        snprintf(fullInputPath, sizeof(fullInputPath), "%s", inputFileName);
    } else {
        // If file doesn't exist in the current working directory, try bin directory
        snprintf(fullInputPath, sizeof(fullInputPath), "bin/%s", inputFileName);
    }

    if (argc == 2 || (argc == 3 && strcmp(argv[1], "-encrypt") == 0)) {
        // Default to encryption if no switch is specified
        strcpy(outputFileName, inputFileName);
        size_t len = strlen(outputFileName);
        if (len > 4 && strcmp(outputFileName + len - 4, ".txt") == 0) {
            // Remove ".txt" extension
            outputFileName[len - 4] = '\0';
        }
        snprintf(fullOutputPath, sizeof(fullOutputPath), "%s/%s.crp", "bin", outputFileName);
        encryptFile(fullInputPath, fullOutputPath);
    } else if (argc == 3 && strcmp(argv[1], "-decrypt") == 0) {
        // Decryption
        strcpy(outputFileName, inputFileName);
        size_t len = strlen(outputFileName);
        if (len > 4 && strcmp(outputFileName + len - 4, ".crp") == 0) {
            // Remove ".crp" extension
            outputFileName[len - 4] = '\0';
        }
        snprintf(fullOutputPath, sizeof(fullOutputPath), "%s/%s.txt", "bin", outputFileName);
        decryptFile(fullInputPath, fullOutputPath);
    } else {
        fprintf(stderr, "Invalid command-line arguments\n");
        exit(EXIT_FAILURE);
    }

    printf("File successfully processed. Output written to %s\n", fullOutputPath);

    return 0;
}
