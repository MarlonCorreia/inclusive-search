compile:
	g++ main.cpp src/trie.cpp -o bin/main

run:
	./bin/main

clean:
	rm bin/main