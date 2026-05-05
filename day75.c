#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[2000], index[2000], size = 0;
    int sum = 0, maxLen = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            maxLen = i + 1;

        int found = 0;
        for(int j = 0; j < size; j++) {
            if(prefix[j] == sum) {
                int len = i - index[j];
                if(len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        if(!found) {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d", maxLen);
    return 0;
}