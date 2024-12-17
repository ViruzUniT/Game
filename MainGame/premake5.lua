project "MainGame"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

files {
  "src/**.cpp",
  "include/**.h",
  "src/**.h",
  "include/**.cpp",
  "include/**.c",
  "external-libs/**.h",
  "external-libs/SDL2-w64/include/SDL2/*.h",
  "external-libs/**.c",
  "external-libs/**.cpp"
}

defines {
  "WINDOWS"
}

extDir = {}
extDir["SDL2"] = "external-libs/SDL2-w64/include/SDL2"

filter { "configurations:Debug" }
libdirs { "./external-libs/SDL2-w64/bin" }
links { "SDL2", "SDL2_image" }
-- linkoptions { "-static-libgcc", "-static-libstdc++" }
runtime "Debug"
symbols "on"
optimize "Debug"

filter { "configurations:Release" }
libdirs { "./external-libs/SDL2-w64/bin" }
links { "SDL2", "SDL2_image" }
--linkoptions { "-static-libgcc", "-static-libstdc++" }
runtime "Release"
optimize "Speed"
