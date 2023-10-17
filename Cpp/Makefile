compile: 
	g++ -std=c++20 "src/Finder.cpp"

compileTest:
	g++ -std=c++20 -fpermissive -I"src/" "test/FinderTests.cpp" "src/Finder.cpp"

runTest: compileTest
	./a.out