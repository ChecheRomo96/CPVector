add_subdirectory(1_BuildTest)
add_subdirectory(2_AppendingData)
add_subdirectory(3_MemoryLeakCheck)

if ( ${CPVECTOR_SORTING_ENABLED} )
	add_subdirectory(4_SortingData)
	add_subdirectory(5_SortingArray)
endif()
