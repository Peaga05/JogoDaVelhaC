#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
  setlocale(LC_ALL," ");
  int opcao, player1, player2, linha, coluna, tamanho=100, partidas=0, empate=0, replay, a, b, aux, aux2,carg=0;
  int menu=0,menuInfo,option,nulo, pesqUser,pesquisa, n;
  int usuarios[tamanho], vitoriasUser[tamanho], partidasUser[tamanho], ranking[tamanho], ordem[tamanho];
  char tabuleiro[3][3];

 //Inicializando os vetores
  for(int i=0;i<tamanho;i++){
    usuarios[i] = i+1;
    vitoriasUser[i]= 0;
    partidasUser[i]= 0;
  }
 
  while(menu == 0){
   replay=0;
   menuInfo=0;
   pesquisa=0;
   printf("\n\t\t JOGO DA VELHA");
   printf("\n FEITO POR PAULO HENRIQUE SERAFIM");
   printf("\n");
   printf("\n 1- Iniciar partida");
   printf("\n 2- Visualizar informações");
   printf("\n 3- Carregar informações");
   printf("\n 4- Sair");
   printf("\n");
   printf("\n Selecione uma opção: ");
   scanf("%d", &opcao);
   system("clear");
   // Vereficando se a opção é valida
   while(opcao>4 || opcao<1){
     printf("\n Opção invalida!");
     printf("\n Digite outra opção! 1- Iniciar partida / 2- Visualizar informações / 3- Carregar informações / 4- Sair: ");
     scanf("%d", &opcao);
     system("clear");
   }
   system("clear");

   switch(opcao){

    case 1:

     printf("\n Iniciando partida...");
     printf("\n");
     // Escolha dos jogadores
     printf("\n Digite o primeiro jogador (Entre 1 e 100): ");
     scanf("%d", &player1);
     // verificação se o usuario 1 é valido
     while(player1>100 || player1<1){
      printf("\n Usuário invalido!");
      printf("\n Digite o primeiro jogador (Entre 1 e 100): ");
      scanf("%d", &player1);
     }

     printf("\n Digite o segundo jogador (Entre 1 e 100, menos o %d): ", player1);
     scanf("%d", &player2);
     // verificação se o usuario 2 é valido
     while(player2>100 || player2<1 || player2==player1){
      printf("\n Usuário invalido ou já eslhido!");
      printf("\n Digite o primeiro jogador (Entre 1 e 100, menos o %d): ",player1);
      scanf("%d", &player2);
     }
     while(replay == 0){
    
     //Inicializando o tabuleiro
     for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
      tabuleiro[i][j] = ' ';
      }
     }
     
     system("clear");
     printf("\n Usuário %d joga com 'X' e usuário %d joga com 'O' ", player1,player2);
     printf("\n");
     printf("\n\t\t   Tabuleiro");
     printf("\n");
     printf("\n \t \t  0   1   2\n");
     printf("\n");
     printf("\t0\t  %c | %c | %c\n",tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
     printf("\t \t ------------\n");
     printf("\t1\t  %c | %c | %c\n",tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
     printf("\t \t ------------\n");
     printf("\t2\t  %c | %c | %c\n",tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);

     //For de jogadas e verificação do vencedor
     for(int jogadas=0;jogadas<9;jogadas++){
      if(jogadas%2 == 0){
        printf("\n Usuário %d digite a cordenada desejada (X): ", player1);
      }else{
        printf("\n Usuário %d digite a cordeanda desejada (O): ", player2);
      }
     //Verifica se as linhas e colunas são válidas
      do{
         printf("\n Linha: ");
         scanf("%d", &linha);
         while(linha>2 || linha<0){
          printf("\n Linha invlaida, digite um valor entre 0 e 2: ");
          scanf("%d",&linha);
          }
          printf("\n Coluna: ");
          scanf("%d", &coluna);
          while(coluna>2 || coluna<0){
            printf("\n Coluna invlaida, digite um valor entre 0 e 2: ");
            scanf("%d",&coluna);
          }
          if(tabuleiro[linha][coluna] != ' '){
            printf("\n Local já preenchido, esolha outra combinação");
          }

        }while(tabuleiro[linha][coluna] != ' ');

      //Inserindo X ou O no tabuleiro
      if(jogadas%2 == 0){
        tabuleiro[linha][coluna] = 'X';
      }else{
        tabuleiro[linha][coluna] = 'O';
      }
      system("clear");
      printf("\n\t\t   Tabuleiro");
      printf("\n");
      printf("\n \t \t  0   1   2\n");
      printf("\n");
      printf("\t0\t  %c | %c | %c\n",tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
      printf("\t \t ------------\n");
      printf("\t1\t  %c | %c | %c\n",tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
      printf("\t \t ------------\n");
      printf("\t2\t  %c | %c | %c\n",tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);

      //Verificação de vencedor por linha (player1)
      if(tabuleiro[0][0] == 'X' && tabuleiro[0][1]=='X' && tabuleiro[0][2]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }
      else if(tabuleiro[1][0] == 'X' && tabuleiro[1][1]=='X' && tabuleiro[1][2]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }
      else if(tabuleiro[2][0] == 'X' && tabuleiro[2][1]=='X' && tabuleiro[2][2]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }

      //Verificação de vencedor por linha (player2)
      else if(tabuleiro[0][0] == 'O' && tabuleiro[0][1]=='O' && tabuleiro[0][2]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }
      else if(tabuleiro[1][0] == 'O' && tabuleiro[1][1]=='O' && tabuleiro[1][2]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }
      else if(tabuleiro[2][0] == 'O' && tabuleiro[2][1]=='O' && tabuleiro[2][2]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }

      //Verificação de vencedor por coluna (player1)
      else if(tabuleiro[0][0] == 'X' && tabuleiro[1][0]=='X' && tabuleiro[2][0]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
         vitoriasUser[player1-1]+=1;
        break;
      }
      else if(tabuleiro[0][1] == 'X' && tabuleiro[1][1]=='X' && tabuleiro[2][1]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }
      else if(tabuleiro[0][2] == 'X' && tabuleiro[1][2]=='X' && tabuleiro[2][2]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }

      //Verificação de vencedor por coluna (player2)
      else if(tabuleiro[0][0] == 'O' && tabuleiro[1][0]=='O' && tabuleiro[2][0]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }
      else if(tabuleiro[0][1] == 'O' && tabuleiro[1][1]=='O' && tabuleiro[2][1]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }
      else if(tabuleiro[0][2] == 'O' && tabuleiro[1][2]=='O' && tabuleiro[2][2]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }

      //Verificação de vecedor diagonal principal e segundaria (player1)
      else if(tabuleiro[0][0] == 'X' && tabuleiro[1][1]=='X' && tabuleiro[2][2]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }
      else if(tabuleiro[0][2] == 'X' && tabuleiro[1][1]=='X' && tabuleiro[2][0]=='X'){
        printf("\n O JOGADOR %d GANHOU", player1);
        vitoriasUser[player1-1]+=1;
        break;
      }

      //Verificação de vecedor diagonal principal e segundaria (player2)
      else if(tabuleiro[0][0] == 'O' && tabuleiro[1][1]=='O' && tabuleiro[2][2]=='O'){
        printf("\nO JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }
      else if(tabuleiro[0][2] == 'O' && tabuleiro[1][1]=='O' && tabuleiro[2][0]=='O'){
        printf("\n O JOGADOR %d GANHOU", player2);
        vitoriasUser[player2-1]+=1;
        break;
      }

      else{
       empate++;
      }

     }
      if(empate==9){
      printf("\n A partida terminou empatada!");
     }
     printf("\n Fim de jogo");
     //Adicionando uma partida a mais no vetor referente ao usuario e somando partidas
     partidasUser[player1-1]++;
     partidasUser[player2-1]++;
     partidas++;
     empate=0;
     //Verficando se desejam jogar outra partida
     printf("\n");
     printf("\n Deseja jogar outra partida? SIM = 0 / NÃO = 1: ");
     scanf("%d", &option);
     while(option < 0 || option > 1){
      printf("\n Digite um valor valido");
      printf("\n Deseja jogar outra partida? SIM = 0 / NÃO = 1: ");
      scanf("%d", &option);
     }
     system("clear");
     if(option== 0){
      replay = 0;
     } else if(option == 1){
      menu=0;
      replay = 1;
      }
    }
     break;
     case 2:
     system("clear");
     while(menuInfo==0){
       printf("\n------------------------------------------------------------------------");       
       printf("\n 1- Quantidade de partidas jogadas ao todo");
       printf("\n------------------------------------------------------------------------");
       printf("\n 2- Quantidade de partidas jogadas por usuário ");
       printf("\n------------------------------------------------------------------------");
       printf("\n 3- Quantidade de vitórias de todos os usuários");
       printf("\n------------------------------------------------------------------------");
       printf("\n 4- Quantidade de vitórias de um usuário específico");
       printf("\n------------------------------------------------------------------------");
       printf("\n 5- Ranking dos jogadores em ordem decrescente do número de vitórias");
       printf("\n------------------------------------------------------------------------");       
       printf("\n 6- Sair ");
       printf("\n------------------------------------------------------------------------");     
       printf("\n\n Digite a opção desejada: ");
       scanf("%d", &option);
       //Verificação se a opção é valida
       while(option>6 || option<1){
         printf("\n Opção invalida, digite outra vez!");
         printf("\n -> ");
         scanf("%d", &option);
       } 
       system("clear");

       switch(option){
         case 1:
          printf("\n Ao todo foram jogadas %d partidas", partidas);
          printf("\n Voltar = 0 / Menu principal = 1");
          printf("\n -> ");
          scanf("%d", &option);
          //Verificação se a opção é valida
          while(option>1 || option<0){
            printf("\n Opção invalida!");
            printf("\n Voltar = 0 / Menu principal = 1");
            printf("\n -> ");
            scanf("%d",&option);
          }
         if(option==0){
           menuInfo=0;
           system("clear"); 
         }else if(option==1){
           menu=0;
           menuInfo=1;
           system("clear");
         }
         break;

         case 2:
          nulo = 0;
          printf("\n------------------------------------------------------------");
          for(int i=0;i<tamanho;i++){
            if(partidasUser[i]>=1){
              printf("\n\t O jogaodor %d jogou %d partidas", i+1,partidasUser[i]);
              printf("\n------------------------------------------------------------");
            }else{
              nulo++;
            }
          }
          //Exibe na tela a quantidade de jogadores que ainda não venceram uma partida
          if(nulo>=1){
            printf("\n %d usuários não jogaram pelo menos uma partida", nulo);
          }
          printf("\n");
          printf("\n Voltar = 0 / Menu principal = 1");
          printf("\n -> ");
          scanf("%d", &option);
          //Verificação se a opção é valida
          while(option>1 || option<0){
            printf("\n Opção invalida!");
            printf("\n Voltar = 0 / Menu principal = 1");
            printf("\n -> ");
            scanf("%d",&option);
          }
         if(option==0){
           menuInfo=0;
           system("clear"); 
         }else if(option==1){
           menu=0;
           menuInfo=1;
           system("clear");
         }
         break;
         case 3:
         nulo=0;
         printf("\n------------------------------------------------------------");
         for(int i=0;i<tamanho;i++){
           if(vitoriasUser[i]>=1){
             printf("\n\t O usuário %d ganhou %d partidas", i+1, vitoriasUser[i]);
             printf("\n------------------------------------------------------------");
           }
           
           else{
             nulo++;
           }
         }
         //Exibe na tela a quantidade de jogadores que ainda não jogaram uma partida
         if(nulo>=1){
           printf("\n %d usuários não ganharam pelo menos uma partida", nulo);
         }
          printf("\n");
          printf("\n Voltar = 0 / Menu principal = 1");
          printf("\n -> ");
          scanf("%d", &option);
          //Verificação se a opção é valida
          while(option>1 || option<0){
            printf("\n Opção invalida!");
            printf("\n Voltar = 0 / Menu principal = 1");
            printf("\n -> ");
            scanf("%d",&option);
          }
          if(option==0){
           menuInfo=0;
           system("clear"); 
          }else if(option==1){
           menu=0;
           menuInfo=1;
           system("clear");
          }
          break;
          
          case 4:
          while(pesquisa==0){
            printf("\n Digite o usuário que deseja ver as vitorias: ");
            scanf("%d",&pesqUser);
            while(pesqUser>100 || pesqUser<1){
              printf("\n Usuário invalido, digite um entre 1 e 100");
              printf("\n Digite o usuário que deseja ver as vitorias: ");
              scanf("%d",&pesqUser);
            }
            printf("\n O usuário %d teve %d vitorias", pesqUser,vitoriasUser[pesqUser-1]);
            printf("\n Deseja fazer outra pesquisa ou voltar ao menu de infomações? pesquisar=0 / menu=1: ");
            scanf("%d", &option);
            // Vereficando se a opção é valida
            while(option>1 || option<0){
            printf("\n Opção invalida!");
            printf("\n Para fazer outra pesquisa digite 0, para voltar ao menu de infomações digite 1: ");
            scanf("%d",&option);
           }
           if(option==0){
           pesquisa=0;
           system("clear"); 
           }else if(option==1){
           menuInfo=0;
           pesquisa=1;
           system("clear");
           }
          }
          break;

          case 5:
          //Cópia as vitorias dos usuarios para vetor ordem
          for(int i=0;i<tamanho;i++){
           ordem[i] = vitoriasUser[i];
           ranking[i] = usuarios[i];
          }
          //Coloca o vetor ordem de forma decrescete, maior numero de vitorias para o menor junto com usuário correspondente usando o BublleSorte
          do{
           a=0;
           for(b = 1; b < tamanho; b++){
           if(ordem[b-1] < ordem[b]){
              aux = ordem[b-1];
              aux2= ranking[b-1];
              ordem[b-1] = ordem[b]; 
              ranking[b-1] = ranking[b];
              ordem[b] = aux;
              ranking[b] = aux2;
              a=1;
              }
            }
          }while(a==1);
          printf("\n------------------------------------------------------------");
          printf("\n \tPOSIÇÃO           USUÁRIO            VITORIAS");
          
          for(int i=0;i<tamanho;i++){
            printf("\n------------------------------------------------------------");
            printf("\n \t  %dº                  %d                  %d",i+1,ranking[i],ordem[i]);
          }
          printf("\n------------------------------------------------------------");
          printf("\n");
          printf("\n Voltar = 0 / Menu principal = 1");
          printf("\n -> ");
          scanf("%d", &option);
          while(option>1 || option<0){
            printf("\n Opção invalida!");
            printf("\n Voltar = 0 / Menu principal = 1");
            printf("\n -> ");
            scanf("%d",&option);
          }
          if(option==0){
           menuInfo=0;
           system("clear"); 
           }else if(option==1){
           menuInfo=1;
           menu=0;
           system("clear");
          }
          break;

          case 6:
          menu = 0;
          menuInfo = 1;
          break; 
        } 
      }
      break;
      
     case 3:
     //Verifica se os valores já foram carregados alguma vez, se não foi carrega eles
     if(carg == 0){
       for(int i=0;i<tamanho;i++){
       vitoriasUser[i]+=i+1;
       partidas+=i;
       partidasUser[i]+=i+1;
      }
      printf("\n Valores carregados");
      carg = 1;
     }else{
       printf("\n Os valores já foram carregados");
     }
     printf("\n");     

      //Verificação se a opção é valida
      printf("\n Voltar = 0 / Sair = 1: ");
      scanf("%d", &option);
      while(option>1 || option<0){
        printf("\n Opção invalida!");
        printf("\n Voltar = 0 / Sair = 1: ");
        scanf("%d", &option);
        system("clear");
      }
      if(option==0){
        menu=0;
        system("clear");
      }
      else if(option==1){
        system("clear");
        printf("\n Saindo...");
        menu=1;
      }
     break;

     case 4:
      printf("\n Saindo...");
      menu = 1;
      break;
    }
  }
    return 0;
}
