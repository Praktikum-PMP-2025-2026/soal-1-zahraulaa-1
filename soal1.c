// EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
// Modul               : 3
// Hari dan Tanggal    : Rabu, 29 April 2026
// Nama (NIM)          : Zahra Aulia (13224007)
// Nama File           : soal1.c
// Deskripsi           : Mengarsip artefak dengan prioritas kategori. Program akan mengruutkan data dengan kategori alfabetis naik, jika sama, pertimbangkan tahun naik. Jika sama, pertimbangkan nilai turun. Jika sama, pertimbangkan nama dengan alfabetis naik.

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50];
    char kategori[50];         
    int tahun;  
    int nilai; 
} Artefak;

int proses (const void *x, const void *y){
    Artefak *a1 = (Artefak *) x;
    Artefak *a2 = (Artefak *) y;
    int cmpkat = strcmp(a1->kategori, a2->kategori);
    if (cmpkat != 0) return cmpkat;
    if (a1->tahun != a2->tahun) return (a2->tahun - a1->tahun); 
    if (a1->nilai != a2->nilai) return (a1->nilai - a2->nilai);
    return strcmp(a1->nama, a2->nama);
}

int main() {
    int n;
    scanf("%d",&n);

    Artefak artefak[n];

    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d", artefak[i].nama, artefak[i].kategori, &artefak[i].tahun, &artefak[i].nilai);
    }

    qsort(artefak,n,sizeof(Artefak),proses);

    for (i = 0; i < n; i++) {
        printf("%s %s %d %d\n", artefak[i].nama, artefak[i].kategori, artefak[i].tahun, artefak[i].nilai);
    }

    return 0;
}
