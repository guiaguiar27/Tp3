# all:

# 	gcc src/main.c src/Reader.c src/TreeServer.c src/List.c -o main 
# production: 

# 	gcc src/main.c  src/Reader.c -D POSITION=$(position) -o main 
	
# clean:
# 	rm main

# run:
#	./main  teste.txt


all:

	gcc src/main.c src/Reader.c src/TreeServer.c src/List.c -o main 
production: 

	gcc src/main.c  src/Reader.c -D POSITION=$(position) -o main 
	
clean:
	rm main
