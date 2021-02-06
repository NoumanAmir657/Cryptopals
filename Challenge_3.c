#include <stdio.h>

int decrypt(int, int);
int convert_letters_to_int(char);

int main(){
    char s[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    for (int i  = 0; i < 256; ++i){
        for (int j = 0; j < ((int)(sizeof(s)-1)); j+=2){
            decrypt(convert_letters_to_int(s[j])*16 + convert_letters_to_int(s[j+1]), i);
        }
        printf("\n");
    }
}

int decrypt(int sum, int key){
    int msg;
    msg = sum ^ key;
    printf("%c", msg);
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