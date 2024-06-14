#include "../include/Playlist.h"

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
