## Screen_Rest

This is a small program that helps you get off the computer every N minutes for
another K minutes of music with a warning before the last 10% of the N minutes.
All on the command line.  If you choose to heed the warning, that's fine. There
is nothing stopping you from continuing on your computing session, or just
<kbd>Ctrl</kbd>-<kbd>C</kbd> to stop this program.

This program uses sfml-audio for handling the audio, so make sure you have SFML
installed.


### Usage

```
./screen_rest <options>

Options:

  -t N,
  --break-time N        The interval of time in minutes that you want to
                        take a break. Default is 55.

  -l K,
  --break-length K      The interval of time in minutes that you want your
                        break to last. Default is 5.

  -a <file>,
  --audio <file>        An alternate audio file to play instead of
                        `res/music.wav`.

  -v, --verbose         If you want it to run in terminal blocking (with
                        status text), have this option.

  -h, --help            Displays the help screen.
```


### Building

To build, simply do:

```
# To rebuild the config.h.in and ./configure files if they don't work
autoheader
autoconf

# The normal building process
mkdir build
cd build
../configure
make
```
