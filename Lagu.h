#ifndef LAGU_H
#define LAGU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Album.h"
#include "Artis.h"
#include "Playlist.h"
#include "Fileoperation.h"
using namespace std;

struct Lagu {
    string idLagu;
    string judulLagu;
    string genre;
    int durasi;
    Lagu *nextLagu;
    Lagu *prevLagu;
};

struct LaguPlaylist;
struct Album;
struct Artis;
struct playlist;

typedef LaguPlaylist *ptrLaguPlaylist;
typedef Lagu *ptrLagu;
typedef Album *ptrAlbum;
typedef Artis *ptrArtis;
typedef playlist *ptrPlaylist;
typedef ptrArtis first;
typedef ptrPlaylist firstPlaylist;

void createLagu(ptrLagu &newLagu); // membuat node lagu baru taro di header lagu
void outputMenuLagu(ptrLagu pBantu); // menampilkan lagu yang di pilih di luar playlist taro di header lagu
void menuLagu(ptrLagu pBantu); // tampilan menu lagu di luar playlist taro di header lagu
void traversalLagu(first head); // menampilkan lagu dari album pertama dari artis tertentu taro di header lagu
void pickLaguFromAlbum(first head, int pilihLagu); // memilih lagu dari album diluar playlist masukin ke header lagu
void traversalLaguFromAlbum(ptrAlbum pAlbum); // menampilkan lagu dari album tertentu diluar playlist taro di header 
bool searchLagu(ptrAlbum pCariAlbum, ptrLagu &pCariLagu, ptrLagu &pCariLaguPrev, const string key); // mencari lagu tertentu dengan id masukin ke header lagu
void insertFirstLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum); // operasi insert first lagu masukin ke header lagu
void insertLastLagu(ptrLagu &newLagu, ptrAlbum pCariAlbum); // operasi insert last lagu masukin ke header lagu
void deleteFirstLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus); // operasi delete first lagu masukin ke header
void deleteLastLagu(ptrAlbum pCariAlbum, ptrLagu &pHapus); // operasi delet last lagu masukin ke header lagu
void deletePcariLagu(ptrAlbum pCariAlbum, ptrLagu pCariLaguPrev, ptrLagu pCariLagu, first &head, ptrLagu &pHapus); // operasi menghapus lagu tertentu yang dicari masukin ke header lagu
void traversal(first head); //operasi traversal semua artis dengan album dan lagunya bebas simpen dmn

#endif // LAGU_H
