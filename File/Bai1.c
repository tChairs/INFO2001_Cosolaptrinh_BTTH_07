#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ten[50];
    char masv[10];
    float diem;
} SinhVien;

void them(SinhVien* sv) {
    printf("Nhap ten: ");
    scanf("%s", sv->ten);
    printf("Nhap ma sinh vien: ");
    scanf("%s", sv->masv);
    printf("Nhap diem: ");
    scanf("%f", &sv->diem);
}

void ghi(SinhVien* sv, FILE* f) {
    fwrite(sv, sizeof(SinhVien), 1, f);
}

void doc(FILE* f) {
    SinhVien sv;
    while (fread(&sv, sizeof(SinhVien), 1, f)) {
        printf("%s %s %.2f\n", sv.ten, sv.masv, sv.diem);
    }
}

int main() {
    
    FILE* f = fopen("sinhvien.txt", "w+");


    if (f == NULL) {
        printf("Khong mo duoc tep\n");
        return 1;
    }

    SinhVien sv;
    them(&sv);
    ghi(&sv, f);
    fseek(f, 0, SEEK_SET);
    doc(f);
    fclose(f);
    return 0;
}
