install(FILES never_overwrite.txt DESTINATION test1)
install(FILES permanent.txt DESTINATION test2)
install(FILES permanent_and_never_overwrite.txt DESTINATION test3)

set_property(INSTALL
  test1/never_overwrite.txt
  test3/permanent_and_never_overwrite.txt
  PROPERTY CPACK_NEVER_OVERWRITE ON
)

set_property(INSTALL
  test2/permanent.txt
  test3/permanent_and_never_overwrite.txt
  PROPERTY CPACK_PERMANENT ON
)

include(CPack)
