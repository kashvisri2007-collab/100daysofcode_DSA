#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    int prefix = 0;

    int freq[10000] = {0};  
    freq[0] = 1;  

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(freq[prefix] != 0)
            count += freq[prefix];

        freq[prefix]++;
    }

    printf("%d\n", count);

    return 0;
}