cmake_minimum_required(VERSION 2.8.12)

project(CMakeWiXTestsuite)

enable_testing()

set(REFERENCE_CMAKE_BIN_DIR "C:/Users/ngladitz/src/git/cmake-build/bin" 
	CACHE PATH "bin directory of the cmake build being tested")

function(add_generator_specific_packaging_test NAME GENERATOR)
	set(TEST_BUILD_DIRECTORY 
		"${CMAKE_CURRENT_BINARY_DIR}/${NAME}/${GENERATOR}")

    add_test(NAME "test-${NAME}-${GENERATOR}"
		WORKING_DIRECTORY "${TEST_BUILD_DIRECTORY}"
		COMMAND "${CMAKE_COMMAND}" 
        "-DTEST_NAME=${NAME}"
		"-DCMAKE_BIN_DIR=${REFERENCE_CMAKE_BIN_DIR}"
		"-DBIN_DIR=${TEST_BUILD_DIRECTORY}"
		"-DSRC_DIR=${CMAKE_CURRENT_SOURCE_DIR}/${NAME}"
        "-DGENERATOR=${GENERATOR}"
        "-DINSTALLER_DIR=${CMAKE_CURRENT_BINARY_DIR}/installers"
		-P "${CMAKE_CURRENT_SOURCE_DIR}/test_wrapper.cmake"
	)

    add_custom_target("${NAME}-${GENERATOR}" SOURCES "${NAME}/CMakeLists.txt")
endfunction()

function(add_packaging_test NAME)
    add_generator_specific_packaging_test("${NAME}" WIX)
    #add_generator_specific_packaging_test("${NAME}" NSIS)
endfunction()

add_custom_target(test_wrapper SOURCES test_wrapper.cmake)

add_packaging_test(basic)
add_packaging_test(space_in_path)
add_packaging_test(umlaut_in_path)
add_packaging_test(wix_cultures)
add_packaging_test(package_executables)
add_packaging_test(components)
add_packaging_test(two_components)
add_packaging_test(custom_template_in_module_path)
add_packaging_test(custom_template_by_variable)
add_packaging_test(ui_bitmaps_and_icon)
add_packaging_test(custom_program_menu_folder)
add_packaging_test(wix_util_extension)
add_packaging_test(fragment_injection)
add_packaging_test(package_install_directory)
