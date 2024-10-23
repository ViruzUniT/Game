workspace "Game"
architecture "x64"

configurations {
  "Debug",
  "Release"
}

startproject "MainGame"

outputdir = "%{cfg.buildcfg}"

include "MainGame"

newaction {
  trigger = "clean",
  description = "Remove all binaries and intermediate binaries, and vs files.",
  execute = function()
    print("Removing binaries")
    os.rmdir("./bin/**.exe")
    os.rmdir("./bin/**.dll")
    os.rmdir("./bin/**.dll")
    os.rmdir("./bin/**.png")
    print("Removing intermediate binaries")
    os.rmdir("./bin-int/**.o")
    os.rmdir("./bin-int/**.d")
    print("Removing project files")
    os.rmdir("./.vs")
    os.remove("**.sln")
    os.remove("**.vcxproj")
    os.remove("**.vcxproj.filters")
    os.remove("**.vcxproj.user")

    os.remove("**Makefile")
    print("Done")
  end
}
