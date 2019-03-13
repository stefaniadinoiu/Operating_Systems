# Operating_Systems
Applications of basic concepts of Operating Systems

Tasks:

1. Write a mycp program who has the first argument of the input
a source file that will be copied on another file named as the
second argument. 

2. Create a new process using fork(2) and display the files from 
the current director using execve(2). From the initial pricess
display the personal PID and the child's PID.

3. The Collatz assumption tells that starting with any n, natuar number
if the next algorithm is applied, the series converges to 1.

n =  n/2  if mod (n,2) = 0      or    n = 3n + 1   if mod (n,2) != 0 

Implement a program that uses fork(2) and tests the assumption 
generating the sequence of a number given into the child process.


4. Write a program for testing the Collatz assumption for more given
numbers. Starting  from a single parent process, it's created one 
child that deals with a single number.
The parent is gonning to wait until the execution of each child is done.

Fulfill the previous tasks  using getpid(2) and getppid(2).


5. Implement a program that is a given string in the input. The program
 copies the string's characters, reverses and saves them into another
string. The inversion will be done in antother thread. 
The result will be obtained with the pthread_join function.

6. Write a program for calculating the multiplication of 2 given
matrices where each element of the resulted matrix it is going
to be calculated by a different thread.
