#include <iostream>
using namespace std;

// Fungsi buat hapus astronot dari array
void removeAstronaut(int astronaut[], int &size, int index)
{
    // Geser semua elemen setelah index ke kiri
    for (int i = index; i < size - 1; i++)
    {
        astronaut[i] = astronaut[i + 1];
    }

    // Jumlah astronaut berkurang
    size--;
}


// Fungsi buat ubah nilai K
int updateK(int K, int eliminated)
{
    // Jika nomor astronot genap
    if (eliminated % 2 == 0)
    {
        K = K + 2;
    }
    // Jika nomor astronot ganjil
    else
    {
        K = K - 1;

        // K tidak boleh kurang dari 2
        if (K < 2)
        {
            K = 2;
        }
    }

    return K;
}


// Fungsi utama simulasi
void eliminationProcess(int astronaut[], int size, int K)
{
    int current = 0;

    cout << "\nUrutan eliminasi: ";

    // Proses berlangsung sampai tersisa satu astronot
    while (size > 1)
    {
        /*
            current = posisi tempat perhitungan dimulai

            Karena astronot pada posisi current
            dihitung sebagai hitungan ke-1,
            maka posisi astronaut yang dieliminasi:
            current + K - 1

            Modulo size digunakan agar kembali
            ke awal lingkaran.
        */
        int index = (current + K - 1) % size;

        // Simpan nomor astronot yang dieliminasi
        int eliminated = astronaut[index];

        cout << eliminated;

        // Jika masih akan ada eliminasi berikutnya,
        // beri tanda panah.
        if (size > 2)
        {
            cout << " -> ";
        }

        // Hapus astronot
        removeAstronaut(astronaut, size, index);

        // K diperbarui berdasarkan nomor astronot yang baru saja dieliminasi
        K = updateK(K, eliminated);

        /*
            Setelah astronaut dihapus,
            posisi index sekarang ditempati astronot
            yang tadinya berada tepat setelahnya.

            Jadi perhitungan berikutnya dimulai dari index.

            Jika index sudah melewati elemen terakhir, kembali ke indeks 0.
        */
        if (size > 0)
        {
            current = index;

            if (current == size)
            {
                current = 0;
            }
        }
    }

    cout << "\n\nAstronaut terakhir: " << astronaut[0] << endl;
    cout << "Nilai K terakhir: " << K << endl;
}


int main()
{
    int N;
    int K;

    cout << "Jumlah astronaut: ";
    cin >> N;

    cout << "Nilai K awal: ";
    cin >> K;

    // Validasi sederhana
    if (N < 1)
    {
        cout << "Jumlah astronaut harus >= 1." << endl;
        return 0;
    }

    if (K < 2)
    {
        K = 2;
    }

    // Bikin array yang dinamis
    int *astronaut = new int[N];

    // Mengisi nomor astronot 1 sampai N
    for (int i = 0; i < N; i++)
    {
        astronaut[i] = i + 1;
    }

    // Menjalankan proses eliminasi
    eliminationProcess(astronaut, N, K);

    // Membebaskan memor i
    delete[] astronaut;

    return 0;
}