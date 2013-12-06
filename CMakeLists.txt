##-----------------------------------------------------------------------------
##
## Root CMake file.
##
##-----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)

project(doom64ex)

include(CheckCXXCompilerFlag)

# This is needed to include the FluidSynth module
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

##----------------------------------------------------------------------------|
## Functions                                                                  |
##

##
## TRY_CXX_COMPILER_FLAG
##
function(TRY_CXX_COMPILER_FLAG flag name)
   CHECK_CXX_COMPILER_FLAG(${flag} ${name})

   if(${name})
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
   endif()
endfunction()


##----------------------------------------------------------------------------|
## Environment Detection                                                      |
##

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
   TRY_CXX_COMPILER_FLAG(-Wall    FLAG_CXX_Wall   )
   TRY_CXX_COMPILER_FLAG(-Wextra  FLAG_CXX_Wextra )
   TRY_CXX_COMPILER_FLAG(-Wshadow FLAG_CXX_Wshadow)
   TRY_CXX_COMPILER_FLAG(-std=c++11 FLAG_CXX_CXX11)
endif()

find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL REQUIRED)
find_package(FluidSynth REQUIRED)
find_package(SDL_net REQUIRED)
find_package(OpenGL REQUIRED)

##----------------------------------------------------------------------------|
## Embed current revision into version.h                                      |
##

execute_process(
	COMMAND git rev-parse --short HEAD
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
