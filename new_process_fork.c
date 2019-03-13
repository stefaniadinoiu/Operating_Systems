#include <stdio.h>

#include <sys/types.h>

#include <unistd.h>

#include <errno.h>

#include <sys/wait.h>




int main()
{

   
    pid_t pid = fork();
	
    char* argv[] = {"ls", NULL};

	if (pid == 0)
	{
  
              printf("Child: %d, Parent: %d \n", getpid(), getppid());
  
              execve("/bin/ls", argv, NULL);
	}


	else if (pid < 0)

		return errno;

  	
    wait(NULL);

	printf("Child %d terminated\n", pid);


	return 0;

}

