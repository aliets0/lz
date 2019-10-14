#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define CMP strcmp

int main(int *argc, char *argv[]){

  struct dirent *de;

  int c;
  
  DIR *dr;

  
  // FLAGS
  //_________________________
  if (strcmp(argv[1], "-b") == 0)
    {
      //CHANGE FILE PATH HERE
      //           VVVVVVVVVVV
      dr = opendir("/usr/bin/");
    } else if (CMP(argv[1], "-d") == 0)
    {
      // CHANGE FILE PATH HERE
      //           VVVVVVVVVVVVVVVVVVVVVVVVV
 
      dr = opendir("/home/aliets/Downloads/");
      // HELP FLAG
    } else if (CMP(argv[1], "-h") == 0)

      dr = opendir("/home/sysname/Downloads/");
    } else if (strcmp(argv[1], "-h") == 0)
 
    {
      printf("___FLAGS___\n");
      printf("-b goes to bin\n-d goes to downloads\n-h for help");
      printf("change the paths in main.c to get flags to work!");
      // OPEN DIRECTORY YOU INPUT
    } else
    {
      dr = opendir(argv[1]);
    }
  // IF DIRECTORY IS INVALID PRINT "No directory"
  if (dr == NULL)
	{
	  printf("No directory");
	  return 0; 
	}
  while ((de = readdir(dr)) != NULL){
    // LINE NUMBERS
    c++;
    // PRINT DIRECTORY NAME
    printf("|\033[1;35m%d. \033[1;36m*[\033[1;34m%s\033[1;36m]*\n", c, de->d_name);
    // FORMATTING
    if (c % 2 == 0 || c == 1) printf("\t\t\t");
  }
  
  closedir(dr);
    
  return 0;
  }
