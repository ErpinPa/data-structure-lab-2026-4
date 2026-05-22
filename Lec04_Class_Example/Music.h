#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Music {
private:
    string title;
    string artist;
    string albumTitle;
    int year;

public:
    Music(string title, string artist, string albumTitle, int year) {
        this->title = title;
        this->artist = artist;
        this->albumTitle = albumTitle;
        this->year = year;
    }

    string getTitle() { return title; }
    string getArtist() { return artist; }
    string getAlbumTitle() { return albumTitle; }
    int getYear() { return year; }
};

class MusicStreamingService {
private:
    string serviceName;
    vector<Music> musicList;

public:
    MusicStreamingService(string serviceName) {
        this->serviceName = serviceName;
    }

    void addMusic(string title, string artist, string albumTitle, int year) {
        Music newMusic(title, artist, albumTitle, year);
        musicList.push_back(newMusic);

        cout << title << " by " << artist
            << " added to " << serviceName << endl;
    }

    // 제목으로 검색
    Music* searchByTitle(string title) {
        for (int i = 0; i < musicList.size(); i++) {
            if (musicList[i].getTitle() == title) {
                return &musicList[i];
            }
        }
        return nullptr;  // 못 찾으면 null
    }

    string artist_name;
    cout <<
        cin >>

        vector<music*> artistResult = myService.searchByArtist(artist_name);
        if(artistResult.size()>0) {
            cout << "검색결과" << artistResult.size() << "-" << artist_name " : " << endl;
            for (int=0; i<artistResult.size(); i++) {
                cout << artistResult[i]->getTitle() << endl;

            }
        }
        return nullptr;
    }
};