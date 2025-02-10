cmake_minimum_required(VERSION 3.26)

project(lcms2cmake VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# set(BUILD_SHARED_LIBS OFF CACHE BOOL "do not build shared libraries" FORCE)
# add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
# add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

if (WIN32)
    add_compile_definitions(NOMINMAX)
endif(WIN32)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO  "${CMAKE_BINARY_DIR}/bin")

set(LCMS2CMAKE "lcms2")
set(LITTLE_CMS2_SRC_PATH "${CMAKE_SOURCE_DIR}/Little-CMS" CACHE BOOL "path to Little CMS2 source" FORCE)

message(STATUS "LITTLE_CMS2 SOURCE DIR: " ${LITTLE_CMS2_SRC_PATH})

set(LITTLE_CMS2_INCLUDE "${LITTLE_CMS2_SRC_PATH}/include")
set(LITTLE_CMS2_SOURCE "${LITTLE_CMS2_SRC_PATH}/src")

set(LCMS2_HEADER_FILES
    ${LITTLE_CMS2_INCLUDE}/lcms2_plugin.h
    ${LITTLE_CMS2_INCLUDE}/lcms2.h
)

set(LCMS2_SOURCE_FILES
    ${LITTLE_CMS2_SOURCE}/cmsalpha.c
    ${LITTLE_CMS2_SOURCE}/cmscam02.c
    ${LITTLE_CMS2_SOURCE}/cmscgats.c
    ${LITTLE_CMS2_SOURCE}/cmscnvrt.c
    ${LITTLE_CMS2_SOURCE}/cmserr.c
    ${LITTLE_CMS2_SOURCE}/cmsgamma.c
    ${LITTLE_CMS2_SOURCE}/cmsgmt.c
    ${LITTLE_CMS2_SOURCE}/cmshalf.c
    ${LITTLE_CMS2_SOURCE}/cmsintrp.c
    ${LITTLE_CMS2_SOURCE}/cmsio0.c
    ${LITTLE_CMS2_SOURCE}/cmsio1.c
    ${LITTLE_CMS2_SOURCE}/cmslut.c
    ${LITTLE_CMS2_SOURCE}/cmsmd5.c
    ${LITTLE_CMS2_SOURCE}/cmsmtrx.c
    ${LITTLE_CMS2_SOURCE}/cmsnamed.c
    ${LITTLE_CMS2_SOURCE}/cmsopt.c
    ${LITTLE_CMS2_SOURCE}/cmspack.c
    ${LITTLE_CMS2_SOURCE}/cmspcs.c
    ${LITTLE_CMS2_SOURCE}/cmsplugin.c
    ${LITTLE_CMS2_SOURCE}/cmsps2.c
    ${LITTLE_CMS2_SOURCE}/cmssamp.c
    ${LITTLE_CMS2_SOURCE}/cmssm.c
    ${LITTLE_CMS2_SOURCE}/cmstypes.c
    ${LITTLE_CMS2_SOURCE}/cmsvirt.c
    ${LITTLE_CMS2_SOURCE}/cmswtpnt.c
    ${LITTLE_CMS2_SOURCE}/cmsxform.c
)

add_library(${LCMS2CMAKE} STATIC 
    ${LCMS2_HEADER_FILES}
    ${LCMS2_SOURCE_FILES}
)

target_include_directories(${LCMS2CMAKE}
    PRIVATE ${LITTLE_CMS2_INCLUDE}
    PUBLIC $<BUILD_INTERFACE:${LITTLE_CMS2_INCLUDE}>   
)

set_target_properties(${LCMS2CMAKE} PROPERTIES LINKER_LANGUAGE C)

add_subdirectory(tests)