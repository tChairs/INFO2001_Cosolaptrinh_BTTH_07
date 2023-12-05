#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ten[50];
    char sdt[15];
    char email[50];
} LienLac;

void them(LienLac* ll) {
    printf("Nhap ten: ");
    scanf("%s", ll->ten);
    printf("Nhap so dien thoai: ");
    scanf("%s", ll->sdt);
    printf("Nhap email: ");
    scanf("%s", ll->email);
}

void ghi(LienLac* ll, FILE* f) {
    fwrite(ll, sizeof(LienLac), 1, f);
}

void doc(FILE* f) {
    
    LienLac ll;
    while (fread(&ll, sizeof(LienLac), 1, f)) {
        printf("%s %s %s\n", ll.ten, ll.sdt, ll.email);
    }
}

int main() {


    FILE* f = fopen("lienlac.txt", "w+");
    if (f == NULL) {
        printf("Khong mo duoc tep\n");
        return 1;
    }
    LienLac ll;
    them(&ll);
    ghi(&ll, f);
    fseek(f, 0, SEEK_SET);
    doc(f);
    fclose(f);
    return 0;
}
