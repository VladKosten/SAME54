
add_library(App STATIC app_startup.c)

target_include_directories(App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(App PRIVATE AtmelStart
                          PRIVATE freertos_kernel
                          PRIVATE freertos_confi
                          )

