#ifndef octethelper
#define octethelper
bool FLAG = true;

void octet_validator(char *ip_passed_from_main, char *octet_1, char *octet_2, char *octet_3)
{
    int i = 0,count=0, track = 0, record_dot_position=0;
    char lastoctet[255]={0};
    char *ip = ip_passed_from_main;
    char *temp_ip = malloc(sizeof(ip)+1);
    strcpy(temp_ip, ip);
    printf("Address of *ip: %p\n",ip );
    printf("Address of *ip: %p\n",temp_ip );

    while ( *(ip+i)!='\0') {
      if (*(ip+i)=='.')
      {
        track = track + 1;
        for (int j = 0; j <i ; j++)
        {
           if ( (*(ip+j) !='x') && (*(ip+j) !='.') )
           {
             *(ip+j) = 'x';
             count = count + 1 ;
           }
        }
        printf("count: %d |  ip: %s \n",count, ip );
        if ( count  > 3 )
           printf("IP has more than 3 numbers in an octet: %s\n",ip );
        count = 0;
      }

     i++;
     if ( (track == 3 ) & (FLAG) ) {
         record_dot_position = i; //record the last dots position because we need the digits after that last dot!
         FLAG = false;
     }
     if ( track > 3 ) {
        printf("More than 3 dots in Subnet. It's illegal and you should arrest yourself immediately.\n");
        exit(0);
     }
    }//while

    if ( track < 3) {
      printf("Less than 3 dots in Subnet. It's illegal and you should arrest yourself immediately.\n");
      exit(0);
    }

    count = 0;
    if ( track == 3) {
      for(int i = record_dot_position; i < strlen(ip) ; i++ ) {
         lastoctet[count] = *(ip+i);
         count++;
      }
    }

    printf("last count: %lu |  ip: %s \n",strlen(lastoctet), lastoctet);
    if ( strlen(lastoctet) > 3)
      printf("IP has more than 3 numbers in an octet: %s\n",lastoctet );
    printf("temp  : %s\n",temp_ip );
}
#endif
