add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(freertos_config INTERFACE AtmelStart)

target_compile_definitions(freertos_config  INTERFACE projCOVERAGE_TEST=0)


add_library(MiddlewareConfig INTERFACE)

target_include_directories(MiddlewareConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MiddlewareConfig INTERFACE freertos_kernel
                                       INTERFACE AtmelStart)


add_library(PiLinkConfig INTERFACE)

target_include_directories(PiLinkConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PiLinkConfig INTERFACE freertos_kernel
                                        INTERFACE AtmelStart)

add_library(FatFsConfig INTERFACE)

target_include_directories(FatFsConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FatFsConfig INTERFACE freertos_kernel
                                        INTERFACE AtmelStart)

add_library(ModbusServerConfig INTERFACE)

target_include_directories(ModbusServerConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ModbusServerConfig INTERFACE freertos_kernel
                                        INTERFACE AtmelStart)

add_library(ModbusClientConfig INTERFACE)

target_include_directories(ModbusClientConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ModbusClientConfig INTERFACE freertos_kernel
                                         INTERFACE AtmelStart)


add_library(PiTalkClientConfig INTERFACE)

target_include_directories(PiTalkClientConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PiTalkClientConfig INTERFACE freertos_kernel
                                        INTERFACE AtmelStart)


add_library(PiTalkPlayerClientConfig INTERFACE)

target_include_directories(PiTalkPlayerClientConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PiTalkPlayerClientConfig INTERFACE freertos_kernel
                                               INTERFACE AtmelStart)

add_library(PiTalkControlConfig INTERFACE)

target_include_directories(PiTalkControlConfig INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PiTalkControlConfig INTERFACE freertos_kernel
                                            INTERFACE AtmelStart)