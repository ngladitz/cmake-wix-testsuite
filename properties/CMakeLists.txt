install(FILES never_overwrite.txt DESTINATION test1)
install(FILES permanent.txt DESTINATION test2)
install(FILES permanent_and_never_overwrite.txt DESTINATION test3)

set_property(CPACK
  test1/never_overwrite.txt
  test3/permanent_and_never_overwrite.txt
  PROPERTY NEVER_OVERWRITE ON
)

set_property(CPACK
  test2/permanent.txt
  test3/permanent_and_never_overwrite.txt
  PROPERTY PERMANENT ON
)

include(CPack)
