#include <stdio.h>
#include "prompt.h"

char Vcname[];
char Vcity[];

double range_from, range_to;
int Cname_choice = 0, City_choice = 0, Distance_choice = 0;
int sql_sign = 0;
char continue_sign[];

exec sql include sqlca;
exec sql begin declare section;
    char user_name[20], user_pwd[20];
    char sqltext[] = "delete from customers where";
exec sql end declare section;

int main(int argc, char **argv){
    exec sql whenever sqlerror goto report_error;
    strcpy(user_name, "root");
    strcpy(user_pwd, "wu188664")
    exec sql connect :user_name identified
        by :user_pwd;
    while(1){
        
    }
}
