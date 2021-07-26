# Store this directory as a variable called ESTRING_SRC_DIRECTORY to reference in deeper directories
set(EVECTOR_SRC_DIRECTORY  ${CMAKE_CURRENT_LIST_DIR})

# Create the EString library (STATIC is not justified tho) and include the directories needed to compile
add_library(EVector INTERFACE)
target_include_directories(EVector INTERFACE ${EVECTOR_SRC_DIRECTORY})