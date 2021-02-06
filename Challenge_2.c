#include <stdio.h>
#include <stdlib.h>
#include </usr/include/math.h>

int convert_letters_to_int(char);

int main(){
    char s[] = "1c0111001f010100061a024b53535009181c";
    char r[] = "686974207468652062756c6c277320657965";
    char x[100];
    long temp = 0;
    for (int i = 0; i < ((int) sizeof(s) - 1); ++i){
        x[i] = convert_letters_to_int(s[i]) ^ convert_letters_to_int(r[i]);
    }

    for (int i = 0; i < ((int) sizeof(s) - 1); ++i){
        if (((int) x[i]) >= 10){
            x[i] = 'a' + ((int)x[i] - 10);
            printf("%c", x[i]);
        }
        else{
            printf("%d", x[i]);
        }
    }
    //printf("%lld", temp);
    //printf("%lld", temp2);

}

int convert_letters_to_int(char temp){
    if (temp >= '0' && temp <= '9'){
        return temp - '0';
    }
    else if(temp >= 'a' && temp <= 'f'){
        return temp - 'a' + 10;
    }

    return 0;
}