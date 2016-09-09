cmake_minimum_required(VERSION 2.8.12)

project(CMakeWiXTestsuite)

enable_testing()

set(REFERENCE_CMAKE_BIN_DIR "$ENV{WIX_REFERENCE_CMAKE_BIN_DIR}"
	CACHE PATH "bin directory of the cmake build being tested")

function(add_packaging_test NAME)
    set(TEST_BUILD_DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/${NAME}")

    add_test(NAME "${NAME}"
        WORKING_DIRECTORY "${TEST_BUILD_DIRECTORY}"
        COMMAND "${CMAKE_COMMAND}"
        "-DTEST_NAME=${NAME}"
        "-DCMAKE_BIN_DIR=${REFERENCE_CMAKE_BIN_DIR}"
        "-DBIN_DIR=${TEST_BUILD_DIRECTORY}"
        "-DSRC_DIR=${CMAKE_CURRENT_SOURCE_DIR}/${NAME}"
        "-DINSTALLER_DIR=${CMAKE_CURRENT_BINARY_DIR}/installers"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/test_wrapper.cmake"
    )

    add_custom_target("${NAME}" SOURCES "${NAME}/CMakeLists.txt")
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

add_packaging_test(fragment_injection_with_bad_id)

set_property(TEST fragment_injection_with_bad_id
    PROPERTY PASS_REGULAR_EXPRESSION
    "Some XML patch fragments did not have matching IDs")

add_packaging_test(package_install_directory)
add_packaging_test(read_only)
add_packaging_test(rtf_writer_unicode)
add_packaging_test(package_registry)
add_packaging_test(package_registry2)
add_packaging_test(desktop_shortcut)
add_packaging_test(properties)
add_packaging_test(arp_properties)
add_packaging_test(product_fragment_injection)

add_packaging_test(property_start_menu_shortcuts)
add_packaging_test(property_desktop_shortcuts)
add_packaging_test(property_startup_shortcuts)

add_packaging_test(extra_sources)

add_packaging_test(custom_action_with_condition)
add_packaging_test(feature_ref_in_product)
add_packaging_test(feature_patch)
