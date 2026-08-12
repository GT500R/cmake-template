# CMake template
This CMake template contains two applications, both of which access multiple libraries. Unit tests based on the GoogleTest framework have also been added. Even though this is an embedded project, the CMake part is generally valid and is therefore applicable to any project.

## Prerequisites
- [STM32CubeCLT](https://www.st.com/en/development-tools/stm32cubeclt.html) (includes CMake)
- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) (if you want to modify the *.ioc files and regenerate code)
- IDE (e.g. [Visual Studio Code](https://code.visualstudio.com/))
- [LLVM](https://github.com/llvm/llvm-project/releases/latest) (for unit tests, choose "Add LLVM to the system PATH for all users" on windows)
