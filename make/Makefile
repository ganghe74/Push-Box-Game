all:pushbox

pushbox:elements.o map.o pushBox.o UI.o main.o
	g++ -o pushbox elements.o map.o pushBox.o UI.o main.o -lncurses

elements.o:elements.cpp
	g++ -c -o elements.o elements.cpp

map.o:map.cpp
	g++ -c -o map.o map.cpp

pushBox.o:pushBox.cpp
	g++ -c -o pushBox.o pushBox.cpp

UI.o:UI.cpp
	g++ -c -o UI.o UI.cpp

main.o:main.cpp
	g++ -c -o main.o main.cpp
