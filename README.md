# StringMapSpeedTest

While tinkering with [Minutor](https://github.com/mrkite/minutor), I found out it takes a really long time to destroy many mid-size `QMap<QString, QVariant>` instances (the block palettes for each chunk section). To investigate, I set out to compare the performance between `QMap`, `std::map` and `std::unordered_map`, and between `QString` and `std::string` as the map keys; this repository is the resulting test.

The test simply fills 50k instances of a map container with 30 items (9-char key, 9-char value) each.

The end result is that the `QMap<QString, QVariant>` is the slowest of the bunch, but not by much. I timed separately the time for filling the containers and the time for clearing the containers. The fastest filling was with `std::unordered_map<std::string, QVariant>`, it was pretty much twice as fast; there were less differences in the clearing times, with `QMap<std::string, QVariant> being the fastest by a factor of ~1.5.

The following table lists the results provided by one run of the program:
```
QMapQString: Filling  the containers took 686 msec
QMapQString: Clearing the containers took 220 msec
StdMapQString: Filling  the containers took 507 msec
StdMapQString: Clearing the containers took 211 msec
StdMapStdString: Filling  the containers took 373 msec
StdMapStdString: Clearing the containers took 186 msec
QMapStdString: Filling  the containers took 493 msec
QMapStdString: Clearing the containers took 139 msec
StdUnorderedMapQString: Filling  the containers took 447 msec
StdUnorderedMapQString: Clearing the containers took 190 msec
StdUnorderedMapStdString: Filling  the containers took 336 msec
StdUnorderedMapStdString: Clearing the containers took 147 msec
```

Since the numbers didn;t match what I was experiencing with the real-life program, I investigated further and finally found out that there's a big difference between running the executable standalone or under QtCreator's debugger. While running under the QtCreator's debugger, the tests were 5 - **60** times slower than when running (the same executable) standalone. The following results are for comparison, they are from the very same executable as the results above, but this time run under QtCreator's debugger:
```
QMapQString: Filling  the containers took 3072 msec
QMapQString: Clearing the containers took 13467 msec
StdMapQString: Filling  the containers took 38562 msec
StdMapQString: Clearing the containers took 6462 msec
StdMapStdString: Filling  the containers took 21542 msec
StdMapStdString: Clearing the containers took 5902 msec
QMapStdString: Filling  the containers took 11225 msec
QMapStdString: Clearing the containers took 9416 msec
StdUnorderedMapQString: Filling  the containers took 18860 msec
StdUnorderedMapQString: Clearing the containers took 8279 msec
StdUnorderedMapStdString: Filling  the containers took 22438 msec
StdUnorderedMapStdString: Clearing the containers took 7316 msec
```
This happens for both Debug and Release variants of the build, at least on Windows 8.1 with MSVC2019 as the compiler and CDB as the debugger, with Qt 5.12.1; I haven't tested on other platforms (yet).
