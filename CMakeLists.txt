cmake_minimum_required(VERSION 2.6)
project(Doom64Ex)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL REQUIRED)
find_package(FluidSynth REQUIRED)
find_package(SDL_net REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/Ext ${FluidSynth_INCLUDE_DIR} ${SDL_INCLUDE_DIR} ${PNG_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

# Get around a issue
add_definitions(-Ddprintf=_dprintf -D__cdecl=)

if(APPLE)
	set(EXTRA_SOURCES Ext/SDLMain.m)
endif(APPLE)
if(MSVC)
	set(EXTRA_SOURCES src/i_exception.c src/i_opndir.c src/i_cpu.c)
else(MSVC)
	set(EXTRA_SOURCES src/i_cpu_posix.c)
endif(MSVC)

execute_process(
	COMMAND git log
	COMMAND grep -i commit
	COMMAND grep -o -E -e "[0-9a-f]{40}"
	COMMAND tr -d "\\n"
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	OUTPUT_VARIABLE GITREVISION
)
execute_process(
	COMMAND sed -e "s/\\$WCREV\\$/${GITREVISION}/g" revconfig.txt
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	OUTPUT_FILE src/version.h
)

add_executable(doom64ex
	${EXTRA_SOURCES}
	src/am_draw.c
	src/am_map.c
	src/con_console.c
	src/con_cvar.c
	src/d_devstat.c
	src/d_main.c
	src/d_net.c
	src/dgl.c
	src/f_finale.c
	src/g_actions.c
	src/g_game.c
	src/g_settings.c
	src/gl_draw.c
	src/gl_main.c
	src/gl_texture.c
	src/i_audio.c
#	i_cpu.c
#	i_cpu_posix.c
#	i_exception.c
	src/i_main.c
#	i_opndir.c
	src/i_png.c
	src/i_system.c
	src/i_video.c
	src/i_xinput.c
	src/in_stuff.c
	src/info.c
	src/m_cheat.c
	src/m_fixed.c
	src/m_keys.c
	src/m_menu.c
	src/m_misc.c
	src/m_password.c
	src/m_random.c
	src/m_shift.c
	src/p_ceilng.c
	src/p_doors.c
	src/p_enemy.c
	src/p_floor.c
	src/p_inter.c
	src/p_lights.c
	src/p_macros.c
	src/p_map.c
	src/p_maputl.c
	src/p_mobj.c
	src/p_plats.c
	src/p_pspr.c
	src/p_saveg.c
	src/p_setup.c
	src/p_sight.c
	src/p_spec.c
	src/p_switch.c
	src/p_telept.c
	src/p_tick.c
	src/p_user.c
	src/psnprntf.c
	src/r_bsp.c
	src/r_clipper.c
	src/r_drawlist.c
	src/r_lights.c
	src/r_main.c
	src/r_scene.c
	src/r_sky.c
	src/r_things.c
	src/r_wipe.c
	src/s_sound.c
	src/sc_main.c
	src/st_stuff.c
	src/tables.c
	src/w_file.c
	src/w_merge.c
	src/w_wad.c
	src/wi_stuff.c
	src/z_zone.c
	src/Ext/md5.c
	src/Ext/ChocolateDoom/net_client.c
	src/Ext/ChocolateDoom/net_common.c
	src/Ext/ChocolateDoom/net_dedicated.c
	src/Ext/ChocolateDoom/net_io.c
	src/Ext/ChocolateDoom/net_loop.c
	src/Ext/ChocolateDoom/net_packet.c
	src/Ext/ChocolateDoom/net_query.c
	src/Ext/ChocolateDoom/net_sdl.c
	src/Ext/ChocolateDoom/net_server.c
	src/Ext/ChocolateDoom/net_structrw.c
)

if(MSVC)
target_link_libraries(doom64ex ${ZLIB_LIBRARY} ${PNG_LIBRARY} ${SDL_LIBRARY} ${FLUIDSYNTH_LIBRARIES} ${SDLNET_LIBRARY} ${OPENGL_LIBRARY})
else()
target_link_libraries(doom64ex ${ZLIB_LIBRARY} ${PNG_LIBRARY} ${SDL_LIBRARY} ${FLUIDSYNTH_LIBRARIES} ${SDLNET_LIBRARY} ${OPENGL_LIBRARY} m)
endif()
