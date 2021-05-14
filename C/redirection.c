#include<sys/types.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
/*
program to redirect wc input from keyboard to monitor
and change redirection of monitor to some other file
*/
{
    int src = open("test.sh",O_RDONLY);
    int dest = open("f3.txt",O_WRONLY | O_CREAT);
    int fd[2];//file discriptor for the read and write ends of pipe used to
    pipe(fd);
  
    int id = fork();
  
    
  /*
   *here child process tranfers its input to rather than standard output but to the pipe that is fd[1]  
   * could use dup2 also
   * dup2 helps assign a filediscriptor of our choice and it also closes the req fd if it is open
  */
    if(id==0)
    {
      close(1);//closing standard output
      close(fd[0]);//closing read end of the file
      dup(fd[1]);//copies the the provided file decriptor to the lowest number of the file descriptor of the available in the file table
      close(fd[1]);
      execlp("who","who",NULL);
    }
    else
    {
      close(0);
      //close(1);
      close(fd[1]);
      dup(fd[0]);
      close(fd[0]);
      execlp("wc","wc","-l",NULL); 
    }
}
