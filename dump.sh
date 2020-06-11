g++ -g -c -march=native -O2 main.cpp; objdump -d -M intel -S main.o > main.s
