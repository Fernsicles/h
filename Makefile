h: h.cpp
	g++ --static -o h h.cpp

h.exe: h.cpp
	x86_64-w64-mingw32-g++ --static -o h.exe h.cpp