CXX = g++
CFLAGS = -Wall  -std=c++11 -g
LDFLAGS = 

target = mvc
objects = main.o observer.o observerable.o view.o application.o controller.o model.o

$(target) : $(objects)
	$(CXX) -o $(target) $(objects) -pthread

all: $(objects)
$(objects): %.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

 .PHONY : clean
clean:
	rm -f $(target) *.o