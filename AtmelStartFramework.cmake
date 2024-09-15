
file(GLOB_RECURSE HalSource ${CMAKE_CURRENT_SOURCE_DIR}/hal/*.c)

file(GLOB_RECURSE HplSource ${CMAKE_CURRENT_SOURCE_DIR}/hpl/*.c)

file(GLOB_RECURSE HriSource ${CMAKE_CURRENT_SOURCE_DIR}/hri/*.c)

add_library(AtmelStartFramework STATIC  ${HalSource}
                                        ${HplSource}
                                        ${HriSource})

target_include_directories(AtmelStartFramework  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hal/include/
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hal/utils/include/
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hri/
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/core
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/dmac
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/gclk/
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/pm
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/tc
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/port
                                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpl/wdt)

target_link_libraries(AtmelStartFramework PUBLIC AtmelStartConfig
                                          PUBLIC Device
                                          PUBLIC CompileOptions)