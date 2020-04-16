#include "SequenceString.h"


Status StrAssign(Str &str, char ch[]){
    //释放原空间
    if (str.ch)free(str.ch);
    //求ch长度
    int len = 0;
    char *c = ch;
    while(*c != '\0'){
        ++len;
        ++c;
    }
    if(len == 0){
        str.ch = NULL;
        str.length = 0;
        return OK;
    }
    else{
        str.ch = (char *)malloc((len+1)*sizeof(char));
        if(!str.ch){
            printf("malloc failed\n");
            return OVERFLOW;
        }
        else
        {
            c = ch;
            for(size_t i = 0; i <= len; ++i,++c){
                str.ch[i] = *c;
            }
            str.length = len;
            return OK;
        }
        return OK;
    }

}

void StrPrint_Sq(Str &str){
    for (size_t i = 0; i < str.length; ++i)
    {
        printf("%c", str.ch[i]);
    }
    printf("\n");
}

int StrLength(Str &str){
    return str.length;
}

int StrCompare_Sq(Str &str1, Str &str2){
    int i = 0;
    while(i<str1.length && i<str2.length){
        if(str1.ch[i] != str2.ch[i]) return str1.ch[i] - str2.ch[i] > 0 ? 1 : -1;
        ++i;
    }
    if (str1.length == str2.length)return 0;
    return str1.length > str2.length ? 1 : -1;
}

Status Concat_Sq(Str &T,Str &S1,Str &S2){
    
    T.ch = (char*)malloc(sizeof((S1.length + S2.length+1) * sizeof(char)));
    if (!T.ch){
        printf("malloc failed\n");
        return OVERFLOW;
    }
    char *p = T.ch;
    for(size_t i = 0; i < S1.length; ++i)*p++ = S1.ch[i];
    for(size_t i = 0; i <= S2.length; ++i)*p++ = S2.ch[i];\
    T.length = S1.length + S2.length;
    return OK;
}
//未解决所有问题
Status SubString_Sq(Str &substr,Str str,int pos,int len){
    substr.ch = (char *)malloc(sizeof(char)*(len+1));
      if (!substr.ch){
        printf("malloc failed\n");
        return OVERFLOW;
    }
    char *p = substr.ch;
    for(size_t i = pos; i < len+pos; ++i) *p++ = str.ch[i];
    *p = '\0';
    substr.length = len;
    return OK;
}

Status ClearString_Sq(Str &str){
    if(str.ch){
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return OK;
}

int Index_Sq(Str &str,Str &substr){
    int i = 0,j = 0,k = i;
    while(i < str.length && j < substr.length){
        if(str.ch[i] == substr.ch[j]){
            j++;
            i++;
        }
        else{
            j = 0;
            i = ++k;
        }
    }
    if(j>= substr.length){
        return k;
    }
    return NO;
}
