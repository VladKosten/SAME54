add_library(CMSIS INTERFACE)

target_include_directories(CMSIS INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(CMSIS INTERFACE CompileOptions)