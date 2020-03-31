void ToUpper(char *);

void ToLower(char *);

int round (double);

void (*pf)(char *);

pf = ToUpper;
char *s = "SSDDX";

(*pf)(s);

pf = ToLower;

pf = round;



