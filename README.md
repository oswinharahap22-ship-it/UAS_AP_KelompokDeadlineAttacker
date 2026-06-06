Nama kelompok: Kelompok DeadlineAttacker

Anggota:

(-) Oswinov Hutabarat (251401078)

(-) Rafly Anthony chaniago (251401018)

(-) Rio Ganda Pahala Sianipar (251401033)

(-) Muhammad Naufal Fairuz (251401108)

(-) Admaja janias Nadhif lahagu (251401090)

# Nomor 1 Parkir Mall

Program ini adalah sebuah aplikasi berbasis CLI (command-line interface) yang ditulis menggunakan bahasa pemrograman C++. Aplikasi ini dirancang untuk mensimulasikan sistem manajemen dan transaksi di sebuah pintu portal parkir khusus mobil secara real-time.

## Main Fitur
Sistem Log-in Petugas: Pada awal program, aplikasi akan meminta input nama dan ID petugas yang sedang berjaga. Informasi ini akan terus ditampilkan sebagai header di bagian atas menu utama sebagai bentuk pertanggungjawaban operasional.
Manajemen Kapasitas Dinamis: Program memiliki batas kapasitas parkir maksimal sebanyak 20 mobil. Sistem akan menolak input otomatis jika jumlah mobil yang dimasukkan melebihi kuota yang tersisa.
Pencatatan Waktu Akurat (Real-Time): Menggunakan pustaka <ctime> untuk merekam waktu masuk kendaraan secara presisi berdasarkan jam internal komputer, bukan berdasarkan input manual.
Penghitungan Durasi & Biaya Otomatis: Saat kendaraan keluar (melakukan pembayaran), sistem langsung menghitung selisih waktu dari awal masuk hingga detik berjalan. Tarif parkir ditetapkan sebesar Rp150 per menit, di mana kelebihan detik akan dibulatkan ke atas menjadi satu menit penuh.

## Opsi In Main Menu
Tambahkan Daftar Kendaraan: Digunakan untuk memasukkan data mobil baru (Nomor Plat, Merk, dan Warna Mobil) sekaligus mencatat waktu masuknya ke dalam sistem.
Tampilkan Daftar Kendaraan: Menampilkan seluruh mobil yang saat ini sedang berada di dalam area parkir beserta durasi parkirnya yang terus berjalan (diwujudkan dalam satuan Jam, Menit, dan Detik).
Pembayaran: Menampilkan daftar mobil aktif, meminta input plat nomor kendaraan yang ingin keluar, memproses hitungan biaya total secara otomatis, dan menghapus kendaraan tersebut dari sistem setelah pembayaran berhasil.
Keluar Program: Menutup aplikasi dengan aman serta membersihkan alokasi memori komputer (memory deallocation) yang digunakan selama program berjalan.

(https://drive.google.com/drive/folders/1-6CXYnx7QkzMk2HeuCVhFTXfE-RkLPkO?usp=sharing)

# Nomor 2 Deskripsi Menu Utama dan Fungsi

Proyek ini adalah aplikasi Game Tebak Kata berbasis Command Line Interface (CLI) menggunakan bahasa pemrograman C++. Konsep permainannya mirip dengan "Hangman", di mana pemain harus menebak sebuah kata rahasia huruf demi huruf sebelum "nyawa" (kesempatan menebak) mereka habis. Jika tebakan benar, huruf akan terbuka pada posisi yang sesuai. Jika salah, nyawa berkurang dan huruf tersebut dicatat agar pemain tahu huruf apa saja yang sudah ditebak.

## Tujuan Akademis:
Memenuhi standar kelulusan UAS Lab Algoritma dan Pemrograman dengan mengimplementasikan konsep-konsep inti C++ secara terpadu.

## Tujuan Teknis: 
Menunjukkan pemahaman mendalam terhadap materi:

## Tipe Data Bentukan (Struct): 
Mengelompokkan berbagai tipe data menjadi satu kesatuan (state game dan data pemain).

## Pointer (Pass by Reference): 
Memanipulasi nilai variabel asli di dalam sebuah fungsi tanpa melakukan return (pengembalian nilai).

## Array & String: 
Menyimpan kumpulan kata, riwayat tebakan salah, dan manipulasi teks.

## Algoritma Pengurutan (Sorting):
Mengurutkan skor tertinggi pemain untuk fitur Leaderboard.

## Modularitas:
Memisahkan fungsi-fungsi spesifik agar main program (program utama) tetap bersih dan mudah dibaca.

Penjelasan Tiap Komponen Kode:

## A. Library dan Bank kata 
#include <cstdlib> dan <ctime>: Digunakan untuk memanggil fungsi rand() dan srand(time(0)). Tujuannya agar sistem bisa mengacak kata secara dinamis setiap kali program dijalankan (tidak memunculkan kata yang sama terus-menerus).

BANK_KATA: Sebuah array konstanta (tidak bisa diubah) berisi 15 kata terkait dunia IT dan kampus yang akan dipilih secara acak oleh komputer.

## B. Struktur Data (struct)
struct KataGame: Ini adalah cetak biru untuk menyimpan status permainan saat itu. Berisi kata yang sedang ditebak (kataAsli), tampilan garis bawah (statusTebakan), sisa nyawa (sisaNyawa), dan daftar huruf salah (tebakanSalah).

struct PlayerScore: Digunakan khusus untuk menyimpan nama dan skor pemain di akhir game untuk keperluan Leaderboard.

## C. Fungsi Inisialilasi (inisialisasiGame)
Fungsi ini dipanggil di awal permainan. Fungsi ini menerima parameter berupa Pointer (KataGame* game).

Logika: Fungsi ini mengambil satu kata acak dari BANK_KATA, mengubah statusTebakan menjadi garis bawah (_ _ _), dan mengatur jumlah nyawa berdasarkan tingkat kesulitan yang dipilih pemain (Easy=8, Medium=6, Hard=4).

## D. Fungsi Logika Utama (prosesTebakan)
Ini adalah "otak" dari permainan. Menerima input huruf dari pemain dan mengeceknya.

Validasi: Program akan mengecek dulu apakah huruf tersebut sudah pernah ditebak sebelumnya (baik tebakan benar maupun salah). Jika sudah, program akan memberikan peringatan dan tidak memotong nyawa.

Pengecekan (Pencarian): Program melakukan looping (perulangan) ke setiap huruf pada kataAsli. Jika huruf tebakan cocok, maka status _ akan diganti dengan huruf tersebut. Jika setelah looping tidak ada huruf yang cocok, nyawa dikurangi 1 dan huruf tersebut dimasukkan ke array tebakanSalah.

## E. Fitur tambahan: Hint (gunakanHint) & Leaderboard
gunakanHint: Mencari karakter _ pertama yang belum tertebak, lalu otomatis membukanya dengan mengorbankan 1 nyawa.

updateLeaderboard: Menggunakan algoritma Bubble Sort. Setiap kali pemain menang dan mendapat skor, data akan dimasukkan ke dalam Array of Struct leaderboard. Algoritma kemudian akan membandingkan dan menukar posisi data agar skor tertinggi selalu berada di urutan teratas (indeks 0).

## F. Fungsi Utama (main)
Berisi alur besar (kontrol flow) permainan menggunakan perulangan do-while agar pemain bisa memilih "Bermain Lagi" setelah game over atau menang. Di sini juga terdapat logika cin untuk meminta input dan pemanggilan fungsi bersihkanLayar() agar tampilan CLI tidak menumpuk ke bawah (seperti aplikasi sungguhan).

Screenshot: https://drive.google.com/drive/folders/1CqqzRKkiPGtWi6Bwm6FGD2oqcVEfaR1C?usp=sharing

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

## 1. Tambah Barang

Fitur ini digunakan untuk memasukkan data barang baru ke dalam inventaris. Pengguna diminta mengisi kode barang, nama barang, harga, dan stok. Program melakukan validasi agar nilai harga dan stok tidak bernilai negatif. Jika pengguna memasukkan nilai yang tidak valid, program akan menampilkan pesan kesalahan dan meminta input ulang.

## 2. Tampilkan Semua Barang

Fitur ini menampilkan seluruh data barang yang tersimpan dalam inventaris. Informasi yang ditampilkan meliputi kode barang, nama barang, harga, dan stok masing-masing barang.

## 3. Cari Barang Termahal

Fitur ini digunakan untuk mencari barang dengan harga tertinggi. Program membandingkan harga seluruh barang yang ada dalam vector, kemudian menampilkan detail barang yang memiliki harga terbesar.

## 4. Hitung Total Nilai Inventaris

Fitur ini menghitung total nilai aset yang tersimpan di gudang. Perhitungan dilakukan dengan mengalikan harga barang dengan stoknya, kemudian menjumlahkan seluruh hasil perkalian tersebut.

Rumus yang digunakan:

Total Nilai Inventaris = Σ(harga × stok)

## 5. Cek Restock

Fitur ini menampilkan daftar barang yang memiliki stok kurang dari 5. Barang-barang tersebut dianggap memiliki stok kritis sehingga perlu segera dilakukan pemesanan ulang (restock).

## 6. Update Stok Menggunakan Pointer

Fitur ini memungkinkan pengguna mengubah stok suatu barang berdasarkan kode barang. Program mencari barang yang sesuai dengan kode yang dimasukkan pengguna, kemudian menggunakan pointer yang menunjuk ke atribut stok untuk memperbarui nilainya. Penggunaan pointer pada fitur ini bertujuan untuk memenuhi konsep manipulasi data menggunakan alamat memori.

## 7. Keluar

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

(https://drive.google.com/drive/folders/1deLJAcCkzs0undaKUz0zgof62uy3AbHy?usp=sharing)

# Nomor 4 Minesweeper++

Program ini merupakan aplikasi berbasis Command Line Interface (CLI) yang dibuat menggunakan bahasa C++. Program merupakan implementasi permainan Minesweeper yang dimainkan pada papan berukuran N × N. Pemain harus menemukan seluruh bom dengan memberikan tanda pada posisi bom tanpa membuka kotak yang berisi bom.

Program dibuat menggunakan satu class utama bernama `Minesweeper` yang bertugas mengelola seluruh data dan logika permainan. Seluruh data papan disimpan menggunakan array dua dimensi statis dengan ukuran maksimum 10 × 10 sesuai ketentuan tugas.

## Struktur Data

Program menggunakan tiga array dua dimensi untuk menyimpan data permainan:

### board[10][10]

Menyimpan kondisi asli papan permainan, yaitu:

* `'*'` untuk bom.
* `'0' - '8'` untuk jumlah bom di sekitar suatu kotak.

### display[10][10]

Menyimpan tampilan papan yang dilihat pemain.

* `'#'` untuk kotak yang belum dibuka.
* `'F'` untuk kotak yang ditandai sebagai bom.
* Angka atau bom yang sudah terbuka.

### flagged[10][10]

Menyimpan status penandaan bom menggunakan nilai boolean (`true` atau `false`).

Selain itu terdapat beberapa variabel penting:

* `size` : ukuran papan permainan.
* `bombCount` : jumlah bom pada permainan.
* `startTime` : waktu mulai permainan.
* `endTime` : waktu selesai permainan.
* `gameOver` : status permainan sedang berlangsung atau telah berakhir.

## Fitur Program

### 1. Menu Utama

Program memiliki menu utama yang memungkinkan pengguna untuk:

1. Memulai permainan baru.
2. Keluar dari program.

Menu akan terus ditampilkan sampai pengguna memilih keluar.

### 2. Papan Dinamis

Sebelum permainan dimulai, pemain dapat menentukan:

* Ukuran papan (4 × 4 sampai 10 × 10).
* Jumlah bom yang akan digunakan.

Program akan melakukan validasi agar input sesuai dengan batas yang ditentukan.

### 3. Penempatan Bom Acak

Bom ditempatkan secara acak menggunakan fungsi `rand()`. Posisi bom akan berbeda setiap kali permainan dimulai sehingga permainan menjadi lebih menantang.

### 4. Perhitungan Angka Otomatis

Setelah bom ditempatkan, program menghitung jumlah bom yang berada di delapan kotak sekitar setiap sel yang bukan bom.

Angka yang ditampilkan memiliki arti:

* 0 = tidak ada bom di sekitar.
* 1–8 = jumlah bom di sekitar kotak tersebut.

### 5. Membuka Kotak

Pemain dapat membuka kotak dengan memasukkan koordinat baris dan kolom.

Kemungkinan yang terjadi:

* Jika kotak berisi bom, permainan berakhir.
* Jika kotak berisi angka, angka akan ditampilkan.
* Jika kotak bernilai 0, area kosong di sekitarnya akan terbuka secara otomatis.

### 6. Flood Fill (Pembukaan Area Otomatis)

Fitur ini digunakan ketika pemain membuka kotak yang bernilai 0.

Program menggunakan metode rekursif untuk membuka seluruh area kosong yang saling terhubung hingga menemukan batas berupa angka yang lebih besar dari 0.

### 7. Penandaan Bom (Flag)

Pemain dapat memberikan tanda pada kotak yang dicurigai berisi bom menggunakan simbol `F`.

Tanda dapat dipasang maupun dihapus kembali kapan saja selama permainan berlangsung.

### 8. Penghitung Waktu

Program mencatat waktu permainan menggunakan fungsi `time()`.

Waktu dihitung sejak papan pertama kali ditampilkan hingga pemain menang atau kalah.

### 9. Kondisi Menang

Pemain dinyatakan menang apabila:

* Semua bom berhasil ditandai dengan benar.
* Tidak ada kotak aman yang diberi tanda bom.

Program akan melakukan pengecekan kondisi kemenangan setiap kali pemain melakukan aksi.

### 10. Menampilkan Semua Bom Saat Kalah

Jika pemain membuka kotak yang berisi bom, program akan menampilkan seluruh lokasi bom pada papan sehingga pemain dapat melihat posisi semua bom yang ada.

## Konsep Pemrograman yang Digunakan

Program ini menerapkan beberapa konsep dasar pemrograman, yaitu:

* Object Oriented Programming (OOP) menggunakan class `Minesweeper`.
* Array dua dimensi untuk merepresentasikan papan permainan.
* Rekursi pada fitur Flood Fill.
* Percabangan (if-else) untuk logika permainan.
* Perulangan (looping) untuk pengolahan papan.
* Random Number Generation menggunakan `rand()`.
* Validasi input pengguna.
* Manipulasi waktu menggunakan `time()`.

## Kesimpulan

Minesweeper++ merupakan permainan berbasis console yang mengimplementasikan konsep OOP, array dua dimensi, rekursi, pengacakan data, serta manajemen waktu. Program memungkinkan pemain menentukan ukuran papan dan jumlah bom, membuka kotak, menandai bom, serta menyelesaikan permainan dengan menemukan seluruh bom secara tepat.
Screenshot : https://drive.google.com/drive/folders/1y68tz37nGp5BuyWryqHDCLDa13Xhi7lm?usp=sharing



# Nomor 5 Game Tebak Negara
Program ini merupakan sebuah game tebak negara yang dibuat menggunakan bahasa pemrograman C++. Tujuan permainan adalah menebak nama negara ASEAN yang ditampilkan dengan beberapa huruf yang telah disembunyikan menggunakan karakter garis bawah (_). Program memanfaatkan konsep dasar pemrograman seperti array, fungsi, string, percabangan, perulangan, dan pembangkitan bilangan acak.

Saat program dijalankan, layar console terlebih dahulu dibersihkan menggunakan fungsi system("cls"). Kemudian program menginisialisasi generator bilangan acak melalui srand(time(0)) sehingga setiap kali program dijalankan, negara yang dipilih dan huruf yang disembunyikan akan berbeda.

Program menyimpan daftar 11 negara dalam sebuah array string bernama negaraASEAN, yaitu Indonesia, Malaysia, Singapore, Thailand, Vietnam, Laos, Myanmar, Cambodia, Brunei, Philippines, dan Timor Leste. Dari daftar tersebut, program akan memilih satu negara secara acak menggunakan fungsi rand().

Setelah negara terpilih, program memanggil fungsi buatSoal(). Fungsi ini bertugas membuat soal dengan cara menyalin nama negara yang dipilih ke dalam variabel baru, kemudian mengganti tiga huruf pada posisi acak dengan karakter _. Proses ini dilakukan menggunakan perulangan while hingga tepat tiga huruf berhasil disembunyikan. Hasil akhirnya berupa petunjuk yang harus ditebak oleh pemain.

Soal yang telah dibuat kemudian ditampilkan kepada pengguna. Program meminta pengguna memasukkan jawaban melalui keyboard menggunakan cin. Jawaban yang diberikan pengguna akan dibandingkan dengan jawaban yang sebenarnya menggunakan percabangan if-else.

Jika jawaban pengguna sesuai dengan nama negara yang dipilih, program menampilkan pesan bahwa jawaban benar dan nilai skor akan bertambah satu. Sebaliknya, jika jawaban salah, program menampilkan pesan kesalahan sekaligus menunjukkan jawaban yang benar agar pengguna mengetahui hasil yang seharusnya.

Setelah proses pengecekan selesai, program menampilkan skor yang telah diperoleh pengguna selama permainan berlangsung. Selanjutnya pengguna diberikan pilihan untuk bermain kembali dengan memasukkan karakter y atau Y. Jika pengguna memilih bermain lagi, program akan mengulangi seluruh proses mulai dari pemilihan negara secara acak hingga pengecekan jawaban. Jika pengguna memasukkan selain y atau Y , perulangan akan berhenti dan permainan berakhir.

Di akhir eksekusi, program menampilkan pesan penutup "Game Selesai ;)" sebagai tanda bahwa permainan telah berakhir.

## Konsep Pemrograman yang Digunakan
### 1. Array

-> Digunakan untuk menyimpan kumpulan nama negara.

string negaraASEAN[11]

### 2. Fungsi

Digunakan untuk memisahkan proses pembuatan soal dari program utama.

-> string buatSoal(string negara)

### 3. String

Digunakan untuk menyimpan dan memanipulasi teks berupa nama negara.

-> string jawabanBenar;

-> string soal;

### 4. Percabangan (If-Else)

Digunakan untuk menentukan apakah jawaban pengguna benar atau salah.

-> if (jawaban == jawabanBenar)

### 5. Perulangan (While)

Digunakan untuk menyembunyikan huruf pada nama negara dan mengulangi permainan selama pengguna ingin bermain lagi.

-> while (jumlahDisembunyikan > 0)

-> while (lagi == 'y' || lagi == 'Y')

### 6. Bilangan Acak

Digunakan untuk memilih negara secara acak dan menentukan posisi huruf yang akan disembunyikan.

-> rand()

### 7. Input dan Output

Digunakan untuk berinteraksi dengan pengguna.

-> cin

-> cout


Screenshot: https://drive.google.com/file/d/1K4291uycbpo_Mn8f9r29NdeBzADepl34/view?usp=sharing


Link Youtube ada didalam ini: https://drive.google.com/drive/folders/1pcm6UOhaAvGZxGe1crccV2a2O4vqw8Wd?usp=sharing
