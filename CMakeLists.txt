# First, we need to check the version of CMake. If the version is less than 3.12, we need to stop the compilation process.
cmake_minimum_required(VERSION 3.15)

# Include the CMake ARM GCC toolchain file.
include(gcc-arm-none-eabi.cmake)

# Set the project name and enable the C and ASM languages.
project(SAME54 C ASM)

# Export compile commands for the project.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the microcontroller.
set(MCU __SAME54P20A__)

# Set the linker script file.
set(LINKER_SCRIPT_FLASH ${PROJECT_SOURCE_DIR}/Device/same54p20a_flash.ld)

# Set the startup file.
set(STARTUP_SCRIPT ${PROJECT_SOURCE_DIR}/Device/startup_same54.c)

# Add interface library to set the compile and link options to all targets.
add_library(CompileOptions INTERFACE)

target_compile_options(CompileOptions INTERFACE -Wall                           # the compiler will output warnings for common programming errors
                                                # -Wextra                       # enables some extra warning flags that are not enabled by -Wall
                                                # -Wshadow                        # warn whenever a local variable or type declaration shadows another variable, parameter, type, class member
                                                #-Wdouble-promotion              # warn if a float is implicitly promoted to a double
                                                # -Wformat-truncation           # check calls to printf and scanf
                                                # -fno-common                     # In C, this option controls the placement of global variables defined without an initializer
                                                -mfloat-abi=softfp              # set the floating-point ABI
                                                -mfpu=fpv4-sp-d16               # set the floating-point unit
                                                -mcpu=cortex-m4                 # set the architecture
                                                -mthumb                         # generate code for the Thumb instruction set
                                                -std=gnu99
                                                --specs=nosys.specs
                                                $<$<CONFIG:Debug>:-O0 -g3 -ggdb3 -DDEBUG>
                                                $<$<CONFIG:Release>:-O3 -g0 -ggdb0 -DNDEBUG>
                                                $<$<CONFIG:MinSizeRel>:-Os -g0 -ggdb0 -DNDEBUG>
                                                $<$<CONFIG:RelWithDebInfo>:-O2 -g3 -ggdb3 -DNDEBUG>
                                                $<$<CONFIG:ReleaseForBootloader>:-O3 -g0 -ggdb0 -DNDEBUG>
                                                )

# Set the link options.
target_link_options(CompileOptions INTERFACE -T${LINKER_SCRIPT_FLASH}            # set the linker script
                                             -Wl,-Map=${CMAKE_PROJECT_NAME}.map  # generate a map file
                                             --specs=nosys.specs
                                             -Wl,--gc-sections                   # remove unused sections
                                             -Wl,--start-group                   # start a group of input sections
                                             -lnosys
                                             -Wl,--end-group                     # end a group of input sections
                                             -mcpu=cortex-m4
                                             -Wl,--print-memory-usage
                                             $<$<CONFIG:ReleaseForBootloader>: -Wl,--section-start=.text=0x2000>
                                             )            # print memory usage

# Include the Atmel Start framework.
include(AtmelStartFramework.cmake)

# Add the subdirectories to the project.
#add_subdirectory(Application)
add_subdirectory(config)
add_subdirectory(Device)
#add_subdirectory(Driver)
#add_subdirectory(Middleware)


# Add the Atmel Start library to the project.
add_library(AtmelStart STATIC   ${CMAKE_CURRENT_SOURCE_DIR}/atmel_start.c
                                ${CMAKE_CURRENT_SOURCE_DIR}/driver_init.c
                                ${PROJECT_SOURCE_DIR}/Device/system_same54.c)

target_include_directories(AtmelStart PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(AtmelStart PUBLIC AtmelStartFramework)

# Add the main library to the project.
add_library(Main STATIC ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

target_link_libraries(Main PRIVATE App)

# Add the executable target to the project.
add_executable(${CMAKE_PROJECT_NAME} ${STARTUP_SCRIPT})

# Add the library targets to the executable target.
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Main
                                            PUBLIC Device)

# Команда для конвертации ELF в BIN
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
                   COMMENT "Converting my_app.elf to my_app.bin")


# Команда для конвертации ELF в HEX
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
COMMENT "Converting my_app.elf to my_app.hex")