/*retrabalho em filas, hohoho*/
#include <stdio.h>
#include <locale.h>
#define max 20

int fila[max],fim = -1, inicio = -1;

void funcao_adicionar_itens_a_fila(int *numero){
    ++fim;
    
    fila[fim] = *numero;
    
}

void funcao_remover_itens_da_fila(){
    inicio++;
}

void trancar_parcial(){
    
    int aux = max - 1;
    
    int contador_de_posicoes = (fim - inicio) + 1;  
    
    for(fim ; fim > inicio ; fim--){
        fila[aux] = fila[fim];
        aux--;
    }
    fim = max -1;
    inicio = max - contador_de_posicoes;
}

void trancar_total(){
    fim = inicio = max - 1;
}

void listar_a_fila(){
    
    int i = inicio + 1;
    
    for(i ; i <= fim; i++){
        printf(" [%d] ",fila[i]);
    }
}

void listar_o_vetor(){
    
    for(int i = 0; i <= fim; i++){
        if(i <= inicio)printf("*[%d] ",fila[i]);
        else printf(" [%d] ",fila[i]);
    }
}

void zerar_a_fila(){
    
    inicio = -1;
    fim = -1;
    
}

int main()
{
    setlocale(LC_ALL, "");
    printf("\t\t\t*ATENDIMENTO AO PACIENTE*");
        
    while(1){
        printf("\n\n_informe a opção que queres escolher:_\n\n");
        printf("1 - para adicionar um elemento qualquer\t\t2 - para remover o último elemento inserido\n");
        printf("3 - zerar a fila\t\t\t\t4 - listar a fila\n");
        printf("5 - listar o vetor\t\t\t\t6 - trancar total\n");
        printf("7 - terminar de atender, mas encerrar a fila\t8 - para encerrar o programa\n");
        int opcao;
        scanf("%d", &opcao);
        if(opcao == 8)break;
        
        switch(opcao){
            case 1:
                if(fim < max - 1){
                    printf("informe o valor que vais inserir: \n");
                    int valor;
                    scanf("%d",&valor);
                    funcao_adicionar_itens_a_fila(&valor);
                }
                else{
                    printf("a fila ja esta completa\n");
                }
                break;
            case 2:
                if(fim > inicio)funcao_remover_itens_da_fila();
                else printf("nao há itens para remover da fila!\n");
                break;
            case 3:
                if (fim != -1)zerar_a_fila();
                else printf("a fila já está zerada!\n");
                break;
            case 4:
                if(fim > inicio)listar_a_fila();
                else printf("nao há itens para serem atendidos!\n");
                break;
            case 5:
                if(fim > -1)listar_o_vetor();
                else printf("não há itens no vetor para listar!\n");
                break; //to esquecendo dos breaks krl
            case 6:
                trancar_total();
                break;
            case 7:
                if(inicio < fim)trancar_parcial();
                else printf("não há pacientes para atender e realizar esta execução");
                break;
            default :
                printf("opção invalida! TENTE NOVAMENTE\n");
        }
    }

    return 0;
}
//FUNCOES USADAS NO SISTEMA DE FILAS EM C: TRANCAR trancar_parcial
//TRANCAR_TOTAL  ,  ZERAR, PUSH, POP, LISTAR O VETOR FISICO, LISTAR APENAS A FILA...
