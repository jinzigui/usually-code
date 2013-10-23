#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str, int start, int end){
    char temp;
    while(start < end){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

//free the retval outsize the function!
char* reverse_str(char* string){

    if(!string)
        return false;

    int str_len = strlen(string);
    int p,q;

    char *str = (char*)malloc(sizeof(char)*str_len);
    strcpy(str, string);

    reverse(str,0,str_len-1);

    p=0;
    q=0;
    while(str[p]==' '){
        p++;
        q++;
    }
    while(q < str_len){
        while(p < str_len && str[p]==' '){
            p++;
        }
        if(p==str_len)
            break;
        q=p;
        while(q < str_len && str[q]!=' '){
            q++;
        }
        reverse(str,p,q-1);
        p=q;
    }
    return str;
}

int main(){
     char *str1="hello world";
	printf("%s\n", str1);
    char* str = reverse_str("Hello world ");
    printf("%s\n", str);

    return 0;
}
