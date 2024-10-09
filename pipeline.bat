@echo compiling
g++ -c -std=c++17 -g -Ofast src/*.cpp -Wall -m64 -lstdc++ -I ./build
@echo compiling success

mkdir "./build/sprites"
xcopy "./sprites" "./build/sprites" /E /Y

move /Y "./*.o" "./build-int"

@echo Linking
g++ ./*.o -o build\debug.exe -L ./build -lmingw32 -lSDL2 -lSDL2_image 
@echo Linking success
