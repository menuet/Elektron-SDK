cmake_minimum_required(VERSION 2.8)
project(Eta)


##############################
# stubs

set(
    ETA_STUBS_FILES
    "${PROJECT_SOURCE_DIR}/CodecStubs/data_stubs.c"
    "${PROJECT_SOURCE_DIR}/CodecStubs/message_stubs.c"
    "${PROJECT_SOURCE_DIR}/TransportStubs/transport_stubs.c"
    "${PROJECT_SOURCE_DIR}/../Include/Transport/rtr/rsslTransport.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/os.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslAckMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslArray.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslCloseMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslDataDictionary.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslDataPackage.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslDataTypeEnums.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslDataUtils.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslDateTime.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslElementList.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslFieldList.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslFilterList.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslGenericMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslIterators.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMap.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMessagePackage.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMsgBase.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMsgDecoders.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMsgEncoders.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslMsgKey.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslPostMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslPrimitiveDecoders.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslPrimitiveEncoders.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslQos.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslRDM.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslReal.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslRefreshMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslRequestMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslRetCodes.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslRmtes.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslSeries.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslSetData.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslState.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslStatusMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslTypes.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslUpdateMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslVector.h"
	)

set(
    ETA_STUBS_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/../Include/Codec"
    "${PROJECT_SOURCE_DIR}/../Include/Transport"
	)

add_library(stubs-shared SHARED ${ETA_STUBS_FILES})
target_compile_definitions(stubs-shared PRIVATE RSSL_EXPORTS WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_compile_definitions(stubs-shared INTERFACE RSSL_IMPORTS)
target_include_directories(stubs-shared PRIVATE ${ETA_STUBS_INCLUDE_DIRS})

add_library(stubs-static STATIC ${ETA_STUBS_FILES})
target_compile_definitions(stubs-static PRIVATE WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_include_directories(stubs-static PRIVATE ${ETA_STUBS_INCLUDE_DIRS})


##############################
# cachestubs

set(
    ETA_CACHESTUBS_FILES
    "${PROJECT_SOURCE_DIR}/CacheStubs/cache_stubs.c"
    "${PROJECT_SOURCE_DIR}/../Include/Codec/rtr/rsslVector.h"
    "${PROJECT_SOURCE_DIR}/../Include/Cache/rtr/rsslCacheDefs.h"
    "${PROJECT_SOURCE_DIR}/../Include/Cache/rtr/rsslCacheError.h"
    "${PROJECT_SOURCE_DIR}/../Include/Cache/rtr/rsslPayloadCache.h"
    "${PROJECT_SOURCE_DIR}/../Include/Cache/rtr/rsslPayloadCacheConfig.h"
    "${PROJECT_SOURCE_DIR}/../Include/Cache/rtr/rsslPayloadCursor.h"
    "${PROJECT_SOURCE_DIR}/../Include/Cache/rtr/rsslPayloadEntry.h"
	)

set(
    ETA_CACHESTUBS_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/../Include/Codec"
    "${PROJECT_SOURCE_DIR}/../Include/Transport"
    "${PROJECT_SOURCE_DIR}/../Include/Cache"
    "${PROJECT_SOURCE_DIR}/../Include/Util"
	)

add_library(cachestubs-shared SHARED ${ETA_CACHESTUBS_FILES})
target_compile_definitions(cachestubs-shared PRIVATE RSSL_VA_EXPORTS WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_compile_definitions(cachestubs-shared INTERFACE RSSL_VA_IMPORTS)
target_include_directories(cachestubs-shared PRIVATE ${ETA_CACHESTUBS_INCLUDE_DIRS})
target_link_libraries(cachestubs-shared PUBLIC stubs-shared)

add_library(cachestubs-static STATIC ${ETA_CACHESTUBS_FILES})
target_compile_definitions(cachestubs-static PRIVATE WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_include_directories(cachestubs-static PRIVATE ${ETA_CACHESTUBS_INCLUDE_DIRS})
target_link_libraries(cachestubs-static PUBLIC stubs-static)


##############################
# va

set(
    ETA_VA_FILES
    "${PROJECT_SOURCE_DIR}/Util/rsslMemoryBuffer.c"
    "${PROJECT_SOURCE_DIR}/Util/rsslHashTable.c"
    "${PROJECT_SOURCE_DIR}/Util/DllVAMain.c"
    "${PROJECT_SOURCE_DIR}/RDM/rsslRDMDictionaryMsg.c"
    "${PROJECT_SOURCE_DIR}/RDM/rsslRDMDirectoryMsg.c"
    "${PROJECT_SOURCE_DIR}/RDM/rsslRDMLoginMsg.c"
    "${PROJECT_SOURCE_DIR}/RDM/rsslRDMQueueMsg.c"
    "${PROJECT_SOURCE_DIR}/Reactor/rsslReactorWorker.c"
    "${PROJECT_SOURCE_DIR}/Reactor/rsslReactor.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/bufferPool.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/tunnelManager.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/msgQueueEncDec.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/persistFile.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rsslRDMQueueMsgInt.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rsslTunnelStream.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/tunnelStreamImpl.c"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/tunnelSubstream.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rsslWatchlistImpl.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlPostIdTable.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlBase.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlDirectory.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlItem.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlLogin.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlMsgReorderQueue.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlService.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlServiceCache.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlSymbolList.c"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/wlView.c"
    "${PROJECT_SOURCE_DIR}/../Include/Util/rtr/rsslEventSignal.h"
    "${PROJECT_SOURCE_DIR}/../Include/Util/rtr/rsslMemoryBuffer.h"
    "${PROJECT_SOURCE_DIR}/../Include/Util/rtr/rsslHashTable.h"
    "${PROJECT_SOURCE_DIR}/../Include/Util/rtr/rsslQueue.h"
    "${PROJECT_SOURCE_DIR}/../Include/Util/rtr/rsslThread.h"
    "${PROJECT_SOURCE_DIR}/../Include/Util/rtr/rsslErrorInfo.h"
    "${PROJECT_SOURCE_DIR}/../Include/RDM/rtr/rsslRDMMsgBase.h"
    "${PROJECT_SOURCE_DIR}/../Include/RDM/rtr/rsslRDMMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/RDM/rtr/rsslRDMDictionaryMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/RDM/rtr/rsslRDMDirectoryMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/RDM/rtr/rsslRDMLoginMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/RDM/rtr/rsslRDMQueueMsg.h"
    "${PROJECT_SOURCE_DIR}/../Include/Reactor/rtr/rsslClassOfService.h"
    "${PROJECT_SOURCE_DIR}/../Include/Reactor/rtr/rsslReactorEvents.h"
    "${PROJECT_SOURCE_DIR}/../Include/Reactor/rtr/rsslReactorChannel.h"
    "${PROJECT_SOURCE_DIR}/../Include/Reactor/rtr/rsslReactor.h"
    "${PROJECT_SOURCE_DIR}/../Include/Reactor/rtr/rsslTunnelStream.h"
    "${PROJECT_SOURCE_DIR}/Reactor/rtr/rsslReactorEventsImpl.h"
    "${PROJECT_SOURCE_DIR}/Reactor/rtr/rsslReactorEventQueue.h"
    "${PROJECT_SOURCE_DIR}/Reactor/rtr/rsslReactorImpl.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/bufferPool.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/msgQueueEncDec.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/msgQueueHeader.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/msgQueueSubstreamHeader.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/msgQueueTimeoutCodes.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/persistFile.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/rsslRDMQueueMsgInt.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/tunnelManager.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/tunnelManagerImpl.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/tunnelStreamImpl.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/tunnelStreamReturnCodes.h"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream/rtr/tunnelSubstream.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Util/rtr/rsslReactorUtils.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/rsslWatchlist.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/rsslWatchlistImpl.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlPostIdTable.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlBase.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlDirectory.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlItem.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlLogin.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlMsgReorderQueue.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlService.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlServiceCache.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlStream.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlSymbolList.h"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist/rtr/wlView.h"
    )

set(
    ETA_VA_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}/../Include/Codec"
    "${PROJECT_SOURCE_DIR}/../Include/Transport"
    "${PROJECT_SOURCE_DIR}/../Include/Util"
    "${PROJECT_SOURCE_DIR}/../Include/RDM"
    "${PROJECT_SOURCE_DIR}/../Include/Reactor"
    "${PROJECT_SOURCE_DIR}/Reactor/Watchlist"
    "${PROJECT_SOURCE_DIR}/Reactor/Util"
    "${PROJECT_SOURCE_DIR}/Reactor/TunnelStream"
    "${PROJECT_SOURCE_DIR}/Reactor"
	)

add_library(va-shared SHARED ${ETA_VA_FILES})
target_compile_definitions(va-shared PRIVATE RSSL_VA_EXPORTS WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_compile_definitions(va-shared INTERFACE RSSL_VA_IMPORTS)
target_include_directories(va-shared PRIVATE ${ETA_VA_INCLUDE_DIRS})
target_link_libraries(va-shared PUBLIC stubs-shared ws2_32)

add_library(va-static STATIC ${ETA_VA_FILES})
target_compile_definitions(va-static PRIVATE WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_include_directories(va-static PRIVATE ${ETA_VA_INCLUDE_DIRS})
target_link_libraries(va-static PUBLIC stubs-static ws2_32)

