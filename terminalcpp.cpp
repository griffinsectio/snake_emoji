#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <emojicode/runtime/Runtime.h>
#include <emojicode/s/String.h>
#include <string>
#include <vector>
#include <iostream>

static struct termios original;

extern "C" void enableCbreakMode(runtime::ClassInfo*) {
    tcgetattr(STDIN_FILENO, &original);

    termios cbreak = original;

    // disable canonical mode (ICANON), echo (ECHO), and interrupt signal (ISIG)
    cbreak.c_lflag &= ~(ICANON | ECHO | ISIG);
    // immediately continue whether or not a key is pressed
    cbreak.c_cc[VMIN] = 0;
    cbreak.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &cbreak);
}

extern "C" void disableCbreakMode(runtime::ClassInfo*) {
    tcsetattr(STDIN_FILENO, TCSADRAIN, &original);
}

extern "C" runtime::Integer getKey(runtime::ClassInfo*) {
    unsigned char key[1];

    if (read(STDIN_FILENO, &key, 1) < 0) return -1;

    return key[0];
}