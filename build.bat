@echo "hello"

g++ -c -std=c++17 -Ofast src/*.cpp -Wall -m64 -I C:/SDL2-w64/include && g++ *.o -o build\main.exe -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && .\build\main.exe
