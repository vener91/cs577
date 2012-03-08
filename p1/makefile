all:
	gcc -g -o main main.c
	gcc -g -Wall -Werror -o generate generate.c
test:	
	gcc -Wall -Werror -o main main.c
	gcc -Wall -Werror -o generate generate.c
	rm -rf ./tmp/sandbox
	mkdir -p /tmp/sandbox
	cp -r ./* /tmp/sandbox
	./generate
	./main
