# Description
Just another snake game but written using emojicode
# How to setup
- Create the packages and the library folder
```sh
mkdir packages/terminal
``` 
- Generate library
```sh
emojicodec -p terminal terminal.🍇
```
- Generate object file of terminalcpp.cpp
```sh
g++ -c terminalcpp.cpp -o terminalcpp.o
```
- Create static library by linking terminal.o and terminalcpp.o
```sh
ar rcs libterminal.a terminal.o terminalcpp.o
```
- Move the interface file and the static library to terminal package folder
```sh
mv 🏛 libterminal.a packages/terminal/
```
- Compile the game
```sh
emojicodec game.🍇
```
# Play the game
Use WASD button to control the snake, ENTER button to confirm selection, and q or Q to quit the game
