ifeq ($(OS), Windows_NT)
	TARGET = main.exe
else
	TARGET = main
endif

all: $(TARGET)

$(TARGET): main.o 
	 g++ -o $(TARGET) main.o

main.o: main.cpp
	 g++ -std=c++14 -c main.cpp
     
clean:
	 rm main.o $(TARGET)