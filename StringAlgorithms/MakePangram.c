#include<stdio.h>
#include<stdbool.h>
#define SIZE 100

void findMissingCharactersForPangram(char str[]) {
    int i;
    bool mark[26] = {false};

    for(i=0; str[i]; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            mark[str[i] - 'A'] = true;
        else if(str[i] >= 'a' && str[i] <= 'z')
            mark[str[i] - 'a'] = true;
    }

    for(i=0; i<26; i++) {
        if(!mark[i]) {
            printf("%c", i+'a');
        }
    }
}

int main(void) {
    char str[SIZE];

    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);

    findMissingCharactersForPangram(str);
    return 0;
}
