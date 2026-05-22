#include <iostream>
#include "Rectangle.h"
#include "Pet.h"
#include "Music.h"

using namespace std;

int main() {

    // Rectangle
    Rectangle rect1(3.4, 2.5);
    cout << "Rectangle 1:" << endl;
    cout << "Area: " << rect1.getArea() << endl;
    cout << "Perimeter: " << rect1.getPerimeter() << endl;
    cout << "Is square? " << boolalpha << rect1.isSquare() << endl;

    cout << "======" << endl;

    // Pet
    Pet myPet("Badugi", 10, "Dog");
    cout << "name: " << myPet.getName() << endl;
    cout << "age: " << myPet.getAge() << endl;
    cout << "type: " << myPet.getType() << endl;

    cout << "======" << endl;

    // Puppy
    Puppy myPuppy("Coco", 2, "Dog", "Poodle");
    cout << "name: " << myPuppy.getName() << endl;
    cout << "age: " << myPuppy.getAge() << endl;
    cout << "type: " << myPuppy.getType() << endl;
    cout << "breed: " << myPuppy.getBreed() << endl;

    cout << "======" << endl;

    // Music
    MusicStreamingService myService("YouTube Music");

    myService.addMusic("Bring Me The Horizon", "Giga Chad", "Wake Up Dun Pi Pi", 2025);
    myService.addMusic("끝까지 걸어가고 싶어", "엔씨아", "트릭컬", 2024);

    // 제목으로 찾기
    string music_title;
    cout << "Enter the music title: ";
    cin >> music_title;

    Music* result = myService.searchByTitle(music_title);

    if (result != nullptr) {
        cout << "Found: " << result->getTitle()
            << " by " << result->getArtist() << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // 아티스트로 찾기
    vector<Music*> searchByArtist(string artist) {
        vector<Music*> result;
        for (int i = 0; i < musicList.size(); i++) {
            if (musicList[i].getArtist() == artist) {
                result.push_back(&musicList[i]);
            }
        };







    };