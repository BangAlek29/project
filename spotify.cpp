#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Lagu
{
    string idLagu;
    string judulLagu;
    string genre;
    int durasi;
    Lagu *nextLagu;
    Lagu *prevLagu;
};

struct Album
{
    string idalbum;
    string judulAlbum;
    int jumlahLagu;
    Lagu *firstLagu;
    Album *nextAlbum;
};

struct Artis
{
    string idArtis;
    string namaArtis;
    int jumlahAlbum;
    Album *firstAlbum;
    Artis *nextArtis;
};

struct LaguPlaylist
{
    string judulLagu;
    string genre;
    int durasi;
    LaguPlaylist *nextLagu;
    LaguPlaylist *prevLagu;
};


struct Queue
{
    ptrLaguPlaylist head;
    ptrLaguPlaylist tail;
};

struct playlist
{
    string namaPlaylist;
    string jumlahLagu;
    playlist *next;
    Queue laguQueue;
};

typedef LaguPlaylist *ptrLaguPlaylist;
typedef Lagu *ptrLagu;
typedef Album *ptrAlbum;
typedef Artis *ptrArtis;
typedef playlist *ptrPlaylist;
typedef ptrArtis first;
typedef ptrPlaylist firstPlaylist;

void tabel() // untuk tabel menu pada awal program dijalankan
{
    for (int i = 0; i < 20; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void createDataList(first &list) // membuat list baru untuk artis taro di header artis
{
    list = nullptr;
}

void createPlayList(firstPlaylist &headPlaylist) // membuat playlist Baru taro di header playlist
{
    headPlaylist = nullptr;
}

void createQueue(Queue &Q)
{ // membuat queue baru untuk di dalam playlist taro di header playlist
    Q.head = nullptr;
    Q.tail = nullptr;
}

void createNodePlayList(ptrPlaylist &newPlaylist) // membuat node playlist baru taro di header playlist
{
    newPlaylist = new playlist;
    newPlaylist->next = nullptr;
    createQueue(newPlaylist->laguQueue);
    cout << "masukan nama playlist : ";
    cin >> newPlaylist->namaPlaylist;
}

void createElementLaguPlayList(ptrLaguPlaylist &newLaguPlaylist, ptrLagu pBantu) // membuat node lagu baru dalam playlist
{
    newLaguPlaylist = new LaguPlaylist;
    newLaguPlaylist->nextLagu = nullptr;
    newLaguPlaylist->judulLagu = pBantu->judulLagu;
    newLaguPlaylist->genre = pBantu->genre;
    newLaguPlaylist->durasi = pBantu->durasi;
}

void traversalPlaylist(firstPlaylist headPlaylist)
{ // menampilkan semua playlist yang dimiliki user simpen di playlist
    ptrPlaylist pBantu = headPlaylist;
    int no = 1;
    if (pBantu == nullptr)
    {
        cout << "tidak ada playlist" << endl;
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->namaPlaylist << endl;
            no++;
            pBantu = pBantu->next;
        }
    }
}

void createArtis(ptrArtis &newArtis) // membuat node artis baru taro di header artis
{
    newArtis = new Artis;
    cout << "Masukkan id artis: ";
    cin >> newArtis->idArtis;
    cout << "Masukkan nama artis: ";
    cin >> newArtis->namaArtis;
    newArtis->nextArtis = nullptr;
    newArtis->firstAlbum = nullptr;
}

void createAlbum(ptrAlbum &newAlbum) // membuat node album baru taro di header album
{
    newAlbum = new Album;
    cout << "Masukkan id album: ";
    cin >> newAlbum->idalbum;
    cout << "Masukkan judul album: ";
    cin >> newAlbum->judulAlbum;
    newAlbum->nextAlbum = nullptr;
    newAlbum->firstLagu = nullptr;
}

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

void enqueue(Queue &Q, ptrLaguPlaylist newSong) // memasukkan lagu ke dalam playlist taro di header playlist
{
    if (Q.head == nullptr && Q.tail == nullptr)
    {
        Q.head = newSong;
        Q.tail = newSong;
    }
    else if (Q.head->nextLagu == nullptr)
    {
        Q.tail->nextLagu = newSong;
        newSong->prevLagu = Q.tail;
        Q.tail = newSong;
    }
}

void dequeue(Queue &Q, ptrLaguPlaylist &playedSong) // menghapus lagu dalam playlist taro di header playlist
{
    cout << "Lagu " << playedSong->judulLagu << " dimulai" << endl;
    if (Q.head == nullptr && Q.tail == nullptr)
    {
        cout << "Playlistmu kosong";
    }
    else if (Q.head->nextLagu == nullptr)
    {
        playedSong = Q.head;
        Q.head = nullptr;
    }
    else
    {
        playedSong = Q.head;
        Q.head = Q.head->nextLagu;
        Q.head->prevLagu = nullptr;
        playedSong->nextLagu = nullptr;
    }
}

void outputMenuLaguDalamPLaylist(ptrLaguPlaylist pBantuLaguPlaylist) // menampilkan judul genre dan durasi dari lagu yang dipilih di dalam playlist taro di header playlist
{
    cout << "\njudul lagu : ";
    cout << pBantuLaguPlaylist->judulLagu;
    cout << "\ngenre lagu : ";
    cout << pBantuLaguPlaylist->genre;
    cout << "\ndurasi lagu : ";
    cout << pBantuLaguPlaylist->durasi;
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

void menuLaguDalamPlaylist(ptrLaguPlaylist pBantuLaguDalamPlaylist) // tampilan menu lagu di dalam playlist taro di header playllist (new)
{
    int pilih;
    outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
    while (pilih != 4)
    {
        cout << "\n1. next lagu\n"
             << "2. prev lagu\n"
             << "3. Hapus dari playlist\n"
             << "4. Stop\n"
             << "Masukan pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            if (pBantuLaguDalamPlaylist->nextLagu != nullptr)
            {
                pBantuLaguDalamPlaylist = pBantuLaguDalamPlaylist->nextLagu;
                outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
            }
            else
            {
                cout << "tidak ada lagu selanjutnya \n";
            }
            break;
        case 2:
            if (pBantuLaguDalamPlaylist->prevLagu != nullptr)
            {
                pBantuLaguDalamPlaylist = pBantuLaguDalamPlaylist->prevLagu;
                outputMenuLaguDalamPLaylist(pBantuLaguDalamPlaylist);
            }
            else
            {
                cout << "tidak ada lagu sebelumnya \n";
            }
            break;
        case 3:
            dequeue();
            break;
        default:
            pilih = 4;
            break;
        }
    }
}

void traversalArtis(first head) // menampilkan semua artis di luar playlist taro di header artis
{
    int no = 1;
    ptrArtis pBantu = head;
    if (head == nullptr)
    {
        cout << "kosong";
    }
    else
    {
        while (pBantu != nullptr)
        {
            cout << no << ". " << pBantu->namaArtis << " ID" << pBantu->idArtis << endl;
            no++;
            pBantu = pBantu->nextArtis;
        }
    }
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
            cout << no << ". " << pBantu->judulAlbum << " ID" << pBantu->idalbum << endl;
            no++;
            pBantu = pBantu->nextAlbum;
        }
    }
}

void traversalLaguDalamPlaylist(ptrPlaylist pBantuPlaylist)
{ // menampilkan semua lagu dalam playlist yang sudah dipilih taro di header playlist
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    int no = 1;
    while (pBantuLaguPlaylist != nullptr)
    {
        cout << no << ". " << pBantuLaguPlaylist->judulLagu << endl;
        no++;
        pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
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

void pickArtisFromList(first head, string key, int pilihArtis) // memilih artis dari banyaknya artis dengan nama artis yang di cari diluar playlist masukin ke header artis
{
    int pilihAlbum, pilihLagu;
    ptrArtis pBantu = head;
    while (pBantu != nullptr)
    {
        if (pBantu->namaArtis == key && pilihArtis != 1)
        {
            pilihArtis--;
            pBantu = pBantu->nextArtis;
        }
        else if (pBantu->namaArtis == key && pilihArtis == 1)
        {
            traversalAlbum(pBantu);
            cout << "Mau Pilih Album ke berapa?";
            cin >> pilihAlbum;
            pickAlbumFromArtis(head, pilihAlbum);
            cout << "Mau Pilih Lagu ke berapa?";
            cin >> pilihLagu;
            pickLaguFromAlbum(head, pilihLagu);

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

void pickLaguFromPlaylist(ptrPlaylist pBantuPlaylist, int pilihLaguDalamPlaylist)
{ // memilih lagu dari dari playlist tertentu masukin ke header playlist
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    while (pBantuLaguPlaylist != nullptr)
    {
        if (pilihLaguDalamPlaylist != 1)
        {
            pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
            pilihLaguDalamPlaylist--;
        }
        else if (pilihLaguDalamPlaylist == 1)
        {
            outputMenuLaguDalamPLaylist(pBantuLaguPlaylist);
        }
    }
}

void putarLaguBerdasarkanQueuePlaylist(ptrPlaylist pBantuPlaylist)
{ // memutar seluruh lagu yang ada di playlist tertentu masukin ke header playlist
    ptrLaguPlaylist pBantuLaguPlaylist = pBantuPlaylist->laguQueue.head;
    while (pBantuLaguPlaylist != nullptr)
    {
        cout << pBantuLaguPlaylist->judulLagu << endl;
        cout << pBantuLaguPlaylist->durasi << endl;
        pBantuLaguPlaylist = pBantuLaguPlaylist->nextLagu;
    }
}

void pickPlaylistFromList(firstPlaylist headPlaylist, int pilihPlaylist) // memilih playlist dari banyaknya playlist di awal menu masukin ke header playlist
{
    int pilihLaguDalamPlaylist;
    ptrPlaylist pBantuPlaylist = headPlaylist;
    while (pBantuPlaylist != nullptr)
    {
        if (pilihPlaylist != 1)
        {
            pilihPlaylist--;
            pBantuPlaylist = pBantuPlaylist->next;
        }
        else if (pilihPlaylist == 1)
        {
            traversalLaguDalamPlaylist(pBantuPlaylist);
            cout << "Mau Pilih Lagu ke berapa?";
            cin >> pilihLaguDalamPlaylist;
            pickLaguFromPlaylist(pBantuPlaylist, pilihLaguDalamPlaylist);
        }
    }
}

void traversalSearchArtis(first head, string key) // mencari artis dengan nama artis masukin ke header artis
{
    ptrArtis pBantu = head;
    int no = 1;
    int pilihArtis; // artis ke berapa yang mau diliat albumnya
    while (pBantu != nullptr)
    {
        if (pBantu->namaArtis == key)
        {
            cout << no << ". " << pBantu->namaArtis << endl;
            no++;
            pBantu = pBantu->nextArtis;
        }
        else
        {
            pBantu = pBantu->nextArtis;
        }
    }
    bool pilihAlbum = true;
    while (pilihAlbum == true)
    {
        cout << "Pilih artis ke berapa (0 untuk keluar): ";
        cin >> pilihArtis;
        if (pilihArtis == 0)
        {
            pilihAlbum = false;
        }
        else
        {
            pickArtisFromList(head, key, pilihArtis);
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

bool searchArtis(first head, ptrArtis &pCariArtis, ptrArtis &pCariArtisPrev, const string key) // mencari artis tertentu diluar playlilst masukin ke header artis
{
    pCariArtis = head;
    pCariArtisPrev = nullptr;
    bool found = false;
    while (!found && pCariArtis != nullptr)
    {
        if (pCariArtis->idArtis == key)
        {
            found = true;
        }
        else
        {
            pCariArtisPrev = pCariArtis;
            pCariArtis = pCariArtis->nextArtis;
        }
    }
    return found;
}

bool searchAlbuminArtis(ptrArtis pCariArtis, ptrAlbum &pCariAlbum, ptrAlbum &pCariAlbumPrev, const string key) // mencari album dari artis tertentu masukin ke header album
{
    pCariAlbum = pCariArtis->firstAlbum;
    pCariAlbumPrev = nullptr;
    bool found = false;
    while (pCariAlbum != nullptr && found == false)
    {
        if (pCariAlbum->idalbum == key)
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

void insertFirstArtis(ptrArtis &newArtis, first &head) // operasi insert first artis masukin ke header artis
{
    if (head == nullptr)
    {
        head = newArtis;
    }
    else
    {
        newArtis->nextArtis = head;
        head = newArtis;
    }
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

void insertLastArtis(ptrArtis &newArtis, first &head) // operasi insert last artis masukin ke header artis
{
    ptrArtis pBantu = head;
    if (head == nullptr)
    {
        head = newArtis;
    }
    else
    {
        while (pBantu->nextArtis != nullptr)
        {
            pBantu = pBantu->nextArtis;
        }
        pBantu->nextArtis = newArtis;
    }
}

void deleteFirstArtis(first &head, ptrArtis &pHapus) // operasi delete first artis masukin ke header artis
{
    if (head == nullptr)
    {
        cout << "Tidak ada artis untuk dihapus" << endl;
    }
    else
    {
        pHapus = head;
        head = head->nextArtis;
        pHapus->nextArtis = nullptr;
    }
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

void deleteLastArtis(first &head, ptrArtis &pHapus) // operasi delete last  artis masukin ke header artis
{
    if (head == nullptr)
    {
        cout << "Tidak ada artis untuk dihapus" << endl;
    }
    else if (head->nextArtis == nullptr) // 1 data doang
    {
        pHapus = head;
        head = nullptr;
    }
    else
    {
        ptrArtis prevArtis = nullptr;
        pHapus = head;
        while (pHapus->nextArtis != nullptr)
        {
            prevArtis = pHapus;
            pHapus = pHapus->nextArtis;
        }
        prevArtis->nextArtis = nullptr;
    }
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

void deletePcariArtis(ptrArtis pCariArtis, ptrArtis pCariArtisPrev, first &head, ptrArtis &pHapus) // operasi menghapus artis tertentu yang dicari masukin ke header artis
{
    if (head == nullptr)
    {
        cout << "Tambahin artis dlu";
    }
    else if (pCariArtis->nextArtis == nullptr && pCariArtisPrev != nullptr)
    {
        cout << "delete last";
        deleteLastArtis(pCariArtis, pHapus);
    }
    else if (pCariArtisPrev == nullptr)
    {
        cout << "delete first";
        deleteFirstArtis(pCariArtis, pHapus);
    }
    else if (pCariArtisPrev != nullptr && pCariArtis->nextArtis != nullptr)
    {
        pCariArtisPrev->nextArtis = pCariArtis->nextArtis;
        pHapus = pCariArtis;
    }
    delete pHapus;
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
                cout << "  Album: " << pBantuAlbum->idalbum << pBantuAlbum->judulAlbum << endl;
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

void insertPlayList(firstPlaylist &head, ptrPlaylist newPlayList)
{ // operasi insert last playlist masukin ke header playlist
    ptrPlaylist pBantu = head;
    if (head == nullptr)
    {
        head = newPlayList;
    }
    else
    {
        while (pBantu->next != nullptr)
        {
            pBantu = pBantu->next;
        }
        pBantu->next = newPlayList;
    }
}

void loadplaylist()
{
    Queue q;
    ifstream file("playlist.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    string line;

    while (getline(file, line))
    {
        if (line == "Lagu:")
        {
            ptrLaguPlaylist newLagu = new LaguPlaylist;
            getline(file, newLagu->judulLagu);
            file.ignore();
            newLagu->nextLagu = nullptr;
            newLagu->prevLagu = nullptr;

            enqueue(q, newLagu);
        }
    }

    file.close();
}

void save(ptrArtis head)
{
    ofstream file("data.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }

    ptrArtis currentArtis = head;
    while (currentArtis != nullptr)
    {
        file << "Artis:" << endl;
        file << currentArtis->idArtis << endl;
        file << currentArtis->namaArtis << endl;
        file << currentArtis->jumlahAlbum << endl;

        ptrAlbum currentAlbum = currentArtis->firstAlbum;
        while (currentAlbum != nullptr)
        {
            file << "Album:" << endl;
            file << currentAlbum->idalbum << endl;
            file << currentAlbum->judulAlbum << endl;
            file << currentAlbum->jumlahLagu << endl;

            ptrLagu currentLagu = currentAlbum->firstLagu;
            while (currentLagu != nullptr)
            {
                file << "Lagu:" << endl;
                file << currentLagu->idLagu << endl;
                file << currentLagu->judulLagu << endl;
                file << currentLagu->genre << endl;
                file << currentLagu->durasi << endl;
                currentLagu = currentLagu->nextLagu;
            }
            currentAlbum = currentAlbum->nextAlbum;
        }
        currentArtis = currentArtis->nextArtis;
    }

    file.close();
}
void load(ptrArtis &pBantu)
{
    ifstream file("data.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    string line;
    pBantu = nullptr;
    ptrArtis currentArtis = nullptr;
    ptrAlbum currentAlbum = nullptr;

    while (getline(file, line))
    {
        if (line == "Artis:")
        {
            ptrArtis newArtis = new Artis;
            getline(file, newArtis->idArtis);
            getline(file, newArtis->namaArtis);
            file >> newArtis->jumlahAlbum;
            file.ignore();
            newArtis->nextArtis = nullptr;
            newArtis->firstAlbum = nullptr;

            insertLastArtis(newArtis, pBantu);
            currentArtis = newArtis;
            currentAlbum = nullptr;
        }
        else if (line == "Album:")
        {
            ptrAlbum newAlbum = new Album;
            getline(file, newAlbum->idalbum);
            getline(file, newAlbum->judulAlbum);
            file >> newAlbum->jumlahLagu;
            file.ignore();
            newAlbum->nextAlbum = nullptr;
            newAlbum->firstLagu = nullptr;

            insertLastAlbum(newAlbum, currentArtis);
            currentAlbum = newAlbum;
        }
        else if (line == "Lagu:")
        {
            ptrLagu newLagu = new Lagu;
            getline(file, newLagu->idLagu);
            getline(file, newLagu->judulLagu);
            getline(file, newLagu->genre);
            file >> newLagu->durasi;
            file.ignore();
            newLagu->nextLagu = nullptr;
            newLagu->prevLagu = nullptr;

            insertLastLagu(newLagu, currentAlbum);
        }
    }

    file.close();
}

int main()
{
    first list;
    firstPlaylist headPlaylist;
    ptrArtis pArtis, pCariArtis, pCariArtisPrev, pHapusArtis;
    ptrAlbum pAlbum, pCariAlbum, pCariAlbumPrev, pHapusAlbum;
    ptrLagu pLagu, pCariLagu, pCariLaguPrev, pHapusLagu;
    int pilih;
    string key, key2;

    createDataList(list);
    load(list);
    createPlayList(headPlaylist);
    traversalPlaylist(headPlaylist);
    do
    {
        tabel();
        cout << "  MENU" << endl;
        tabel();
        cout << "1. Tambah Artis" << endl;
        cout << "2. Tambah Album" << endl;
        cout << "3. Tambah Lagu" << endl;
        cout << "4. Hapus Artis" << endl;
        cout << "5. Hapus Album" << endl;
        cout << "6. Hapus Lagu" << endl;
        cout << "7. Search (User)" << endl;
        cout << "10. Tampilkan Data" << endl;
        cout << "11. Keluar" << endl;
        tabel();
        cout << "Pilih menu: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            createArtis(pArtis);
            insertLastArtis(pArtis, list);
            break;
        case 2:
            if (list == nullptr)
            {
                cout << "List kosong, tambahkan artis terlebih dahulu." << endl;
            }
            else
            {
                cout << "Masukkan id artis: ";
                cin.ignore();
                getline(cin, key);
                if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
                {
                    createAlbum(pAlbum);
                    insertLastAlbum(pAlbum, pCariArtis);
                }
                else
                {
                    cout << "Artis tidak ditemukan." << endl;
                }
            }
            break;
        case 3:
            if (list == nullptr)
            {
                cout << "List kosong, tambahkan artis terlebih dahulu." << endl;
            }
            else
            {
                cout << "Masukkan id artis: ";
                cin >> key;
                if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
                {
                    cout << "Masukkan id album: ";
                    cin >> key;
                    if (searchAlbuminArtis(pCariArtis, pCariAlbum, pCariAlbumPrev, key))
                    {
                        createLagu(pLagu);
                        insertLastLagu(pLagu, pCariAlbum);
                    }
                    else
                    {
                        cout << "Album tidak ditemukan." << endl;
                    }
                }
                else
                {
                    cout << "Artis tidak ditemukan." << endl;
                }
            }
            break;
        case 4:
            traversalArtis(list);
            cout << "Masukkan nama artis yang ingin di hapus : ";
            cin >> key;
            if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
            {
                deletePcariArtis(pCariArtis, pCariArtisPrev, list, pHapusArtis);
            }
            else
            {
                cout << "nama artis tidak ditemukan";
            }

            break;
        case 5:
            traversalArtis(list);
            cout << "Masukkan id Artis dari album yang ingin di hapus : ";
            cin >> key;
            if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
            {
                traversalAlbum(list);
                cout << "masukan id album yang ingin dihapus : ";
                cin >> key;
                if (searchAlbuminArtis(pCariArtis, pCariAlbum, pCariAlbumPrev, key))
                {
                    cout << "album ketemu" << endl;
                    deletePcariAlbum(pCariArtis, pCariAlbumPrev, pCariAlbum, list, pHapusAlbum);
                }
                else
                {
                    cout << "nama Album tidak ditemukan";
                }
            }
            else
            {
                cout << "nama artis tidak ditemukan";
            }
            break;
        case 6:
            traversalArtis(list);
            cout << "Masukkan id Artis dari album yang ingin di hapus : ";
            cin >> key;
            if (searchArtis(list, pCariArtis, pCariArtisPrev, key))
            {
                traversalAlbum(list);
                cout << "masukan id album yang ingin dihapus : ";
                cin >> key;
                if (searchAlbuminArtis(pCariArtis, pCariAlbum, pCariAlbumPrev, key))
                {
                    traversalLagu(list);
                    cout << "album ketemu" << endl;
                    cout << "Masukan id lagu : ";
                    cin >> key;
                    if (searchLagu(pCariAlbum, pCariLagu, pCariLaguPrev, key))
                    {
                        cout << "lagu ketemu" << endl;
                        deletePcariLagu(pCariAlbum, pCariLaguPrev, pCariLagu, list, pHapusLagu);
                    }
                    else
                    {
                        cout << "lagu tidak ditemukan" << endl;
                    }
                }
                else
                {
                    cout << "nama Album tidak ditemukan";
                }
            }
            else
            {
                cout << "nama artis tidak ditemukan";
            }
            break;
        case 7:
            int pilihSearch;
            while (pilihSearch != 4)
            {
                cout << "1. search Artis\n"
                     << "2. Serach Album\n"
                     << "3. Search Lagu\n"
                     << "4. Back\n"
                     << "5. Masukan Pilihan : ";
                cin >> pilihSearch;
                switch (pilihSearch)
                {
                case 1:
                    cout << "Masukan nama artis : ";
                    cin >> key;
                    traversalSearchArtis(list, key);
                    break;
                case 2:
                    cout << "Masukan nama album : ";
                    cin >> key;
                    traversalSearchAlbum(list, key);
                    break;
                default:
                    pilihSearch = 4;
                    break;
                }
            }

            break;
        case 9:

            break;
        case 10:
            traversal(list);
            break;
        case 11:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilih != 11);

    save(list);

    return 0;
}
