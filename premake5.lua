--[[ 
========================================================================
			GAME MAKER STUDIO WWISE GENIE CONFIGURATION FILE
========================================================================	
]]--
function split(str, pat)
	local t = {}  -- NOTE: use {n = 0} in Lua-5.0
	local fpat = "(.-)" .. pat
	local last_end = 1
	local s, e, cap = str:find(fpat, 1)
	while s do
		if s ~= 1 or cap ~= "" then
			table.insert(t,cap)
		end
        last_end = e+1
        s, e, cap = str:find(fpat, last_end)
    end
	
    if last_end <= #str then
		cap = str:sub(last_end)		
		table.insert(t, cap)
    end
   
    return t
end

--------------------------------------------------------------------
-- Check if the required dependencies are installed.
function checkDependencies()
	print("***  DEPENDENCIES  ***")
	
	-- check if wwise is installed.
	WWISESDK = os.getenv("WWISESDK")
	if WWISESDK == nil then
		error("Wwise SDK cannot be found")
	else		
		local parts = split(WWISESDK, "\\")
		local wwiseVersion = parts[#parts - 1]
		
		if wwiseVersion:find('2015.1') then
			print("Wwise SDK Version: " .. wwiseVersion)
		else
			error("Unsupported Wwise SDK Version: " .. wwiseVersion)
		end
	end
	
	-- check if DirectX is installed.
	DXSDK = os.getenv("DXSDK_DIR")
	if DXSDK == nil then
		error("DirectX connect be found")
	end
end

solution "GMSWwise"
	checkDependencies()
	
	--[[ 
		Debug: non optimized with debug information
		Profile: optimized with debug information
		Release: optimized without debug information
	]]--
	configurations { "Debug", "Profile", "Release" }	
	
    PLATFORM_DEF = "PLATFORM_UNDEF"
	if os.is("windows") == true then
		DEBUG_DEF = "_DEBUG"	
		platforms  { "x32", "x64" }		
    else
		error("Unsupported Platform")
	end
	
	--------------------------------------------------------------------
	-------------------------------------- specific library per platform
	local dependencies = {}
	dependencies["wwise"] = 
	{
		include = WWISESDK.."/include",
		commonLib = 
		{ 
			"AkSoundEngine",
			"AkMemoryMgr",
			"AkStreamMgr",
			"AkMusicEngine",
			"AkAudioInputSource",
			"AkCompressorFX",
			"AkConvolutionReverbFX",
			"AkDelayFX",
			"AkExpanderFX",
			"AkFlangerFX",
			"AkGuitarDistortionFX",
			"AkMatrixReverbFX",
			"AkMeterFX",
			"AkMotionGenerator",
			"AkParametricEQFX",
			"AkPeakLimiterFX",
			"AkRoomVerbFX",
			"AkRumble",
			"AkSilenceSource",
			"AkSineSource",
			"AkSoundSeedImpactFX",
			"AkSoundSeedWind",
			"AkSoundSeedWoosh",
			"AkToneSource",
			"AkTremoloFX",
			"AkVorbisDecoder",
			"AkPitchShifterFX",
		},		
		
		debug =
		{
			lib = { "CommunicationCentral", "Ws2_32" },			
			libX86dir = WWISESDK.."/Win32_vc140/Debug/lib",
			libX64dir = WWISESDK.."/x64_vc140/Debug/lib",
		},
		profile =
		{
			lib = { "CommunicationCentral", "Ws2_32" },
			libX86dir = WWISESDK.."/Win32_vc140/Profile/lib",
			libX64dir = WWISESDK.."/x64_vc140/Profile/lib",
		},
		release =
		{
			lib = { },
			libX86dir = WWISESDK.."/Win32_vc140/Release/lib",
			libX64dir = WWISESDK.."/x64_vc140/Release/lib",
		}
	}
		
	dependencies["directx"] = 
	{
		include = DXSDK.."/Include",
		commonLib = { "dsound", "dxguid" },

		debug =
		{
			lib = { },
			libX86dir = DXSDK.."/Lib/x86",
			libX64dir = DXSDK.."/Lib/x64",
		},
		profile =
		{
			lib = { },
			libX86dir = DXSDK.."/Lib/x86",
			libX64dir = DXSDK.."/Lib/x64",
		},
		release =
		{
			lib = { },
			libX86dir = DXSDK.."/Lib/x86",
			libX64dir = DXSDK.."/Lib/x64",
		}
	}
	
	--------------------------------------------------------------------
	------------------------------------------  CREATION OF SAM PROJECTS
	print("***  PROJECT GENERATION  ***")
	location("tmp/".._ACTION)	
	
	-- Generate Sam Projects.
	project("GMSWwise")
		location("tmp/".._ACTION)
		
		kind "SharedLib"
		language "C++"				
		pchheader "GMSWwisePCH.h"
		
		local commonFlags = { }
			
		-- paths.
		local projectFolder = "source/"
		local platformRootFolder = "source/platforms/"		
			
        pchheader("GMSWwisePCH.h")
		pchsource("source/GMSWwisePCH.cpp")
			
		-- include and library directories per dependencies.
		for i, dep in pairs(dependencies) do
			if dependencies[i] ~= nil then
				includedirs { dependencies[i].include }
				links { dependencies[i].commonLib }
				
				configuration { "Debug" }
					links { dependencies[i].debug.lib }
				configuration { "Profile" }
					links { dependencies[i].profile.lib }
				configuration { "Release" }
					links { dependencies[i].release.lib }
				configuration {}
				
				-- x32 settings.
				configuration { "x32", "Debug" }					
					libdirs { dependencies[i].debug.libX86dir }
				configuration { "x32", "Profile" }
					libdirs { dependencies[i].profile.libX86dir }
				configuration { "x32", "Release" }
					libdirs { dependencies[i].release.libX86dir }
				configuration {}
				
				-- x64 settings.
				configuration { "x64", "Debug" }
					libdirs { dependencies[i].debug.libX64dir }
				configuration { "x64", "Profile" }
					libdirs { dependencies[i].profile.libX64dir }
				configuration { "x64", "Release" }
					libdirs { dependencies[i].release.libX64dir }

				configuration {}
			end
		end			
			
		------------------------------------------------------------
		-------------------------------------------------  ADD FILES
		-- create files patterns.
		local projectFiles = { projectFolder.."**.h", projectFolder.."**.cpp", projectFolder.."**.inl" }
		local platformFiles = { }
			
		local windowsProjectFolder = platformRootFolder.."windows/"
		includedirs { "source/" }		
		if os.is("windows") == true then
			includedirs { platformRootFolder.."windows/" }
			windowsPlatformFiles = { windowsProjectFolder.."**.h", windowsProjectFolder.."**.cpp", windowsProjectFolder.."**.inl" }
			
			-- create virtual folder.
			vpaths 
			{
				["**"] = projectFiles,					
				["platform/windows/**"] = windowsPlatformFiles
			}
				
			files 
			{
				projectFiles,
				windowsPlatformFiles
			}
		end	
		------------------------------------------------------------
			
			
			
		------------------------------------------------------------
		--------------------------------------------  CONFIGURATIONS
		configuration { "x32" }
			defines { "GMSW_PLATFORM_WINDOWS", "GMSW_32BITS" }
		
		configuration { "x64" }
			defines { "GMSW_PLATFORM_WINDOWS", "GMSW_64BITS" }			
				
		configuration {}
			
		configuration "Debug"
			defines { DEBUG_DEF, "GMSW_DEBUG", "GMSW_PROFILING", "GMSW_EXPORTS" }
			flags { "Symbols", commonFlags }
			objdir("tmp/".._ACTION.."/obj/debug/")
			implibdir("lib/")
			targetdir("bin/")
			libdirs { "lib/" }
			targetname "GMSWwise_d"
				
		configuration "Profile"
			defines { "GMSW_PROFILING", "GMSW_EXPORTS" }
			flags { "Symbols", commonFlags }
			objdir("tmp/".._ACTION.."/obj/profile/")
			implibdir("lib/")
			targetdir("bin/")
			libdirs { "lib/" }
			targetname "GMSWwise_p"
			optimize "Full"
				
		configuration "Release"
			defines { "NDEBUG", "GMSW_EXPORTS" }
			flags { "Optimize", "FatalWarnings", commonFlags }
			objdir("tmp/".._ACTION.."/obj/release/")
			implibdir("lib/")
			targetdir("bin/")
			libdirs { "lib/" }
			targetname "GMSWwise"
			optimize "Full"
		------------------------------------------------------------		