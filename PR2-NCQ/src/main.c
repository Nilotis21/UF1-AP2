/*
  ____           __    _    _   _             __         ________
 |  _ \         |  \  | |  (_) | |           / _\       /  ____  \
 | |_) |_   _   | \ \ | |   _  | |          / /         | |    | |
 |  _ <| | | |  | |\ \| |  | | | |         | |          | |    | |
 | |_) | |_| |  | | \ | |  | | | |___   _   \ \_    _   | |__\ \ |
 |____/ \__, |  |_|  \__|  |_| |_____| |_|   \__/  |_|  \_____\ \/
         __/ |                                                 \_\
         |_ /
 */
#include <stdio.h>

#define SIZE 10

void main() {

  char name[15], board[SIZE][SIZE], col2;
  int num, aux = 3, i, j, exp = 0, col = -1, row, rep = 0;

  printf(" _    _ _    _ _   _ _____ _____ _____         _        ____  \n"
    "| |  | | |  | | \\ | |  __ \\_   _|  __ \\       | |      / __ \\\n"
    "| |__| | |  | |  \\| | |  | || | | |__) |      | |     | |__| |\n"
    "|  __  | |  | | . \\ | |  | || | |  _  /       | |     |  __  |\n"
    "| |  | | |__| | |\\  | |__| || |_| | \\ \\       | |____ | |  | |\n"
    "|_|  |_|\\____/|_| \\_|_____/_____|_|  \\_\\      |______/|_|  |_|\n\n"
    "\t ______ _      ____ _______   ____"
    "\n\t|  ____| |    / __ \\__   __| / __ \\"
    "\n\t| |__  | |   | |  | | | |   | |__| |"
    "\n\t|  __| | |   | |  | | | |   |  __  |"
    "\n\t| |    | |___| |__| | | |   | |  | |"
    "\n\t|_|    |______\\____/  |_|   |_|  |_|\n");

  //Pregunto el nombre al usuario para poder dirigirme hacia él.
  printf("\n\n  Introduce tu nombre: ");
  scanf("%s", name);

  do {
    //Este primer printf es el resultado de juntar varios prints en uno para ahorrar uso de CPU.
    /*printf("\n***************************************************\n**"
    		"***************HUNDIR LA FLOTA*******************\n*******"
    		"********************************************\n");*/
    printf("\n\n Saludos %s, escoge la dificultad del juego:\n\n  1 - Fácil\t\t\t "
      "+50 XP\n  2 - Heroico\t\t\t +100 XP\n  3 - Legendario\t\t "
      "+200 XP\n  4 - Salir del programa.\t +0 XP\n\n  Tus puntos"
      " actuales son: %d XP\n\n***********************************"
      "****************\n", name, exp);
    scanf("%d", & num);
    /*La diferencia entre las dificultades sera la cantidad de barcos en el tablero.
     A mayor dificultad menos barcos para difucultar el juego. Pero en esta primera
     revision solo esta implementada una difultad para todos los niveles.*/

    //Valido el numero de intentos fallidos eligiendo dificultad.
    while (num < 1 || num > 4) {
      printf("  Ese número no está disponible. Prueba otra vez."
        "\n  (Intentos restantes : %d)\n", aux - 1);
      scanf("%d", & num);
      aux--;
      if (aux == 0) {
        break;
      }
    }

    if (aux > 0) {
      switch (num) {
      case 1:
        printf("  Vale jugaremos en Fàcil, tranquilo/a no será\n  difícil.\n");

        //Printar el tablero vacío.
        printf("\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
          "--+---+---+---+---+---+---+---+---+---+\n");
        for (i = 0; i < SIZE; i++) {
          if (i == 9) {
            printf("  %d  | ", i + 1);
          } else {
            printf("   %d  | ", i + 1);
          }
          for (j = 0; j < SIZE; j++) {
            printf("  | ");
          }
          printf(
            "\n      +---+---+---+---+---+---+---+---+---+---+\n");
        }

        //Poner los barcos en el tablero.
        for (i = 0; i < SIZE; i++) {
          for (j = 0; j < SIZE; j++) {
            if (i == 1 && j == 8) {
              board[i][j] = 1;
            } else if (i == 2 && (j == 2 || j == 4 || j == 5 || j == 8)) {
              board[i][j] = 1;
            } else if (i == 3 && (j == 2 || j == 8)) {
              board[i][j] = 1;
            } else if (i == 4 && (j == 2)) {
              board[i][j] = 1;
            } else if (i == 5 && (j == 4 || j == 5 || j == 6 || j == 7)) {
              board[i][j] = 1;
            } else if (i == 8 && (j == 2 || j == 3 || j == 4 || j == 5 || j == 6)) {
              board[i][j] = 1;
            } else {
              board[i][j] = 0;
            }
          }
        }

        do {
          printf("\n  Introduce la fila: ");
          scanf("%d", & row);
        } while (row < 1 || row > 10);

        do {
          printf("\n  Introduce la columna: ");
          scanf(" %c", & col2);

          //Comparamos la letra introducida con su carácter en la tabla ASCII.
          if (col2 == 65 || col2 == 97) {
            col = 0;
          } else if (col2 == 66 || col2 == 98) {
            col = 1;
          } else if (col2 == 67 || col2 == 99) {
            col = 2;
          } else if (col2 == 68 || col2 == 100) {
            col = 3;
          } else if (col2 == 69 || col2 == 101) {
            col = 4;
          } else if (col2 == 70 || col2 == 102) {
            col = 5;
          } else if (col2 == 71 || col2 == 103) {
            col = 6;
          } else if (col2 == 72 || col2 == 104) {
            col = 7;
          } else if (col2 == 73 || col2 == 105) {
            col = 8;
          } else if (col2 == 74 || col2 == 106) {
            col = 9;
          }
        } while (col < 0 || col > 9);

        row = row - 1;

        if (board[row][col] == 1) {
          printf("\n\n\t\t\t¡TOCADO!"//\n\tLos barcos estan representados con █."
            "\n\tTu disparo esta representado con 'X'."
            "\n\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
            "--+---+---+---+---+---+---+---+---+---+\n");
          for (i = 0; i < SIZE; i++) {
            if (i == 9) {
              printf("  %d  | ", i + 1);
            } else {
              printf("   %d  | ", i + 1);
            }
            for (j = 0; j < SIZE; j++) {
              if (board[i][j] == 0) {
                printf("  | ");
              } else if (i == row && j == col) {
                printf("X | ");
              } else {
                printf("  | ");
              }
            }
            printf(
              "\n      +---+---+---+---+---+---+---+---+---+---+\n");
          }
          exp = exp + 50;
          printf("\n  Tus puntos actuales son: %d XP\n", exp);
          do {
            printf("  ¿Quieres volver a jugar? [1 = Sí / 0 = No]\n");
            scanf("%d", & rep);
          } while (rep < 0 || rep > 1);

        } else {
          printf("\n\n\t\t\t¡AGUA!"
            "\n\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
            "--+---+---+---+---+---+---+---+---+---+\n");
          for (i = 0; i < SIZE; i++) {
            if (i == 9) {
              printf("  %d  | ", i + 1);
            } else {
              printf("   %d  | ", i + 1);
            }
            for (j = 0; j < SIZE; j++) {
              printf("  | ");
            }
            printf(
              "\n      +---+---+---+---+---+---+---+---+---+---+\n");
          }
          printf("\n  Tus puntos actuales son: %d XP\n", exp);
          do {
            printf("  ¿Quieres volver a jugar? [1 = Sí / 0 = No]\n");
            scanf("%d", & rep);
          } while (rep < 0 || rep > 1);
        }

        break;
      case 2:
        printf("  ¡Con que Heroico! Veo que te gustan los retos.\n");

        //Printar el tablero vacio.
        printf("\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
          "--+---+---+---+---+---+---+---+---+---+\n");
        for (i = 0; i < SIZE; i++) {
          if (i == 9) {
            printf("  %d  | ", i + 1);
          } else {
            printf("   %d  | ", i + 1);
          }
          for (j = 0; j < SIZE; j++) {
            printf("  | ");
          }
          printf(
            "\n      +---+---+---+---+---+---+---+---+---+---+\n");
        }

        //Poner los barcos en el tablero.
        for (i = 0; i < SIZE; i++) {
          for (j = 0; j < SIZE; j++) {
            if (i == 0 && (j == 8 || j == 9)) {
              board[i][j] = 1;
            } else if (i == 2 && (j == 2 || j == 3 || j == 4 || j == 5 || j == 6)) {
              board[i][j] = 1;
            } else if (i == 3 && (j == 7)) {
              board[i][j] = 1;
            } else if (i == 4 && (j == 7)) {
              board[i][j] = 1;
            } else if (i == 5 && (j == 2 || j == 3 || j == 4 || j == 7)) {
              board[i][j] = 1;
            } else if (i == 7 && (j == 6 || j == 7 || j == 8 || j == 9)) {
              board[i][j] = 1;
            } else {
              board[i][j] = 0;
            }
          }
        }

        do {
          printf("\n  Introduce la fila: ");
          scanf("%d", & row);
        } while (row < 1 || row > 10);

        do {
          printf("\n  Introduce la columna: ");
          scanf(" %c", & col2);

          //Comparamos la letra introducida con su carácter en la tabla ASCII.
          if (col2 == 65 || col2 == 97) {
            col = 0;
          } else if (col2 == 66 || col2 == 98) {
            col = 1;
          } else if (col2 == 67 || col2 == 99) {
            col = 2;
          } else if (col2 == 68 || col2 == 100) {
            col = 3;
          } else if (col2 == 69 || col2 == 101) {
            col = 4;
          } else if (col2 == 70 || col2 == 102) {
            col = 5;
          } else if (col2 == 71 || col2 == 103) {
            col = 6;
          } else if (col2 == 72 || col2 == 104) {
            col = 7;
          } else if (col2 == 73 || col2 == 105) {
            col = 8;
          } else if (col2 == 74 || col2 == 106) {
            col = 9;
          }
        } while (col < 0 || col > 9);

        row = row - 1;

        if (board[row][col] == 1) {
          printf(
            "\n\n\t\t\t¡TOCADO!"//\n\tLos barcos estan representados con █."
            "\n\tTu disparo esta representado con 'X'."
            "\n\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
            "--+---+---+---+---+---+---+---+---+---+\n");
          for (i = 0; i < SIZE; i++) {
            if (i == 9) {
              printf("  %d  | ", i + 1);
            } else {
              printf("   %d  | ", i + 1);
            }
            for (j = 0; j < SIZE; j++) {
              if (board[i][j] == 0) {
                printf("  | ");
              } else if (i == row && j == col) {
                printf("X | ");
              } else {
                printf("  | ");
              }
            }
            printf(
              "\n      +---+---+---+---+---+---+---+---+---+---+\n");
          }
          exp = exp + 100;
          printf("\n  Tus puntos actuales son: %d XP\n", exp);

          do {
            printf("  ¿Quieres volver a jugar? [1 = Sí / 0 = No]\n");
            scanf("%d", & rep);
          } while (rep < 0 || rep > 1);

        } else {
          printf(
            "\n\n\t\t\t¡AGUA!"
            "\n\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
            "--+---+---+---+---+---+---+---+---+---+\n");
          for (i = 0; i < SIZE; i++) {
            if (i == 9) {
              printf("  %d  | ", i + 1);
            } else {
              printf("   %d  | ", i + 1);
            }
            for (j = 0; j < SIZE; j++) {
              printf("  | ");
            }
            printf(
              "\n      +---+---+---+---+---+---+---+---+---+---+\n");
          }
          printf("\n  Tus puntos actuales son: %d XP\n", exp);

          do {
            printf("  ¿Quieres volver a jugar? [1 = Sí / 0 = No]\n");
            scanf("%d", & rep);
          } while (rep < 0 || rep > 1);
        }

        break;
      case 3:
        printf("  ¿Estás seguro de que quieres jugar en Legendario?\n "
          " Si lo superas, serás recordado con honor.\n");

        //Printar el tablero vacio.
        printf("\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
          "--+---+---+---+---+---+---+---+---+---+\n");
        for (i = 0; i < SIZE; i++) {
          if (i == 9) {
            printf("  %d  | ", i + 1);
          } else {
            printf("   %d  | ", i + 1);
          }
          for (j = 0; j < SIZE; j++) {
            printf("  | ");
          }
          printf(
            "\n      +---+---+---+---+---+---+---+---+---+---+\n");
        }

        //Poner los barcos en el tablero.
        for (i = 0; i < SIZE; i++) {
          for (j = 0; j < SIZE; j++) {
            if (i == 1 && (j == 1 || j == 2 || j == 3 || j == 4 )){
              board[i][j] = 1;
            } else if (i == 4 &&
              (j == 0 || j == 4 || j == 5 || j == 6)) {
              board[i][j] = 1;
            } else if (i == 5 && (j == 0 || j == 2)) {
              board[i][j] = 1;
            } else if (i == 6 && (j == 2)) {
              board[i][j] = 1;
            } else if (i == 7 &&
              (j == 2 || j == 7 || j == 8 || j == 9)) {
              board[i][j] = 1;
            } else if (i == 8 && j == 2) {
              board[i][j] = 1;
            } else if (i == 9 && j == 2) {
              board[i][j] = 1;
            } else {
              board[i][j] = 0;
            }
          }
        }

        do {
          printf("\n  Introduce la fila: ");
          scanf("%d", & row);
        } while (row < 1 || row > 10);
        do {
          printf("\n  Introduce la columna: ");
          scanf(" %c", & col2);

          //Comparamos la letra introducida con su carácter en la tabla ASCII.
          if (col2 == 65 || col2 == 97) {
            col = 0;
          } else if (col2 == 66 || col2 == 98) {
            col = 1;
          } else if (col2 == 67 || col2 == 99) {
            col = 2;
          } else if (col2 == 68 || col2 == 100) {
            col = 3;
          } else if (col2 == 69 || col2 == 101) {
            col = 4;
          } else if (col2 == 70 || col2 == 102) {
            col = 5;
          } else if (col2 == 71 || col2 == 103) {
            col = 6;
          } else if (col2 == 72 || col2 == 104) {
            col = 7;
          } else if (col2 == 73 || col2 == 105) {
            col = 8;
          } else if (col2 == 74 || col2 == 106) {
            col = 9;
          }
        } while (col < 0 || col > 9);

        row = row - 1;

        if (board[row][col] == 1) {
          printf(
            "\n\n\t\t\t¡TOCADO!"//\n\tLos barcos estan representados con █."
            "\n\tTu disparo esta representado con 'X'."
            "\n\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
            "--+---+---+---+---+---+---+---+---+---+\n");
          for (i = 0; i < SIZE; i++) {
            if (i == 9) {
              printf("  %d  | ", i + 1);
            } else {
              printf("   %d  | ", i + 1);
            }
            for (j = 0; j < SIZE; j++) {
              if (board[i][j] == 0) {
                printf("  | ");
              } else if (i == row && j == col) {
                printf("X | ");
              } else {
                printf("  | ");
              }
            }
            printf(
              "\n      +---+---+---+---+---+---+---+---+---+---+\n");
          }
          exp = exp + 200;
          printf("\n  Tus puntos actuales son: %d XP\n", exp);

          do {
            printf("  ¿Quieres volver a jugar? [1 = Sí / 0 = No]\n");
            scanf("%d", & rep);
          } while (rep < 0 || rep > 1);

        } else {
          printf(
            "\n\n\t\t\t¡AGUA!"
            "\n\n\tA   B   C   D   E   F   G   H   I   J\n      +-"
            "--+---+---+---+---+---+---+---+---+---+\n");
          for (i = 0; i < SIZE; i++) {
            if (i == 9) {
              printf("  %d  | ", i + 1);
            } else {
              printf("   %d  | ", i + 1);
            }
            for (j = 0; j < SIZE; j++) {
              printf("  | ");
            }
            printf(
              "\n      +---+---+---+---+---+---+---+---+---+---+\n");
          }
          printf("\n  Tus puntos actuales son: %d XP\n", exp);

          do {
            printf("  ¿Quieres volver a jugar? [1 = Sí / 0 = No]\n");
            scanf("%d", & rep);
          } while (rep < 0 || rep > 1);
        }

        break;
      default:
    	rep = 0;
        break;
      }
    } else {
      printf("¡Error! Demasiados intentos fallidos.");
    }
  } while ((num < 0 && num > 5) || rep == 1);
  printf("  Saliste del programa.\n  Muchas gracias por jugar <3.\n  Tus puntos actuales son %d XP.", exp);
}
