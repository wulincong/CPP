#ifndef SEQUEUESTRING_H
#define SEQUEUESTRING_H
#include "Status.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSTRING 1024

typedef struct {
    char *ch;
    int length;
} Str;

Status StrAssign(Str &, char *);

void StrPrint_Sq(Str &);

int StrLength(Str &);

Status Concat_Sq(Str &T,Str &S1,Str &S2);

Status SubString_Sq(Str &substr,Str str,int pos,int len);

Status ClearString_Sq(Str &str);

int Index_Sq(Str &str,Str &substr);

void KMP_Matcher(Str T,Str P);

#endif