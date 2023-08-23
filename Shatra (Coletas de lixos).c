#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//Estrutura que sera usada para realizar cadastro
struct tipo_cadastro
{


       int cod;
       char endereco[60];
       char responsavel[60];
       char sexo[60];
       int idade;
       int telefone;
       char NOMEDOCLIENTE[60];
       char Tipodelixo[60];
       int vazio;

} registros[100];

//Funçoes que serao usadas
void cadastrar(int cod, int pos); // pos = posição

//Funçao para consulta
void consultar( void );

//Funçao para exibir relatorio
int relatorio( void );

//Função para verificar posição
int verifica_pos( void );

//Função para verificar codigo
int verifica_cod( int cod );

//Função para verificar posição do codigo
int verifica_pos( void );

//Função para excluir cadastro
void excluir( void );

//Começo do programa principal
int main( void )

{
                                           setlocale(LC_ALL,"Portuguese");
    	system("COLOR 0F0");     // PARA MUDAR A COR DA INTERFACE
    int op = 0, posicao, codaux, retorno;

    while ( op != 5 )
    {
        printf("\n\n\t\t\t\t RUBBISH TRASH \n\n\n" );
        printf("MENU\n\n1 - CADASTRAR\n2 - DADOS DO CLIENTE\n3 - EXCLUIR\n4 - =====EM BREVE=====\n5 - EXIT\n\n=====EM BREVE=====: ");
        scanf("%d",&op);
        system("cls");
        switch ( op )
        {
            case 1: // CADASTRAR
            {

                posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nDIGITE SEU CPF/CNPJ: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastrar( codaux, posicao );
                    else
                        printf("\n ESSE CPF/CNPJ JA ESTÁ NO SISTEMA\n");

                }
                else
                    printf("\nNAO CONSEGUIMOS REALIZAR SEU CADASTRO!\n");

                break;

            }
            case 2: // CONSULTAR
            {
                consultar();
                break;
            }
            case 3:
            {
                excluir();
                break;
            }
            case 4:
            {
                int main();
                break;
            }
            case 5:
            {
                 printf("\n Encerrando o Programa");
                 getchar();
                 break;
            }
            default :
                printf("Opcao Invalida");
                break;
        }
    }


    getchar();

    return 0;

}//Final da Main

// FUNÇAO CADASTRAR
void cadastrar( int cod, int pos )
{
    pos = verifica_pos();

    registros[pos].cod = cod;

    printf("\n VOCE E UMA PESSOA JURIDICA OU FISICA (J/F):\n");
    gets(registros[pos].NOMEDOCLIENTE);

    printf("\nDATA DE NASCIMENTO:\n");
    scanf("%d",&registros[pos].idade);
    fflush(stdin);

    printf("\nSEXO M/F:\n");
    gets(registros[pos].sexo);

    printf("\nNOME DO CLIENTE:\n");
    gets(registros[pos].responsavel);

    printf("\nCEP/ENDERECO:\n");
    gets(registros[pos].endereco);

    printf("\nTELEFONE PARA CONTATO:\n");
    scanf("%d",&registros[pos].telefone);
    fflush(stdin);

    printf("\nQUAL TIPO DE LIXO QUE DESEJA DESCARTAR :(\n\n (1)- Lixo orgânico \n\n (2)- Lixo reciclável \n\n (3)- Lixo doméstico \n\n (4)- Lixo comercial \n\n (5)- Lixo industrial \n\n (6)- Lixo hospitalar \n\n (7)- Lixo verde \n\n (8)- lixo eletrônico \n\n (9)- Lixo radioativo,\n\n (10)- Outros)\n");

    gets(registros[pos].Tipodelixo);

    registros[pos].vazio = 1;

    printf("\nCADASTRO REALIZADO COM SUCESSO SEJA BEM VINDO A NOSSA EMPRESA!\n\n");
    getchar();

    system("cls");

} //Final da Função Cadastrar

//FUNÇÃO CONSULTAR
void consultar( void )
{
    int cont = 0, cod;

    printf("\nENTRE COM SEU CPF\n");
    scanf("%d",&cod);

    system("cls");

    while ( cont <= 100 )
    {

        if (registros[cont].cod==cod)
        {
            if (registros[cont].vazio==1)
            {

                printf("\nVOCE E UMA PESSOA JURIDICA OU FISICA?: \n%s\n",registros[cont].NOMEDOCLIENTE);
                printf("\nDATA DE NASCIMENTO: \n%d\n",registros[cont].idade);
                printf("\nSexo M/F:\n%s\n",registros[cont].sexo);
                printf("\nNOME DO CLIENTE: \n%s\n",registros[cont].responsavel);
                printf("\nCEP/ENDERECO: \n%s\n",registros[cont].endereco);
                printf("\nTELEFONE PARA CONTATO:\n%d\n",registros[cont].telefone);
    printf("\nQUAL TIPO DE LIXO QUE DESEJA DESCARTAR :(\n\n 1- Lixo orgânico \n\n, 2- Lixo reciclável \n\n 3- Lixo doméstico \n\n 4- Lixo comercial \n\n 5- Lixo industrial \n\n 6- Lixo hospitalar,\n\n -7 Lixo verde ,\n\n 8- lixo eletrônico \n\n 9- Lixo radioativo,\n\n 10- Outros)\n");
                printf("\n");

                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 100 )
            printf("\nCodigo não encontrado\n");

    }
}

//FUNÇÃO VERIFICA POSIÇÃO
int verifica_pos( void )
{
    int cont = 0;

    while ( cont <= 100 )
    {

        if ( registros[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

}

//FUNÇÃO ZERAR
void zerar( void )
{
    int cont;

    for ( cont = 0; cont <= 100; cont++ )
        registros[cont].vazio = 0;
}

//FUNÇÃO VERIFICA CODIGO
int verifica_cod( int cod )
{
    int cont = 0;

    while ( cont <= 100 )
    {
        if ( registros[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

}

//FUNÇÃO EXCLUIR
void excluir( void )
{
    int cod, cont = 0;
    char resp; // variavel para perguntar sim ou não

    printf("\nEntre com o codigo do registro que deseja excluir\n");
    scanf("%d", &cod );

    while ( cont <= 100 )
    {

        if ( registros[cont].cod == cod )
        {

            if ( registros[cont].vazio == 1 )
            {

                printf("\nVOCE E UMA PESSOA JURIDICA OU FISICA: \n%s\n", registros[cont].NOMEDOCLIENTE );
                printf("\nDATA DE NASCIMENTO: \n%d\n", registros[cont].idade );
                printf("\nSexo M/F:\n%s\n",registros[cont].sexo);
                printf("\nNOME DO CLIENTE: \n%s\n", registros[cont].responsavel );
                printf("\nCEP/ENDERECO: \n%s\n", registros[cont].endereco);
                printf("\nTELEFONE PARA CONTATO:\n%d\n",registros[cont].telefone);
    printf("\nQUAL TIPO DE LIXO QUE DESEJA DESCARTAR :(\n\n 1- Lixo orgânico \n\n, 2- Lixo reciclável \n\n 3- Lixo doméstico \n\n 4- Lixo comercial \n\n 5- Lixo industrial \n\n 6- Lixo hospitalar,\n\n -7 Lixo verde ,\n\n 8- lixo eletrônico \n\n 9- Lixo radioativo,\n\n 10- Outros)\n");
                getchar();

                printf("\nDeseja realmente excluir? S/N:");
                scanf("%c",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    registros[cont].vazio=0;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 100 )
            printf("\nCodigo não encontrado\n");

    }

    system("pause");
    system("cls");

}
