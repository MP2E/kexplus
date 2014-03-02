##-----------------------------------------------------------------------------
##
## Root CMake file.
##
##-----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)

project(doom64ex)
set(VERSION_MAJOR "2")
set(VERSION_MINOR "6")
set(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
IF(VERSION_SUFFIX)
    SET(VERSION "${VERSION}-${VERSION_SUFFIX}")
ENDIF(VERSION_SUFFIX)

include(CheckCCompilerFlag)

# This is needed to include the FluidSynth module
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

##----------------------------------------------------------------------------|
## Functions                                                                  |
##

##
## TRY_C_COMPILER_FLAG
##
function(TRY_C_COMPILER_FLAG flag name)
   CHECK_C_COMPILER_FLAG(${flag} ${name})

   if(${name})
	   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flag}" PARENT_SCOPE)
   endif()
endfunction()


##----------------------------------------------------------------------------|
## Environment Detection                                                      |
##

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
   TRY_C_COMPILER_FLAG(-Wall    FLAG_C_Wall   )
   TRY_C_COMPILER_FLAG(-Wextra  FLAG_C_Wextra )
   TRY_C_COMPILER_FLAG(-Wshadow FLAG_C_Wshadow)
   TRY_C_COMPILER_FLAG(-std=c11 FLAG_C_C11)
   # 2014/02/27 dotfloat: Ignore all warnings about unused parameters
   TRY_C_COMPILER_FLAG(-Wno-unused-parameter FLAG_NO_UNUSED_PARAMS)

   if(WIN32) # MinGW should build D64EX as a GUI program
       TRY_C_COMPILER_FLAG(-mwindows FLAG_GUI_WINDOWS)
   endif()
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
   TRY_C_COMPILER_FLAG(/Wall    FLAG_C_Wall   )
endif()

# Run cmake with the argument "-DUSE_SDL2=true" to enable SDL2
if(USE_SDL2)
   find_package(SDL2 REQUIRED)
   find_package(SDL2_net REQUIRED)

   set(SDL_INCLUDE_DIR ${SDL2_INCLUDE_DIRS})
   set(SDL_LIBRARY ${SDL2_LIBRARIES})
   set(SDL_NET_INCLUDE_DIRS ${SDL2_NET_INCLUDE_DIRS})
   set(SDL_NET_LIBRARIES ${SDL2_NET_LIBRARIES})
else()
   find_package(SDL REQUIRED)
   find_package(SDL_net REQUIRED)
endif() 

find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)
find_package(FluidSynth REQUIRED)
find_package(OpenGL REQUIRED)

##----------------------------------------------------------------------------|
## Embed current revision into version.h                                      |
##

execute_process(
    COMMAND git describe HEAD
	COMMAND tr -d "\\n"
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
	OUTPUT_VARIABLE GITREVISION
)
execute_process(
	COMMAND sed -e "s/\\$WCREV\\$/${GITREVISION}/g" revconfig.txt
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
	OUTPUT_FILE version.h
)

##----------------------------------------------------------------------------|
## Targets                                                                    |
##

add_subdirectory(src)

## EOF
