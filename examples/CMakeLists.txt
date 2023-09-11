add_subdirectory(BuildConfiguration)
add_subdirectory(AppendingData)

if ( ${CPVECTOR_SORTING} )
	add_subdirectory(SortingData)
	add_subdirectory(SortingArray)
endif()