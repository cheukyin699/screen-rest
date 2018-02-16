/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstring>
#include <iostream>
#include <string>

#include <SFML/Audio.hpp>

#include "config.h"

using namespace std;
using namespace sf;

int main(int argc, char **argv) {
    bool verbose = false;
    double bt = 55, bl = 5;
    string audio_file = "res/music.wav";

    // Argument parsing
    for (unsigned i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--break-time") == 0) {
            if (++i >= argc) {
                cerr << "Error: expected an integer.\n";
                continue;
            }
            bt = atof(argv[i]);
        }
        else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--break-length") == 0) {
            if (++i >= argc) {
                cerr << "Error: expected an integer.\n";
                continue;
            }
            bl = atof(argv[i]);
        }
        else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--audio") == 0) {
            if (++i >= argc) {
                cerr << "Warning: expected audio file, using default `res/music.wav'.\n";
                continue;
            }
            audio_file = argv[i];
        }
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
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
                   "  -a <file>,\n"
                   "  --audio <file>       To specify another audio file other than the default.\n\n"
                   "  -v, --verbose        If you want it to run in terminal with status text,\n"
                   "                       have this option.\n\n"
                   "  -h, --help           Displays this help dialog.\n";
            return 0;
        }
    }

    SoundBuffer warning_sound;
    if (!warning_sound.loadFromFile(audio_file.c_str())) {
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
        sleep(seconds(bt * 60 * .9 - c.getElapsedTime().asSeconds()));

        // Alert the user as a warning
        // With the audio
        cout << "Warning: You have " << bt * .1 << "min left until "
        "total audio irritation.\n\n";
        warning.setLoop(false);
        warning.play();
        sleep(seconds(bt * 60 - c.getElapsedTime().asSeconds()));
        warning.pause();
        } else {
            sleep(seconds(bt * 60));
        }

        // HAHAHA
        warning.setLoop(true);
        warning.play();

        sleep(seconds(bl * 60));

        warning.pause();

        if (verbose)
            cout << "You may now return to the computer\n\n";
    }
    return 0;
}
