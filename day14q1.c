#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    // Read matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    printf("Not an Identity Matrix");
                    return 0;
                }
            } else {
                if(matrix[i][j] != 0) {
                    printf("Not an Identity Matrix");
                    return 0;
                }
            }
        }
    }

    printf("Identity Matrix");
    return 0;
}
