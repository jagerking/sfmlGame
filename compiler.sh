g++ -c src/*.cpp include/*.hpp -g -Wall -I include
g++ *.o -o bin/main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./bin/main
