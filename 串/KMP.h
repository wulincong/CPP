#include "SequenceString.h"

int *prefix(Str &P);
void prefix_table(char pattern[],int prefix[],int n);
void move_prefix_table(int prefix[],int n);
void kmp_search(Str &text,char pattern[]);