#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

int compare(const void *a, const void *b)
{
    char ** aa = (char **)a;
    char ** bb = (char **)b;

    return strcmp(*aa, *bb);
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }
    char ** read = malloc(PASS_LEN * sizeof(char*)); //the array of arrays
    
    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.

    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size = 0;
    //char (*hashes)[HASH_LEN] = loadFile(argv[1], &size);
    char **hashes = loadFileAA(argv[1], &size);
    printf("File loaded\n");
    
    
    // CHALLENGE1: Sort the hashes using qsort.
    qsort(hashes, size, sizeof(char*), compare);


    // TODO
    // Open the password file for reading.
    char password[PASS_LEN];
    FILE *dict = fopen(argv[2], "r");
    int locate = 0;
    while(fgets(password, PASS_LEN, dict) != NULL)
    {
        char *nl = strchr(password, '\n');
        if(nl) *nl = '\0';

        char *hashed = md5(password, strlen(password));

        char **found = (char **)bsearch(&hashed, hashes, size, sizeof(char*),compare);
        if (found != NULL) 
        {
            printf("Found matching password: %s -> %s\n", password, hashed);
            locate++;
        }
        free(hashed);
    }
    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.

    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.
    // TODO
    // When done with the file:
    //   Close the file
    fclose(dict);

    // Free allocated memory for hashes array
    for (int i = 0; i < size; i++) 
    {
        free(hashes[i]);
    }
    free(hashes);
    //   Display the number of hashes found.
    printf("Total found: %d\n", locate);
    //   Free up memory.
}
