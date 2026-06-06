*This project has been created as part of the 42 curriculum by lschawer.*
# Get Next Line


## Description
This project is about programming a function that returns a line read from a file descriptor, ending with a newline character (`\n`) if one is present.<br>
This project taught me an important concept in C programming: **static variables**.


## Instructions
Since this project consists of source files to be integrated directly into another program, there is no Makefile required. You can compile the functions directly with your main program using `cc`.

1. **Include the header** in your source code:
   ```c
   #include "get_next_line.h"
   ```

2. **Compile the files together**, ensuring you define the BUFFER_SIZE at compile time:
   ```c
   Bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test
   ```


## Resources
To build this library I have used the following resources:
* subject.pdf: Detailed assignment requirements.
* man7.org: Linux manual pages for standard functions.
* 42-cursus.gitbook.io: Simplified descriptions and logic for non-standard functions.
* funcheck and francinette : Unit testing for all functions.
* AI Assistance: Used for clarifying concepts.


## Details about the algorithm
The core challenge of get_next_line is that the system call read() is unpredictable; it doesn't know where a line ends, so it simply reads a chunk of bytes defined by BUFFER_SIZE. The algorithm must read data, store it, carve out exactly one line to return, and save any leftover characters for the next time the function is called.

To achieve this efficiently, the algorithm follows a 3-step cycle using a static variable:

1. Read and Accumulate (read_to_stash)
Because read() might fetch data past the first newline character, we need a "stash" (a static string variable) that persists across multiple function calls.
The function reads chunks of BUFFER_SIZE bytes from the file descriptor.
Each chunk is appended to our static stash.
This reading loop continues until a newline character (\n) is found inside the stash, or read() hits the End-Of-File (EOF) / an error.

2. Extract the Line (extract_line)
Once we know we have a full line (or we hit the end of the file), we need to isolate it.
The algorithm scans the stash up to the first \n (or \0).
It allocates memory for this specific segment, copies the characters over (including the \n if it exists), and finishes it with a null-terminator.
This newly allocated string is what get_next_line will ultimately return to the user.

3. Clean the Stash (clean_stash)
Before returning the line, we must prepare the static stash for the next time get_next_line is called.
The algorithm allocates a new string containing only the characters that appeared after the extracted line's newline character.
The old stash memory is freed, and the static variable is updated to point to this new, trimmed string.
If there are no characters left over, the stash is freed and set to NULL.


**Why this approach?**<br>
Using a static variable is mandatory here because standard local variables lose their values once a function finishes execution. By keeping the leftover data in a static string, the function safely "remembers" where it left off in the file descriptor without needing to re-read from the disk, ensuring seamless sequential line extraction.
