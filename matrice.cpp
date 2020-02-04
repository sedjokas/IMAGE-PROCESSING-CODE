#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <opencv/cv.h>
#include <math.h>
#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace cv;

string getNomFile(string nom);
int getNomDoc(string s);

int main(int argc, char* argv[]) 
{  
	fstream fichier("fichier_score.txt", ios::in);  // on ouvre en lecture
	
        
	string mot[3];
  	//création de la matrice de confusion
		int sizeBase = 40;
		int clasf[sizeBase][sizeBase];
		for (int i = 0; i < sizeBase; i++){
 			for (int j = 0; j < sizeBase; j++)
				clasf[i][j] = 0;
 		}
      if(fichier)
	  {
        string lignerep="",lignerep1="";
	string oldlignerep1="";
	string ligne;
	 float max=0.0;
	 string nomApprentissage;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                 //cout << ligne << '\n';  // on l'affiche
       
		istringstream iss(ligne);
		int i=0;
		while ( getline( iss, lignerep, ' ' ) )
		{
		    mot[i]=lignerep;
		    if(i==1){
		      lignerep1=getNomFile(mot[i]);
		    }
		      i++;
		}
		if(oldlignerep1!="" && strcmp(oldlignerep1.c_str(),lignerep1.c_str())!=0){
		  cout<<oldlignerep1<<"   "<<nomApprentissage<<"   "<<getNomDoc(nomApprentissage) <<endl;
			clasf[getNomDoc(oldlignerep1)-1][getNomDoc(nomApprentissage)-1]++;
		  max=atof(mot[2].c_str());
		  nomApprentissage=getNomFile(mot[0]);
		  oldlignerep1=lignerep1;
		}
		if((strcmp(oldlignerep1.c_str(),lignerep1.c_str())==0 and atof(mot[2].c_str())>max) || oldlignerep1==""){
		  max=atof(mot[2].c_str());
		  nomApprentissage=getNomFile(mot[0]);
		  oldlignerep1=lignerep1;
		}
	}
       cout<<oldlignerep1<<"   "<<nomApprentissage<<"   "<<getNomDoc(nomApprentissage) <<endl;
clasf[getNomDoc(oldlignerep1)-1][getNomDoc(nomApprentissage)-1]++;
      }
	
	else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
	

// 		
// 		//Enregistrement des fichiers
 		ofstream fm;
 		fm.open("matrice_confusion.txt");
 		for (int i = 0; i < sizeBase; i++) {
 			for (int j = 0; j < sizeBase - 1; j++)
 				fm << clasf[i][j] << " ";
 			fm << clasf[i][sizeBase - 1] << endl;
		}
 	fm.close();   
  
        return 0;
}

string getNomFile(string nom){
  string recup;
 istringstream iss1(nom);
  int j=0;
  while ( std::getline( iss1, recup, '/' ) )
  {
    if(j==1){
      return recup;
    }
    j++;
  } 
  return recup;
}

int getNomDoc(string s) {
	int num;
	string sub;
	size_t pos;
	pos = s.find("__");
	int p = (int) pos;
	sub = s.substr(3, p - 3);
	num = atoi(sub.c_str());
	return num;
}
