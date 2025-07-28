cmake_minimum_required(VERSION 3.10)
project(APE VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(APE SHARED
    src/SDL2/APE_SDL2_Window.cpp
    src/APE_Color.cpp
    src/APE_Structure.cpp
    src/APE_Window.cpp
    src/APE.cpp
)

target_include_directories(APE
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
        $<INSTALL_INTERFACE:includes>
)

# Package stuff

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
target_include_directories(APE PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_LIBRARIES})

pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
target_include_directories(APE PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_IMAGE_LIBRARIES})

pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
target_include_directories(APE PRIVATE ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_TTF_LIBRARIES})

pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
target_include_directories(APE PRIVATE ${SDL2_MIXER_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_MIXER_LIBRARIES})

pkg_check_modules(SDL2_GFX REQUIRED SDL2_gfx)
target_include_directories(APE PRIVATE ${SDL2_GFX_INCLUDE_DIRS})
target_link_libraries(APE PRIVATE ${SDL2_GFX_LIBRARIES})


install(TARGETS APE
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY includes/
    DESTINATION includes
)

add_executable(SurvivalGame
    examples/SurvivalGame/Game.cpp
)

target_link_libraries(SurvivalGame PRIVATE APE)