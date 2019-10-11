#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int *argc, char *argv[]){

  struct dirent *de;

  int c;
  
  DIR *dr;

  // FLAGS
  //_____________________________
  if (strcmp(argv[1], "-b") == 0)
    {
      //CHANGE FILE PATH HERE
      //           VVVVVVVVVVV
      dr = opendir("/usr/bin/");
    } else if (strcmp(argv[1], "-d") == 0)
    {
      // CHANGE FILE PATH HERE
      //           VVVVVVVVVVVVVVVVVVVVVVVVV
      dr = opendir("/home/sysname/Downloads/");
    } else if (strcmp(argv[1], "-h") == 0)
    {
      printf("___FLAGS___\n");
      printf("-b goes to bin\n-d goes to downloads\n-h for help");
      printf("change the paths in main.c to get flags to work!");
    } else
    {
      dr = opendir(argv[1]);
    }

  /*                           */
  //FLAGS
  // PRINT DIRECTORIES
  if (dr == NULL)
	{
	  printf("No directory");
	  return 0; 
	}
  while ((de = readdir(dr)) != NULL){
    c++;
    printf("%d. %s\n", c, de->d_name);
  }
  
  closedir(dr);
    
  return 0;
}
