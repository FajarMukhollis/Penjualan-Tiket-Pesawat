/*
struktur -> modul 1
poiter -> modul 2
ADT - SDL - Linier Single Linked List -> modul 3 dan 4
SDL - Stack -> modul 4
Merge Sort - Desccending -> modul 6
Heap Sort ->
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <conio.h>
#include <iostream>
using namespace std;
//struct and pointer
struct node {
    string fanama[20], falamat[20], fapemberangkatan[20], fatujuan[20]; 
};
//struct and pointer
//ADT-Single Linked List
struct ADT
{
      int data;
      ADT* next;
};

ADT* head;
ADT* tail;
ADT* curr;
ADT* entry;
ADT* del;

void inisialisasi()
{
      head = NULL;
      tail = NULL;
}

void input(int dt)
{
      entry = (ADT* )malloc(sizeof(ADT)); //alokasi memori
      entry->data = dt;
      entry->next = NULL;
      if(head==NULL)
      {
            head = entry;
            tail = head;
      }
      else
      {
            tail->next = entry;
            tail = entry;
      }
}

void berangkat() {
      curr = head;
            while(curr!=NULL)
            {
                  cout<<curr->data<< " ";
                  curr = curr->next;
            }
            cout<<endl;
}

//ADT-Single Linked List
//SDL - Stack
struct SDL {
    int data2;
    SDL *LINK2;
};

class LList {
private:
    SDL *First, *Last, *fa;
public:
    LList();
    int insertkiri(int data2);
    void kode();
};
LList :: LList () {
    First = NULL;
}

int LList :: insertkiri(int dt2) {
    SDL *f;
    f = new SDL;
    f -> LINK2 = First;
    f -> data2 = dt2;
    First = f;
    return(1);
}

void LList :: kode() {
    SDL *fa;
    fa = First;
    while(fa != NULL) {
        cout << " Kode - " << fa -> data2 << "  " <<endl;
        fa = fa -> LINK2;
    }
}
//SDL - Stack
//MERGE SORT
int afa[50];
int numfa, ifa;

void merge(int lowfa, int midfa, int highfa) {
    int hfa, ifa, jfa, bfa[50], kfa;
    hfa = lowfa;
    ifa = lowfa;
    jfa = midfa+1;
    while ((hfa <= midfa) && (jfa<=highfa)) {
        if(afa[hfa] >= afa[jfa]) { // Note 1
            bfa[ifa] = afa[hfa];
            hfa++;
        }
        else {
            bfa[ifa] = afa[jfa]; 
            jfa++;
        }
        ifa++;
    }
        if (hfa>midfa) {
            for (kfa = jfa; kfa <= highfa; kfa++) {
                bfa[ifa] = afa[kfa];
                ifa++;
            }
        }
        else {
            for (kfa=hfa; kfa<=midfa; kfa++) {
                bfa[ifa] = afa[kfa];
                ifa++;
            }
        }
        for (kfa = lowfa; kfa <= highfa; kfa++) {
            afa[kfa] = bfa[kfa];
        }
}


void merge_sort(int lowfa, int highfa) {
    int midfa;
    if (lowfa < highfa) {
        midfa = (lowfa+highfa)/2;
        merge_sort(lowfa,midfa);
        merge_sort(midfa+1, highfa);
        merge(lowfa, midfa, highfa);
    }
}
//MERGE SORT
//HEAP SORT
//Fungsi Tukar
void tukar(int &a, int &b)
{
    int temp;

    temp=a;
    a=b;
    b=temp;
}

//Fungsi Heapify
void heapify(int val[], int l, int r)
{
    int temp, idx;

    temp = val[r];
    idx = r * 2 + 1;

    if ((idx < l) && (val[idx] > val[idx+1])) //Note 1
        idx++;

    while ((idx <= l) && (val[idx] < temp)) //Note 2
    {
        val[r] = val[idx];
        r = idx;
        idx = idx * 2 + 1;
        if ((idx < l) && (val[idx] > val[idx+1])) //Note 3
            idx++;
    }

    val[r] = temp;
}

//Fungsi Heap Sort
void heapsort(int val[], int n) {
    for (int x = n/2 - 1; x >= 0; x--) {
        heapify(val, n - 1, x);
    }
    for (int y = n - 1; y > 0; y--) {
        tukar(val[0], val[y]);
        heapify(val, y - 1, 0);
    }
}
//heap sort

int main() {
    LList Xx; //SDL - Stack
    node*npenumpang;
    npenumpang = new node;
    int i,fajumlah,fapilih, faharga, fabayar,z;
    int jartanggal,jartahun,jarbulan,temp; //ADT
	int fadigit[100];
    int kode; //SDL - Stack
	int num = 4; 
    int har[4] = {1000000, 1500000, 2000000, 1400000}; //merge
    system("cls");
	awal :
    do {
        cout << endl;
        cout << " SELAMAT DATANG DI PEMESANAN TIKET KODE " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Pesan Tiket " << endl; 
        cout << " 2. Batalkan Pemesanan " << endl;
        cout << " 3. Exit/Selesai " << endl;
        cout << "===========================================" << endl;
        cout << " Masukkan Pilihan Anda 1 sd 3 : "; cin >> fapilih;
        cout << endl;
        system("cls");
        switch (fapilih) {
            case 1 :
                cout << " Masukkan Jumlah Penumpang : ";cin >> fajumlah;
                system("cls");
                if (fajumlah > 1 ) {
                    for ( i = 0; i < fajumlah; i++) {
                        cout << " Nama              : "; cin >> npenumpang->fanama[i];/*fflush(stdin);gets(npenumpang[i].fanama);*/
                        cout << " Alamat            : "; cin >> npenumpang->falamat[i];/*fflush(stdin);gets(npenumpang[i].falamat);*/
                        cout << " Pemberangkatan    : "; cin >> npenumpang->fapemberangkatan[i];
                        cout << " Tujuan            : "; cin >> npenumpang->fatujuan[i];
                        cout<<endl;
                        cout << " MASUKKAN PASSPORT PERDIGIT " << endl;
                        cout << "--------------------------------------" << endl;
                        for(z = 0; z < 6; z++) {
                            cout<<"Digit ke-"<<1+z<<"  : ";
                            cin>>fadigit[z];
                        }
                        //Memanggil fungsi Heap Sort
                        heapsort(fadigit, 6);
                        //Mencetak data setelah diurutkan
                        cout<<endl;
                        cout << " Passport Sudah Diurutkan " << endl;
                        cout << "==========================" << endl;
                        for(z=0; z < 6; z++) {
                            cout<<fadigit[z]<<" ";
                        }
                        cout << endl; 
                    }
                    cout << endl;
                    cout << " TANGGAL PEMBERANGKATAN " << endl;
                    cout << "========================" << endl;
                    cout << " Masukkan Tanggal    : ";
                    cin>>jartanggal;
                    input(jartanggal);
                    cout << " Masukkan Bulan      : ";
                    cin>>jarbulan;
                    input(jarbulan);
                    cout<<" Masukkan Tahun      : ";
                    cin>>jartahun;
                    input(jartahun);
                    cout << endl;
                    cout << " KODE PEMBERANGKATAN " << endl;
                    cout << "===========================================" << endl;
                    Xx.insertkiri(411);
                    Xx.insertkiri(321);
                    Xx.insertkiri(233);
                    Xx.insertkiri(121);
                    Xx.kode();
                    cout << endl;
                    cout << "-------------------------------------------" << endl;
                    cout << " PILIH KODE PEMBERANGKATAN : "; cin >> kode;
                    cout << endl;
                    cout << endl;
                    cout << " HARGA YANG TERSEDIA " << endl;
                    cout << "==================== " << endl;
                    cout << " Sebelum Diurutkan " << endl;
                    for (ifa=0; ifa < num; ifa++) {
                        cout << " - Rp " << har[ifa] << endl;
                        afa[ifa] = har[ifa];
                    } 
                    cout << endl;
                    cout << " Setelah Diurutkan " << endl;
                    merge_sort(0, num);
                    for (ifa=0; ifa<num; ifa++) {
                        cout << " - Rp " << afa[ifa] << endl;
                    }
                    cout << "--------------------------------------------" << endl;
                    cout << " Masukkan Nominal Yang Anda Pilih : Rp "; cin >> faharga;
                    cout<<endl;
                    cout <<"==============================================="<<endl;
                    system("cls");
                    cout << endl;
                    for ( i = 0; i < fajumlah; i++) {
                        cout << " Nama              : " << npenumpang->fanama[i] << endl;
                        cout << " Alamat            : " << npenumpang->falamat[i] << endl;
                        cout << " Pemberangkatan    : " << npenumpang->fapemberangkatan[i] << endl;
                        cout << " Tujuan            : " << npenumpang->fatujuan[i] << endl;
                        cout << " No Passport Anda  : " ;
                        for(z=0; z<6; z++) {
                            cout<<fadigit[z]<<" "; 
                        }
                        cout << endl;
                        cout << endl;
                    } 
                    cout <<"==============================================="<<endl;
                    cout<<endl;
                    cout <<" TANGGAL PEMBERANGKATAN  : ";
                    berangkat();
                    inisialisasi();
                    cout <<"==============================================="<<endl;
                    cout << endl;
                    cout << " Kode Pemberangkatan - " << kode << endl;
                    cout << endl;
                    cout <<"==============================================="<<endl;
                    fabayar = faharga*fajumlah;
                    cout << endl;
                    cout << " Total Harga Yang Harus Anda Bayar : Rp " << fabayar << endl;
                    cout << endl;
                    cout <<"==============================================="<<endl;
                    goto awal;
                    system("cls");
                }
                else {
                    system("cls");
                    for ( i = 0; i < fajumlah; i++) {
                        cout << " Nama              : "; cin >> npenumpang->fanama[i];/*fflush(stdin);gets(npenumpang[i].fanama);*/
                        cout << " Alamat            : "; cin >> npenumpang->falamat[i];/*fflush(stdin);gets(npenumpang[i].falamat);*/
                        cout << " Pemberangkatan    : "; cin >> npenumpang->fapemberangkatan[i];
                        cout << " Tujuan            : "; cin >> npenumpang->fatujuan[i];
                        cout<<endl;
                        cout << " MASUKKAN PASSPORT PERDIGIT " << endl;
                        cout << "--------------------------------------" << endl;
                        for(z = 0; z < 6; z++) {
                            cout<<"Digit ke-"<<1+z<<"  : ";
                            cin>>fadigit[z];
                        }
                        //Memanggil fungsi Heap Sort
                        heapsort(fadigit, 6);
                        //Mencetak data setelah diurutkan
                        cout<<endl;
                        cout << " Passport Sudah Diurutkan " << endl;
                        cout << "==========================" << endl;
                        for(z=0; z<6; z++) {
                            cout<<fadigit[z]<<" ";
                        }
                        cout << endl; 
                    }
                    cout << endl;
                    cout << " TANGGAL PEMBERANGKATAN " << endl;
                    cout << "========================" << endl;
                    cout << " Masukkan Tanggal    : ";
                    cin>>jartanggal;
                    input(jartanggal);
                    cout << " Masukkan Bulan      : ";
                    cin>>jarbulan;
                    input(jarbulan);
                    cout<<" Masukkan Tahun      : ";
                    cin>>jartahun;
                    input(jartahun);
                    cout << endl;
                    cout << " KODE PEMBERANGKATAN " << endl;
                    cout << "===========================================" << endl;
                    Xx.insertkiri(411);
                    Xx.insertkiri(321);
                    Xx.insertkiri(233);
                    Xx.insertkiri(121);
                    Xx.kode();
                    cout << endl;
                    cout << "-------------------------------------------" << endl;
                    cout << " PILIH KODE PEMBERANGKATAN : "; cin >> kode;
                    cout << endl;
                    cout << endl;
                    cout << " HARGA YANG TERSEDIA " << endl;
                    cout << "==================== " << endl;
                    cout << " Sebelum Diurutkan " << endl;
                    for (ifa=0; ifa < num; ifa++) {
                        cout << " - Rp " << har[ifa] << endl;
                        afa[ifa] = har[ifa];
                    } 
                    cout << endl;
                    cout << " Setelah Diurutkan " << endl;
                    merge_sort(0, num);
                    for (ifa=0; ifa<num; ifa++) {
                        cout << " - Rp " << afa[ifa] << endl;
                    }
                    cout << "--------------------------------------------" << endl;
                    cout << " Masukkan Nominal Yang Anda Pilih : Rp "; cin >> faharga;
                    cout<<endl;
                    cout <<"==============================================="<<endl;
                    system("cls");
                    cout << endl;
                    for ( i = 0; i < fajumlah; i++) {
                        cout << " Nama              : " << npenumpang->fanama[i] << endl;
                        cout << " Alamat            : " << npenumpang->falamat[i] << endl;
                        cout << " Pemberangkatan    : " << npenumpang->fapemberangkatan[i] << endl;
                        cout << " Tujuan            : " << npenumpang->fatujuan[i] << endl;
                        cout << " No Passport Anda  : " ;
                        for(z=0; z<6; z++) {
                            cout<<fadigit[z]<<" "; 
                        }
                        cout << endl;
                        cout << endl;
                    } 
                    cout <<"==============================================="<<endl;
                    cout<<endl;
                    cout <<" TANGGAL PEMBERANGKATAN  : ";
                    berangkat();
                    inisialisasi();
                    cout <<"==============================================="<<endl;
                    cout << endl;
                    cout << " Kode Pemberangkatan - " << kode << endl;
                    cout << endl;
                    cout <<"==============================================="<<endl;
                    fabayar = faharga*fajumlah;
                    cout << endl;
                    cout << " Total Harga Yang Harus Anda Bayar : Rp " << fabayar << endl;
                    cout << endl;
                    cout <<"==============================================="<<endl;
                    goto awal;
                    system("cls");
                }
                break; 
            case 2 :
                system("cls");
                cout << " PESANAN TELAH DIBATALKAN, TERIMAKASIH " << endl;
                break; 
            case 3 :
                system("cls");
                return 0;
                break;
        }
        cin.get();    
    } while (fapilih != 3);
    return 0;
}