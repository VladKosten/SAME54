add_subdirectory(CMSIS)

add_library(Device INTERFACE)

target_include_directories(Device INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include
                                  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include/component
                                  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include/instance
                                  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include/pio)

target_compile_definitions(Device INTERFACE ${MCU})

target_link_libraries(Device INTERFACE CMSIS)