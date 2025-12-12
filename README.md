# Get Next Line

*This project has been created as part of the 42 curriculum by eamaral-.*

# Description

Get Next Line is a function that reads a line from a file descriptor. The project teaches about static variables, buffer management, and file I/O in C.   

The function reads one line at a time with any buffer size. The bonus part handles multiple file descriptors at the same time.

# Instructions

**Compilation**

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line. c get_next_line_utils.c main.c -o gnl

You can change BUFFER_SIZE to any number: 

cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl

# Algorithm Explanation

**Static Buffer with Dynamic Line Construction**

The function uses a static variable to save buffer data between calls and dynamic memory to build each line.

**How it works**

The function reads BUFFER_SIZE bytes from the file and saves it in a static buffer.  This buffer stays between calls so the function remembers leftover data. 

The function looks for a newline in the buffer. If found, it returns the line including the newline and saves the rest for next time.  If not found, it reads more data until it finds a newline or reaches the end of file.

**Why this approach**

Reading in chunks is faster than reading byte by byte because it makes less system calls. The function only uses the memory it needs for each line.  

Static variables let the function remember data without extra variables. This keeps the code simple and handles edge cases like empty files or very long lines.

Reading the whole file at once wastes memory. Reading byte by byte is too slow.  

# Resources

**Documentation**

- man read
- man open
- man malloc
- man free

**Tutorials**

- Static variables in C: https://www.geeksforgeeks.org/static-variables-in-c/
- File I/O in C: https://www.tutorialspoint.com/cprogramming/c_file_io.htm

**AI Usage**

AI Tools:  ChatGPT and GitHub Copilot

I used AI to write and format this README.  It helped me organize everything and make sure I included what the subject asks for.  

I used AI to find documentation about static variables, file descriptors, and buffer management. 

I wrote all the code myself. AI did not write any part of the function.  
