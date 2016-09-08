install(FILES CMakeLists.txt DESTINATION src)

set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/patch.xml")

include(CPack)
