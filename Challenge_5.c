#include <stdio.h>

int convert_letters_to_int(char);
int encrypt(int , int);
int convert(char *);

int main(){
    char s[] = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    convert(s);
}

int encrypt(int sum, int key){
    int msg;
    msg = sum ^ key;
    printf("%x", msg);
}

int convert(char *s){
    int key[] = {73, 67, 69};
    int counter= 0;
    while (*s != '\0'){
        if (counter == 0){
            encrypt(*s, key[counter]);
            ++counter;
        }
        else if(counter == 1){
            encrypt(*s, key[counter]);
            ++counter;
        }
        else{
            encrypt(*s, key[counter]);
            counter = 0;
        }
        ++s;
    }
}