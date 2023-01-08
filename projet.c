#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char* read_lines(int fd) 
{
	
  	static char buffer[BUFFER_SIZE];
  	static int buffer_size = 0;
  	static int buffer_pos = 0;

  	char* line = NULL;
  	int line_size = 0;

 	 while (1) 
 	 {
    		if (buffer_pos >= buffer_size) 
    		{
    			
      			buffer_size = read(fd, buffer, BUFFER_SIZE);
     			if (buffer_size <= 0) 
     		{
        
       			break;
      		}
      		buffer_pos = 0;
   	 	}

    
    		if (buffer[buffer_pos] == '\n') 
    		{
    			line = malloc((line_size + 1) * sizeof(char));
      			for (int i = 0; i < line_size; i++) 
      			{
        			line[i] = buffer[i];
      			}
      			line[line_size] = '\0';
      			buffer_pos++;
      			return line;
  		}

    		line_size++;
   		buffer_pos++;
  	}
	if (line_size > 0) 
	{
		line = malloc((line_size + 1) * sizeof(char));
		for (int i = 0; i < line_size; i++) 
		{
      			line[i] = buffer[i];
    		}
    		line[line_size] = '\0';
   		return line;
  	}
  	return NULL;
}
/*Cette fonction utilise un tampon statique pour stocker les caractères qui ont été lus à partir du descripteur de fichier mais pas encore renvoyés sous forme de ligne. Il lit les caractères du tampon jusqu'à ce qu'une nouvelle ligne soit rencontrée ou que le tampon soit vide, auquel cas il remplit à nouveau le tampon avec un appel à read. Si la fin du fichier est atteinte ou si une erreur se produit, il vérifie si des caractères ont été lus avant de renvoyer NULL. S'il y avait des caractères, il alloue de la mémoire pour une chaîne et copie les caractères dans la chaîne avant de la renvoyer.*/
int main()
{
	int fd = open("filename", O_RDONLY);
	char* line;
	while ((line = read_lines(fd)) != NULL) 
	{
  		printf("%s\n", line);
  		free(line);
  	}
	close(fd);
	return 0;
}


