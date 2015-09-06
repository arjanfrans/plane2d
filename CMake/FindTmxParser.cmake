# Copyright (c) 2014 Andrew Kelley
# This file is MIT licensed.
# See http://opensource.org/licenses/MIT

# TMXPARSER_INCLUDE_DIR
# TMXPARSER_LIBRARY
# TMXPARSER_FOUND

find_path(TMXPARSER_INCLUDE_DIR NAMES tmxparser/Tmx.h
    PATHS
        ${PROJECT_SOURCE_DIR}/dependencies/tmxparser/include
        /usr/local/include/
        /usr/local/
        /usr/
)

find_library(TMXPARSER_LIBRARY NAMES tmxparser
    PATHS
        ${PROJECT_SOURCE_DIR}/dependencies/tmxparser
        ${PROJECT_SOURCE_DIR}/dependencies/tmxparser/build
        /usr/local
        /usr
)

if(TMXPARSER_LIBRARY)
  set(TMXPARSER_FOUND TRUE)
else()
  set(TMXPARSER_FOUND FALSE)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TMXPARSER DEFAULT_MSG TMXPARSER_LIBRARY TMXPARSER_INCLUDE_DIR)

mark_as_advanced(TMXPARSER_INCLUDE_DIR TMXPARSER_LIBRARY)
