cmake_minimum_required(VERSION 2.6)
project(Doom64Ex)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL REQUIRED)
find_package(FluidSynth REQUIRED)
find_package(SDL_net REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/Ext ${FluidSynth_INCLUDE_DIR} ${SDL_INCLUDE_DIR} ${PNG_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

# Get around a issue
add_definitions(-Ddprintf=_dprintf -D__cdecl=)

if(APPLE)
	set(EXTRA_SOURCES Ext/SDLMain.m)
endif(APPLE)
if(MSVC)
	set(EXTRA_SOURCES i_exception.c i_opndir.c i_cpu.c)
else (MSVC)
	set(EXTRA_SOURCES i_cpu_posix.c)
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
	OUTPUT_FILE version.h
)

add_executable(doom64ex
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
	g_game.c
	g_settings.c
	gl_draw.c
	gl_main.c
	gl_texture.c
	i_audio.c
#	i_cpu.c
#	i_cpu_posix.c
#	i_exception.c
	i_main.c
#	i_opndir.c
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

target_link_libraries(doom64ex ${ZLIB_LIBRARY} ${PNG_LIBRARY} ${SDL_LIBRARY} ${FLUIDSYNTH_LIBRARIES} ${SDLNET_LIBRARY} ${OPENGL_LIBRARY})
