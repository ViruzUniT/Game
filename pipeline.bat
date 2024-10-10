.\vendor\premake5.exe gmake2
mkdir "./bin-int"
make

copy "./MainGame/external-libs/SDL2-w64/bin/SDL2.dll" "./bin/Debug-windows/MainGame"
copy "./MainGame/external-libs/SDL2-w64/bin/SDL2_image.dll" "./bin/Debug-windows/MainGame"
mkdir "./bin/Debug-windows/MainGame/sprites"
xcopy "./MainGame/sprites" "./bin/Debug-windows/MainGame/sprites" /E /Y
