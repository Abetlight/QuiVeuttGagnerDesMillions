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

    printf ("\n\33[1;34;5m================Bonjour et bienvenue QuiVeutGagneDesMillions!================\33[0m\n\n\n");
    printf ("\33[1;33m******Pret a commencer?******\33[0m\n \33[1;36mY ou N: ");
    scanf(" %c", &apro);

    while (apro != 'Y')
    {
      printf ("\33[1;33m******Pret a commencer?******\33[0m\n \33[1;36mY ou N: ");
      scanf(" %c", &apro);
    }

      printf("\n\33[1;33m*******C'est parti !*******\33[0m\n\n");

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
       printf("\n \33[1;35m*******Question numero %d:******\33[0m \n\n", jeux[i].questions);
       printf ("\33[1;36mChoisis ta reponse entre\33[0m \33[1;37m%s\33[0m\n", jeux[i].choix);
       scanf(" %c", &reponseJ);

       if (jeux[i].bonneRep == reponseJ)
       {
           printf("\33[1;32mBonne reponse ! Tu as passe le palier des\33[0m \33[1;41m%d$\33[0m\n", jeux[i].gains);

       if (jeux[i].questions == 5 || jeux[i].questions == 10)
            {
           printf("\33[1;33m\n******Tu as le choix de t'arreter ?*******\33[0m\n \33[1;36mY ou N\33[0m\n");
           scanf(" %c", &apro);

           if (apro == 'Y')
                {
                printf("\33[1;32m====== BRAVO TU AS GAGNE \33[1;41m%d $\33[0m\33[1;32m ======\33[0m\n", jeux[i].gains);
                break;
                }
            if (apro == 'N')
                {
                printf("\n\33[1;33mTres bien on continu !\33[0m\n");
                }
            }
        if (jeux[i].questions == 15)
            {
              printf("\n\n\n\33[1;32;5m======== FELICITATION TU VIENS DE GAGNE QuiVeutGagneDesMillions! ET \33[1;41;5m%d$\33[0m \33[1;32;5m!!! ========\33[0m\n\n\n", jeux[14].gains);
            }

         }
            else
            {
                 if (jeux[i].questions<=5)
                    {
                    printf("\33[1;32mPerdu ! Tu reparts avec \33[1;41m0$\33[0m \33[1;32m!\33[0m\n" );
                    break;
                    }
                 else if(jeux[i].questions>5 && jeux[i].questions<=10)
                    {
                    printf("\33[1;32mPerdu ! Tu reparts quand meme avec \33[1;41m%d$\33[0m \33[1;32m!\33[0m\n", jeux[4].gains );
                    break;
                    }
                 else
                    {
                    printf("\33[1;32mPerdu ! C'est dommage ! Mais \33[1;41m%d$\33[0m \33[1;32mc'est pas rien !\33[0m\n", jeux[9].gains );
                    break;
                    }
            }



    }
    return 0;
}
