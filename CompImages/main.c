#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define _CRT_SECURE_NO_DEPRECATE

#include "img_io.h"


int main(int argc, char* argv[]) {
	int xsize, ysize, xsize_r, ysize_r,x,y;
	unsigned char* in_img; 
	unsigned char* in_ref;
	int comp;
	char nom_fichier[256];
	int Identique = 1,OK = 1,diff = 0;
	int i;


	

	for (i = 1; i <= 1000; i++)
	{
		Identique = 1;
		// Ouverture de l'image à vérifier
		sprintf(nom_fichier, "Resultats/%d.pgm", i);
		in_img = read_pgm(&xsize, &ysize, nom_fichier);

		if (in_img == NULL)
		{
			break;
		}
		// Ouverture de l'image de référence
		sprintf(nom_fichier, "References/%d.pgm", i);
		in_ref = read_pgm(&xsize_r, &ysize_r, nom_fichier);

		if (in_ref == NULL)
		{
			break;
		}
		
		// Comparaison des fichiers

		for (x = 0; x < xsize; x++)
		{
			for (y = 0; y < ysize; y++)
			{
				comp = in_img[x + y*xsize] - in_ref[x + y*xsize];
				if (comp != 0)
				{
					Identique = 0;
					OK = 0;
				}
			}
		}
		if (Identique == 0)
		{
			printf("Images %d differentes !\n", i);
			diff++;
		}
		else printf("OK -- Images %d Identiques !\n", i);
	}	
	if (OK == 0) printf("Il y a %d images differentes",diff);
	if (OK == 1) printf("Toutes les images sont identiques !");

	getchar();
    return 0;
}// main()

