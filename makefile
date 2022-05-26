CC =g++
CFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = Triangle.h

all:TFractal style
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS)  -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<
TFractal: TFractal.o Triangle.o
	$(CC) $(CFLAGS)  -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
clean:
	rm -f *.o 
	rm -f TFractal
style:
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp $(DEPS)
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp Triangle.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp TFractal.cpp
