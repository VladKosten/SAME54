add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(freertos_config INTERFACE AtmelStart)

target_compile_definitions(freertos_config  INTERFACE projCOVERAGE_TEST=0)

# Select the heap port
set(FREERTOS_HEAP "4" CACHE STRING "" FORCE)
message(STATUS "Setting FREERTOS_HEAP=${FREERTOS_HEAP}")
# Select the native compile PORT
set(FREERTOS_PORT "GCC_ARM_CM4F" CACHE STRING "" FORCE)
message(STATUS "UNIX, setting FREERTOS_PORT=${GCC_ARM_CM4F}")
# And make it available