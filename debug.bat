g++ -c -std=c++17 -g -Ofast src/*.cpp -Wall -m64 -lstdc++ -I ./external-libs/SDL2-w64/include 

@echo off
copy "./SDL2.dll" "./build"
copy "./SDL2_image.dll" "./build"
mkdir "./build/sprites"
xcopy "./sprites" "./build/sprites" /E /Y

move /Y "./*.o" "./build-int"

g++ ./*.o -o build\debug.exe -L ./external-libs/SDL2-w64/bin -lmingw32 -lSDL2 -lSDL2_image 

echo starting...
.\build\debug.exe
@echo on
