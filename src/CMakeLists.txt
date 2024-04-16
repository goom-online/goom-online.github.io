set(TARGET_NAME ${PROJECT_NAME})

add_executable(${TARGET_NAME}
	main.c
)

add_dependencies(${TARGET_NAME} goom)

#target_compile_options(${TARGET_NAME} PRIVATE "-msimd128")

target_link_options(${TARGET_NAME} PRIVATE "--closure 1" "-sMALLOC=emmalloc" "-sINITIAL_MEMORY=33554432" "-sSINGLE_FILE" "-sENVIRONMENT=web" "-sFILESYSTEM=0" "-flto")

#target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_BINARY_DIR}/ext/goom2k4-0-nologo/include/)
#target_link_directories(${TARGET_NAME} PRIVATE ${CMAKE_BINARY_DIR}/ext/goom2k4-0-nologo/lib)
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ext/goom2k4-0-nologo/include)
target_link_libraries(${TARGET_NAME} goom)
