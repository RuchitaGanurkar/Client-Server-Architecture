#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>


int main(int x, char** files)
{ 

 // read from sent file
 char buffer[1024];
 int fd, nb, nb1=0;

 // write to file
 char buff[1024];
 int fd1, nb2;
 while(1)
 {
 	fd=open(files[1], O_RDONLY);
 	nb=read(fd, buffer, 1024);
 	close(fd);
	
 	buffer[nb] = '\0';
	fd=open(files[1], O_TRUNC);
	close(fd);
	
	printf("received message from ear is %s", buffer);
	gets(buff);

	
	fd1=open(files[2], O_WRONLY);
 	nb2=write(fd1, buff, strlen(buff));
 	close(fd1);
	
	printf("sent message from mouth is %s", buff);
	
	}
	
  printf("System brain is still NOT developed fully, waiting for the developer to work on its completion.\n");
  return 1;
}
		













/*

{
  printf("System brain is still NOT developed fully, waiting for the developer to work on its completion.\n");
  return 1;

// Open two files to be merged
FILE *fp1 = fopen("f1.txt", "r");
FILE *fp2 = fopen("f2.txt", "w");

// Open file to store the result
FILE *fp3 = fopen("f3.txt", "w" "r");
char c;

if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
{
		puts("Could not open files");
		exit(0);
}

// Copy contents of first file to file3.txt
while ((c = fgetc(fp1)) != EOF)
	fputc(c, fp3);

// Copy contents of second file to file3.txt
while ((c = fgetc(fp2)) != EOF)
	fputc(c, fp3);

fclose(fp1);
fclose(fp2);
fclose(fp3);
return 0;


}

*/
