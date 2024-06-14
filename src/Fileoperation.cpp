#include "../include/Fileoperation.h"

void loadplaylist()
{
    Queue q;
    ifstream file("Data/playlist.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan. Membuat file baru..." << endl;
        ofstream createFile("Data/playlist.txt"); // Membuat file baru
        createFile.close();
        file.open("Data/playlist.txt"); // Membuka file yang baru dibuat
        if (!file.is_open())
        {
            cout << "Gagal membuat file baru." << endl;
            return;
        }
    
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
    ofstream file("Data/data.txt");
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
            file << currentAlbum->idAlbum << endl;
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
    ifstream file("Data/data.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan. Membuat file baru..." << endl;
        ofstream createFile("Data/data.txt"); // Membuat file baru
        createFile.close();
        file.open("Data/data.txt"); // Membuka file yang baru dibuat
        if (!file.is_open())
        {
            cout << "Gagal membuat file baru." << endl;
            return;
        }
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
            getline(file, newAlbum->idAlbum);
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