# Factorial Calculator using Pthreads

## Overview
This is a C program that calculates the factorial of a given number using POSIX threads (pthreads). The program creates multiple threads, each of which calculates the factorial of the given number. The results are then printed to the console.


### Usage

Compile the program using gcc:

Bash:

`gcc -o Progassignment2.c  Progassignment2 -lpthread`

Run the program:

`./Progassignment2`

Enter a number when prompted:


## Program Explanation

### factorial_thread Function:
Each thread calculates the factorial of a given number using a loop.
The result is stored in a dynamically allocated structure `(struct thread_result)`.

Takes a pointer arg to an integer `(int*)` as input, which represents the number whose factorial is to be computed `(n)`.

Computes the factorial using a for loop and stores the result in a dynamically allocated struct thread_result.

Checks if memory allocation `(malloc)` was successful.

Returns a pointer to the allocated memory `(res)` as `void*`.

### Main Function:
Prompts the user to input a number `(num)` for which factorial needs to be computed.
Creates 4 threads `(pthread_create)` with each thread computing a portion of the factorial.
Waits for all threads to finish `(pthread_join)`.
Prints the computed factorial for each thread.

Prompts the user to enter a number `(num)` whose factorial is to be calculated.

Creates an array threads of size 4 to hold thread IDs.

Creates an array args containing four copies of num, which are passed as arguments to each thread.

Creates an array results to hold pointers to struct thread_result, which will store the results of each thread's computation.

Uses a for loop to create four threads `(pthread_create)`, each executing the factorial_thread function with its respective args value.

Uses another for loop with pthread_join to wait for each thread to finish executing and collect its result.

Prints the results of each thread showing the computed factorial.

Frees the memory allocated for each struct thread_result after printing.

### Struct thread_result:
Defines a structure to store the result of factorial computation (long long result).

### Memory Management:
Ensures proper allocation and deallocation of memory for storing factorial results (malloc and free).

### Example Output:
If you input 5 as the number, the program should output:


```
Enter any number: 5
Thread 0 finished. Factorial of 5 is 120
Thread 1 finished. Factorial of 5 is 120
Thread 2 finished. Factorial of 5 is 120
Thread 3 finished. Factorial of 5 is 120 
```

Each thread correctly computes the factorial of 5, which is 120.

Note:
>This program assumes a Unix-like environment with POSIX threads support.

>Ensure proper error handling and memory management practices are followed in production code.

>You can modify the number of threads (#define NUM_THREADS) or adjust the range of computation (args array) based on your specific requirements.
(The number of threads is hardcoded to 4, but can be changed by modifying the num_threads variable in the code.)

>The program uses long long to store the factorial, which can handle large numbers. However, very large numbers may still cause overflow.

>Error checking is minimal, and the program assumes that the user will enter a non-negative integer.

##### Author

Temitope D Olajide
