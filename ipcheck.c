#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "checkinput.h"
#include "octetshelper.h"



int main(int argc, char *argv[] ) {
  char *octet_1 = NULL, *octet_2=NULL, *octet_3=NULL;
  char ip[61];
  int ipvalid = 0;
  if (argv[1]== NULL ) {
    printf("No IP inputted.\n");
    exit(0);
  }
  strcpy(ip,argv[1]); //could use atoi(argv[1]);
  if ( (4 * strlen(ip)) > 60 ) {
     printf("IP has too much octects. Correct and try again.\n");
     exit(0);
  }

if ( is_ip_valid(ip) == 1 ) {  //calls function in checkinput.h
     printf("Invalid IP: %s\n",ip );
     exit(0);
  }
  else
     printf("Valid IP: %s \n",ip );
  octet_validator(ip, octet_1, octet_2, octet_3);

}
