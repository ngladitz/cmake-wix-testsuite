install(FILES icon.ico DESTINATION .)

set(MY_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")

configure_file(patch.xml.in patch.xml)

set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_BINARY_DIR}/patch.xml")

set(CPACK_WIX_PROPERTY_ARPPRODUCTICON "my_icon_id")

include(CPack)
