add_executable("h w" "h w.cpp")
install(TARGETS "h w" DESTINATION "my bin")

install(FILES "h w.cpp" DESTINATION "my src")

include(CPack)