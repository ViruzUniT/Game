g++ -c -std=c++17 -g -Ofast src/*.cpp -Wall -m64 -I C:/SDL2-w64/include && g++ *.o -o build\debug.exe -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
@echo off
echo starting...
.\build\debug.exe
@echo on
