#include <cstring>
#include <iostream>

#include <SFML/Audio.hpp>

#include "config.h"

using namespace std;
using namespace sf;

int main(int argc, char **argv) {
    bool verbose = false;
    double bt = 55, bl = 5;

    // Argument parsing
    for (unsigned i=0; i<argc; i++) {
        if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--break-time") == 0) {
            if (i+1 >= argc) continue;
            bt = atof(argv[++i]);
        } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--break-length") == 0) {
            if (i+1 >= argc) continue;
            bl = atof(argv[++i]);
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            cout << PACKAGE_STRING << endl
                << "Please report any bugs to: <" << PACKAGE_URL << ">\n\n"
                << argv[0] << " [options]\n\n"
                   "Options:\n"
                   "  -t N,\n"
                   "  --break-time N       The interval of time in minutes that you want to\n"
                   "                       take a break. Default is 55.\n\n"
                   "  -l N,\n"
                   "  --break-length K     The interval of time in minutes that you want your\n"
                   "                       break to last. Default is 5.\n\n"
                   "  -v, --verbose        If you want it to run in terminal with status text,\n"
                   "                       have this option.\n\n"
                   "  -h, --help           Displays this help dialog.\n";
            return 0;
        }
    }

    SoundBuffer warning_sound;
    if (!warning_sound.loadFromFile("res/music.wav")) {
        return -1;
    }

    Sound warning;
    warning.setBuffer(warning_sound);

    Clock c;

    if (verbose)
        cout << "Now running...\n";

    while (true) {
        c.restart();

        if (verbose) {
        sleep(seconds(bt*60*.9-c.getElapsedTime().asSeconds()));

        // Alert the user as a warning
        // With the audio
        cout << "Warning: You have " << bt * .1 << "min left until "
        "total audio irritation.\n\n";
        warning.setLoop(false);
        warning.play();
        sleep(seconds(bt*60-c.getElapsedTime().asSeconds()));
        warning.pause();
        } else {
            sleep(seconds(bt*60));
        }

        // HAHAHA
        warning.setLoop(true);
        warning.play();

        sleep(seconds(bl*60));

        warning.pause();

        if (verbose)
            cout << "You may now return to the computer\n\n";
    }
    return 0;
}
