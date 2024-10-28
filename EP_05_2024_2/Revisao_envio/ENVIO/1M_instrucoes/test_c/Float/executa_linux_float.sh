#!/bin/bash
  #Executa comando
  FILE="main_float_1.c"
  gcc -Wall -W "$FILE" && ./a.out
  echo
  #Aguarda por 5 segundos
  read -t 5 -s -r -p  $'Pressione ENTER para iniciar.....'
  #Executa comando
  FILE="main_float_2.c"
  gcc -Wall -W "$FILE" && ./b.out
  echo
  #Aguarda por 5 segundos
  read -t 5 -s -r -p  $'Atribuicao i=j\nPressione ENTER para continuar.....'
  #Executa comando
  FILE="main_float_3.c"
  gcc -Wall -W "$FILE" && ./c.out
  echo
  #Aguarda por 5 segundos
  read -t 5 -s -r -p  $'Atribuicao i=i+3\nPressione ENTER para continuar.....'
  #Executa comando
  FILE="main_float_4.c"
  gcc -Wall -W "$FILE" && ./d.out
  echo
  #Aguarda por 5 segundos
  read -t 5 -s -r -p  $'Atribuicao i=i*3\nPressione ENTER para continuar.....'
  #Executa comando
  FILE="main_float_5.c"
  gcc -Wall -W "$FILE" && ./e.out
  echo
  #Aguarda por 5 segundos
  read -t 5 -s -r -p  $'Processo Finalizado\nPressione ENTER para encerrar.....'
  
