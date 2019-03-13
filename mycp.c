#include <stdio.h>

#include <unistd.h>

#include <fcntl.h>

#include <errno.h>



int main(int argc, char* argv[])

{

	if( argc < 3)
         { 
		perror("Cod Motan 1547");
		 return -1;
	}

 	
   int fd1, fd2;

   fd1 = open(argv[1], O_RDONLY|O_CREAT);

   fd2 = open(argv[2], O_WRONLY|O_CREAT);





	if( fd1 < 0 || fd2 < 0)
	 {
		 perror("Cod Motan 154");
		 return errno;
	 }



  const int size = 1024;

  char buff[size];

  ssize_t numRead;


    while((numRead=read(fd1,buff,size))>0)
	{

		if((write(fd2,buff,numRead)) != numRead)
		   {
			 perror("Cod Motan 9960");
			 return errno;
		   }

	}
	
	
	if (numRead < 0)
	 {
		 perror("Cod Motan 4960");
		 return errno;
	 } 


	if(17 != (write(1, "copiere completa/n", 17)))
	 {
		perror("Cod Motan 5560");
		return errno;
	 }


	if(close(fd1) == -1)
	 {
	   perror("Cod Motan 5360");
 	   return errno;
	}


	if(close(fd2) == -1)
	 {
		perror("Cod Motan 59960");
	        return errno;
	 }

}
