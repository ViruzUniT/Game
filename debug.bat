g++ -c -std=c++17 -g -Ofast src/*.cpp -Wall -m64 -lstdc++ -I ./external-libs/SDL2-w64/include 

@echo off
copy "./SDL2.dll" "./build"
copy "./SDL2_image.dll" "./build"
robocopy "./sprites" "./build" /E 

move ./*.o ./build-int

g++ ./build-int/*.o -o build\debug.exe -L ./external-libs/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 

echo starting...
.\build\debug.exe
@echo on
