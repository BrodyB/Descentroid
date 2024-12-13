# Our Project
add_executable(${GAME_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug/TestWorld.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/debug/TestWorld.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug/CrashTestActor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/debug/CrashTestActor.cpp

    # ${CMAKE_CURRENT_SOURCE_DIR}/include/PlayerShip.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/PlayerShip.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug/Grid3DActor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/debug/Grid3DActor.cpp
)

target_include_directories(${GAME_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#set(raylib_VERBOSE 1)
target_link_libraries(${GAME_TARGET_NAME} PUBLIC
    ${RAYLIB_NAME}
    ${ENGINE_TARGET_NAME}
)


function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
		POST_BUILD
		COMMAND
		${CMAKE_COMMAND} -E copy_directory
		$<TARGET_FILE_DIR:${LIB_NAME}>
		$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibDirToTarget(${ENGINE_TARGET_NAME} ${GAME_TARGET_NAME})


# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${GAME_TARGET_NAME} PROPERTIES SUFFIX ".html") # Tell Emscripten to build an example.html file.
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${GAME_TARGET_NAME} "-framework IOKit")
    target_link_libraries(${GAME_TARGET_NAME} "-framework Cocoa")
    target_link_libraries(${GAME_TARGET_NAME} "-framework OpenGL")
endif()

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
	TARGET ${GAME_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	${RESOURCE_SRC_DIR}
	$<TARGET_FILE_DIR:${GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
	"config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)