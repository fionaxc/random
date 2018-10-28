#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int generaterand(){
  int fd;
  fd = open("/dev/urandom", O_RDONLY);
  int rand;
  read(fd, &rand, sizeof(int));
  close(fd);
  return rand;
}

int main(){
  int arr[10];
  printf("Generating random numbers: \n");
  int i;
  for(i = 0; i < 10; i++){
    arr[i] = generaterand();
    printf("random %d: %d\n",i,arr[i]);
  }
  int filew = open("filew.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
  printf("\n");
  printf("Writing numbers to file...\n" );
  write(filew, arr, 40);
  close(filew);

  printf("Reading numbers from file...\n");
  int checkarr[10];
  int filer = open("filew.txt", O_RDONLY, 0777);
  read(filer, &checkarr, 40);
  close(filer);

  printf("Verification that written values were the same:\n");
  for(int i = 0; i < 10; i ++){
    printf("random %d: %d\n",i,checkarr[i]);
  }

  return 0;

}
