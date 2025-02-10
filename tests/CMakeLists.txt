set(SRGB2XYZ "srgb2xyz")

set(SRGB2XYZ_HEADER_FILES
)

set(SRGB2XYZ_SOURCE_FILES 
    SRGB2XYZ.cpp
)

add_executable(${SRGB2XYZ} 
    ${SRGB2XYZ_HEADER_FILES}
    ${SRGB2XYZ_SOURCE_FILES}
)

target_include_directories(${SRGB2XYZ} 
    PRIVATE lcms2
)

target_link_libraries(${SRGB2XYZ}
    PRIVATE lcms2      
)

target_compile_definitions(${SRGB2XYZ} PRIVATE CMAKE_EXPORT_COMPILE_COMMANDS=1)
