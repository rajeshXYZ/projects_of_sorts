#ifndef CHECKINPUT
#define CHECKINPUT

#define FORLOOP for (int i=0; *(ip+i)!='\0'; i++)
int ERRORFLAG=0;
int isitalldigits(char *ip);
int threedots(char *ip);
int is_ip_valid(char *ip);


int is_ip_valid(char *ip) {  //main calls only this function. This function calls others. Using pointers all the way to avoid copy of data.
  if(isitalldigits(ip)== 1) { return (ERRORFLAG); }
  if(threedots(ip)== 1) { return (ERRORFLAG); }
  return ERRORFLAG;
}

int threedots(char *ip) {
  int count = 0;
  FORLOOP
  {
    if ( *(ip+i) == '.' ) {count = count + 1;}
    if (( *(ip+i) == '.') && (*(ip + (i+1)) == '.') ) { ERRORFLAG = 1; break;} //ex. 192..168.0.1
    if (count > 3) { ERRORFLAG =1; return ERRORFLAG;} // e.x: 192..168.1.1
  }
  if (count < 3 ) ERRORFLAG = 1;
  return ERRORFLAG;
}

int isitalldigits(char *ip) {
  FORLOOP
  {
    if ( *(ip+i) >= 'a' &&  *(ip+i) <= 'z' ) {
      ERRORFLAG = 1;
      break;
    }
  }
  return ERRORFLAG;
}

#endif
