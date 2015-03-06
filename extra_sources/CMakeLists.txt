add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/patch.xml")

set(CPACK_WIX_EXTRA_SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/features.wxs"
	"${CMAKE_CURRENT_SOURCE_DIR}/extra.foo.wxs"
	"${CMAKE_CURRENT_SOURCE_DIR}/extra.bar.wxs"
)

include(CPack)
