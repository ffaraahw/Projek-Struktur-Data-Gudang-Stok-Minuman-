#include <iostream>
using namespace std;

struct Minuman {
    string nama;
    int kodeunik;
    int jumlahstok;
    int harga;
    Minuman* prev = NULL;
    Minuman* next = NULL;
};

struct DoubleLinkedList {
  private:
    Minuman* head;
    Minuman* tail;

  public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void AddMinuman(string newnama, int newkodeunik, int newjumlahstok, int newharga) {

        Minuman* tmp = new Minuman();
        tmp->nama = newnama;
        tmp->kodeunik = newkodeunik;
        tmp->jumlahstok = newjumlahstok;
        tmp->harga = newharga;
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tmp->prev = tail;
            tmp->next = NULL;
            tail = tmp;
        }
    }

    void LihatData() {
        Minuman* cur = head;
        cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --- -- \n";
        cout << " DATA STOK GUDANG MINUMAN SD JAYA MAJU\n";
        cout << "Kode \t Nama \t\t\t Jumlah \t Harga /kardus\n";
        while (cur != NULL) {
            cout << cur->kodeunik << "\t" << cur->nama << "\t\t" << cur->jumlahstok << "\t" << cur->harga << "\t" << "\n";
            cur = cur->next; // Move to the next node
        }
        cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --- -- \n";
    }

    void SortingData(){
        Minuman* cur = head->next;
        while (cur!= nullptr){
            Minuman* walker = cur;

            while (walker->prev != nullptr && walker->prev->kodeunik > walker->kodeunik){
                int tmpkodeunik = walker->kodeunik;
                string tmpnama = walker->nama;
                int tmpjumlahstok = walker->jumlahstok;
                int tmpharga = walker->harga;

                walker->kodeunik = walker->prev->kodeunik;
                walker->nama = walker->prev->nama;
                walker->jumlahstok = walker->prev->jumlahstok;
                walker->harga = walker->prev->harga;

                walker->prev->kodeunik =tmpkodeunik;
                walker->prev->nama = tmpnama;
                walker->prev->jumlahstok = tmpjumlahstok;
                walker->prev->harga = tmpharga;

                walker = walker->prev;
            }
            cur = cur-> next;
        }
    }

    void CariData(int kodeunik){
        Minuman* cur = head;
        bool found = false;

        while(cur != nullptr){
            if (cur ->kodeunik == kodeunik){
                cout<<"Kode \t Nama \t\t\t Jumlah \t Harga /kardus\n";
                cout<< cur->kodeunik << "\t" << cur->nama << "\t\t" << cur->jumlahstok << "\t" << cur->harga << "\t" << "\n";
                found = true;
                break;
            }
            cur = cur->next;
        }
        if (!found){
            cout<<"KODE "<<kodeunik<<"TIDAK DITEMUKAN\n";
        }
    }

    // Destructor to free memory
    ~DoubleLinkedList() {
        Minuman* cur = head;
        while (cur != NULL) {
            Minuman* next = cur->next;
            delete cur;
            cur = next;
        }
    }
};

int main() {
    DoubleLinkedList Minuman;
    int menu;

    Minuman.AddMinuman("Teh Botol Sosro", 1001, 90, 90000);
    Minuman.AddMinuman("Susu Dancow", 1009, 50, 140000);
    Minuman.AddMinuman("Pocari Sweat", 1008, 100, 150000);
    Minuman.AddMinuman("Coca Cola", 1003, 80, 99000);


    char confirm = 'y'; // Initialize confirm
    string nama;
    int kodeunik, jumlahstok, harga, expired;
    while (true) {
        cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
        cout << "Silahkan Pilih Menu\n";
        cout << "0. Keluar\n";
        cout << "1. Tambah Data Stok Minuman\n";
        cout << "2. Lihat Data Minuman\n";
        cout << "3. Sorting Data Minuman\n";
        cout << "4. Cari Data Minuman\n";
        cout << " -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n";
        cout << "Silahkan pilih menu (0-4): ";
        cin >> menu;

        switch (menu) {
            case 1:
                confirm = ' '; // Reset confirm for adding
                while (confirm != 't') {
                    cout << "-----------------------------------------\n";
                    cout << "Nama Merk Minuman: ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "Masukkan kode Unik: ";
                    cin >> kodeunik;
                    cout << "Jumlah Stok (kardus): ";
                    cin >> jumlahstok;
                    cout << "Harga per 1 kardus: ";
                    cin >> harga;
                    Minuman.AddMinuman(nama, kodeunik, jumlahstok, harga);
                    cout << "Apakah ingin menambah data lagi (y/t)? ";
                    cin >> confirm;
                    cout << "-----------------------------------------\n";
                }

                    cout << "Stok Minuman berhasil ditambahkan!\n";
                break;
            case 2:
                confirm = ' '; // Reset confirm for viewing
                while (confirm != 'y') {
                    Minuman.LihatData();
                    cout << "Kembali ke menu (y/t)? ";
                    cin >> confirm;
                }
                break;
            case 3:
                Minuman.SortingData();
                Minuman.LihatData();
                cout<<"Sorting telah berhasil dilakukan!";
                break;
            case 4:
                cout<<"Masukka kode : ";
                cin>>kodeunik;
                Minuman.CariData(kodeunik);
                break;
        }
        if (menu == 0) {
            cout << "Keluar...\n";
            break;
        }
    }
    return 0;
}
