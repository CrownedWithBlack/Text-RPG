#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>
// 10:30  martes
//____________________________VariablesGlobales________________________________________________________________________
    int cont=0,armaSeleccionada,armaduraSeleccionada,Clase;
    int i,k;
//______________________________Funciones_________________________________________________________________________________________
    int inventario();
    int combate();
    int estado();
    void unedl();
    float DMG(int TipoDano, int DadoEnemigo, int turno);
//_______________________________Structs__________________________________________________________________________________________
    struct Armaduras{
        char nombreArmadura[30];
        float defArmadura;
    };

    struct Armas{
    char nombreArma[30];
    float dannoArma;
    };

    struct Personajes{
    float HPMax,HPActual,EXP,DannoBase,DannoTotal,DefensaBase,DefensaTotal;
    char NombreClase[9];
    int pociones,LVL;
    struct Armas Arma[14];
    struct Armaduras Armadura[14];
    };
    struct Personajes jugador[4];

    struct Combate {
        float HpActual,HpMax,Def,Dano;
        char nombre[25];
    }Enemigo[11];
//_______________________________Main______________________________________________________________________________________
void main(){
    system("color 09");
    system("cls");
    unedl();//________________Bienvenida
    system("cls");

    printf("||__________SELECCIONE PERSONAJE__________||\n");
    printf("|| 1.-Guerrero || 2.- Mago || 3.- Asesino ||\n");
    printf("Selecci\xa2n: ");
    do{
        scanf("%i",&Clase);

    }while(Clase!=1 && Clase!=2 && Clase!=3);
    
    jugador[Clase].HPMax=100;
    jugador[Clase].HPActual=jugador[Clase].HPMax;
    jugador[Clase].EXP=0;
    jugador[Clase].LVL=1;
    jugador[Clase].DannoBase=10;
    jugador[Clase].DannoTotal=jugador[Clase].DannoBase;
    jugador[Clase].DefensaBase=5;
    jugador[Clase].DefensaTotal=jugador[Clase].DefensaBase;
    jugador[Clase].pociones=10;
    if(Clase==1){
        strcpy(jugador[Clase].NombreClase,"Guerrero");
    }
    if(Clase==2){
        strcpy(jugador[Clase].NombreClase,"Mago");
    }
    if(Clase==3){
        strcpy(jugador[Clase].NombreClase,"Asesino");
    }
    system("cls");
    int MenuPrincipal;
    do{ 
        printf("||______________________Men\xa3 principal______________________||\n");
        printf("|| 1.- Combate || 2.- Inventario || 3.- Estado || 4.- Salir ||\n");
        printf("|| Clase: %s\tHP: %.2f/%.2f\n",jugador[Clase].NombreClase,jugador[Clase].HPActual,jugador[Clase].HPMax);



        printf("Selecci\xa2n: ");
       
        scanf("%i",&MenuPrincipal);
        

        switch(MenuPrincipal){
            case 1:
                combate();
                break;
            case 2: 
            inventario();
                break;
            case 3:
            estado();
                break;
            case 4:
                break;
        }
        system("cls");
    }while(MenuPrincipal!=4);




}//END Main
//________________________Funciones__________________________________________________________________________________

int combate(){
    char lugar[25];
    int DadoLugar,DadoEnemigo,turno=1;
    srand(time(0));
    DadoLugar=rand()%12+1;
    DadoEnemigo=GetTickCount()%10+1;
        switch(DadoLugar){
        case 1:
            strcpy(lugar,"un pantano");
            break;
        case 2:
            strcpy(lugar,"una cueva");
            break;
        case 3:
            strcpy(lugar,"un bosque");
            break;
        case 4:
            strcpy(lugar,"una jungla");
            break;
        case 5:
            strcpy(lugar,"una mina abandonada");
            break;
        case 6:
            strcpy(lugar,"un calabozo");
            break;
        case 7:
            strcpy(lugar,"una mansi\xa2n antigua");
            break;
        case 8:
            strcpy(lugar,"un cementerio");
            break;
        case 9:
            strcpy(lugar,"un pueblo fantasma");
            break;
        case 10:
            strcpy(lugar,"una ciudad apocal\xa1ptica");
            break;
        case 11:
            strcpy(lugar,"un castillo");
            break;
        case 12:
            strcpy(lugar,"unas catacumbas");
            break;
    }//END switch
    
    char ara[7]="Ara\xa4", na[2]="a";
    switch(DadoEnemigo){
        case 1:
            strcpy(Enemigo[DadoEnemigo].nombre,"Bruja");
            break;
        case 2:
            strcpy(Enemigo[DadoEnemigo].nombre,"Fantasma");
            break;
        case 3:
            strcpy(Enemigo[DadoEnemigo].nombre,"Hombre lobo");
            break;
        case 4:
            strcpy(Enemigo[DadoEnemigo].nombre,"Bandido");
            break;
        case 5:
        
        strcat(ara,na);
            strcpy(Enemigo[DadoEnemigo].nombre,ara);
            break;
        case 6:
            strcpy(Enemigo[DadoEnemigo].nombre,"Esqueleto");
            break;
        case 7:
            strcpy(Enemigo[DadoEnemigo].nombre,"Cazarecompensas");
            break;
        case 8:
            strcpy(Enemigo[DadoEnemigo].nombre,"Demonio");
            break;
        case 9:
            strcpy(Enemigo[DadoEnemigo].nombre,"Zombie");
            break;
        case 10:
            strcpy(Enemigo[DadoEnemigo].nombre,"Nigromante");
            break;
    }

    printf("Te encuetras en %s cuando de repente un(a) %s ataca.\n",lugar,Enemigo[DadoEnemigo].nombre);
    system("pause");
    system("cls");
    int ContHab=0,salir=0;
    int OpcionCombate;
    Enemigo[DadoEnemigo].HpMax=50+(jugador[Clase].LVL*5);
    Enemigo[DadoEnemigo].HpActual=Enemigo[DadoEnemigo].HpMax;
    Enemigo[DadoEnemigo].Def=2+(jugador[Clase].LVL*1.2);
    Enemigo[DadoEnemigo].Dano=10+(jugador[Clase].LVL*1.2);
    do{
        if(Enemigo[DadoEnemigo].HpActual<=0){

            printf("El enemigo ha sido derrotado!\n");
            printf("Obtuviste 45Pts de EXP!\n");
            jugador[Clase].EXP+=45;
            if(jugador[Clase].EXP>=100){
                jugador[Clase].EXP=0;
                jugador[Clase].LVL+=1;
                jugador[Clase].DannoBase+=(jugador[Clase].LVL*1.5);
                jugador[Clase].DefensaBase+=(jugador[Clase].LVL*1.5);
                jugador[Clase].HPMax+=(jugador[Clase].LVL*5);
                jugador[Clase].HPActual=jugador[Clase].HPMax;
                printf("Has subido al nivel %i!!\n",jugador[Clase].LVL);
            }

            if(rand()%2==0){
                printf("Obtuviste Poci\xa2n!\n");
                jugador[Clase].pociones++;
            }

            system("pause");
            break;
        }
        if(jugador[Clase].HPActual<=0){
            printf("Has muerto...");
            system("pause");
            exit(1);
            
            break;
        }
        
        do{
            system("cls");
            turno=1;
            printf("|| ___________________Combate__________________||\n");
            printf("|| 1.- Atacar || 2.- Habilidad || 3.- Pociones ||\n\n");
            printf("|| Clase: %s\tHP: %.2f/%.2f\n",jugador[Clase].NombreClase,jugador[Clase].HPActual,jugador[Clase].HPMax);
            printf("|| Enemigo: %s\tHP: %.2f/%.2f\n",Enemigo[DadoEnemigo].nombre,Enemigo[DadoEnemigo].HpActual,Enemigo[DadoEnemigo].HpMax);
            printf("Selecci\xa2n: ");
            scanf("%i",&OpcionCombate);
            if(ContHab>=3 && OpcionCombate==2){
                printf("Has usado Habilidades demasidas veces durante\nel combate descansa un poco!!!\n");
                system("pause");
            }
        }while(ContHab>=3 && OpcionCombate==2);

        switch(OpcionCombate){
            case 1:
                printf("Usaste un ataque normal, ");
                printf("el enemigo\n%s recibi\xa2 %.2f de da\xa4o!\n",Enemigo[DadoEnemigo].nombre, DMG(OpcionCombate,DadoEnemigo,turno));
                turno++;
                system("pause");
                break;
            case 2:
                ContHab++;
                printf("Usaste  una habilidad especial, ");
                    printf("el enemigo\n%s recibi\xa2 %.2f de da\xa4o!\n",Enemigo[DadoEnemigo].nombre, DMG(OpcionCombate,DadoEnemigo,turno));
                    turno++;
                    system("pause");
                    break;
            case 3:
                if(jugador[Clase].HPActual==jugador[Clase].HPMax){
                    printf("Ya tienes la vida al m\xa0ximo!\n");
                    system("pause");
                    break;
                }
                jugador[Clase].pociones--;
                if(jugador[Clase].pociones<=0){
                    jugador[Clase].pociones=0;
                    OpcionCombate=2;
                    printf("No te quedan m\xa0s pociones\n");
                    system("pause");
                    break;
                }

                printf("Haz usado una poci\xa2n y curado 50HP, te quedan: %i\n",jugador[Clase].pociones);
                jugador[Clase].HPActual+=50;

                if(jugador[Clase].HPActual>jugador[Clase].HPMax){
                    jugador[Clase].HPActual=jugador[Clase].HPMax;
                }
                turno++;
                system("pause");
                break;
        }//END Switch
        if(Enemigo[DadoEnemigo].HpActual>0){
            if(turno==2){
                printf("El enemigo %s te atac\xa2 infliendote %.2f de da\xa4o!\n",Enemigo[DadoEnemigo].nombre,DMG(OpcionCombate,DadoEnemigo,turno));
                system("pause");
            }
        }

    }while(salir==0);

}// END FuncCombate

int inventario(){
    system("cls");
    strcpy(jugador[1].Arma[0].nombreArma,"Espada Corta");
    jugador[1].Arma[0].dannoArma=10;
    strcpy(jugador[1].Arma[1].nombreArma,"Lanza");
    jugador[1].Arma[1].dannoArma=20;
    char hacha[17]="Hacha de Le\xa4", lennador[5]="ador";
    strcat(hacha, lennador);
    strcpy(jugador[1].Arma[2].nombreArma,hacha);
    jugador[1].Arma[2].dannoArma=30;
    strcpy(jugador[1].Arma[3].nombreArma,"Espada Larga");
    jugador[1].Arma[3].dannoArma=40;
    strcpy(jugador[1].Arma[4].nombreArma,"Lanza de Caballero");
    jugador[1].Arma[4].dannoArma=50;
    strcpy(jugador[1].Arma[5].nombreArma,"Hacha de Verdugo");
    jugador[1].Arma[5].dannoArma=60;
    strcpy(jugador[1].Arma[6].nombreArma,"Espada de Zeus");
    jugador[1].Arma[6].dannoArma=70;
    strcpy(jugador[1].Arma[7].nombreArma,"Lanza de Atenea");
    jugador[1].Arma[7].dannoArma=80;
    strcpy(jugador[1].Arma[8].nombreArma,"Hacha Maldita");
    jugador[1].Arma[8].dannoArma=90;
    strcpy(jugador[1].Arma[9].nombreArma,"Espadas del Caos");
    jugador[1].Arma[9].dannoArma=100;
    strcpy(jugador[1].Arma[10].nombreArma,"Lostvayne");
    jugador[1].Arma[10].dannoArma=120;
    strcpy(jugador[1].Arma[11].nombreArma,"Chastiefol");
    jugador[1].Arma[11].dannoArma=120;
    strcpy(jugador[1].Arma[12].nombreArma,"Rhitta");
    jugador[1].Arma[12].dannoArma=120;
    strcpy(jugador[1].Arma[13].nombreArma,"Ninguna");
    jugador[1].Arma[13].dannoArma=0;

    strcpy(jugador[1].Armadura[0].nombreArmadura,"Pechera");
    jugador[1].Armadura[0].defArmadura=5;
    strcpy(jugador[1].Armadura[1].nombreArmadura,"Peto de Cuero");
    jugador[1].Armadura[1].defArmadura=10;
    strcpy(jugador[1].Armadura[2].nombreArmadura,"Armadura de Metal");
    jugador[1].Armadura[2].defArmadura=15;
    strcpy(jugador[1].Armadura[3].nombreArmadura,"Armadura de Caballero");
    jugador[1].Armadura[3].defArmadura=20;
    strcpy(jugador[1].Armadura[4].nombreArmadura,"Placas Pesadas");
    jugador[1].Armadura[4].defArmadura=25;
    strcpy(jugador[1].Armadura[5].nombreArmadura,"Armadura de Legionario");
    jugador[1].Armadura[5].defArmadura=30;
    strcpy(jugador[1].Armadura[6].nombreArmadura,"Escudo del Rey");
    jugador[1].Armadura[6].defArmadura=35;
    strcpy(jugador[1].Armadura[7].nombreArmadura,"Armadura de Palad\xa1n");
    jugador[1].Armadura[7].defArmadura=40;
    strcpy(jugador[1].Armadura[8].nombreArmadura,"Cota de Fenrir");
    jugador[1].Armadura[8].defArmadura=45;
    strcpy(jugador[1].Armadura[9].nombreArmadura,"Armadura de Centauro");
    jugador[1].Armadura[9].defArmadura=55;
    strcpy(jugador[1].Armadura[10].nombreArmadura,"Ninguna");
    jugador[1].Armadura[10].defArmadura=0;

    strcpy(jugador[2].Arma[0].nombreArma,"Orbe");
    jugador[2].Arma[0].dannoArma=10;
    strcpy(jugador[2].Arma[1].nombreArma,"Libro");
    jugador[2].Arma[1].dannoArma=20;
    strcpy(jugador[2].Arma[2].nombreArma,"Bast\xa2n");
    jugador[2].Arma[2].dannoArma=30;
    strcpy(jugador[2].Arma[3].nombreArma,"Bola de Adivinaci\xa2n");
    jugador[2].Arma[3].dannoArma=40;
    strcpy(jugador[2].Arma[4].nombreArma,"Libro M\xa0gico");
    jugador[2].Arma[4].dannoArma=50;
    strcpy(jugador[2].Arma[5].nombreArma,"Vara de Bruja");
    jugador[2].Arma[5].dannoArma=60;
    strcpy(jugador[2].Arma[6].nombreArma,"Cristal Encantado");
    jugador[2].Arma[6].dannoArma=70;
    strcpy(jugador[2].Arma[7].nombreArma,"Bast\xa2n del Rey Brujo");
    jugador[2].Arma[7].dannoArma=80;
    strcpy(jugador[2].Arma[8].nombreArma,"Black Clover");
    jugador[2].Arma[8].dannoArma=90;
    strcpy(jugador[2].Arma[9].nombreArma,"Grimorio Maldito");
    jugador[2].Arma[9].dannoArma=100;
    strcpy(jugador[2].Arma[10].nombreArma,"Gema del Infinito");
    jugador[2].Arma[10].dannoArma=120;
    strcpy(jugador[2].Arma[11].nombreArma,"Necronomicon");
    jugador[2].Arma[11].dannoArma=120;
    strcpy(jugador[2].Arma[12].nombreArma,"Aldan");
    jugador[2].Arma[12].dannoArma=120;
    strcpy(jugador[2].Arma[13].nombreArma,"Ninguna");
    jugador[2].Arma[13].dannoArma=0;

    strcpy(jugador[2].Armadura[0].nombreArmadura,"T\xa3nica");
    jugador[2].Armadura[0].defArmadura=5;
    strcpy(jugador[2].Armadura[1].nombreArmadura,"T\xa3nica de Monje");
    jugador[2].Armadura[1].defArmadura=10;
    strcpy(jugador[2].Armadura[2].nombreArmadura,"T\xa3nica de Aprend\xa1z");
    jugador[2].Armadura[2].defArmadura=15;
    strcpy(jugador[2].Armadura[3].nombreArmadura,"Bata M\xa0gica");
    jugador[2].Armadura[3].defArmadura=20;
    strcpy(jugador[2].Armadura[4].nombreArmadura,"T\xa3nica de Mago Negro");
    jugador[2].Armadura[4].defArmadura=25;
    strcpy(jugador[2].Armadura[5].nombreArmadura,"T\xa3nica de Hechiero");
    jugador[2].Armadura[5].defArmadura=30;
    strcpy(jugador[2].Armadura[6].nombreArmadura,"T\xa3nica Astral");
    jugador[2].Armadura[6].defArmadura=35;
    strcpy(jugador[2].Armadura[7].nombreArmadura,"Ropas Malditas");
    jugador[2].Armadura[7].defArmadura=40;
    strcpy(jugador[2].Armadura[8].nombreArmadura,"T\xa3nica de ArchiMago");
    jugador[2].Armadura[8].defArmadura=45;
    strcpy(jugador[2].Armadura[9].nombreArmadura,"Armadura M\xa0gica");
    jugador[2].Armadura[9].defArmadura=55;
    strcpy(jugador[2].Armadura[10].nombreArmadura,"Ninguna");
    jugador[2].Armadura[10].defArmadura=0;

    strcpy(jugador[3].Arma[0].nombreArma,"Daga");
    jugador[3].Arma[0].dannoArma=10;
    strcpy(jugador[3].Arma[1].nombreArma,"Arco");
    jugador[3].Arma[1].dannoArma=20;
    strcpy(jugador[3].Arma[2].nombreArma,"Garras");
    jugador[3].Arma[2].dannoArma=30;
    strcpy(jugador[3].Arma[3].nombreArma,"Daga de Asesino");
    jugador[3].Arma[3].dannoArma=40;
    strcpy(jugador[3].Arma[4].nombreArma,"Arco Largo");
    jugador[3].Arma[4].dannoArma=50;
    strcpy(jugador[3].Arma[5].nombreArma,"Garras de Pelea");
    jugador[3].Arma[5].dannoArma=60;
    strcpy(jugador[3].Arma[6].nombreArma,"Daga Envenenada");
    jugador[3].Arma[6].dannoArma=70;
    strcpy(jugador[3].Arma[7].nombreArma,"Arco Compuesto");
    jugador[3].Arma[7].dannoArma=80;
    strcpy(jugador[3].Arma[8].nombreArma,"Garra de Drag\xa2n");
    jugador[3].Arma[8].dannoArma=90;
    char guad[7]="Guada\xa4", na[2]="a";
    strcat(guad,na);
    strcpy(jugador[3].Arma[9].nombreArma,guad);
    jugador[3].Arma[9].dannoArma=100;
    strcpy(jugador[3].Arma[10].nombreArma,"Filo Nocturno");
    jugador[3].Arma[10].dannoArma=120;
    strcpy(jugador[3].Arma[11].nombreArma,"Arco de las Hadas");
    jugador[3].Arma[11].dannoArma=120;
    strcpy(jugador[3].Arma[12].nombreArma,"Daga Oculta de Altair");
    jugador[3].Arma[12].dannoArma=120;
    strcpy(jugador[3].Arma[13].nombreArma,"Ninguna");
    jugador[3].Arma[13].dannoArma=0;

    strcpy(jugador[3].Armadura[0].nombreArmadura,"Armadura Ligera");
    jugador[3].Armadura[0].defArmadura=5;
    strcpy(jugador[3].Armadura[1].nombreArmadura,"Traje de Ladr\xa2n");
    jugador[3].Armadura[1].defArmadura=10;
    strcpy(jugador[3].Armadura[2].nombreArmadura,"Conjunto De Arquero");
    jugador[3].Armadura[2].defArmadura=15;
    strcpy(jugador[3].Armadura[3].nombreArmadura,"Cota de Malla");
    jugador[3].Armadura[3].defArmadura=20;
    strcpy(jugador[3].Armadura[4].nombreArmadura,"Armadura de Cazador");
    jugador[3].Armadura[4].defArmadura=25;
    strcpy(jugador[3].Armadura[5].nombreArmadura,"Traje de Asesino");
    jugador[3].Armadura[5].defArmadura=30;
    strcpy(jugador[3].Armadura[6].nombreArmadura,"Armadura de Placas Ligera");
    jugador[3].Armadura[6].defArmadura=35;
    strcpy(jugador[3].Armadura[7].nombreArmadura,"Conjunto Ligero Antiguo");
    jugador[3].Armadura[7].defArmadura=40;
    strcpy(jugador[3].Armadura[8].nombreArmadura,"Armadura de la Hermandad Oscura");
    jugador[3].Armadura[8].defArmadura=45;
    strcpy(jugador[3].Armadura[9].nombreArmadura,"J\x94rmundgander");
    jugador[3].Armadura[9].defArmadura=55;
    strcpy(jugador[3].Armadura[10].nombreArmadura,"Ninguna");
    jugador[3].Armadura[10].defArmadura=0;
    int menuInventario,i;
do{
    
    printf("||________________________________Inventario________________________________||\n");
    printf("|| 1.- Equipar Arma || 2.- Equipar Armadura || 3.- Pociones || 4.- Regresar ||\n");
    printf("|| Clase: %s\tHP: %.2f/%.2f\n",jugador[Clase].NombreClase,jugador[Clase].HPActual,jugador[Clase].HPMax);
    if(cont==0){
        armaSeleccionada=13;
        armaduraSeleccionada=10;
    }
    printf("Arma Equipada: %s, ",jugador[Clase].Arma[armaSeleccionada].nombreArma);
    printf("da\xa4o: %.0f\n",jugador[Clase].Arma[armaSeleccionada].dannoArma);
    printf("Armadura Equipada: %s, ",jugador[Clase].Armadura[armaduraSeleccionada].nombreArmadura);
    printf("defensa: %.0f\n\n",jugador[Clase].Armadura[armaduraSeleccionada].defArmadura);
    
    printf("Selecci\xa2n: ");
    scanf("%i",&menuInventario);
    switch(menuInventario){
        case 1:
            printf("Armas:\n");
            for(i=0;i<13;i++){
                printf("%i.-%s\n",i+1,jugador[Clase].Arma[i].nombreArma);
                printf("\t    Da\xa4o: %.0f\n",jugador[Clase].Arma[i].dannoArma);
            }
            printf("Selecci\xa2n: ");
            scanf("%i",&armaSeleccionada);
            armaSeleccionada-=1;
            cont++;
            jugador[Clase].DannoTotal=jugador[Clase].DannoBase+jugador[Clase].Arma[armaSeleccionada].dannoArma;
            break;
        case 2:
            printf("Armaduras:\n");
            for(i=0;i<11;i++){
                printf("%i.-%s\n",i+1,jugador[Clase].Armadura[i].nombreArmadura);
                printf("\t    Defensa: %.0f\n",jugador[Clase].Armadura[i].defArmadura);
            }
            printf("Selecci\xa2n: ");
            scanf("%i",&armaduraSeleccionada);
            armaduraSeleccionada-=1;
            jugador[Clase].DefensaTotal=jugador[Clase].DefensaBase+jugador[Clase].Armadura[armaduraSeleccionada].defArmadura;
            cont++;
            break;
        case 3:
            if(jugador[Clase].HPActual==jugador[Clase].HPMax){
            printf("Ya tienes la vida al m\xa0ximo!\n");
            system("pause");
            break;
            }
            if(jugador[Clase].pociones<=0){
                jugador[Clase].pociones=0;
                printf("No te quedan m\xa0s pociones\n");
                system("pause");
                break;
            }
            jugador[Clase].pociones--;
            printf("Haz usado una poci\xa2n y curado 50HP, te quedan: %i\n",jugador[Clase].pociones);
            jugador[Clase].HPActual+=50;
            if(jugador[Clase].HPActual>jugador[Clase].HPMax){
                jugador[Clase].HPActual=jugador[Clase].HPMax;
            }
            system("pause");
            break;
        case 4:
            break;
    }
    system("cls");
}while(menuInventario!=4);

}// END FuncionInventario

int estado(){
    system("cls");
printf("||________________Estado________________||\n");
printf("Clase: %s\n",jugador[Clase].NombreClase);
printf("Nivel: %i\n",jugador[Clase].LVL);
printf("XP para siguiente nivel: %.0f\n",(100-jugador[Clase].EXP));
printf("HP: %.2f/%.2f\n",jugador[Clase].HPActual,jugador[Clase].HPMax);
printf("Ataque: %.2f\n",jugador[Clase].DannoTotal);
printf("Defensa: %.2f\n",jugador[Clase].DefensaTotal);
printf("Presione cualquier tecla para salir del men\xa3...");
getch();
}

void unedl(){
    char tecla[42];
    strcpy(tecla, "Presione cualquier tecla para comenzar...");
printf("\t\t\t\t     PROYECTO FIN DE SEMESTRE\n\t\t\t\t           JUEGO DE ROL\t\t\t\t\n");
    Sleep(1000);
    for(i=0;i<97;i++){
        Sleep(10); 
        printf("_");
    }
    Sleep(10);  printf("\n|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");                  Sleep(10);  printf("\t\t\t\t\t|\n");
    printf("|\t\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");                 printf("\t\t\t\t\t|\n");
    printf("|\t\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");                  printf("\t\t\t\t\t|\n");
    printf("|\t\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");                  printf("\t\t\t\t\t|\n");
    printf("|\t\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");                  printf("\t\t\t\t\t|\n");
    printf("|\t\t\t\t"); Sleep(10);  printf(" \xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");             printf("\t\t\t\t|\n");
    printf("|\t\t\t\t");                                               printf("\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb"); printf("\t\t\t|\n");
    printf("|\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb"); printf("\t\t\t|\n");
    printf("|\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb"); printf("\t\t\t|\n");
    printf("|\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb"); printf("\t\t\t|\n");
    printf("|\t\t\t");Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb      ");      Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb "); Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb"); printf("\t\t\t|\n");
    printf("|\t\t\t");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb   ");   Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb");Sleep(10);  printf("\xdb  ");  Sleep(10);  printf("\xdb    ");    Sleep(10);  printf("\xdb"); printf("\t\t\t|\n");
    printf("|_______________________________________________________________________________________________|\n");
    for(i=0;i<42;i++){
        printf("%c",tecla[i]);
        Sleep(10);
    }
    getch();
    system("cls");
}

float DMG(int TipoDano, int DadoEnemigo, int turno){
    float danoEfectivo;

    switch(turno){
        case 1:
            switch(TipoDano){
                case 1:
                    danoEfectivo=jugador[Clase].DannoTotal-Enemigo[DadoEnemigo].Def;
                    if(danoEfectivo<0){
                        danoEfectivo=1;
                    }
                    Enemigo[DadoEnemigo].HpActual-=danoEfectivo;
                    break;
                case 2:
                    danoEfectivo=(jugador[Clase].DannoTotal*1.5)-Enemigo[DadoEnemigo].Def;
                    if(danoEfectivo<0){
                        danoEfectivo=1;
                    }
                    Enemigo[DadoEnemigo].HpActual-=danoEfectivo;
                    break;
            }
        break;
        case 2:
            danoEfectivo=Enemigo[DadoEnemigo].Dano-jugador[Clase].DefensaTotal;
            if(danoEfectivo<0){
                danoEfectivo=1;
            }
            jugador[Clase].HPActual=jugador[Clase].HPActual-danoEfectivo;
        break;
    }
return danoEfectivo;
}