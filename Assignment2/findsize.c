#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  char * filename = argv[1];

  int fd = open(filename, O_RDONLY);
  int currentPosition = lseek(fd, 0, SEEK_CUR);
  int size = lseek(fd, currentPosition, SEEK_END);
  lseek(fd, currentPosition, SEEK_SET);

  close(fd);
  printf("\nSize of file is: %d\n", size);

  int blocks;

  if(size/512 < 8){
    blocks = 8;
  }
  else{
    blocks = size/512;
  }

  printf("\nNumber of blocks is: %d\n", blocks);

}
