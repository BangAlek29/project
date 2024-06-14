#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "../include/Album.h"
#include "../include/Lagu.h"
#include "../include/Artis.h"
#include "../include/Playlist.h"
#include "../include/Fileoperation.h"
using namespace std;

void tabel() // untuk tabel menu pada awal program dijalankan
{
    for (int i = 0; i < 20; i++)
    {
        cout << "=";
    }
    cout << endl;
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
