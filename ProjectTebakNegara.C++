#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
string buatSoal(string negara) {
string soal = negara;
int jumlahDisembunyikan = 3;
   while (jumlahDisembunyikan > 0) {
    int pos = rand() % negara.length();
        if (soal[pos] != '_') {
            soal[pos] = '_';
            jumlahDisembunyikan--;
        }
    }
return soal;
}

int main(){
 system("cls");
 srand(time(0));
 string negaraASEAN[11] = {
    "indonesia",
    "malaysia",
    "singapore",
    "thailand",
    "vietnam",
    "laos",
    "myanmar",
    "cambodia",
    "brunei",
    "philippines",
    "timorleste"
 };
int skor = 0;
char lagi = 'y';
while (lagi == 'y' || lagi == 'Y') {
int index = rand() % 11;
string jawabanBenar = negaraASEAN[index];
string soal = buatSoal(jawabanBenar);
cout << "\nTebak negara: " << soal << endl;
string jawaban;
cout << "Negara apakah yang dimaksud? ";
cin >> jawaban;
if (jawaban == jawabanBenar) {
    cout << "Selamat! Anda benar." << endl;
    skor++;
 } else {
    cout << "Maaf, jawaban Anda salah. Coba lagi." << endl;
    cout << "Jawaban yang benar adalah: "
    << jawabanBenar << endl;
  }
  cout << "Skor Anda: " << skor << endl;
  cout << "Ingin bermain lagi? (y/n): ";
  cin >> lagi;
}
cout << "\nGame Selesai ;)" << endl;
return 0;
}