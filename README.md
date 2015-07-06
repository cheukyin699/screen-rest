## Screen_Rest

This is a small program that helps you get off the computer every N minutes for another
K minutes of music with a warning before the last 10% of the N minutes. All on the command line.
If you choose to heed the warning, that's fine. There is nothing stopping you from continuing on
your computing session, or just <kbd>Ctrl</kbd>-<kbd>C</kbd> to stop this program.

### Usage

```
./screen_rest [-t|--break-time N] [-l|--break-length K]

-t
--break-time N
    The interval of time in minutes that you want to take a break.
    Default is 60.

-l
--break-length K
    The interval of time in minutes that you want your break to last.
    Default is 5.
```
