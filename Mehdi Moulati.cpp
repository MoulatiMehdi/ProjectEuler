      /***************************************************************/
     /*                 nom       :    Moulati                      */
    /*                  prenom    :      Mehdi                     */
   /*                   felilre   :      MIPC                     */
  /*                    Groupe    :       G4                     */
 /*                                                             */
/***************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct  EnsCreux
   {
	 struct EnsCreux *PGauche;
	 struct EnsCreux *PDroit;
	 int valeur;
    }EnsCreux;

typedef struct Listerepere
   {
     EnsCreux *debut;
     EnsCreux *fin;
	 int taille;
    }Dlist;

// Allocation et Initialisation  pour Dlist
Dlist* new_dlist_vide(void)
    {
	 Dlist* p_new=(Dlist*)malloc(sizeof(Dlist));
	 p_new->taille=0;
	 p_new->debut=NULL;
	 p_new->fin=NULL;
	 return p_new;
    }

// Allocation et Initialisation pour EnsCreux
EnsCreux* new_EnsCreux_vide(void)
   {
	 EnsCreux* p_new=(EnsCreux*)malloc(sizeof(EnsCreux));
	 p_new->valeur=0;
	 p_new->PDroit=NULL;
	 p_new->PGauche=NULL;
	 return p_new;
    }

//l'insertion pour une liste vide
int ins_liste_vide(Dlist* liste,int donnee)
   {
	 EnsCreux *new_elem=new_EnsCreux_vide();
	 
	 if(new_elem==NULL)
	   {
	     return -1;
	    }
	 new_elem->valeur=donnee;
	 new_elem->PGauche=liste->debut;
	 new_elem->PDroit=liste->fin;
	 
	 liste->debut=new_elem;
	 liste->fin=new_elem;
	 liste->taille++;
  	 return 0;
    }

//l'insertion au debut de la liste
int ins_debut_liste(Dlist* liste,int donnee)
   {
	 EnsCreux *new_elem=new_EnsCreux_vide();
	 
	 if(new_elem==NULL)
	   {
	     return -1;
		}
		
	 new_elem->valeur=donnee;
	 new_elem->PGauche=NULL;
	 new_elem->PDroit=liste->debut;
	 
	 liste->debut->PGauche=new_elem;
	 liste->debut=new_elem;
	 liste->taille++;
	 
	 return 0;
	}

//l'insertion au fin de la liste
int ins_fin_liste(Dlist* liste,int donnee)
   {
   	
	 EnsCreux *new_elem=new_EnsCreux_vide();
	 
	 if(new_elem==NULL)
	   {
	     return -1;
	    }
	    
     new_elem->valeur=donnee;
	 new_elem->PGauche=liste->fin;
	 new_elem->PDroit=NULL;
	 
	 liste->fin->PDroit=new_elem;
     liste->fin=new_elem;
	 liste->taille++;
	 
	 return 0;
	}
	
	//l'insertion sur un position par rapport a la fin de la liste
 void ins_avant_fin_liste(Dlist* liste,int donnee,int position){
	
	int pos=position;
	do {
	 	if(pos<0||pos>liste->taille)
	 	   {    
			    printf("ERROR,ce position n'exsite pas\n");
			    printf("resaisir le position entre 0 et%d",liste->taille);
			    printf(" avant la fin\n");
		        printf("Reponse:");
		        scanf("%d",&pos);
		         
            }
        }while(pos<0&&pos>liste->taille); 
			  
     if(pos==0)	ins_fin_liste(liste,donnee);     
	 else if(pos==liste->taille ) ins_debut_liste(liste,donnee); 
	 else
	   {

	     EnsCreux* p=new_EnsCreux_vide();
         EnsCreux* Q=new_EnsCreux_vide();
	     int i;
	     for( p=liste->fin,i=0;i<pos;i++)
            {
	         p=p->PGauche;
	        }    
		 Q->PDroit=p->PDroit;
		 Q->PGauche=p;
		 p->PDroit->PGauche=Q;
		 p->PDroit=Q;
		 Q->valeur=donnee;
		 liste->taille++;
	    }	
	}
	
//l'insertion sur un position par rapport a debut de la liste
void ins_apres_debut_liste(Dlist* liste,int donnee,int position)
	{
	 int pos=position;
	 do
	   { 
	     if(pos<0||pos>liste->taille)
		   {
		     printf("ERROR,le position n'exsite pas\n");
		     printf("resaisir le position entre 0 et%d apres le debut\n",liste->taille);
		     printf("Reponse:");
		     scanf("%d",&pos);
		     printf("\n");
            }
		}while(pos<0&&pos>liste->taille);
		  
     if(pos==0)	ins_debut_liste(liste,donnee);
	 else if(pos==liste->taille ) ins_fin_liste(liste,donnee); 
	 else 
		{

         EnsCreux* p=new_EnsCreux_vide();
         EnsCreux* Q=new_EnsCreux_vide();   
	     int i;
	    
     	 for( p=liste->debut,i=0;i<pos;i++, p=p->PDroit){}
		 Q->PDroit=p;
	     Q->PGauche=p->PGauche;
		 p->PGauche->PDroit=Q;
		 p->PGauche=Q;
		 Q->valeur=donnee;
		 liste->taille++;
        }   
    }

// supprimer un cellule de la liste

void supprimer_cellule_EnsCreux(Dlist* liste,int valeur_sup)
   {
 	 EnsCreux* p=new_EnsCreux_vide();
	 for(p=liste->debut;p!=NULL;p=p->PDroit)
	   {
	     if (p->valeur==valeur_sup)
	       {	
	         if(p==liste->debut)
		        {
			     liste->debut=p->PDroit;
			     p->PDroit->PGauche=NULL;
			     
		        }
		     else if (p!=liste->debut&&p!=liste->fin)
			    {
			 	 p->PGauche->PDroit=p->PDroit;
			 	 p->PDroit->PGauche=p->PGauche;
			    }
		     else if(p==liste->fin)
		       {
			     liste->fin=p->PGauche;
			     p->PGauche->PDroit=NULL;
		        }
		     
			 liste->taille--;
			 	 	
		    }
        }
    }

// destruction de la liste 

void destruction_liste(Dlist* liste)
    {
	 EnsCreux* p=new_EnsCreux_vide();
	 for(p=liste->debut;p!=liste->fin;p=p->PDroit)
	    {   
	     
	         p->PGauche=new_EnsCreux_vide();
             p->PDroit->PGauche=new_EnsCreux_vide();	
	         p->PGauche->PDroit=new_EnsCreux_vide();
	        
	     if(p==liste->fin->PGauche) p->PDroit=new_EnsCreux_vide();
		 liste->taille--;
	    }
	    liste->debut=NULL;
	    liste->fin=NULL;	    
	 printf("\nla liste est totalement vide\n ");
    }
    
    
    // disposition les cellules croissant par rapport a sa valeur
void ordre_donnee_croissant(Dlist* L)	
    {
	 EnsCreux* i=new_EnsCreux_vide();
     EnsCreux* j=new_EnsCreux_vide();
     for(i=L->debut;i!=NULL;i=i->PDroit)
       {   
         int aide=0;
         for(j=i;j!=NULL;j=j->PDroit)
            {
  	         if(i->valeur>j->valeur)
                {
  	             aide=j->valeur;
  	             j->valeur=i->valeur;
  	             i->valeur=aide;
	            }
            }	
        }
    }
    
    
    //l'affichage des donnee d'un forme decroissant 
void print_dlist_decroissant(Dlist* liste)
    { 
    if(liste->fin==NULL)
	    {
	     printf("IMPOSSIBLE de faire l'affichage");
		 	
	    }
	 else
	    {
	
         printf(" \taffichage decroissant:\n");
	     ordre_donnee_croissant(liste);
	     EnsCreux* tmp=liste->fin;
	     while(tmp)
	        {
		     printf("\t\t%d\n",tmp->valeur);
		     tmp=tmp->PGauche;
	        }
		}
    }
    
    
    //l'affichage des donnee d'un forme croissant 
void print_dlist_croissant(Dlist* liste)
    {
     if(liste->debut==NULL)
	    {
	     printf("IMPOSSIBLE de faire l'affichage  ");
		 	
	    }
	 else
	    {
	 
	     printf("\taffichage croissant:\n");
	     ordre_donnee_croissant(liste);
	     EnsCreux* tmp=liste->debut;
	     while(tmp)
	        {
		      printf("\t\t%d\n",tmp->valeur);
		      tmp=tmp->PDroit;
	        }
	    
        }
	}
    
    
    //calculer le nombre des celulles dans une liste
int cardinal(Dlist* notre_liste)
   { 
     int i;
	 EnsCreux* p=new_EnsCreux_vide();
	 for(p=notre_liste->debut;p!=NULL;p=p->PDroit)
	    {
	    	
	      i++;	 
		}
	 return i;
   }
   
   
   //la valeur x exist dans la liste ou non
int appartient(Dlist* liste,int x) 
   { 
     EnsCreux* p=new_EnsCreux_vide();
     int res=0;
	 for(p=liste->debut;p!=NULL;p=p->PDroit)
	    {
	    	
		 if(p->valeur==x) res=1;
		 
	    }
	 return res;
    }
     
     
     //l'union entre deux liste
Dlist* Union(Dlist* liste1,Dlist* liste2)
   { 
     printf("\tl'union entre deux liste...\n");
     if(liste1==NULL||liste2==NULL)
	   {
	   	 printf("\tl'union n'est pas reussi.");
	     return NULL;
		}
     Dlist* liste_1=new_dlist_vide();
     Dlist* liste_2=new_dlist_vide();
  
     liste_1=liste1;
     liste_2=liste2;

     EnsCreux* i=new_EnsCreux_vide();
     
     for(i=liste1->debut;i!=NULL;i=i->PDroit)
        {
  
         if(appartient(liste_2,i->valeur))
            {
      	     supprimer_cellule_EnsCreux(liste_2,i->valeur);
	        }
	    }
     liste_1->fin->PDroit=liste2->debut;
     liste_2->debut->PGauche=liste1->fin;
     liste_1->fin=liste2->fin;
     liste_1->taille=cardinal(liste_1);
  
     ordre_donnee_croissant(liste_1);
     
     printf("\tl'union est reussi.\n\n");
     return liste_1;
    }


//l'intersection entre deux listes
Dlist* intersection(Dlist* liste1,Dlist* liste2)
{    
    
     printf("\tl'intersection entre deux liste...\n");
	 if(liste1==NULL||liste2==NULL)
	   {
	   	 printf("intersection n'est pas reussi.\n");
	   	 exit(1);
	     return NULL;
		 }
     Dlist* U=new_dlist_vide();
     Dlist* liste_1=new_dlist_vide();
     Dlist* liste_2=new_dlist_vide();
  
     liste_1=liste1;
     liste_2=liste2;
  
     EnsCreux* i=new_EnsCreux_vide();
  
     for(i=liste_1->debut;i!=NULL;i=i->PDroit)
        {
  	     if(appartient(liste_2,i->valeur)==1)
  	        {
  		     if(U->taille==0) ins_liste_vide(U,i->valeur);
  		     else ins_debut_liste(U,i->valeur);
            }
        }
	 ordre_donnee_croissant(U);
	 printf("\tl'intersection est reussi.\n\n");
     return U;
  
 
    }

main()
    {

     Dlist* L=new_dlist_vide();
     printf("\n___________________________________________\n");
     printf("\t\tliste A: ");
     printf("\n___________________________________________\n");
     ins_liste_vide(L,37);
     ins_debut_liste(L,2);
     ins_apres_debut_liste(L,55,1);
     ins_fin_liste(L,231);
     ins_avant_fin_liste(L,9999,1); 
     
     
     
     print_dlist_croissant(L);
     print_dlist_decroissant(L);


     Dlist* K=new_dlist_vide();
     
     printf("\n___________________________________________\n");
     printf("\t\t liste B: ");
     printf("\n___________________________________________\n");
     ins_liste_vide(K,37);
     ins_debut_liste(K,2);
     ins_apres_debut_liste(K,54,1);
     ins_fin_liste(K,231);
     ins_avant_fin_liste(K,9999,1);

     print_dlist_croissant(K);
     

     Dlist* J=new_dlist_vide();
     printf("\n___________________________________________\n");
     printf("\t\tL'INTERSECTION:");
     printf("\n___________________________________________\n");
     
     J=intersection(L,K);
     print_dlist_croissant(J);
     
     printf("\n___________________________________________\n");
     printf("\t\tL'UNION:");
     printf("\n___________________________________________\n");
     
     Dlist* U=Union(L,K);
     print_dlist_croissant(U);
     
     destruction_liste(U);
     print_dlist_croissant(U);
     

    }
    
    
