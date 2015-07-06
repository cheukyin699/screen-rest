#include <cstring>
#include <iostream>

#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main(int argc, char **argv) {
    double bt = 60, bl = 5;

    // Argument parsing
    for (unsigned i=0; i<argc; i++) {
        if (strcmp(argv[i], "-t")==0 || strcmp(argv[i], "--break-time")==0) {
            if (i+1 >= argc) continue;
            bt = atof(argv[++i]);
        } else if (strcmp(argv[i], "-l")==0 || strcmp(argv[i], "--break-length")==0) {
            if (i+1 >= argc) continue;
            bl = atof(argv[++i]);
        }
    }

    SoundBuffer warning_sound;
    if (!warning_sound.loadFromFile("res/music.wav")) {
        return -1;
    }

    Sound warning;
    warning.setBuffer(warning_sound);

    Clock c;

    cout << "Now running...\n";

    while (true) {
        c.restart();

        sleep(seconds(bt*60*.9-c.getElapsedTime().asSeconds()));

        // Alert the user as a warning
        // With the audio
        cout << "Warning: You have " << bt * .1 << "min left until "
        "total audio irritation.\n\n";
        warning.setLoop(false);
        warning.play();
        sleep(seconds(bt*60-c.getElapsedTime().asSeconds()));
        warning.pause();

        // HAHAHA
        warning.setLoop(true);
        warning.play();

        sleep(seconds(bl*60));

        warning.pause();

        cout << "You may now return to the computer\n\n";
    }
    return 0;
}
