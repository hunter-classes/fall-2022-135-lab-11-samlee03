main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o --std=c++11

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o --std=c++11

profile.o: profile.cpp profile.o profile.h

network.o: network.cpp network.o network.h

main.o: main.cpp profile.h network.h

tests.o: tests.cpp doctest.h profile.h network.h

clean:
	rm -f main.o tests.o funcs.o profile.o network.o