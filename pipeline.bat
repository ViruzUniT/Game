.\vendor\premake5.exe gmake2
mkdir "./bin-int/Debug-windows/MainGame"
mkdir "./bin/Debug-windows/MainGame"
make

copy "./SDL2.dll" "./bin/Debug-windows/MainGame"
copy "./SDL2_image.dll" "./bin/Debug-windows/MainGame"
mkdir "./bin/Debug-windows/MainGame/sprites"
xcopy "./MainGame/sprites" "./bin/Debug-windows/MainGame/sprites" /E /Y
