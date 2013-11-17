# KexPlus Engine

KexPlus is a fork of the Doom64 EX source port engine that aims to provide a portable,
readable, and modern source port of Doom64. Compatibility with Doom64 is a priority,
however limit removing features, and new features for mappers, are planned for the future.

Currently the focus is on rewriting most of the code to C++11, LLVM-style, with doxygen style
comments. I want to modularize the source as much as possible, so as to be able to easily swap
out I/O libraries(video backend for renderer, input to game, sound output). An SDL2 port will be
made after, and then a libretro port. Once the initial libretro port is finished I can focus on
making the source more portable and on the fancier features.
