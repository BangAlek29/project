#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Lagu.h"
#include "Artis.h"
#include "Playlist.h"
#include "Fileoperation.h"
using namespace std;


struct LaguPlaylist
{
    string judulLagu;
    string genre;
    int durasi;
    LaguPlaylist *nextLagu;
    LaguPlaylist *prevLagu;
};

typedef LaguPlaylist *ptrLaguPlaylist;
 
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

struct Lagu;
struct Album;
struct Artis;

typedef Lagu *ptrLagu;
typedef Album *ptrAlbum;
typedef Artis *ptrArtis;
typedef playlist *ptrPlaylist;
typedef ptrArtis first;
typedef ptrPlaylist firstPlaylist;

void createPlayList(firstPlaylist &headPlaylist); //membuat playlist Baru taro di header playlist
void createQueue(Queue& Q); // membuat queue baru untuk di dalam playlist taro di header playlist
void createNodePlayList(ptrPlaylist &newPlaylist); //membuat node playlist baru taro di header playlist
void createElementLaguPlayList(ptrLaguPlaylist &newLaguPlaylist, ptrLagu pBantu); //membuat node lagu baru dalam playlist 
void traversalPlaylist(firstPlaylist headPlaylist); //menampilkan semua playlist yang dimiliki user simpen di playlist
void enqueue(Queue &Q, ptrLaguPlaylist newSong); // memasukkan lagu ke dalam playlist taro di header playlist
void dequeue(Queue &Q, ptrLaguPlaylist &playedSong); // menghapus lagu dalam playlist taro di header playlist
void outputMenuLaguDalamPLaylist(ptrLaguPlaylist pBantuLaguPlaylist); // menampilkan judul genre dan durasi dari lagu yang dipilih di dalam playlist taro di header playlist
void traversalLaguDalamPlaylist(ptrPlaylist pBantuPlaylist); // menampilkan semua lagu dalam playlist yang sudah dipilih taro di header playlist
void pickLaguFromPlaylist (ptrPlaylist pBantuPlaylist, int pilihLaguDalamPlaylist);  // memilih lagu dari dari playlist tertentu masukin ke header playlist
void putarLaguBerdasarkanQueuePlaylist (ptrPlaylist pBantuPlaylist); //memutar seluruh lagu yang ada di playlist tertentu masukin ke header playlist
void pickPlaylistFromList(firstPlaylist headPlaylist, int pilihPlaylist); // memilih playlist dari banyaknya playlist di awal menu masukin ke header playlist
void insertPlayList(firstPlaylist& head, ptrPlaylist newPlayList); // operasi insert last playlist masukin ke header playlist

#endif