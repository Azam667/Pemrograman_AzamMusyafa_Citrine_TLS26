# Pemrograman_AzamMusyafa_Citrine_TLS26

Repository ini berisi solusi dari dua problem TETI Lab Skill menggunakan bahasa pemrograman C++.

## Problem 1 — The Last Astronaut
Problem ini merupakan simulasi eliminasi sejumlah astronaut yang berdiri membentuk lingkaran.
Setiap astronaut memiliki nomor unik dari 1 sampai N, dan proses eliminasi menggunakan nilai K.

### Aturan eliminasi:
1. Perhitungan dimulai dari astronaut nomor 1.
2. Astronaut yang mendapatkan hitungan ke-K akan dieliminasi.
3. Setelah seorang astronaut dieliminasi, perhitungan berikutnya dimulai dari astronaut yang tepat setelahnya.
4. Setelah setiap eliminasi, nilai K berubah:
   - Jika nomor astronaut yang dieliminasi genap, K bertambah 2.
   - Jika nomor astronaut yang dieliminasi ganjil, K berkurang 1.
   - Nilai K tidak boleh kurang dari 2.
5. Proses terus dilakukan hingga hanya tersisa satu astronaut.

### Program menghasilkan:
- Urutan astronaut yang dieliminasi.
- Astronaut terakhir yang bertahan.
- Nilai K setelah proses eliminasi.

### Konsep yang digunakan
- Array
- Perulangan
- Percabangan
- Fungsi
- Operasi modulo
- Simulasi proses eliminasi

---

## Problem 2 — Alien-In-The-Middle
Problem ini merupakan sistem penyandian pesan berdasarkan nilai huruf dalam alfabet.
Setiap huruf memiliki nilai:

A = 1
B = 2
C = 3
...
Z = 26

### Aturan penyandian:
Huruf pertama tidak mengalami perubahan.
Setiap huruf berikutnya digeser berdasarkan nilai huruf yang berada tepat sebelumnya pada pesan asli.
Jika hasil pergeseran melewati Z, perhitungan kembali dimulai dari A

### Konsep yang digunakan
Array char
Manipulasi karakter
Konversi huruf menjadi nilai alfabet
Perulangan
Fungsi
Operasi aritmatika
Penyandian sederhana

---
