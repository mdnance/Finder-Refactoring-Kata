compile: 
	g++ -std=c++20 -Wall -c "src/Finder.cpp"

compileTest:
	g++ -std=c++20 -Wall -fpermissive -I"src/" "test/FinderTests.cpp" "src/Finder.cpp"

runTest: compileTest
	./a.out
