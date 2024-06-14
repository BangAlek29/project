#ifndef ARTIS_H
#define ARTIS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Lagu.h"
#include "Album.h"
#include "Playlist.h"
#include "Fileoperation.h"
using namespace std;

struct Artis {
    string idArtis;
    string namaArtis;
    int jumlahAlbum;
    Album *firstAlbum;
    Artis *nextArtis;
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

void createDataList(first &list); //membuat list baru untuk artis taro di header artis
void createArtis(ptrArtis &newArtis); //membuat node artis baru taro di header artis
void traversalArtis(first head); //menampilkan semua artis di luar playlist taro di header artis
void pickArtisFromList(first head, string key, int pilihArtis); // memilih artis dari banyaknya artis dengan nama artis yang di cari diluar playlist masukin ke header artis
void traversalSearchArtis(first head, string key); // mencari artis dengan nama artis masukin ke header artis
bool searchArtis(first head, ptrArtis &pCariArtis, ptrArtis &pCariArtisPrev, const string key); // mencari artis tertentu diluar playlilst masukin ke header artis
void insertFirstArtis(ptrArtis &newArtis, first &head); // operasi insert first artis masukin ke header artis
void insertLastArtis(ptrArtis &newArtis, first &head); // operasi insert last artis masukin ke header artis
void deleteFirstArtis(first &head, ptrArtis &pHapus); // operasi delete first artis masukin ke header artis
void deleteLastArtis(first &head, ptrArtis &pHapus); // operasi delete last  artis masukin ke header artis
void deletePcariArtis(ptrArtis pCariArtis, ptrArtis pCariArtisPrev, first &head, ptrArtis &pHapus); // operasi menghapus artis tertentu yang dicari masukin ke header artis

#endif // ARTIS_H
