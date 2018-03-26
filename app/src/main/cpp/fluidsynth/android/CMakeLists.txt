cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

### INCLUDE OBOE LIBRARY ###

# Set the path to the Oboe library directory (may not exist yet)
set (OBOE_RELATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib-oboe)

# Get the absolute path to the Oboe library directory
get_filename_component(OBOE_DIR
                       ${OBOE_RELATIVE_PATH}
                       ABSOLUTE)

# If the Oboe library directory doesn't exist, clone it from github
if ((NOT EXISTS ${OBOE_DIR}) OR
    (NOT EXISTS ${OBOE_DIR}/CMakeLists.txt))
    message(FATAL_ERROR "Couldn't find lib-oboe sources. Aborting.")
endif()

# Add the Oboe library as a subproject. Since Oboe is an out-of-tree source library we must also
# specify a binary directory
add_subdirectory(${OBOE_DIR} ./oboe)

# Include the Oboe headers
include_directories(${OBOE_DIR}/include)

### END OBOE INCLUDE SECTION ###

set(src_DIR ../src)

set(fluidsynth_sources
        ${src_DIR}/midi/fluid_midi.c
        ${src_DIR}/midi/fluid_midi_router.c
        ${src_DIR}/midi/fluid_seq.c
        ${src_DIR}/midi/fluid_seqbind.c
        ${src_DIR}/rvoice/fluid_adsr_env.c
        ${src_DIR}/rvoice/fluid_chorus.c
        ${src_DIR}/rvoice/fluid_iir_filter.c
        ${src_DIR}/rvoice/fluid_lfo.c
        ${src_DIR}/rvoice/fluid_rev.c
        ${src_DIR}/rvoice/fluid_rvoice.c
        ${src_DIR}/rvoice/fluid_rvoice_dsp.c
        ${src_DIR}/rvoice/fluid_rvoice_event.c
        ${src_DIR}/rvoice/fluid_rvoice_mixer.c
        ${src_DIR}/sfloader/fluid_defsfont.c
        ${src_DIR}/sfloader/fluid_ramsfont.c
        ${src_DIR}/sfloader/fluid_sfont.c
        ${src_DIR}/synth/fluid_chan.c
        ${src_DIR}/synth/fluid_event.c
        ${src_DIR}/synth/fluid_gen.c
        ${src_DIR}/synth/fluid_mod.c
        ${src_DIR}/synth/fluid_synth.c
        ${src_DIR}/synth/fluid_tuning.c
        ${src_DIR}/synth/fluid_voice.c
        ${src_DIR}/synth/fluid_synth_monopoly.c
        ${src_DIR}/utils/fluid_conv.c
        ${src_DIR}/utils/fluid_hash.c
        ${src_DIR}/utils/fluid_list.c
        ${src_DIR}/utils/fluid_ringbuffer.c
        ${src_DIR}/utils/fluid_settings.c
        ${src_DIR}/bindings/fluid_filerenderer.c
        ${src_DIR}/drivers/fluid_adriver.c
        ${src_DIR}/drivers/fluid_opensles.c
        ${src_DIR}/drivers/oboe/OboeDriver.cpp
        ${src_DIR}/drivers/oboe/OboeDriverWrapper.cpp
        ${src_DIR}/drivers/oboe/OboeSynthesizer.cpp
        ${src_DIR}/utils/fluid_sys.c
        src/bindings/fluid_cmd.c
        src/drivers/fluid_mdriver.c
        ../../native-lib.cpp # This line needs to be removed; It's only for testing purposes
)

set ( public_main_HEADER
    ${CMAKE_BINARY_DIR}/include/fluidsynth.h
)

configure_file ( ../include/fluidsynth.cmake
                 ${public_main_HEADER} )

add_library(fluidsynth SHARED ${fluidsynth_sources})

if(ANDROID_ABI STREQUAL "armeabi-v7a")
        target_compile_options(fluidsynth PRIVATE -DWITH_FLOAT)
endif()
if(ANDROID_ABI STREQUAL "x86")
        target_compile_options(fluidsynth PRIVATE -DWITH_FLOAT)
endif()

# Specify directories which the compiler should look for headers
target_include_directories(fluidsynth PRIVATE
                            . include
                            ${src_DIR}/../include
                            ${src_DIR}/synth
                            ${src_DIR}/midi
                            ${src_DIR}/rvoice
                            ${src_DIR}/sfloader
                            ${src_DIR}/utils
                            ${src_DIR}/bindings
                            ${src_DIR}/drivers
                            ${CMAKE_BINARY_DIR}/include
                            )

target_include_directories(fluidsynth INTERFACE
                            . include
                            ${src_DIR}/../include
                            ${CMAKE_BINARY_DIR}/include
                            )

target_compile_options(fluidsynth
                            PRIVATE -Wall
                            PRIVATE -DHAVE_CONFIG_H
                            PRIVATE -Wno-unused-variable
                            PRIVATE "$<$<CONFIG:DEBUG>:-Werror>") # Only include -Werror when building debug config

target_link_libraries (fluidsynth OpenSLES log oboe)