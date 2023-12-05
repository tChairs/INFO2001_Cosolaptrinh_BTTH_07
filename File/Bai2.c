#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f = fopen("file.bin", "wb+");
    if (f == NULL) {
        printf("Khong mo duoc tep\n");
        return 1;
    }
    int n = 5;
    fwrite(&n, sizeof(int), 1, f);
    fseek(f, 0, SEEK_SET);
    int m;
    fread(&m, sizeof(int), 1, f);
    printf("%d\n", m);
    fclose(f);
    return 0;
}
