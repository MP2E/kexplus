##-----------------------------------------------------------------------------
##
## Source Level CMake file.
##
##-----------------------------------------------------------------------------

include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/Ext
    ${FLUIDSYNTH_INCLUDE_DIR} ${SDL_INCLUDE_DIR} ${SDL_NET_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

if(APPLE)
    set(EXTRA_SOURCES apple/SDLMain.m)
elseif(WIN32)
    set(EXTRA_SOURCES win32/i_exception.c win32/i_cpu.c
        win32/resources/doom64.rc)
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
    gl_texture.c
    i_audio.c
    i_main.c
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
target_link_libraries(doom64ex ${PNG_LIBRARY} ${ZLIB_LIBRARY} ${SDL_LIBRARY}
    ${FLUIDSYNTH_LIBRARIES} ${SDLNET_LIBRARY} ${OPENGL_LIBRARY})
elseif(WIN32)
target_link_libraries(doom64ex ${PNG_LIBRARY} ${ZLIB_LIBRARY} ${SDL_LIBRARY}
    ${FLUIDSYNTH_LIBRARIES} ${SDLNET_LIBRARY} ${OPENGL_LIBRARY} iphlpapi
    ws2_32 winmm dxguid m)
else()
target_link_libraries(doom64ex ${PNG_LIBRARY} ${ZLIB_LIBRARY} ${SDL_LIBRARY}
    ${FLUIDSYNTH_LIBRARIES} ${SDLNET_LIBRARY} ${OPENGL_LIBRARY} m)
endif()
