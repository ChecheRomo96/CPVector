# Cross-Platform Vector

Library for unifiying Vectors across multiple systems. CPVector::vector<> is based on std::vector<> class and uses it on desktop (*WIN32*, *_WIN32*, *__WIN32__*, *__APPLE__*, *linux*), These library contains a CMake build generation system. You can install the package with cmake to make it available in your system, also you can "add" this subdirectory with cmake to compile the library when building your project.

This library also complies with the Arduino Library Specification. To achieve this, a library.properties file has been included. Also there is a keywords.txt file so the IDE knows how to color keywords, examples are in the directory examples. The exaples are automatically discovered by Arduino IDE due to the file structure. Examples can also be compiled via cmake by adding the cache variable CPVECTOR_BUILD_EXAMPLES = ON.

List of platforms where it has been tested.

- Arduino IDE (AVR, ESP32)
- Windows (cl)
- Ubuntu (g++, clang++)
- Mac Os (g++, clang++)

# Docs:

Docs hosted at: https://checheromo96.github.io/CPVector/

#Introduction



# Steps to compile package:

## Mac Os X through CMake + make

1.- Clone or download the repo.

2.- Open terminal and go to the the download directory (Replace "<path_to_directory>" with the path to the directory you downloaded) 

    cd <path_to_directory>/CPVector

3.- Run 

	mkdir build && cd build

4.1.- To compile run: 
	
	cmake ..

4.2.- To compile examples and turn them into executables, run: 
	
	cmake .. -DBUILD_EXAMPLES="ON"

5.- Run 
	
	make	
	sudo make install

# Steps to uninstall package:

## Mac Os X

1.- Remove the following directories

	usr/local/lib/CPString
	usr/local/include/CPString

# Steps to install as an Arduino Library:

## a) download zip file

If you downlaoded the zip file containing this repository extract ists contents and move the CPVector_vX.X.X to your current Arduino Project library directory.

Even though you did not installed through git you can update the package through it.

## b) clone through git

Note that you must have git installed on your computer. 

### To istall git through homebrew on Mac Os X:

	brew install git

1.- Go to your current Arduino Project library directory replace <myArduinoProjectDirectory> with your directory path.

	cd <myArduinoProjectDirectory>/libraries

2.- Clone through git

	git clone https://github.com/ChecheRomo96/CPVector.git

3.- To update this repository, enter to the repository and pull the newer version

	cd CPString
	git pull