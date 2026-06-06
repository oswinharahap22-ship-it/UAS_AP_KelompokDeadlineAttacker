Nama kelompok: Kelompok DeadlineAttacker

Anggota:
(-) Oswinov Hutabarat (251401078)
(-) Rafly Anthony chaniago (251401018)
(-) Rio Ganda Pahala Sianipar (251401033)
(-) Muhammad Naufal Fairuz (251401108)
(-) Admaja janias Nadhif lahagu (251401090)



# Nomor 3 Deskripsi Menu Utama dan Fungsi

Program ini merupakan aplikasi berbasis Command Line Interface (CLI) yang dibuat menggunakan bahasa C++. Program berfungsi untuk membantu pengelolaan inventaris barang pada sebuah toko. Data barang disimpan menggunakan struktur data `struct Barang` dan seluruh data barang dikelola dalam sebuah `vector`.

## Struktur Data

Program menggunakan `struct Barang` untuk merepresentasikan setiap barang yang ada di inventaris. Struktur ini memiliki empat atribut, yaitu:

* `kodeBarang` : kode unik barang.
* `namaBarang` : nama barang.
* `harga` : harga satuan barang.
* `stok` : jumlah stok barang yang tersedia.

Seluruh data barang disimpan dalam `vector<Barang>` sehingga jumlah data dapat bertambah secara dinamis sesuai kebutuhan pengguna.

Fitur Program

# 1. Tambah Barang

Fitur ini digunakan untuk memasukkan data barang baru ke dalam inventaris. Pengguna diminta mengisi kode barang, nama barang, harga, dan stok. Program melakukan validasi agar nilai harga dan stok tidak bernilai negatif. Jika pengguna memasukkan nilai yang tidak valid, program akan menampilkan pesan kesalahan dan meminta input ulang.

# 2. Tampilkan Semua Barang

Fitur ini menampilkan seluruh data barang yang tersimpan dalam inventaris. Informasi yang ditampilkan meliputi kode barang, nama barang, harga, dan stok masing-masing barang.

# 3. Cari Barang Termahal

Fitur ini digunakan untuk mencari barang dengan harga tertinggi. Program membandingkan harga seluruh barang yang ada dalam vector, kemudian menampilkan detail barang yang memiliki harga terbesar.

# 4. Hitung Total Nilai Inventaris

Fitur ini menghitung total nilai aset yang tersimpan di gudang. Perhitungan dilakukan dengan mengalikan harga barang dengan stoknya, kemudian menjumlahkan seluruh hasil perkalian tersebut.

Rumus yang digunakan:

Total Nilai Inventaris = Σ(harga × stok)

# 5. Cek Restock

Fitur ini menampilkan daftar barang yang memiliki stok kurang dari 5. Barang-barang tersebut dianggap memiliki stok kritis sehingga perlu segera dilakukan pemesanan ulang (restock).

# 6. Update Stok Menggunakan Pointer

Fitur ini memungkinkan pengguna mengubah stok suatu barang berdasarkan kode barang. Program mencari barang yang sesuai dengan kode yang dimasukkan pengguna, kemudian menggunakan pointer yang menunjuk ke atribut stok untuk memperbarui nilainya. Penggunaan pointer pada fitur ini bertujuan untuk memenuhi konsep manipulasi data menggunakan alamat memori.

# 7. Keluar

Fitur ini digunakan untuk menghentikan program. Program akan terus menampilkan menu utama dalam sebuah perulangan hingga pengguna memilih menu keluar.

## Konsep Pemrograman yang Digunakan

Program ini menerapkan beberapa konsep dasar pemrograman C++, yaitu:

1. Struct untuk merepresentasikan data barang.
2. Vector untuk menyimpan kumpulan data barang.
3. Function untuk memisahkan setiap fitur program.
4. Looping (do-while dan for) untuk perulangan menu dan pengolahan data.
5. Conditional Statement (if) untuk validasi dan pengambilan keputusan.
6. Pointer untuk memperbarui nilai stok barang.
7. Input dan Output menggunakan cin dan cout.

Dengan adanya fitur-fitur tersebut, program dapat membantu pengguna dalam mengelola data inventaris toko secara sederhana dan terstruktur.

https://drive.google.com/drive/folders/1deLJAcCkzs0undaKUz0zgof62uy3AbHy?usp=drive_link
