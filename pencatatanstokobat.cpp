#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Struktur untuk menyimpan informasi obat
struct Obat {
    string nama;
    int stok;
    string tanggalKedaluwarsa;
};

// Fungsi untuk menambahkan data obat
void tambahObat(vector<Obat> &daftarObat) {
    Obat obatBaru;
    cout << "Masukkan nama obat: ";
    cin.ignore();
    getline(cin, obatBaru.nama);
    cout << "Masukkan jumlah stok: ";
    cin >> obatBaru.stok;
    cout << "Masukkan tanggal kedaluwarsa (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, obatBaru.tanggalKedaluwarsa);

    daftarObat.push_back(obatBaru);
    cout << "Data obat berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan semua data obat
void tampilkanObat(const vector<Obat> &daftarObat) {
    if (daftarObat.empty()) {
        cout << "Tidak ada data obat.\n";
        return;
    }

    cout << left << setw(20) << "Nama Obat" << setw(10) << "Stok"
         << "Tanggal Kedaluwarsa\n";
    cout << string(40, '-') << endl;

    for (const auto &obat : daftarObat) {
        cout << left << setw(20) << obat.nama << setw(10) << obat.stok
             << obat.tanggalKedaluwarsa << endl;
    }
}

// Fungsi untuk mengecek stok obat
void cekStok(const vector<Obat> &daftarObat) {
    bool stokHampirHabis = false;
    for (const auto &obat : daftarObat) {
        if (obat.stok < 5) {
            cout << "Peringatan: Stok obat \"" << obat.nama << "\" hampir habis. "
                 << "Sisa stok: " << obat.stok << endl;
            stokHampirHabis = true;
        }
    }
    if (!stokHampirHabis) {
        cout << "Semua stok obat mencukupi.\n";
    }
}

// Fungsi utama
int main() {
    vector<Obat> daftarObat;
    int pilihan;

    do {
        cout << "\n=== Sistem Pencatatan Stok Obat ===\n";
        cout << "1. Tambah Obat\n";
        cout << "2. Tampilkan Semua Obat\n";
        cout << "3. Cek Stok Obat\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahObat(daftarObat);
                break;
            case 2:
                tampilkanObat(daftarObat);
                break;
            case 3:
                cekStok(daftarObat);
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
