#include <iostream>
using namespace std;

struct Buku
{
    string judul, pengarang;
    int tahunTerbit;

    Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del;

// prototype fungsi sederhana
void createSingleLinklist(string judul, string pengarang, int tahunTerbit);

// tambah di awal single linked list
void addPertama(string judul, string pengarang, int tahunTerbit);

// tambah di akhir single linked list
void addTerakhir(string judul, string pengarang, int tahunTerbit);

// hapus pertama
void hapusPertama();

// hapus akhir
void hapusAkhir();

// ubah pertama
void gantiPertama(string judul, string pengarang, int tahunTerbit);

// ubah akhir
void gantiAkhir(string judul, string pengarang, int tahunTerbit);

// tammpilkan data
void printSingleLinkedList();

// menu tampilan awal
void menu();

int main()
{
    menu();

    cin.get();
    return 0;
}

// definisi prototype fungsi di atas

void createSingleLinklist(string judul, string pengarang, int tahunTerbit)
{
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
    head->next = NULL;
    tail = head;
}

// tambah di awal single linked list

void addPertama(string judul, string pengarang, int tahunTerbit)
{

    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
    newNode->next = NULL;
    newNode->next = head; // newnodenya bakalan ke head
    head = newNode;       // dan head pindahin ke newnode
}

// tambah di akhir single linked list

void addTerakhir(string judul, string pengarang, int tahunTerbit)
{

    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// hapus pertama
void hapusPertama()
{

    del = head;
    head = head->next;
    delete del;
}

// hapus akhir
void hapusAkhir()
{
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }

    tail = cur;
    tail->next = NULL;
    delete del;
}

// ubah pertama
void gantiPertama(string judul, string pengarang, int tahunTerbit)
{

    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
}

// ubah akhir
void gantiAkhir(string judul, string pengarang, int tahunTerbit)
{

    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
}

void printSingleLinkedList()
{
    cur = head;
    while (cur != NULL)
    {
        cout << "Judul Buku  : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit : " << cur->tahunTerbit << endl;

        cur = cur->next;
        cout << endl; // untuk memberi spasi tiap node
    }
}

void menu()
{
    int pilih, tahunTerbit;
    string judul, pengarang;
    char ulang;

    do
    {
        system("clear");
        cout << "Single Linked List Buku" << endl;
        cout << "------------------" << endl;
        cout << "Option Menu : " << endl;
        cout << "1.Input Data Buku" << endl;
        cout << "2.Input Data Buku Di awal" << endl;
        cout << "3.Input Data Buku Di akhir" << endl;
        cout << "4.Ganti Data Buku Pertama" << endl;
        cout << "5.Ganti Data Buku Di akhir" << endl;
        cout << "6.Hapus Data Buku di awal" << endl;
        cout << "7.Hapus Data BUku di Akhir" << endl;
        cout << "8.Tampilkan Data Buku " << endl;

        cout << "Masukan pilihan anda :";
        cin >> pilih;
        cout << endl;

        switch (pilih)
        {
        case 1:
            cout << "Masukan Judul Buku :";
            cin >> judul;
            cout << "Masukan Pengarang Buku :";
            cin >> pengarang;
            cout << "Masukan Tahun Terbit Buku :";
            cin >> tahunTerbit;
            createSingleLinklist(judul, pengarang, tahunTerbit);
            break;

        case 2:
            cout << "Masukan Judul Buku :";
            cin >> judul;
            cout << "Masukan Pengarang Buku :";
            cin >> pengarang;
            cout << "Masukan Tahun Terbit Buku :";
            cin >> tahunTerbit;
            addPertama(judul, pengarang, tahunTerbit);
            break;

        case 3:
            cout << "Masukan Judul Buku :";
            cin >> judul;
            cout << "Masukan Pengarang Buku :";
            cin >> pengarang;
            cout << "Masukan Tahun Terbit Buku :";
            cin >> tahunTerbit;
            addTerakhir(judul, pengarang, tahunTerbit);
            break;

        case 4:
            cout << "Masukan Judul Buku :";
            cin >> judul;
            cout << "Masukan Pengarang Buku :";
            cin >> pengarang;
            cout << "Masukan Tahun Terbit Buku :";
            cin >> tahunTerbit;
            gantiPertama(judul, pengarang, tahunTerbit);
            break;

        case 5:
            cout << "Masukan Judul Buku :";
            cin >> judul;
            cout << "Masukan Pengarang Buku :";
            cin >> pengarang;
            cout << "Masukan Tahun Terbit Buku :";
            cin >> tahunTerbit;
            gantiAkhir(judul, pengarang, tahunTerbit);
            break;

        case 6:
            hapusPertama();
            break;

        case 7:
            hapusAkhir();
            break;

        case 8:
            cout << "Data Buku Masuk :" << endl;
            printSingleLinkedList();
            break;

        default:
            system("clear");
            cout << "Inputan salah !!" << endl;
        }
        cout << "\nKembali Ke menu (y/n)";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
}
