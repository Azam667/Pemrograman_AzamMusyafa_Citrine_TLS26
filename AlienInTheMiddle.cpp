#include <iostream>
using namespace std;


// ======================================================
// Fungsi untuk menentukan nilai sebuah huruf
// A = 1, B = 2, ..., Z = 26
// ======================================================
int nilaiHuruf(char huruf)
{
    return huruf - 'A' + 1;
}


// ======================================================
// Fungsi untuk menggeser sebuah huruf
// berdasarkan nilai pergeseran
// ======================================================
char geserHuruf(char huruf, int geser)
{
    int nilai = nilaiHuruf(huruf);

    // Geser huruf
    nilai = nilai + geser;

    // Jika melewati 26, kembali ke awal alfabet
    while (nilai > 26)
    {
        nilai = nilai - 26;
    }

    // Mengubah nilai 1-26 kembali menjadi huruf A-Z
    return 'A' + nilai - 1;
}


// ======================================================
// Fungsi untuk mengenkripsi pesan
// ======================================================
void enkripsi(char pesan[], char hasil[])
{
    int i = 0;

    // --------------------------------------------------
    // Huruf pertama tidak mengalami perubahan
    // --------------------------------------------------
    hasil[0] = pesan[0];

    // --------------------------------------------------
    // Memproses huruf berikutnya
    // --------------------------------------------------
    i = 1;

    while (pesan[i] != '\0')
    {
        /*
            Huruf baru ditentukan berdasarkan
            huruf saat ini
            +
            nilai huruf ASLI sebelumnya
        */

        int nilaiSebelumnya = nilaiHuruf(pesan[i - 1]);

        hasil[i] = geserHuruf(pesan[i], nilaiSebelumnya);

        i++;
    }

    // Tanda akhir array karakter
    hasil[i] = '\0';
}


// ======================================================
// Fungsi untuk menampilkan proses enkripsi
// ======================================================
void tampilkanProses(char pesan[])
{
    int i = 0;

    cout << "\nProses penyandian:\n";

    // Huruf pertama
    cout << pesan[0]
         << " = "
         << nilaiHuruf(pesan[0])
         << " -> "
         << pesan[0]
         << endl;

    i = 1;

    while (pesan[i] != '\0')
    {
        int nilaiSekarang = nilaiHuruf(pesan[i]);
        int nilaiSebelumnya = nilaiHuruf(pesan[i - 1]);

        char hasil = geserHuruf(
            pesan[i],
            nilaiSebelumnya
        );

        cout << pesan[i]
             << " = " << nilaiSekarang
             << " + "
             << pesan[i - 1]
             << " = " << nilaiSebelumnya
             << " -> "
             << hasil
             << endl;

        i++;
    }
}


// ======================================================
// PROGRAM UTAMA
// ======================================================
int main()
{
    char pesan[100];
    char hasil[100];

    cout << "=== ALIEN-IN-THE-MIDDLE ===\n";

    cout << "Masukkan pesan (kata) : ";
    cin >> pesan;

    // Mengenkripsi
    enkripsi(pesan, hasil);

    // Menampilkan proses
    tampilkanProses(pesan);

    // Menampilkan hasil akhir
    cout << "\nPesan asli  : " << pesan << endl;
    cout << "Pesan sandi : " << hasil << endl;

    return 0;
}