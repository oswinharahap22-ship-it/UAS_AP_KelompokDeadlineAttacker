#ifndef TEBAKKATA_H
#define TEBAKKATA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const string BANK_KATA[15] = {
    "MAHASISWA", "ALGORITMA", "PEMROGRAMAN", "KOMPUTER", "NUSANTARA",
    "INFORMATIKA", "STRUKTUR", "POINTER", "UNIVERSITAS", "MEDAN",
    "SUMATERA", "FUNGSI", "VARIABEL", "TERMINAL", "INTELLIGENCE"
};

struct KataGame {
    string kataAsli;
    string statusTebakan;
    int sisaNyawa;
    char tebakanSalah[26];
    int jumlahSalah;
};

struct PlayerScore {
    string nama;
    int skor;
};


inline void bersihkanLayar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

inline void inisialisasiGame(KataGame* game, int tingkatKesulitan) {

    game->kataAsli = BANK_KATA[rand() % 15];
    
    game->statusTebakan = "";
    for (int i = 0; i < game->kataAsli.length(); i++) {
        game->statusTebakan += "_";
    }

    
    if (tingkatKesulitan == 1) game->sisaNyawa = 8;      
    else if (tingkatKesulitan == 2) game->sisaNyawa = 6;
    else game->sisaNyawa = 4;                            

    game->jumlahSalah = 0;
}

inline void prosesTebakan(KataGame* game, char tebakan) {
    tebakan = toupper(tebakan); // Pastikan huruf besar

    for (int i = 0; i < game->statusTebakan.length(); i++) {
        if (game->statusTebakan[i] == tebakan) {
            cout << "\n[Peringatan] Huruf '" << tebakan << "' sudah ditebak benar! Tidak mengurangi nyawa.\n";
            return;
        }
    }

    for (int i = 0; i < game->jumlahSalah; i++) {
        if (game->tebakanSalah[i] == tebakan) {
            cout << "\n[Peringatan] Huruf '" << tebakan << "' sudah pernah ditebak dan salah! Tidak mengurangi nyawa.\n";
            return;
        }
    }

    bool tebakanBenar = false;
    for (int i = 0; i < game->kataAsli.length(); i++) {
        if (game->kataAsli[i] == tebakan) {
            game->statusTebakan[i] = tebakan; 
            tebakanBenar = true;
        }
    }

    if (!tebakanBenar) {
        game->tebakanSalah[game->jumlahSalah] = tebakan;
        game->jumlahSalah++;
        game->sisaNyawa--;
        cout << "\n[Salah] Huruf '" << tebakan << "' tidak ada!\n";
    } else {
        cout << "\n[Benar] Huruf '" << tebakan << "' ditemukan!\n";
    }
}

inline void gunakanHint(KataGame* game) {
    if (game->sisaNyawa <= 1) {
        cout << "\n[Gagal] Nyawa Anda tidak cukup untuk menggunakan Hint!\n";
        return;
    }

    for (int i = 0; i < game->kataAsli.length(); i++) {
        if (game->statusTebakan[i] == '_') {
            char hintChar = game->kataAsli[i];
            for(int j = 0; j < game->kataAsli.length(); j++){
                if(game->kataAsli[j] == hintChar){
                    game->statusTebakan[j] = hintChar; 
                }
            }
            game->sisaNyawa--; 
            cout << "\n[Hint Berhasil] Huruf '" << hintChar << "' terbuka. (Nyawa -1)\n";
            break;
        }
    }
}

inline void tampilkanInfoLayar(KataGame* game) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "           GAME TEBAK KATA            \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Kata Rahasia : ";
    for(int i = 0; i < game->statusTebakan.length(); i++) {
        cout << game->statusTebakan[i] << " ";
    }
    cout << "\n\nSisa Nyawa   : " << game->sisaNyawa << "\n";
    
    cout << "Huruf Salah  : ";
    for (int i = 0; i < game->jumlahSalah; i++) {
        cout << game->tebakanSalah[i] << " ";
    }
    cout << "\n--------------------------------------\n";
}

inline void updateLeaderboard(PlayerScore leaderboard[], int& totalPemain, string namaBaru, int skorBaru) {
    if (totalPemain < 5) {
        leaderboard[totalPemain].nama = namaBaru;
        leaderboard[totalPemain].skor = skorBaru;
        totalPemain++;
    } else {
        int minIndex = 0;
        for (int i = 1; i < 5; i++) {
            if (leaderboard[i].skor < leaderboard[minIndex].skor) minIndex = i;
        }
        if (skorBaru > leaderboard[minIndex].skor) {
            leaderboard[minIndex].nama = namaBaru;
            leaderboard[minIndex].skor = skorBaru;
        }
    }
    for (int i = 0; i < totalPemain - 1; i++) {
        for (int j = 0; j < totalPemain - i - 1; j++) {
            if (leaderboard[j].skor < leaderboard[j + 1].skor) {
                swap(leaderboard[j], leaderboard[j + 1]);
            }
        }
    }
}

inline void tampilkanLeaderboard(PlayerScore leaderboard[], int totalPemain) {
    cout << "\n=== LEADERBOARD (Top 5) ===\n";
    if (totalPemain == 0) cout << "Belum ada data.\n";
    else {
        for (int i = 0; i < totalPemain; i++) {
            cout << i + 1 << ". " << leaderboard[i].nama << " - " << leaderboard[i].skor << " Poin\n";
        }
    }
    cout << "===========================\n";
}

#endif
