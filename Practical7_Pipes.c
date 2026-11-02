#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/wait.h> 

int main() {
  int p1[2], p2[2] ;
  char fileName[100], buffer[1000] ;
  int pid ;
  FILE *fp ;
  int n ;

  pipe(p1) ;
  pipe(p2) ;

  pid = fork() ;

  if(pid == 0) {
    //Child Process
    close(p1[1]) ;
    close(p2[0]) ;

    read(p1[0], fileName, sizeof(fileName)) ;

    fp = fopen(fileName, "r") ;

    if(fp == NULL) {
      write(p2[1], "File not found", 14) ;
    } else {
      while((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) 
        write(p2[1], buffer, n) ;
      
      fclose(fp) ;
    }

    close(p1[0]) ;
    close(p2[1]) ;
    exit(0) ;
  } else {
    //Parent Process
    close(p1[1]) ;
    close(p2[0]) ;

    printf("Enter file name: ") ;
    scanf("%99s" , fileName) ;
    
    write(p1[0], fileName, sizeof(fileName)) ;
    close(p1[1]) ;

    printf("File Contents :\n") ;
    while((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) 
      write(1, buffer, n) ;

    close(p2[1]) ;
    wait(NULL) ;
  }

  return 0 ;
}