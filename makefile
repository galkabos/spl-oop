all: clean bin/cRace

bin/cRace: bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o bin/Offer.o bin/JoinPolicy.o bin/SelectionPolicy.o bin/MandatesJoinPolicy.o bin/MandatesSelectionPolicy.o bin/LastOfferJoinPolicy.o bin/EdgeWeightSelectionPolicy.o
	g++ -o bin/cRace bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o bin/JoinPolicy.o bin/SelectionPolicy.o bin/Offer.o bin/MandatesJoinPolicy.o bin/MandatesSelectionPolicy.o bin/LastOfferJoinPolicy.o bin/EdgeWeightSelectionPolicy.o

bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Offer.o: src/Offer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Offer.o src/Offer.cpp

bin/MandatesJoinPolicy.o: src/MandatesJoinPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MandatesJoinPolicy.o src/MandatesJoinPolicy.cpp

bin/LastOfferJoinPolicy.o: src/LastOfferJoinPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/LastOfferJoinPolicy.o src/LastOfferJoinPolicy.cpp

bin/EdgeWeightSelectionPolicy.o: src/EdgeWeightSelectionPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/EdgeWeightSelectionPolicy.o src/EdgeWeightSelectionPolicy.cpp

bin/MandatesSelectionPolicy.o: src/MandatesSelectionPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MandatesSelectionPolicy.o src/MandatesSelectionPolicy.cpp

bin/SelectionPolicy.o: src/SelectionPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/SelectionPolicy.o src/SelectionPolicy.cpp

bin/JoinPolicy.o: src/JoinPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/JoinPolicy.o src/JoinPolicy.cpp

bin/Agent.o: src/Agent.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp

bin/Graph.o: src/Graph.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

bin/Parser.o: src/Parser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Parser.o src/Parser.cpp

bin/Party.o: src/Party.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Party.o src/Party.cpp

bin/Simulation.o: src/Simulation.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Simulation.o src/Simulation.cpp

clean:
	rm -f bin/*
