#include <stdio.h>
#include <stdlib.h>

void affQuestionsReponses (int nb, char chx[] )
{
    printf("\n \33[1;35m*******Question numero %d:******\33[0m \n\n", nb);
    printf ("\33[1;36mChoisis ta reponse entre\33[0m \33[1;37m%s\33[0m\n", chx);
}

void affGains(int nbQ, int nb5, int nb10)
{
    if (nbQ<=5)
        {
        printf("\33[1;32mPerdu ! Tu reparts avec \33[1;41m0$\33[0m \33[1;32m!\33[0m\n" );
        }
    else if(nbQ>5 && nbQ<=10)
        {
        printf("\33[1;32mPerdu ! Tu reparts quand meme avec \33[1;41m%d$\33[0m \33[1;32m!\33[0m\n", nb5 );
        }
    else
        {
        printf("\33[1;32mPerdu ! C'est dommage ! Mais \33[1;41m%d$\33[0m \33[1;32mc'est pas rien !\33[0m\n", nb10);
        }

}

struct quiVeutDesMillions   // Déclaration de la structure
{
   int questions;
   char choix[5]; // Marqueur de fin pour le 5eme char.
   char bonneRep;
   int gains;
};
int main()
{
     char apro;
     char reponseJ;

    printf ("\n\33[1;34;5m================Bienvenue a QuiVeutGagneDesMillions!================\33[0m\n\n\n"); // Validation d'entrée dans le game.
    printf ("\33[1;33m******Pret a commencer?******\33[0m\n \33[1;36mY ou N: ");
    scanf(" %c", &apro); // l'espace annule le dernier char invisible.

    while (apro != 'Y')
    {
      printf ("\33[1;33m******Pret a commencer?******\33[0m\n \33[1;36mY ou N: "); // 'y' pour continuer.
      scanf(" %c", &apro);
    }

      printf("\n\33[1;33m*******C'est parti !*******\33[0m\n\n");

    struct quiVeutDesMillions jeux[15]=
    {
        {1,"ABCD",'C',100},{2,"ABCD",'A',200},{3,"ABCD",'D',300},
        {4,"ABCD",'B',500},{5,"ABCD",'B',1000},{6,"ABCD",'C',2000},               // Déclaration de la variable jeux.
        {7,"ABCD",'A',4000},{8,"ABCD",'D',8000},{9,"ABCD",'C',12000},
        {10,"ABCD",'B',24000},{11,"ABCD",'A',36000},{12,"ABCD",'C',72000},
        {13,"ABCD",'D',150000},{14,"ABCD",'A',300000},{15,"ABCD",'B',1000000}
    };

    for (int i=0; i<15; i++)   // Nombre de questions définies, utilisation du for.
    {
        affQuestionsReponses (jeux[i].questions, jeux[i].choix);
        scanf(" %c", &reponseJ);

        while (reponseJ != 'A' && reponseJ !='B' && reponseJ !='C' && reponseJ !='D')
        {
         affQuestionsReponses (jeux[i].questions, jeux[i].choix); // La réponse ne peut pas être diff de abc ou d sinon question reposée.
         scanf(" %c", &reponseJ);
        }


       if (jeux[i].bonneRep == reponseJ)
       {
           printf("\33[1;32mBonne reponse ! Tu as passe le palier des\33[0m \33[1;41m%d$\33[0m\n", jeux[i].gains); // Bonne rep => question suivante.

       if (jeux[i].questions == 5 || jeux[i].questions == 10)
            {
           printf("\33[1;33m\n******Tu as le choix de t'arreter ?*******\33[0m\n \33[1;36mY ou N\33[0m\n"); // Choix stop ou continue q5 et q10.
           scanf(" %c", &apro);

           while (apro != 'Y' && apro != 'N' )
           {
           printf("\33[1;33m\n******Tu as le choix de t'arreter ?*******\33[0m\n \33[1;36mY ou N\33[0m\n"); // rep ne peut etre diff de Y ou N.
           scanf(" %c", &apro);
           }

           if (apro == 'Y')
                {
                printf("\33[1;32m====== BRAVO TU AS GAGNE \33[1;41m%d $\33[0m\33[1;32m ======\33[0m\n", jeux[i].gains); // action selon  la rep.
                break;
                }
            if (apro == 'N')
                {
                printf("\n\33[1;33mTres bien on continu !\33[0m\n");
                }
            }
        if (jeux[i].questions == 15) // Mess si derniere quest ok.
            {
              printf("\n\n\n\33[1;32;5m======== FELICITATION TU VIENS DE GAGNE QuiVeutGagneDesMillions! ET \33[1;41;5m%d$\33[0m \33[1;32;5m!!! ========\33[0m\n\n\n", jeux[14].gains);
            }

         }
         else
         {
         affGains(jeux[i].questions, jeux[4].gains, jeux[9].gains);  // gains attribué selon quest perdu.
         break;
         }
    }
    return 0;
}
