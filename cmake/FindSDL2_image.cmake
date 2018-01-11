# Locate SDL_image library
#
# This module defines:
#  SDL2_IMAGE_LIBRARY, the name of the library to link against
#  SDL2_IMAGE_INCLUDE_DIR, where to find the headers
#  SDL2_IMAGE_FOUND, if false, do not try to link against
#  SDL2_IMAGE_VERSION_STRING - human-readable string containing the version of SDL_image
#
# For backward compatibility the following variables are also set:
#  SDLIMAGE_LIBRARY (same value as SDL2_IMAGE_LIBRARY)
#  SDLIMAGE_INCLUDE_DIR (same value as SDL2_IMAGE_INCLUDE_DIR)
#  SDLIMAGE_FOUND (same value as SDL2_IMAGE_FOUND)
#
# $SDL2DIR is an environment variable that would correspond to the
# ./configure --prefix=$SDL2DIR used in building SDL2.
#
# Created by Eric Wing.  This was influenced by the FindSDL.cmake
# module, but with modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).
#
#=============================================================================
# Copyright 2005-2009 Kitware, Inc.
# Copyright 2012 Benjamin Eikel
#
# This software is distributed under the OSI-approved
# BSD License (the "License");
#
# CMake - Cross Platform Makefile Generator
# Copyright 2000-2016 Kitware, Inc.
# Copyright 2000-2011 Insight Software Consortium
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
#
# * Neither the names of Kitware, Inc., the Insight Software Consortium,
#   nor the names of their contributors may be used to endorse or promote
#   products derived from this software without specific prior written
#   permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# ------------------------------------------------------------------------------
#
# CMake was initially developed by Kitware with the following sponsorship:
#
#  * National Library of Medicine at the National Institutes of Health
#    as part of the Insight Segmentation and Registration Toolkit (ITK).
#
#  * US National Labs (Los Alamos, Livermore, Sandia) ASC Parallel
#    Visualization Initiative.
#
#  * National Alliance for Medical Image Computing (NAMIC) is funded by the
#    National Institutes of Health through the NIH Roadmap for Medical Research,
#    Grant U54 EB005149.
#
#  * Kitware, Inc.
#
#=============================================================================
# (To distribute this file outside of CMake, include the full
#  License text provided above.)

#message("<FindSDL2_image.cmake> Start.")

set(SDL2_IMAGE_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        ${SDL2_PATH}
        )

#message("SDL2_IMAGE_PATH: " ${SDL2_IMAGE_PATH})
#message("SDL2_IMAGE_SEARCH_PATHS: " ${SDL2_IMAGE_SEARCH_PATHS})
#
#foreach(iter ${SDL2_IMAGE_SEARCH_PATHS})
#    message("   Image search path element:" ${iter})
#endforeach()

find_path(SDL2_IMAGE_INCLUDE_DIRS SDL_image.h
        HINTS
            ${SDL2}
            ENV SDL2IMAGEDIR
            ENV SDL2DIR
        PATH_SUFFIXES
            include/SDL2
            include
            SDL2
        PATHS
            ${SDL2_IMAGE_SEARCH_PATHS}
        )

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VC_LIB_PATH_SUFFIX lib/x64)
else()
    set(VC_LIB_PATH_SUFFIX lib/x86)
endif()

find_library(SDL2_IMAGE_LIBRARIES
        NAMES
            SDL2_image
        HINTS
            ${SDL2}
            ENV SDL2IMAGEDIR
            ENV SDL2DIR
        PATH_SUFFIXES
            lib
            lib64
            ${VC_LIB_PATH_SUFFIX}
        PATHS
            ${SDL2_IMAGE_PATH}
        )

if(SDL2_IMAGE_INCLUDE_DIRS AND EXISTS "${SDL2_IMAGE_INCLUDE_DIRS}/SDL_image.h")
    file(STRINGS "${SDL2_IMAGE_INCLUDE_DIRS}/SDL_image.h" SDL2_IMAGE_VERSION_MAJOR_LINE REGEX "^#define[ \t]+SDL_IMAGE_MAJOR_VERSION[ \t]+[0-9]+$")
    file(STRINGS "${SDL2_IMAGE_INCLUDE_DIRS}/SDL_image.h" SDL2_IMAGE_VERSION_MINOR_LINE REGEX "^#define[ \t]+SDL_IMAGE_MINOR_VERSION[ \t]+[0-9]+$")
    file(STRINGS "${SDL2_IMAGE_INCLUDE_DIRS}/SDL_image.h" SDL2_IMAGE_VERSION_PATCH_LINE REGEX "^#define[ \t]+SDL_IMAGE_PATCHLEVEL[ \t]+[0-9]+$")
    string(REGEX REPLACE "^#define[ \t]+SDL_IMAGE_MAJOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_IMAGE_VERSION_MAJOR "${SDL2_IMAGE_VERSION_MAJOR_LINE}")
    string(REGEX REPLACE "^#define[ \t]+SDL_IMAGE_MINOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_IMAGE_VERSION_MINOR "${SDL2_IMAGE_VERSION_MINOR_LINE}")
    string(REGEX REPLACE "^#define[ \t]+SDL_IMAGE_PATCHLEVEL[ \t]+([0-9]+)$" "\\1" SDL2_IMAGE_VERSION_PATCH "${SDL2_IMAGE_VERSION_PATCH_LINE}")
    set(SDL2_IMAGE_VERSION_STRING ${SDL2_IMAGE_VERSION_MAJOR}.${SDL2_IMAGE_VERSION_MINOR}.${SDL2_IMAGE_VERSION_PATCH})
    unset(SDL2_IMAGE_VERSION_MAJOR_LINE)
    unset(SDL2_IMAGE_VERSION_MINOR_LINE)
    unset(SDL2_IMAGE_VERSION_PATCH_LINE)
    unset(SDL2_IMAGE_VERSION_MAJOR)
    unset(SDL2_IMAGE_VERSION_MINOR)
    unset(SDL2_IMAGE_VERSION_PATCH)
endif()

set(SDL2_IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARIES})
set(SDL2_IMAGE_INCLUDE_DIR ${SDL2_IMAGE_INCLUDE_DIRS})

include(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image
        REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR
        VERSION_VAR SDL2_IMAGE_VERSION_STRING)

# for backward compatibility
set(SDLIMAGE_LIBRARY ${SDL2_IMAGE_LIBRARY})
set(SDLIMAGE_INCLUDE_DIR ${SDL2_IMAGE_INCLUDE_DIR})
set(SDLIMAGE_FOUND ${SDL2_IMAGE_FOUND})

mark_as_advanced(SDL2_IMAGE_LIBRARIES SDL2_IMAGE_INCLUDE_DIRS)
