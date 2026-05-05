#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int found = 0;

    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        freq[idx]++;

        if(freq[idx] == 2) {
            printf("%c", s[i]);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("-1");

    return 0;
}