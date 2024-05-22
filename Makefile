InputGenerator.exe: src.cc
	g++ -o InputGenerator.exe src.cc

clean:
	rm -f *.exe
	rm -f *.inp

generate: InputGenerator.exe
	./InputGenerator.exe > gen_test.inp