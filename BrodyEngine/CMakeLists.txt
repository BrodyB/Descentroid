# Dependencies
add_library(${ENGINE_TARGET_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
)

target_include_directories(${ENGINE_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(RAYLIB_VERSION 5.5)
set(RAYLIB_NAME raylib)

include(FetchContent)

FetchContent_Declare(
    ${RAYLIB_NAME}
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

set(FETCHCONTENT_QUIET NO)
FetchContent_MakeAvailable(${RAYLIB_NAME})
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

target_link_libraries(${ENGINE_TARGET_NAME} PUBLIC ${RAYLIB_NAME})

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
		POST_BUILD
		COMMAND
		${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:${LIB_NAME}>
		$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibToTarget(${RAYLIB_NAME} ${ENGINE_TARGET_NAME})