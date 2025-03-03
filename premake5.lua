workspace("Game")
architecture("x64")
configurations({
	"Debug",
	"Release",
})
toolset("msc")

startproject("MainGame")

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

include("MainGame")

postbuildcommands({
	-- Copy SDL DLLs to the target directory
	'{COPY} "SDL2.dll" "%{cfg.targetdir}"',
	'{COPY} "SDL2_image.dll" "%{cfg.targetdir}"',
	-- Create sprites directory and copy its contents
	'{MKDIR} "%{cfg.targetdir}/sprites"',
	'{COPY} "MainGame/sprites/*" "%{cfg.targetdir}/sprites"',
})

newaction({
	trigger = "clean",
	description = "Remove all binaries and intermediate binaries, and vs files.",
	execute = function()
		print("Removing binaries")
		os.rmdir("./bin")
		print("Removing intermediate binaries")
		os.rmdir("./bin-int")
		print("Removing project files")
		os.rmdir("./.vs")
		os.remove("**.sln")
		os.remove("**.vcxproj")
		os.remove("**.vcxproj.filters")
		os.remove("**.vcxproj.user")

		os.remove("**Makefile")
		print("Done")
	end,
})
