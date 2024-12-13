# Dependencies
add_library(${ENGINE_TARGET_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Vector3.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Vector3.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Ray.h
	
	${CMAKE_CURRENT_SOURCE_DIR}/include/Color.h

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Object.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${ENGINE_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(RAYLIB_VERSION 5.5)
set(RAYLIB_NAME raylib)
set(RAYLIB_CPP_NAME raylib_cpp)

include(FetchContent)

FetchContent_Declare(
    ${RAYLIB_NAME}
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

set(FETCHCONTENT_QUIET NO)
FetchContent_MakeAvailable(${RAYLIB_NAME})
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

# raylib-cpp
find_package(${RAYLIB_CPP_NAME} QUIET)
if (NOT ${RAYLIB_CPP_NAME}_FOUND)
    if (NOT DEFINED RAYLIB_CPP_VERSION)
        set(RAYLIB_CPP_VERSION next)
    endif()
    # include(FetchContent)
    FetchContent_Declare(
        ${RAYLIB_CPP_NAME}
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG ${RAYLIB_CPP_VERSION}
    )
    FetchContent_MakeAvailable(${RAYLIB_CPP_NAME})
endif()

target_link_libraries(${ENGINE_TARGET_NAME} PUBLIC ${RAYLIB_NAME} ${RAYLIB_CPP_NAME})

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
# CopyLibToTarget(${RAYLIB_CPP_NAME} ${ENGINE_TARGET_NAME})