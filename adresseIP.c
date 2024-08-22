#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct adresse adresse;
struct adresse {
	int num1;
	int num2;
	int num3;
	int num4;
	};
void entete();	
void Division_Info( char *donne , char  **N1 , char  **N2, char  **N3 , char  **N4);
void enregistrement( char **N1 , char **N2, char **N3 ,char  **N4, adresse *ip);
void resultat(adresse *ip);
void verifyIPClass(adresse *ip , int validity);
void verifyIPValidity(adresse *ip , int *validity);
void fin();

int main(){
		char *donne ;
		adresse ip;
		char *N1= NULL ,*N3= NULL ,*N2= NULL, *N4= NULL ; 
		int  validity = 1;
		entete();
		donne = getenv("QUERY_STRING");
		Division_Info( donne , &N1 , &N2, &N3 , &N4);
		enregistrement( &N1 , &N2, &N3 , &N4 ,&ip);
		resultat(&ip);
		verifyIPValidity(&ip , &validity);
		verifyIPClass(&ip ,  validity);
		fin();
		 
	return 0;
}
void entete(){
	printf("Content-type: Text/html\n\n");
	printf("<html>\n\t<head>\n\t\t<title>adresse</title>\n\t<style>\n\t\tP{color:blue;}\n\tH4{color : red ;}\n\t\t</style></head>\n<body>\n");
}
void Division_Info( char *donne , char **N1 , char **N2, char **N3 , char  **N4){
	
	if (donne != NULL){ 
			*N1 = strtok(donne , "&");
			*N2 = strtok(NULL , "&");
			*N3 = strtok(NULL , "&");
			*N4 = strtok(NULL , "&");
	}
}
void enregistrement( char **N1 , char **N2, char **N3 ,char  **N4, adresse *ip){
	if (*N1 != NULL || *N2 != NULL || *N3 != NULL || *N4 != NULL){
			sscanf(*N1 , "I=%d" , &ip->num1);
			sscanf(*N2 , "II=%d" , &ip->num2);
			sscanf(*N3 , "III=%d" , &ip->num3);
			sscanf(*N4 , "IV=%d" , &ip->num4);
		}
	
}
void resultat(adresse *ip){
           
			printf("<h4>IP:%d.%d.%d.%d", ip->num1 ,ip->num2 ,ip->num3 ,ip->num4 );
            
	}
void verifyIPClass(adresse *ip , int validity){
	if (validity == 1 ){
		if (ip->num1 >= 0  && ip->num1 < 128){
						printf("<p  >=> IP de classe A</p>");
			}
		if (ip->num1 >= 128  && ip->num1 < 192){
						printf("<p > => Adresse IP de classe B</p>");
		}
		if (ip->num1 >=192   && ip->num1 < 224){
						printf("<p > => Adresse IP de classe C</p>");
			}
		if (ip->num1 >=224  && ip->num1 < 240){
						printf("<p > => Adresse IP de classe D</p>");
			}
		if (ip->num1 >= 240  && ip->num1 <= 255){
						printf("<p > =>Adresse IP de classe E</p>");
			}
		}
}
void verifyIPValidity(adresse *ip , int *validity){
	if (ip->num1 > 255 || ip->num2 > 255 ||ip->num3 > 255 ||ip->num4 > 255 ){
					printf("<p>Adresse IP non valide</p>");
					*validity = 0;
		}
	}
void fin(){
	printf("\n\t</body>\n</html>");
}	
