add_library(UShellStartupConfig INTERFACE)

target_include_directories(UShellStartupConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(UShellStartupConfig INTERFACE UShellHalPort
                                          INTERFACE UShellOsalPort
                                          INTERFACE freertos_kernel
                                          INTERFACE AtmelStart)