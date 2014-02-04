##-----------------------------------------------------------------------------
##
## Root CMake file.
##
##-----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)

project(doom64ex)
set(VERSION_MAJOR "2")
set(VERSION_MINOR "4")
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
   if(WIN32) # MinGW should build D64EX as a GUI program
       TRY_C_COMPILER_FLAG(-mwindows FLAG_GUI_WINDOWS)
   endif()
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
   TRY_C_COMPILER_FLAG(/Wall    FLAG_C_Wall   )
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

##----------------------------------------------------------------------------|
## CPack Info                                                                 |
##

INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Doom64EX: A recreation of Midway's
Doom64")
SET(CPACK_PACKAGE_VENDOR "Team Kex")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/docs/Readme.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/docs/COPYING.txt")

SET(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
IF(VERSION_SUFFIX)
    SET(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}-${VERSION_SUFFIX}")
ENDIF(VERSION_SUFFIX)

SET(CPACK_PACKAGE_INSTALL_DIRECTORY "Doom64EX ${VERSION}")

##----------------------------------------------------------------------------|
## System-specific CPack Variables                                            |
##

IF(WIN32)
    # TODO
    #SET(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/data\\\\nsis_branding.bmp")
    SET(CPACK_NSIS_MUI_ICON
        "${CMAKE_SOURCE_DIR}/src/win32/resources/\\\\doom64.ico")
    SET(CPACK_NSIS_INSTALLED_ICON_NAME "doom64ex.exe")
    SET(CPACK_NSIS_DISPLAY_NAME "Doom64EX (Recreation of Doom64)")
    SET(CPACK_NSIS_HELP_LINK "http:\\\\\\\\www.doom64ex.wordpress.com/")
    SET(CPACK_NSIS_URL_INFO_ABOUT "http:\\\\\\\\www.doom64ex.wordpress.com/")
    SET(CPACK_NSIS_CONTACT "MP2E@archlinux.us")
    SET(CPACK_PACKAGE_EXECUTABLES "doom64ex.exe;Recreation of Doom64")
    SET(CPACK_NSIS_MENU_LINKS "doom64ex.exe;Recreation of Doom64")
    SET(CPACK_SOURCE_GENERATOR "ZIP")
ELSEIF(APPLE)
	# set how it shows up in the Info.plist file
    SET(MACOSX_BUNDLE_INFO_STRING "Doom64EX for Mac")
	SET(MACOSX_BUNDLE_ICON_FILE "icon.icns")
    SET(MACOSX_BUNDLE_GUI_IDENTIFIER "Doom64EX")
	SET(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION}")
    SET(MACOSX_BUNDLE_BUNDLE_NAME "Doom64EX")
	SET(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION}")
	SET(MACOSX_BUNDLE_BUNDLE_VERSION "${VERSION}")
	SET(MACOSX_BUNDLE_COPYRIGHT "Team Kex, 2014")

    # set where in the bundle to put the icns file
	SET_SOURCE_FILES_PROPERTIES(${CMAKE_SOURCE_DIR}/src/apple/icon.icns
        PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
	# include the icns file in the target
    LIST(APPEND EXTRA_SOURCES ${CMAKE_SOURCE_DIR}/src/apple/icon.icns)
ENDIF()

SET(CPACK_SOURCE_PACKAGE_FILE_NAME "doom64ex-${VERSION}")
SET(CPACK_SOURCE_IGNORE_FILES ".*~;\\\\.git;\\\\.svn;${CMAKE_BINARY_DIR}")

# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
set(CPACK_BINARY_DRAGNDROP ON)
INCLUDE(CPack)

## EOF
