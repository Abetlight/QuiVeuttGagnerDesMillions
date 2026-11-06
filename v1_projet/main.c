#include <stdio.h>
#include <stdlib.h>

struct quiVeutDesMillions
{
   int questions;
   char choix[5];
   char bonneRep;
   int gains;
};
int main()
{
     char apro= 'y' || 'N';
     char reponseJ;

    printf ("\n\33[1;34;5m================Bonjour est bienvenue a QuiVeutGagneDesMillions!================\33[0m\n\n\n");
    printf ("Pret a commencer?\n Y ou N: ");
    scanf(" %c", &apro);

    while (apro != 'Y')
    {
      printf ("Pret a commencer?\n Y ou N: \n");
      scanf(" %c", &apro);
    }

      printf("C'est parti !\n\n");

    struct quiVeutDesMillions jeux[15]=
    {
        {1,"ABCD",'C',100},{2,"ABCD",'A',200},{3,"ABCD",'D',300},
        {4,"ABCD",'B',500},{5,"ABCD",'B',1000},{6,"ABCD",'C',2000},
        {7,"ABCD",'A',4000},{8,"ABCD",'D',8000},{9,"ABCD",'C',12000},
        {10,"ABCD",'B',24000},{11,"ABCD",'A',36000},{12,"ABCD",'C',72000},
        {13,"ABCD",'D',150000},{14,"ABCD",'A',300000},{15,"ABCD",'B',1000000}
    };

    for (int i=0; i<15; i++)
    {
       printf("\n Question numero %d: \n\n", jeux[i].questions);
       printf ("Choisis ta reponse entre %s\n", jeux[i].choix);
       scanf(" %c", &reponseJ);

       if (jeux[i].bonneRep == reponseJ)
       {
           printf("Bonne reponse ! Tu as passe le palier des %d$\n", jeux[i].gains);

       if (jeux[i].questions == 5 || jeux[i].questions == 10)
            {
           printf("S'arreter ?\n Y ou N\n");
           scanf(" %c", &apro);

           if (apro == 'Y')
                {
                printf("Bravo tu as gagne %d $\n", jeux[i].gains);
                break;
                }
            if (apro == 'N')
                {
                printf("Tres bien on continu !\n");
                }
            }
        if (jeux[i].questions == 15)
            {
              printf("\nFelicitation, tu as gagne QuiVeutGagneDesMillions! Et %d$ !!!", jeux[14].gains);
            }

         }
            else
            {
                 if (jeux[i].questions<=5)
                    {
                    printf("Perdu ! Tu reparts avec 0$ !\n" );
                    break;
                    }
                 else if(jeux[i].questions>5 && jeux[i].questions<=10)
                    {
                    printf("Perdu ! Tu reparts avec %d$ !\n", jeux[4].gains );
                    break;
                    }
                 else
                    {
                    printf("Perdu ! Tu reparts avec %d$ !\n", jeux[9].gains );
                    break;
                    }
            }



    }
    return 0;
}
