clean:
	@rm -f $(wildcard %.exe)

%.exe: %.c clean
	gcc -o $@ $< -lopengl32 -lglu32 -lfreeglut
	$@
	
%.exe: %.cpp clean
	gcc -o $@ $< -lopengl32 -lglu32 -lfreeglut
	$@