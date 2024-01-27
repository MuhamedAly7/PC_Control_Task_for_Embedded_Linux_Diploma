build:
	@g++ main.cpp Server/server.cpp -o pc.out

clean:
	@rm pc.out

run: build
	@./pc.out
