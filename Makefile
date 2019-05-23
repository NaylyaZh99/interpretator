install:
		mkdir -p bin && g++ main1.cpp sources/executor.cpp sources/objects.cpp sources/poliz.cpp -o bin/main -std=c++17
