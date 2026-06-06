#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Petugas {
    string nama;
    string id;
};

struct Kendaraan {
    string plat;
    string merk;
    string warna;
    time_t waktuMasuk;
};

const int MAKS_KAPASITAS = 20;

void tampilkanGaris() {
    cout << "====================================================================" << endl;
}

void tampilkanHeaderPetugas(const Petugas* p) {
    cout << "Nama Petugas : " << p->nama << endl;
    cout << "ID Petugas   : " << p->id << endl << endl;
    cout << "                    TERIMA KASIH ATAS KERJASAMANYA !" << endl;
    cout << "------------------------ SELAMAT BERTUGAS --------------------------" << endl;
    tampilkanGaris();
}

void hitungDurasi(time_t awal, int &jam, int &menit, int &detik) {
    time_t sekarang = time(0);
    int totalDetik = difftime(sekarang, awal);
    
    jam = totalDetik / 3600;
    menit = (totalDetik % 3600) / 60;
    detik = totalDetik % 60;
}

int hitungBiaya(time_t awal) {
    int jam, menit, detik;
    hitungDurasi(awal, jam, menit, detik);
    int totalMenit = (jam * 60) + menit + (detik > 0 ? 1 : 0);
    
    if (totalMenit == 0 && detik >= 0) {
        totalMenit = 1;
    }
    return totalMenit * 150;
}

int main() {
    Petugas* petugasHariIni = new Petugas;
    vector<Kendaraan> daftarParkir;

    tampilkanGaris();
    cout << "------------------------ SELAMAT DATANG ----------------------------" << endl;
    cout << "                     DI PORTAL PARKIR KHUSUS MOBIL" << endl;
    cout << "                             MALL PRIENAL" << endl;
    tampilkanGaris();
    cout << "Kami senang Anda telah hadir." << endl;
    cout << "Sebelum melanjutkan, silahkan masukkan informasi Anda yang akan bertugas hari ini.\n" << endl;
    
    cout << "Masukkan nama : ";
    getline(cin, petugasHariIni->nama);
    cout << "Masukkan ID   : ";
    cin >> petugasHariIni->id;
    cin.ignore();

    int opsi = 0;
    while (opsi != 4) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        tampilkanHeaderPetugas(petugasHariIni);
        cout << "\nSilahkan input opsi berikut dalam bentuk angka." << endl;
        cout << "1. Tambahkan Daftar Kendaraan" << endl;
        cout << "2. Tampilkan Daftar Kendaraan" << endl;
        cout << "3. Pembayaran" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "Masukkan opsi : ";
        cin >> opsi;
        cin.ignore();

        if (opsi == 1) {
            int jumlah;
            cout << "Masukkan jumlah mobil yang akan di parkirkan : ";
            cin >> jumlah;
            cin.ignore();

            if (daftarParkir.size() + jumlah > MAKS_KAPASITAS) {
                cout << "Maaf, parkiran hanya dapat memuat " << MAKS_KAPASITAS << " mobil." << endl;
            } else {
                for (int i = 0; i < jumlah; i++) {
                    Kendaraan k;
                    cout << "\nMobil ke " << (daftarParkir.size() + 1) << endl;
                    cout << "Masukkan plat mobil  : ";
                    getline(cin, k.plat);
                    cout << "Masukkan merk mobil  : ";
                    getline(cin, k.merk);
                    cout << "Masukkan warna mobil : ";
                    getline(cin, k.warna);
                    k.waktuMasuk = time(0);
                    daftarParkir.push_back(k);
                }
            }
        } 
        else if (opsi == 2) {
            cout << "\nDAFTAR MOBIL YANG SUDAH TERPARKIR :" << endl;
            tampilkanGaris();
            if (daftarParkir.empty()) {
                cout << "Parkiran kosong." << endl;
            } else {
                for (size_t i = 0; i < daftarParkir.size(); i++) {
                    Kendaraan* kPtr = &daftarParkir[i];
                    int h, m, s;
                    hitungDurasi(kPtr->waktuMasuk, h, m, s);
                    cout << "Mobil ke-" << (i + 1) << endl;
                    cout << "Plat mobil   : " << kPtr->plat << endl;
                    cout << "Merk mobil   : " << kPtr->merk << endl;
                    cout << "Warna mobil  : " << kPtr->warna << endl;
                    cout << "Waktu parkir : " << h << " jam " << m << " menit " << s << " detik" << endl;
                    tampilkanGaris();
                }
            }
        } 
        else if (opsi == 3) {
            string cariPlat;
            cout << "Masukkan plat mobil yang ingin dibayar : ";
            getline(cin, cariPlat);
            bool ditemukan = false;

            for (auto it = daftarParkir.begin(); it != daftarParkir.end(); ++it) {
                if (it->plat == cariPlat) {
                    int biaya = hitungBiaya(it->waktuMasuk);
                    cout << "\nBIAYA PARKIR : Rp" << biaya << endl;
                    daftarParkir.erase(it);
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "PLAT TIDAK DITEMUKAN !" << endl;
            }
        }

        if (opsi != 4) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }
    }

    delete petugasHariIni;
    cout << "\nProgram selesai. Sampai jumpa!" << endl;
    return 0;
}