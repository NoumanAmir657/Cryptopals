#include <stdio.h>

int decrypt(int, int);
int convert_letters_to_int(char);

int main(){
    FILE *ptr = NULL;
    ptr = fopen("4.txt", "r");
    char str[100];
    while(fgets(str, 60, ptr) != 0){
        for (int i  = 0; i < 256; ++i){
            for (int j = 0; j < sizeof(str); j+=2){
                decrypt(convert_letters_to_int(str[j])*16 + convert_letters_to_int(str[j+1]), i);
            }
        printf("\n");
        }
        printf("------------------------------------------------------------------------------------------------------------------\n");
        //getc(stdin);
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