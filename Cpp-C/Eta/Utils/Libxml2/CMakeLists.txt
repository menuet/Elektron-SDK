cmake_minimum_required(VERSION 2.8)
project(LibXml2)


set(
    LIBXML2_FILES
    "${PROJECT_SOURCE_DIR}/SAX.c"
    "${PROJECT_SOURCE_DIR}/entities.c"
    "${PROJECT_SOURCE_DIR}/encoding.c"
    "${PROJECT_SOURCE_DIR}/error.c"
    "${PROJECT_SOURCE_DIR}/parserInternals.c"
    "${PROJECT_SOURCE_DIR}/parser.c"
    "${PROJECT_SOURCE_DIR}/tree.c"
    "${PROJECT_SOURCE_DIR}/hash.c"
    "${PROJECT_SOURCE_DIR}/list.c"
    "${PROJECT_SOURCE_DIR}/xmlIO.c"
    "${PROJECT_SOURCE_DIR}/xmlmemory.c"
    "${PROJECT_SOURCE_DIR}/uri.c"
    "${PROJECT_SOURCE_DIR}/valid.c"
    "${PROJECT_SOURCE_DIR}/xlink.c"
    "${PROJECT_SOURCE_DIR}/HTMLparser.c"
    "${PROJECT_SOURCE_DIR}/HTMLtree.c"
    "${PROJECT_SOURCE_DIR}/debugXML.c"
    "${PROJECT_SOURCE_DIR}/xpath.c"
    "${PROJECT_SOURCE_DIR}/xpointer.c"
    "${PROJECT_SOURCE_DIR}/xinclude.c"
    "${PROJECT_SOURCE_DIR}/nanohttp.c"
    "${PROJECT_SOURCE_DIR}/nanoftp.c"
    "${PROJECT_SOURCE_DIR}/DOCBparser.c"
    "${PROJECT_SOURCE_DIR}/catalog.c"
    "${PROJECT_SOURCE_DIR}/globals.c"
    "${PROJECT_SOURCE_DIR}/threads.c"
    "${PROJECT_SOURCE_DIR}/c14n.c"
    "${PROJECT_SOURCE_DIR}/xmlstring.c"
    "${PROJECT_SOURCE_DIR}/xmlregexp.c"
    "${PROJECT_SOURCE_DIR}/xmlschemas.c"
    "${PROJECT_SOURCE_DIR}/xmlschemastypes.c"
    "${PROJECT_SOURCE_DIR}/xmlunicode.c"
    "${PROJECT_SOURCE_DIR}/xmlreader.c"
    "${PROJECT_SOURCE_DIR}/relaxng.c"
    "${PROJECT_SOURCE_DIR}/dict.c"
    "${PROJECT_SOURCE_DIR}/SAX2.c"
    "${PROJECT_SOURCE_DIR}/xmlwriter.c"
    "${PROJECT_SOURCE_DIR}/legacy.c"
    "${PROJECT_SOURCE_DIR}/chvalid.c"
    "${PROJECT_SOURCE_DIR}/pattern.c"
    "${PROJECT_SOURCE_DIR}/xmlsave.c"
    "${PROJECT_SOURCE_DIR}/xmlmodule.c"
    "${PROJECT_SOURCE_DIR}/schematron.c"
    "${PROJECT_SOURCE_DIR}/acconfig.h"
    "${PROJECT_SOURCE_DIR}/config.h"
    "${PROJECT_SOURCE_DIR}/elfgcchack.h"
    "${PROJECT_SOURCE_DIR}/libxml.h"
    "${PROJECT_SOURCE_DIR}/trio.h"
    "${PROJECT_SOURCE_DIR}/triodef.h"
    "${PROJECT_SOURCE_DIR}/trionan.h"
    "${PROJECT_SOURCE_DIR}/triop.h"
    "${PROJECT_SOURCE_DIR}/triostr.h"
    "${PROJECT_SOURCE_DIR}/include/win32config.h"
    "${PROJECT_SOURCE_DIR}/include/wsockcompat.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/DOCBparser.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/HTMLparser.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/HTMLtree.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/SAX.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/SAX2.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/c14n.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/catalog.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/chvalid.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/debugXML.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/dict.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/encoding.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/entities.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/globals.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/hash.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/list.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/nanoftp.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/nanohttp.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/parser.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/parserInternals.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/pattern.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/relaxng.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/schemasInternals.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/schematron.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/threads.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/tree.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/uri.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/valid.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xinclude.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xlink.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlIO.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlautomata.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlerror.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlexports.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlmemory.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlmodule.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlreader.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlregexp.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlsave.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlschemas.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlschemastypes.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlstring.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlunicode.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlversion.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xmlwriter.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xpath.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xpathInternals.h"
    "${PROJECT_SOURCE_DIR}/include/libxml/xpointer.h"
    )

set(
    LIBXML2_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/include"
    )

if(MSVC)
    set_source_files_properties("${PROJECT_SOURCE_DIR}/xmlIO.c" PROPERTIES COMPILE_FLAGS "/wd4996")
endif()

add_library(libxml2-shared SHARED ${LIBXML2_FILES})
target_compile_definitions(libxml2-shared PRIVATE ${ELEK_DEFINITIONS} _CRT_NO_POSIX_ERROR_CODES)
if(MSVC)
    target_compile_options(libxml2-shared PRIVATE ${ELEK_C_FLAGS} "/wd4244" "/wd4267" "/wd4311" "/wd4312")
else()
    target_compile_options(libxml2-shared PRIVATE ${ELEK_C_FLAGS})
endif()
target_include_directories(libxml2-shared PRIVATE ${LIBXML2_INCLUDE_DIRS})

add_library(libxml2-static STATIC ${LIBXML2_FILES})
target_compile_definitions(libxml2-static PRIVATE ${ELEK_DEFINITIONS} _CRT_NO_POSIX_ERROR_CODES)
if(MSVC)
    target_compile_options(libxml2-shared PRIVATE ${ELEK_C_FLAGS} "/wd4244" "/wd4267" "/wd4311" "/wd4312")
else()
    target_compile_options(libxml2-shared PRIVATE ${ELEK_C_FLAGS})
endif()
target_include_directories(libxml2-static PRIVATE ${LIBXML2_INCLUDE_DIRS})


