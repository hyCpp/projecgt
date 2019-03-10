#ifndef SIGNALPUBLICIF
#define SIGNALPUBLICIF

#include "Signal.h"

#define SIGNAL(...) Signal<void(*)(__VA_ARGS__)>

#define ZPOST(poster, ...) poster.post(FromHere,##__VA_ARGS__)

#define ZCONNECT(signal, ...) signal.connect(FromHere,##__VA_ARGS__)

#define ZDISCONNECT(signal, ...) signal.disconnect(__VA_ARGS__)

#endif // SIGNALPUBLICIF

