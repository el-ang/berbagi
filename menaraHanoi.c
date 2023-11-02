#include <stdio.h>

int langkah = 0; // Variabel global untuk menghitung langkah

// Fungsi rekursif untuk menyelesaikan masalah Menara Hanoi
void hanoiRekursif(int n, char awal, char bantu, char akhir) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari %c ke %c\n", awal, akhir);
        langkah++;
        return;
    }

    hanoiRekursif(n - 1, awal, akhir, bantu);
    printf("Pindahkan cakram %d dari %c ke %c\n", n, awal, akhir);
    langkah++;
    hanoiRekursif(n - 1, bantu, awal, akhir);
}

// Fungsi iteratif untuk menghitung langkah minimum
int hanoiIteratif(int n) {
    int totalLangkah = 0;
    for (int i = 1; i <= n; i++) {
        totalLangkah = 2 * totalLangkah + 1;
    }
    return totalLangkah;
}

int main() {
    int n;
    do {
        printf("Masukkan jumlah cakram (minimal 3): ");
        scanf("%d", &n);
    } while (n < 3);

    printf("Langkah-langkah penyelesaian menggunakan metode rekursif:\n");
    hanoiRekursif(n, 'A', 'B', 'C');
    int langkahMinimum = hanoiIteratif(n);

    printf("Jumlah langkah minimum: %d\n", langkahMinimum);
    printf("Jumlah langkah keseluruhan: %d\n", langkah);

    return 0;
}