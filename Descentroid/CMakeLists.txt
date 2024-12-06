# Our Project
add_executable(${GAME_TARGET_NAME}
    "../main.cpp"
)

#set(raylib_VERBOSE 1)
target_link_libraries(${GAME_TARGET_NAME} raylib)