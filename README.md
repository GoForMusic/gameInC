# Game in C++ using SDL2 libs


Is a personal project created by Adrian-Cristian Militaru using C++ with CMAKE and VCPKG to install external libs...
(x64 x86 arhitecture)


<p>&nbsp;<img align="center" src="https://github-readme-stats.vercel.app/api?username=goformusic&show_icons=true&locale=en&theme=radical" alt="goformusic" /></p>

<hr/>
Install and RUN:
1. Need to install libs using vcpkg run in terminal

```html
vcpkg "@vcpkg_rf"
```

OBS: For install structions for vcpkg go to: https://vcpkg.io/en/getting-started.html

2. Need to build CMAKE file (I was using Clion and build from there using VS2019/VS2022 compiler)
OBS: You need to add toolchain to vcpkg for Debug 
![image](https://user-images.githubusercontent.com/26068529/182837273-48a7fe77-2ee5-48ad-8857-56f359affda9.png).

```html
-DCMAKE_TOOLCHAIN_FILE=<Path_To_vcpkg>/scripts/buildsystems/vcpkg.cmake
```

3. Run the program normally.
