##-----------------------------------------------------------------------------
##
## Source Level CMake file.
##
##-----------------------------------------------------------------------------

include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/Ext
    ${FLUIDSYNTH_INCLUDE_DIRS} ${SDL_INCLUDE_DIR} ${SDL_NET_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})

if(APPLE)
    set(EXTRA_SOURCES apple/SDLMain.m)
elseif(WIN32)
    set(EXTRA_SOURCES win32/i_exception.c win32/i_cpu.c
        win32/resources/doom64.rc win32/SDL_win32_main.c)
else()
        LIST(APPEND EXTRA_SOURCES unix/i_cpu_posix.c)
endif()

if(MSVC)
    LIST(APPEND EXTRA_SOURCES win32/i_opndir.c)
endif()

add_executable(doom64ex
    WIN32
    MACOSX_BUNDLE
    ${EXTRA_SOURCES}
    am_draw.c
    am_map.c
    con_console.c
    con_cvar.c
    d_devstat.c
    d_main.c
    d_net.c
    dgl.c
    f_finale.c
    g_actions.c
    g_demo.c
    g_game.c
    g_settings.c
    gl_draw.c
    gl_main.c
    gl_pixmap.c
    gl_texture.c
    i_audio.c
    i_joystick.c
    i_keyboard.c
    i_main.c
    i_mouse.c
    i_png.c
    i_system.c
    i_video.c
    i_xinput.c
    in_stuff.c
    info.c
    m_cheat.c
    m_fixed.c
    m_keys.c
    m_menu.c
    m_misc.c
    m_password.c
    m_random.c
    m_shift.c
    p_ceilng.c
    p_doors.c
    p_enemy.c
    p_floor.c
    p_inter.c
    p_lights.c
    p_macros.c
    p_map.c
    p_maputl.c
    p_mobj.c
    p_plats.c
    p_pspr.c
    p_saveg.c
    p_setup.c
    p_sight.c
    p_spec.c
    p_switch.c
    p_telept.c
    p_tick.c
    p_user.c
    psnprntf.c
    r_bsp.c
    r_clipper.c
    r_drawlist.c
    r_lights.c
    r_main.c
    r_scene.c
    r_sky.c
    r_things.c
    r_wipe.c
    s_sound.c
    sc_main.c
    st_stuff.c
    tables.c
    w_file.c
    w_merge.c
    w_wad.c
    wi_stuff.c
    z_zone.c
    Ext/md5.c
    Ext/ChocolateDoom/net_client.c
    Ext/ChocolateDoom/net_common.c
    Ext/ChocolateDoom/net_dedicated.c
    Ext/ChocolateDoom/net_io.c
    Ext/ChocolateDoom/net_loop.c
    Ext/ChocolateDoom/net_packet.c
    Ext/ChocolateDoom/net_query.c
    Ext/ChocolateDoom/net_sdl.c
    Ext/ChocolateDoom/net_server.c
    Ext/ChocolateDoom/net_structrw.c
)

if(MSVC)
    target_link_libraries(doom64ex ${FLUIDSYNTH_LIBRARIES} ${SDL_NET_LIBRARIES}
        ${SDL_LIBRARY} ${PNG_LIBRARIES} ${ZLIB_LIBRARIES} ${OPENGL_LIBRARIES})
elseif(WIN32)
    target_link_libraries(doom64ex ${FLUIDSYNTH_LIBRARIES} ${SDL_NET_LIBRARIES}
        ${SDL_LIBRARY} ${PNG_LIBRARIES} ${ZLIB_LIBRARIES} ${OPENGL_LIBRARIES}
        imm32 version iphlpapi ws2_32 winmm dxguid m)
else()
    target_link_libraries(doom64ex ${FLUIDSYNTH_LIBRARIES} ${SDL_NET_LIBRARIES}
        ${SDL_LIBRARY} ${PNG_LIBRARIES} ${ZLIB_LIBRARIES} ${OPENGL_LIBRARIES} m)
endif()

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

# Installation configuration
SET(plugin_dest_dir bin)
SET(APPS "\${CMAKE_INSTALL_PREFIX}/bin/Doom64EX")
IF(APPLE)
    SET(plugin_dest_dir Doom64EX.app/Contents/MacOS)
    SET(APPS "\${CMAKE_INSTALL_PREFIX}/Doom64EX.app")
ENDIF()
IF(WIN32)
    SET(APPS "\${CMAKE_INSTALL_PREFIX}/bin/Doom64EX.exe")
ENDIF()

#------------------------------------------------------------------------------
# Install Doom64EX application. On Mac OS X, the bundle is the root of the
# install tree and on other platforms it goes in the bin directory
install(TARGETS doom64ex
    BUNDLE DESTINATION . COMPONENT Runtime
    RUNTIME DESTINATION bin COMPONENT Runtime
    )


#------------------------------------------------------------------------------
# Use BundleUtilities to get all other dependencies for the application to work.
# It takes a bundle or executable along with possible plugins and inspects it
# for dependencies.  If they are not system dependencies, they are copied.

# directories to look for dependencies
SET(DIRS ${FLUIDSYNTH_LIBRARY_DIRS} ${SDL_LIBRARY_DIRS} ${SDL_NET_LIBRARY_DIRS}
    ${PNG_LIBRARY_DIRS} ${OPENGL_LIBRARY_DIRS})

# Now the work of copying dependencies into the bundle/package
# The quotes are escaped and variables to use at install time are escaped 
INSTALL(CODE "
    file(GLOB_RECURSE QTPLUGINS
        \"\${CMAKE_INSTALL_PREFIX}/${plugin_dest_dir}/plugins/*${CMAKE_SHARED_LIBRARIES_SUFFIX}\")
    set(BU_CHMOD_BUNDLE_ITEMS ON)
    include(BundleUtilities)
    fixup_bundle(\"${APPS}\" \"\${FLUIDSYNTH_LIBRARIES}\"
        \"\${SDL_LIBRARY}\" \"\${SDL_NET_LIBRARIES}\"
        \"\${PNG_LIBRARIES}\" \"\${OPENGL_LIBRARIES}\" \"${DIRS}\")
    " COMPONENT Runtime)
# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
set(CPACK_BINARY_DRAGNDROP ON)
INCLUDE(CPack)

# eof
