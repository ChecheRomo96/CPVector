# CPVector: Cross-Platform vector

CPVector is a library that provides an encapsulation for the `std::vector` class, enabling the implementation of the same functionality across various platforms in a unified manner. This library has been developed with the purpose of achieving cross-compatibility in different programming environments, while offering a familiar and user-friendly interface.

## Repository Structure

This repository serves as the primary repository for the CPVector project. It's worth noting that CPVector has been organized into separate repositories to structure the files by compatibility and to adhere to specific standards in each of its applications. Additional repositories include:

- [CPVector-Arduino](https://github.com/ChecheRomo96/CPVector-Arduino): Optimized and tested for use in Arduino projects.
- [CPVector-CMake](https://github.com/ChecheRomo96/CPVector-CMake): Provides a directory structure and CMake files to facilitate integration into larger projects.

## Key Features

- **Cross-Platform Compatibility:** CPVector is designed to work on different platforms, meaning you can write code that uses the `std::vector` functionality and run it on multiple environments without worrying about implementation differences.

- **Ease of Use:** By using the same interface as `std::vector`, developers familiar with C++'s Standard Template Library (STL) will find it comfortable to work with CPVector.

- **Integration with CMake:** The directory and CMake files are included in the repository, making it easier to compile and use in larger projects.

- **Arduino Support:** CPVector has been optimized and tested for use in Arduino projects, making it an excellent choice for those seeking compatibility with this platform.

- **Dynamic Documentation:** The documentation may vary depending on the configuration of the package compilation, ensuring that it remains accurate and relevant to the specific build.

- **Clear Documentation:** The library's documentation has been generated using Doxygen, making it easier to understand the provided functions, methods, and classes by CPVector.

## Tested Platforms

CPVector has been tested on the following platforms:

- Arduino IDE:
  - AVR (e.g., Arduino Uno, Arduino Mega, etc.) (using C)
  - ESP32 (using C, C++, and std::vector<>)

- Windows:
  - Compiled using Visual C++ (cl) (using std::vector<>)

- Ubuntu:
  - Compiled using g++ (using std::vector<>)
  - Compiled using clang++ (using std::vector<>)

- Raspbian:
  - Compiled using g++ (using std::vector<>)
  - Compiled using clang++ (using std::vector<>)

- macOS:
  - Compiled using g++ (using std::vector<>)
  - Compiled using clang++ (using std::vector<>)

## Online Documentation

CPVector features comprehensive online documentation, generated using Doxygen. This documentation provides in-depth insights into the functions, methods, classes, and usage examples offered by the library.

To access the online documentation, visit the [CPVector Documentation](https://checheromo96.github.io/CPVector_Arduino/index.html) website.

The online documentation serves as a valuable resource for understanding and effectively utilizing CPVector in your projects.

## Quick Start

Please note that the main repository houses all essential files compatible with various platforms and filesystems, including implementations for diverse environments such as Arduino, Windows, Ubuntu, and macOS.

- If your primary focus is integrating CPVector seamlessly with CMake, you'll find dedicated resources in the CPVector-CMake repository. Here, you'll discover a structured directory layout and CMake files tailored to simplify CPVector integration into larger projects.

- For projects centered around Arduino, we recommend exploring the CPVector-Arduino repository. This repository has been specifically designed with a file structure optimized for Arduino development.

Please select the appropriate repository aligned with your project's specific needs, you can streamline the integration of CPVector into your development environment and harness its cross-platform capabilities more effectively.

## Unit Testing

Unit testing is a vital aspect of maintaining the quality and reliability of CPVector across its various sub-repositories. It's important to note that unit testing methods may vary between each sub-project due to the unique requirements and platforms they cater to. As such, thorough unit testing is performed on each sub-repository to ensure functionality and compatibility.

When contributing to or working with a specific sub-repository, be sure to refer to the respective unit testing guidelines and procedures provided in that repository's documentation. This approach ensures that CPVector remains robust and dependable across diverse environments.

## Contributions

Your contributions are welcome! If you find issues, want to add new features, or improve existing ones, feel free to submit a pull request to the CPVector repository.

## Contact

If you have questions, suggestions, or comments, you can open an [issue](https://github.com/ChecheRomo96/CPVector/issues) on the repository.

We hope CPVector proves to be a valuable asset in your cross-platform development projects!
