files := src/main.c
projectname := app
flags := -Wall -g -o $(projectname)

run: $(projectname)
	./$(projectname) $(size)

$(projectname):
	gcc $(files) $(flags) 

clean:
	rm -f ./$(projectname)