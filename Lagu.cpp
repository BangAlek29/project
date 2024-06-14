#include "Lagu.h"

void createLagu(ptrLagu &newLagu) // membuat node lagu baru taro di header lagu
{
    newLagu = new Lagu;
    cout << "Masukkan id lagu: ";
    cin >> newLagu->idLagu;
    cout << "Masukkan judul lagu: ";
    cin >> newLagu->judulLagu;
    cout << "Masukkan genre lagu: ";
    cin >> newLagu->genre;
    cout << "Masukkan durasi lagu: ";
    cin >> newLagu->durasi;
    newLagu->nextLagu = nullptr;
    newLagu->prevLagu = nullptr;
}

void outputMenuLagu(ptrLagu pBantu) // menampilkan lagu yang di pilih di luar playlist taro di header lagu
{
    cout << "\njudul lagu : ";
    cout << pBantu->judulLagu;
    cout << "\ngenre lagu : ";
    cout << pBantu->judulLagu;
    cout << "\ndurasi lagu : ";
    cout << pBantu->durasi;
}

void menuLagu(ptrLagu pBantu) // tampilan menu lagu di luar playlist taro di header lagu
{
    int pilih;
    outputMenuLagu(pBantu);
    while (pilih != 4)
    {
        cout << "\n1. next lagu\n"
             << "2. prev lagu\n"
             << "3. Masukan ke playlist\n"
             << "4. Stop\n"
             << "Masukan pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            if (pBantu->nextLagu != nullptr)
            {
                pBantu = pBantu->nextLagu;
                outputMenuLagu(pBantu);
            }
            else
            {
                cout << "tidak ada lagu selanjutnya \n";
            }
            break;
        case 2:
            if (pBantu->prevLagu != nullptr)
            {
                pBantu = pBantu->prevLagu;
                outputMenuLagu(pBantu);
            }
            else
            {
                cout << "tidak ada lagu sebelumnya \n";
            }
            break;
        case 3:
            int pilihPlaylist;
            cout << "1. buat playlist baru << endl";
            cout << "2. buat playlist yang sdah ada << endl";
            cin >> pilihPlaylist;
            if (pilihPlaylist == 1)
            {
                Queue q;
                ptrPlaylist newPlaylist;
                ptrLaguPlaylist newLaguPlaylist;
                createNodePlayList(newPlaylist);
                enqueue(q, newLaguPlaylist);
            }
            else if (pilihPlaylist == 2)
            {
                cout << "tidak ada playlist \n";
            }
            break;
        default:
            pilih = 4;
            break;
        }
    }
}

void traversalLagu(first head) // menampilkan lagu dari album pertama dari artis tertentu taro di header lagu
{
    int no = 1;
    ptrLagu pBantu = head->firstAlbum->firstLagu;
    if (pBantu == nullptr)
    {
        cout << "kosong";
        return;
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->judulLagu << endl;
            no++;
            pBantu = pBantu->nextLagu;
        }
    }
}

void pickLaguFromAlbum(first head, int pilihLagu) // memilih lagu dari album diluar playlist masukin ke header lagu
{
    ptrLagu pBantu = head->firstAlbum->firstLagu;
    while (pBantu != nullptr)
    {
        if (pilihLagu != 1)
        {
            pilihLagu--;
            pBantu = pBantu->nextLagu;
        }
        else if (pilihLagu == 1)
        {
            cout << "masuk menu lagu";
            menuLagu(pBantu);
            return;
        }
    }
}

void traversalLaguFromAlbum(ptrAlbum pAlbum) // menampilkan lagu dari album tertentu diluar playlist taro di header
{
    int no = 1;
    ptrLagu pBantu = pAlbum->firstLagu;
    if (pBantu == nullptr)
    {
        cout << "kosong";
        return;
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->judulLagu << endl;
            no++;
            pBantu = pBantu->nextLagu;
        }
    }
}

bool searchLagu(ptrAlbum pCariAlbum, ptrLagu &pCariLagu, ptrLagu &pCariLaguPrev, const string key) // mencari lagu tertentu dengan id masukin ke header lagu
{
    pCariLagu = pCariAlbum->firstLagu;
    pCariLaguPrev = nullptr;
    bool found = false;
    while (!found && pCariLagu != nullptr)
    {
        if (pCariLagu->idLagu == key)
        {
            found = true;
        }
        else
        {
            pCariLaguPrev = pCariLagu;
            pCariLagu = pCariLagu->nextLagu;
        }
    }
    return found;
}

void insertFirstLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum) // operasi insert first lagu masukin ke header lagu
{
    if (pCariAlbum->firstLagu == nullptr)
    {
        pCariAlbum->firstLagu = newLagu;
    }
    else
    {
        newLagu->nextLagu = pCariAlbum->firstLagu;
        pCariAlbum->firstLagu->prevLagu = newLagu;
        pCariAlbum->firstLagu = newLagu;
    }
    pCariAlbum->jumlahLagu++;
}

void insertLastLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum) // operasi insert last lagu masukin ke header lagu
{
    ptrLagu pBantu = pCariAlbum->firstLagu;

    if (pCariAlbum->firstLagu == nullptr)
    {
        pCariAlbum->firstLagu = newLagu;
    }
    else
    {
        while (pBantu->nextLagu != nullptr)
        {

            pBantu = pBantu->nextLagu;
        }
        pBantu->nextLagu = newLagu;
        newLagu->prevLagu = pBantu;
    }
    pCariAlbum->jumlahLagu++;
}

void deleteFirstLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus) // operasi delete first lagu masukin ke header lagu
{
    if (pCariAlbum == nullptr || pCariAlbum->firstLagu == nullptr)
    {
        cout << "Tidak ada lagu untuk dihapus" << endl;
    }
    else if (pCariAlbum->firstLagu->nextLagu == nullptr && pCariAlbum->firstLagu->prevLagu == nullptr)
    {
        pHapus = pCariAlbum->firstLagu;
    }
    else
    {
        pHapus = pCariAlbum->firstLagu;
        pCariAlbum->firstLagu = pCariAlbum->firstLagu->nextLagu;
        pHapus->nextLagu->prevLagu == nullptr;
        pHapus->nextLagu == nullptr;
    }
    pCariAlbum->jumlahLagu--;
}

void deleteLastLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus) // operasi delet last lagu masukin ke header lagu
{
    ptrLagu prevLagu = nullptr;
    pHapus = pCariAlbum->firstLagu;

    if (pCariAlbum == nullptr || pCariAlbum->firstLagu == nullptr)
    {
        cout << "Tidak ada lagu untuk dihapus" << endl;
    }
    while (pHapus->nextLagu != nullptr)
    {
        prevLagu = pHapus;
        pHapus = pHapus->nextLagu;
    }

    if (prevLagu == nullptr) // 1 data
    {
        pCariAlbum->firstLagu = nullptr;
    }
    else // banyak data
    {
        pHapus->prevLagu->nextLagu = nullptr;
        pHapus->prevLagu = nullptr;
    }

    pCariAlbum->jumlahLagu--;
}

void deletePcariLagu(ptrAlbum pCariAlbum, ptrLagu pCariLaguPrev, ptrLagu pCariLagu, first &head, ptrLagu &pHapus) // operasi menghapus lagu tertentu yang dicari masukin ke header lagu
{
    if (pCariLagu->nextLagu == nullptr && pCariLaguPrev != nullptr)
    {
        cout << "delete last";
        deleteLastLagu(pCariAlbum, pHapus);
    }
    else if (pCariLaguPrev == nullptr && pCariLagu->nextLagu != nullptr)
    {
        cout << "delete first";
        deleteFirstLagu(pCariAlbum, pHapus);
    }
    else if (pCariLaguPrev != nullptr && pCariLagu->nextLagu != nullptr)
    {
        cout << "masuk mas";
        pCariLaguPrev->nextLagu = pCariLagu->nextLagu;
        pCariLagu->nextLagu->prevLagu = pCariLaguPrev;
        pCariLagu->nextLagu = nullptr;
        pCariLagu->prevLagu = nullptr;
        pHapus = pCariLagu;
    }
}

void traversal(first head) // operasi traversal semua artis dengan album dan lagunya bebas simpen dmn
{
    ptrArtis pBantuArtis = head;
    ptrAlbum pBantuAlbum;
    ptrLagu pBantuLagu;
    if (head == nullptr)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        while (pBantuArtis != nullptr)
        {

            cout << "Artis: " << pBantuArtis->idArtis << pBantuArtis->namaArtis << endl;
            pBantuAlbum = pBantuArtis->firstAlbum;
            while (pBantuAlbum != nullptr)
            {
                cout << "  Album: " << pBantuAlbum->idAlbum << pBantuAlbum->judulAlbum << endl;
                pBantuLagu = pBantuAlbum->firstLagu;
                while (pBantuLagu != nullptr)
                {
                    cout << "    id: " << pBantuLagu->idLagu << "    Lagu: " << pBantuLagu->judulLagu << ", Genre: " << pBantuLagu->genre << ", Durasi: " << pBantuLagu->durasi << endl;
                    pBantuLagu = pBantuLagu->nextLagu;
                }
                pBantuAlbum = pBantuAlbum->nextAlbum;
            }
            pBantuArtis = pBantuArtis->nextArtis;
        }
    }
}