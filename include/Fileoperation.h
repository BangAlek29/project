#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Lagu.h"
#include "Artis.h"
#include "Playlist.h"
#include "Album.h"

using namespace std;

struct LaguPlaylist;
struct Lagu;
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

void loadplaylist();
void save(ptrArtis head);
void load(ptrArtis &pBantu);

#endif
