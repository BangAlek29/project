#include "Album.h"

void createAlbum(ptrAlbum &newAlbum) // membuat node album baru taro di header album
{
    newAlbum = new Album;
    cout << "Masukkan id album: ";
    cin >> newAlbum->idAlbum;
    cout << "Masukkan judul album: ";
    cin >> newAlbum->judulAlbum;
    newAlbum->nextAlbum = nullptr;
    newAlbum->firstLagu = nullptr;
}

void traversalAlbum(first head) // menampilkan semua album dari artis tertentu di luar playlist taro di header album
{
    int no = 1;
    ptrAlbum pBantu = head->firstAlbum;
    if (pBantu == nullptr)
    {
        cout << "kosong";
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->judulAlbum << " ID" << pBantu->idAlbum << endl;
            no++;
            pBantu = pBantu->nextAlbum;
        }
    }
}

void pickAlbumFromArtis(first head, int pilihAlbum) // memilih album dari artis diluar playlist masukin ke header album
{
    ptrAlbum pBantu = head->firstAlbum;
    while (pBantu != nullptr)
    {
        if (pilihAlbum != 1)
        {
            pilihAlbum--;
            pBantu = pBantu->nextAlbum;
        }
        else if (pilihAlbum == 1)
        {
            traversalLaguFromAlbum(pBantu);
            return;
        }
    }
}

void pickAlbumFromList(first head, string key, int pilihAlbum) // memilih album dari banyaknya list album yang dicari
{
    int pilihLagu;
    ptrArtis pBantuArtis = head;
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            if (pBantuAlbum->judulAlbum == key && pilihAlbum != 1)
            {
                pilihAlbum--;
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
            else if (pBantuAlbum->judulAlbum == key && pilihAlbum == 1)
            {
                traversalLaguFromAlbum(pBantuAlbum);
                cout << "Mau Pilih Lagu ke berapa?";
                cin >> pilihLagu;
                pickLaguFromAlbum(head, pilihLagu);

                return;
            }
        }
    }
}

void traversalSearchAlbum(first head, string key) // mencari album tertentu yang ingin dilihat lagunya masukin ke header album
{
    ptrArtis pBantuArtis = head;
    int no = 1;
    int pilihAlbum; // album ke berapa yang mau diliat lagunya
    while (pBantuArtis != nullptr)
    {
        ptrAlbum pBantuAlbum = pBantuArtis->firstAlbum;
        while (pBantuAlbum != nullptr)
        {
            if (pBantuAlbum->judulAlbum == key)
            {
                cout << no << ". " << pBantuAlbum->judulAlbum << endl;
                no++;
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
            else
            {
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
        }
        pBantuArtis = pBantuArtis->nextArtis;
    }
    bool pilihLagu = true;
    while (pilihLagu == true)
    {
        cout << "Pilih album ke berapa (0 untuk keluar): ";
        cin >> pilihAlbum;
        if (pilihAlbum == 0)
        {
            pilihLagu = false;
        }
        else
        {
            pickAlbumFromList(head, key, pilihAlbum);
        }
    }
}

bool searchAlbuminArtis(ptrArtis pCariArtis, ptrAlbum &pCariAlbum, ptrAlbum &pCariAlbumPrev, const string key) // mencari album dari artis tertentu masukin ke header album
{
    pCariAlbum = pCariArtis->firstAlbum;
    pCariAlbumPrev = nullptr;
    bool found = false;
    while (pCariAlbum != nullptr && found == false)
    {
        if (pCariAlbum->idAlbum == key)
        {
            found = true;
        }
        else
        {
            pCariAlbumPrev = pCariAlbum;
            pCariAlbum = pCariAlbum->nextAlbum;
        }
    }
    return found;
}

void insertFirstAlbum(ptrAlbum &newAlbum, ptrArtis pCariArtis) // operasi insert first album masukin ke header album
{
    if (pCariArtis->firstAlbum == nullptr)
    {
        pCariArtis->firstAlbum = newAlbum;
    }
    else
    {
        newAlbum->nextAlbum = pCariArtis->firstAlbum;
        pCariArtis->firstAlbum = newAlbum;
    }
    pCariArtis->jumlahAlbum++;
}

void insertLastAlbum(ptrAlbum &newAlbum, ptrArtis pCariArtis) // operasi insert last album masukin ke header album
{
    ptrAlbum pBantu = pCariArtis->firstAlbum;
    if (pCariArtis->firstAlbum == nullptr)
    {
        pCariArtis->firstAlbum = newAlbum;
    }
    else
    {
        while (pBantu->nextAlbum != nullptr)
        {
            pBantu = pBantu->nextAlbum;
        }
        pBantu->nextAlbum = newAlbum;
    }
    pCariArtis->jumlahAlbum++;
}

void deleteFirstAlbum(ptrArtis pCariArtis, ptrAlbum &pHapus) // operasi delete first album masukin ke header album
{
    if (pCariArtis == nullptr || pCariArtis->firstAlbum == nullptr)
    {
        cout << "Tidak ada album untuk dihapus" << endl;
    }
    else if (pCariArtis->firstAlbum->nextAlbum == nullptr && pCariArtis->firstAlbum != nullptr)
    {
        pHapus = pCariArtis->firstAlbum;
        pCariArtis->firstAlbum = nullptr;
    }
    else
    {

        pHapus = pCariArtis->firstAlbum;
        pCariArtis->firstAlbum = pHapus->nextAlbum;
        pHapus->nextAlbum = nullptr;
    }
    pCariArtis->jumlahAlbum--;
}

void deleteLastAlbum(ptrArtis pCariArtis, ptrAlbum &pHapus) // operasi delete last album masukin ke header album
{
    ptrAlbum prevAlbum = nullptr;
    pHapus = pCariArtis->firstAlbum;
    if (pCariArtis == nullptr || pCariArtis->firstAlbum == nullptr)
    {
        cout << "Tidak ada album untuk dihapus" << endl;
    }
    while (pHapus->nextAlbum != nullptr)
    {
        prevAlbum = pHapus;
        pHapus = pHapus->nextAlbum;
    }
    if (prevAlbum == nullptr)
    {
        pHapus = pHapus->nextAlbum;
    }

    prevAlbum->nextAlbum = nullptr;
    pCariArtis->jumlahAlbum--;
}

void deletePcariAlbum(ptrArtis pCariArtis, ptrAlbum pCariAlbumPrev, ptrAlbum pCariAlbum, first &head, ptrAlbum &pHapus) // operasi menghapus album tertentu yang di search masukin ke header album
{
    if (head->firstAlbum == nullptr)
    {
        cout << "Tambahin album dlu";
    }
    else if (pCariAlbum->nextAlbum == nullptr && pCariAlbumPrev != nullptr)
    {
        cout << "delete last" << endl;
        deleteLastAlbum(pCariArtis, pHapus);
    }
    else if (pCariAlbumPrev == nullptr)
    {
        cout << "delete first" << endl;
        deleteFirstAlbum(pCariArtis, pHapus);
    }
    else if (pCariAlbumPrev != nullptr && pCariAlbum->nextAlbum != nullptr)
    {
        pCariAlbumPrev->nextAlbum = pCariAlbum->nextAlbum;
        pHapus = pCariAlbum;
    }
}
