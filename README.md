# OpenGlLearn

## Install Vcpkg

```shell
cd D:/codes/ 
git clone https://github.com/microsoft/vcpkg
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install opengl:x64-windows
```

You'd better add vcpkg into PATH

Add vcpkg path `D:/codes/vcpkg/scripts/buildsystems/vcpkg.cmake` in CMakeSettings.json: Cmake ToolChain



