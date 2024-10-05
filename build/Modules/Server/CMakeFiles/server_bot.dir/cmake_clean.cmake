file(REMOVE_RECURSE
  "libserver_bot.a"
  "libserver_bot.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/server_bot.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
