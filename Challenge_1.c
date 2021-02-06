#include <stdio.h>
#include <stdlib.h>

int convert_letters_to_int(char);

int main(){
    char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char array[97];
    char s[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    //printf("%lu", sizeof(s));
    int k = 0;
    for (int i  = 0; i < ((int) sizeof(s) - 6); i+=6){
        long temp = convert_letters_to_int(s[i])*16 + convert_letters_to_int(s[i+1]);
        temp = temp<<8 | (convert_letters_to_int(s[i+2])*16 + convert_letters_to_int(s[i+3]));
        temp = temp<<8 | (convert_letters_to_int(s[i+4])*16 + convert_letters_to_int(s[i+5]));
    
        for(int j = 3; j >= 0; j--){
            array[k++] = map[temp>>j*6&0x3F];
        }
    }
    //printf("%d", k);
    
    printf("\n");
    for (int i = 0; i < k; ++i){
        printf("%c", array[i]);
    }
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