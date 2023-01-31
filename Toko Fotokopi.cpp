#include <iostream>
#include <vector>

using namespace std;

struct Barang{
  string nama;
  int harga;
};

vector<Barang> daftarLayanan{
  {"Fotokopi", 300},
  {"Print", 1000}, 
  {"ATK"}
};

vector<Barang> daftarBarang{
  {"Pensil", 2000},
  {"Bulpen", 3000},
  {"Buku Tulis", 4000},
  {"Penggaris", 3000},
  {"Spidol Whiteboard", 10000},
  {"Penghapus", 1500},
  {"Tipe X", 8000},
};

struct Keranjang{
  Barang barang;
  int jumlah;
};

vector<Keranjang> keranjang;

void keranjangBarang(Barang barang, int jumlahBarang) {
  keranjang.push_back({barang.nama, barang.harga, jumlahBarang});
};

void tampilkanLayanan(int nomorLayanan) {
  int jumlahBarang, nomorBarang;

  if (nomorLayanan != 3) {
    amountService:
      cout << "Masukkan jumlah barang (minimal 1) : ";
      cin >> jumlahBarang;

      system("cls");
      
      if (jumlahBarang > 0) {
        keranjangBarang(daftarLayanan[nomorLayanan - 1], jumlahBarang);
      } else {
        goto amountService;
      }
  } else {
    amountItem:
      for (int i = 0; i < daftarBarang.size(); i++) {
        cout << i + 1 << ". " << daftarBarang[i].nama << " ~ Rp " << daftarBarang[i].harga << endl;
      }

      cout << endl << "Pilih barang (1 - " << daftarBarang.size() << ") : ";
      cin >> nomorBarang;

      system("cls");

      if (nomorBarang > 0 && nomorBarang <= daftarBarang.size()) {
        cout << "Masukkan jumlah barang (minimal 1) : ";
        cin >> jumlahBarang;

        system("cls");  

        if (jumlahBarang > 0) {
          keranjangBarang(daftarBarang[nomorBarang - 1], jumlahBarang);
        } else {
          goto amountItem;
        }
      } else {
        goto amountItem;
      }
  }
};


int main() {
  int nomorLayanan, totalHarga;
  char ulang;
  
  service:
     cout << "--------------------------------------------------" << endl;
     cout << "    SELAMAT DATANG KE TOKO FOTOKOPI PAGARUYUNG    " << endl;
     cout << "--------------------------------------------------" << endl;
     cout << "Keranjang : " << keranjang.size() << endl;

    for (int i = 0; i < daftarLayanan.size(); i++) {
      cout << i + 1 << ". " << daftarLayanan[i].nama << endl;
    }

    cout << endl << "Silahkan Pilih Layanan Yang Inginkan (1 - " << daftarLayanan.size() << ") : ";
    cin >> nomorLayanan;

    system("cls");

    if (nomorLayanan > 0 && nomorLayanan <= daftarLayanan.size()) {
      tampilkanLayanan(nomorLayanan);
    } else {
      goto service;
    }

    cout << "Apakah ada tambahan barang? (y/t) : ";
    cin >> ulang;

    system("cls");

    if (ulang == 'y') {
      goto service;
    } else {
      cout << "======== Rincian Barang ========" << endl << endl;

      for (int i = 0; i < keranjang.size(); i++) {
        cout << i + 1 << ". " << keranjang[i].barang.nama << " (Rp " << keranjang[i].barang.harga << ") : " << keranjang[i].jumlah << endl;
      }

      for (int i = 0; i < keranjang.size(); i++) {
        totalHarga = (keranjang[i].jumlah * keranjang[i].barang.harga) + totalHarga;
      }

      cout << endl << "Total harga : Rp " << totalHarga;  
    }
}
