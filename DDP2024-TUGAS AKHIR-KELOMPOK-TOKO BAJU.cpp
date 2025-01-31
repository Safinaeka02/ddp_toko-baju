// Nama Kelompok:
//1. Ani Anggraini Prasetyo 2400018117
//2.Lathiifah Faathimah 2400018123
//3,Safina Eka Anindita 2400018130
//Kellas : C


//Safina Eka Anindita 2400018130
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

using namespace std;

struct Barang {
    string nama;
    string kategori;
    string ukuran;
    string warna;
    float harga;
    int stok;
};
struct ItemTransaksi {
    string nama_barang;
    int jumlah;
    double total_harga;
};
struct Transaksi {
    string id_transaksi;
    string nama_pelanggan;
    ItemTransaksi barang_dibeli[100];  
    int jumlahBarangDibeli; 
    double total_harga_transaksi;
};


void tambahBarang(Barang &b) {
    cin.ignore();
    cout << "Masukkan nama barang: ";
    getline(cin, b.nama);
    cout << "Masukkan kategori: ";
    getline(cin, b.kategori);
    cout << "Masukkan ukuran: ";
    getline(cin, b.ukuran);
    cout << "Masukkan warna: ";
    getline(cin, b.warna);
    cout << "Masukkan harga: ";
    cin >> b.harga;
    cout << "Masukkan stok: ";
    cin >> b.stok;
}

//2.Lathiifah Faathimah 2400018123
void catatTransaksi(Transaksi &t, Barang barang[], int jumlahBarang) {
    cin.ignore();  
    cout << "Masukkan ID Transaksi: ";
    getline(cin, t.id_transaksi);
    cout << "Masukkan Nama Pelanggan: ";
    getline(cin, t.nama_pelanggan);

    char lanjut = 'y';
    t.total_harga_transaksi = 0.0;
    t.jumlahBarangDibeli = 0;  
    
    while (lanjut == 'y' || lanjut == 'Y') {
        ItemTransaksi item;  

        cout << "Masukkan Nama Barang yang dibeli: ";
        getline(cin, item.nama_barang);
        cout << "Masukkan Jumlah yang dibeli: ";
        cin >> item.jumlah;
        cin.ignore();

        bool barangTersedia = false;

        for (int i = 0; i < jumlahBarang; i++) {
            if (barang[i].nama == item.nama_barang && barang[i].stok >= item.jumlah) {
                item.total_harga = item.jumlah * barang[i].harga;
                barang[i].stok -= item.jumlah; 
                t.total_harga_transaksi += item.total_harga; 
                t.barang_dibeli[t.jumlahBarangDibeli++] = item; 
                barangTersedia = true;
                break;
            }
        }

        if (!barangTersedia) {
            cout << "Barang '" << item.nama_barang << "' tidak tersedia atau stok tidak cukup." << endl;
        }

        cout << "Apakah Anda ingin membeli barang lain? (y/n): ";
        cin >> lanjut;
        cin.ignore();
    }
    
    ofstream file("struk_belanja.txt", ios::app);
    file << "==================================================" << endl;
    file << "        Toko SANILA - STRUK BELANJA      " << endl;
    file << "    Jl. Bantul No. 456, Kota Yogyakarta    " << endl;
    file << "==================================================" << endl;
    file << "ID Transaksi    : " << t.id_transaksi << endl;
    file << "Nama Pelanggan  : " << t.nama_pelanggan << endl;
    file << "--------------------------------------------------" << endl;
    file << "Barang          | Jumlah | Harga | Total  " << endl;
    file << "--------------------------------------------------" << endl;

    for (int i = 0; i < t.jumlahBarangDibeli; i++) {
        file << left << setw(16) << t.barang_dibeli[i].nama_barang
             << setw(8) << t.barang_dibeli[i].jumlah
             << setw(8) << fixed << setprecision(2) << barang[0].harga 
             << setw(8) << fixed << setprecision(2) << t.barang_dibeli[i].total_harga << endl;
    }

    file << "--------------------------------------------------" << endl;
    file << "Total Harga     : " << fixed << setprecision(2) << t.total_harga_transaksi << endl;
    file << "==================================================" << endl;
    file << "Terima kasih atas belanja Anda!" << endl;
    file << "==================================================" << endl << endl;

    file.close(); // Menutup file

    cout << "Transaksi berhasil! Total harga: " << t.total_harga_transaksi << endl;
}

//Safina Eka Anindita 2400018130 & Ani Anggraini Prasetyo 2400018117
void tampilkanBarang(Barang barang[], int jumlahBarang) {
    cout << "\nDaftar Barang Toko:" << endl;
    cout << left << setw(20) << "Nama"
         << setw(15) << "Kategori"
         << setw(10) << "Ukuran"
         << setw(10) << "Warna"
         << setw(10) << "Harga"
         << setw(10) << "Stok" << endl;
    cout << string(75, '-') << endl;

    for (int i = 0; i < jumlahBarang; i++) {
        cout << left << setw(20) << barang[i].nama
             << setw(15) << barang[i].kategori
             << setw(10) << barang[i].ukuran
             << setw(10) << barang[i].warna
             << setw(10) << barang[i].harga
             << setw(10) << barang[i].stok << endl;
    }
}

//Ani Anggraini Prasetyo 2400018117
void tampilkanMenu() {
    cout << "\nMenu Program Toko Baju:" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Lihat Daftar Barang" << endl;
    cout << "3. Catat Transaksi" << endl;
    cout << "4. Keluar" << endl;
}

int main() {
    Barang barang[100];      
    int jumlahBarang = 0;

    int pilihan;
    while (true) {
        tampilkanMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            Barang b;
            tambahBarang(b);
            barang[jumlahBarang] = b;
            jumlahBarang++;
        } else if (pilihan == 2) {
            tampilkanBarang(barang, jumlahBarang);
        } else if (pilihan == 3) {
            Transaksi t;
            catatTransaksi(t, barang, jumlahBarang);
        } else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    }

    return 0;
}

