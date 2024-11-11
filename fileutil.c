#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

const int CAPACITY = 50;
const int INCREMENT = 10;

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	char line[256];
	int capacity = CAPACITY;
	int arr_size = 0;
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	char ** read = malloc(CAPACITY * sizeof(char*));
	// Read the file line by line.
	while(fgets(line,sizeof(line), in))
	{
		//   Trim newline.
		char *nl = strchr(line, '\n');
            if(nl) *nl = '\0';

		//   Expand array if necessary (realloc).
		if(arr_size == capacity)
		{
			capacity += INCREMENT;
			read = realloc(read, capacity * sizeof(char*));
		}
		//   Allocate memory for the string (str).
		read[arr_size] = malloc(strlen(line)+1);

		//   Copy each line into the string (use strcpy).
		strcpy(read[arr_size], line);
		arr_size++;
		
	}

    	
	//   Attach the string to the large array (assignment =).

    // Close the file.
	fclose(in);
	// The size should be the number of entries in the array.
	*size = arr_size;
	
	// Return pointer to the array of strings.
	return read;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	
	for(int i = 0; i < size; i++)
	{
		char *ret = strstr(lines[i], target);
		
		if(ret != NULL)
		{
			return ret;
		}
		
	}
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

void free2D(char (*arr)[COLS])
{

}