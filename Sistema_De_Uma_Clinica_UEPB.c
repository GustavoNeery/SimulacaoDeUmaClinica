#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define SIZE 100
int op;
void MENUREMOVERaluno(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* REMOVENDO ALUNO ************************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void MENUEDITARaluno(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* EDITANDO ALUNO ************************\n");
        printf("\t\t\t\t*************************************************************\n\n");
}
void MENUPESQUISARaluno(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* PESQUISANDO ALUNO *******************\n");
        printf("\t\t\t\t*************************************************************\n\n");
}
void MENULISTADEALUNOS(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* LISTA COMPLETA DE ALUNOS **************\n");
        printf("\t\t\t\t*************************************************************\n\n");

}
void MENUCADASTRODEALUNO(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* CADASTRANDO ALUNO *********************\n");
        printf("\t\t\t\t*************************************************************\n\n");

}
typedef struct{

    char nome[50];
    char matricula[50];
    char cpf[50];
    char curso[50];
}Dados_aluno;
void inputdataaluno(){
    FILE* arquivo;
    Dados_aluno ctt;
    arquivo = fopen("ddaluno.txt","ab");

    if(arquivo == NULL){
        printf("Problemas na Abertura do Arquivo!");
    }
    else{
        do{
            MENUCADASTRODEALUNO();
            fflush(stdin);
            printf("\t\t\t\tDigite a Matricula do Aluno: ");
            gets(ctt.matricula);

            fflush(stdin);
            printf("\t\t\t\tDigite o nome: ");
            gets(ctt.nome);

            printf("\t\t\t\tDigite o CPF do aluno: ");
            scanf("%s",&ctt.cpf);

            fflush(stdin);
            printf("\t\t\t\tDigite o curso: ");
            gets(ctt.curso);

            fwrite(&ctt, sizeof(Dados_aluno),1,arquivo);

            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tAluno CRIADO com sucesso !\n");
            printf("\t\t\t\tTECLE 's' para cadastrar novamente, ou tecle outro para sair.");

        }while(getche() == 's');
        fclose(arquivo);
    }
}
void listaraluno(){
    FILE* arquivo;
    Dados_aluno ctt;
    arquivo = fopen("ddaluno.txt","rb");
    MENULISTADEALUNOS();
    if(arquivo == NULL){
        printf("Problemas na Abertura do Arquivo!");
    }
    else{
        while(fread(&ctt, sizeof(Dados_aluno),1,arquivo)==1){
            printf("\t\t\t\tMatricula: %s\n",ctt.matricula);
            printf("\t\t\t\tNome: %s\n",ctt.nome);
            printf("\t\t\t\tCPF: %s\n",ctt.cpf);
            printf("\t\t\t\tCurso: %s\n",ctt.curso);
            printf("\t\t\t\t-----------------------------------------------\n\n");
        }

    }
    fclose(arquivo);
    getche();
}
void pesquisaraluno(){
    FILE* arquivo;
    Dados_aluno ctt;
    char nome[50];
    arquivo = fopen("ddaluno.txt","rb");
    MENUPESQUISARaluno();
    if(arquivo == NULL){
        printf("Problemas na abertura do arquivo\n\n");
    }
    else{
        fflush(stdin);
        printf("\t\t\t\tDigite o nome do aluno a pesquisar: ");
        gets(nome);

        while(fread(&ctt,sizeof(Dados_aluno),1,arquivo)==1){
            if(strcmp(nome, ctt.nome)==0){
            system("cls");
            printf("\t\t\t\t---------DADOS DO ALUNO PESQUISADO----------\n\n");
            printf("\t\t\t\tMatricula: %s\n",ctt.matricula);
            printf("\t\t\t\tNome: %s\n",ctt.nome);
            printf("\t\t\t\tCPF: %s\n",ctt.cpf);
            printf("\t\t\t\tCurso: %s\n",ctt.curso);
            printf("\t\t\t\t---------------------------------------------\n\n");
            }
        }

    }
    fclose(arquivo);
    getch();
}
void editaraluno(){
    Dados_aluno ctt;
    char mat[20],i[20];
    FILE *arq=fopen("ddaluno.txt","r+b");
    FILE *arq1=fopen("auxiliar2.txt","a+b");
    MENUEDITARaluno();
            fflush(stdin);
            printf("\t\t\t\tDigite a Matricula: ");
            gets(mat);
    while(fread(&ctt,sizeof(Dados_aluno),1,arq)==1){
        if(strcmp(mat, ctt.matricula)==0){
            system("cls");
            printf("\n\t\t\t\t****************************************************");
            printf("\n\t\t\t\t************** NOVOS DADOS DO ALUNO ****************");
            printf("\n\t\t\t\t****************************************************");
            printf("\n");
            printf("\t\t\t\tDigite o nome:");
            scanf (" %[^\n]s", ctt.nome);
            printf("\t\t\t\tDigite o CPF:");
            scanf(" %[^\n]s",ctt.cpf);
            printf("\t\t\t\tDigite o Curso:");
            scanf (" %[^\n]s", ctt.curso);
            fflush(stdin);
            printf("\t\t\t\tDigite a Matricula: ");
            gets(ctt.matricula);
            printf("\n");
            system("cls");
            printf("\n\t\t\t\t****************************************************");
            printf("\n\t\t\t\t************** NOVOS DADOS DO ALUNO ****************");
            printf("\n\t\t\t\t****************************************************");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tAluno editado com sucesso !\n");
            printf("\t\t\t\t\tTECLE algo para voltar ao menu principal.");
            system("pause>>NULL");;
            fwrite(&ctt, sizeof(Dados_aluno),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&ctt, sizeof(Dados_aluno), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del ddaluno.txt");
system("ren auxiliar2.txt ddaluno.txt");
}
void removeraluno(){
    Dados_aluno ctt;
    char matricula[20],b[20];
    FILE *arquivo=fopen("ddaluno.txt","r+b");
    FILE *arquivo1=fopen("auxiliar2.txt","a+b");
    MENUREMOVERaluno();
    fflush(stdin);
    printf("\t\t\t\tDigite a Matricula: ");
    gets(matricula);
    rewind(arquivo);
    while(fread(&ctt,sizeof(Dados_aluno),1,arquivo)==1){
        if(strcmp(matricula, ctt.matricula)==1){
            fwrite(&ctt,sizeof(Dados_aluno),1,arquivo1);
        }
    }
            system("cls");
            MENUREMOVERaluno();
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tAluno REMOVIDO com sucesso !\n");
            printf("\t\t\t\t\tTECLE algo para voltar ao menu principal.");
system("pause>>NULL");
fclose(arquivo1);
fclose(arquivo);
system("del ddaluno.txt");
system("ren auxiliar2.txt ddaluno.txt");
}
void mainaluno(){
setlocale(LC_ALL,"Portuguese");
    int op;
    do{
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* MENU DE ALUNOS ************************\n");
        printf("\t\t\t\t*************************************************************\n");
        printf("\n\t\t\t\t1- Cadastrar aluno\n");
        printf("\t\t\t\t2- Editar aluno\n");
        printf("\t\t\t\t3- Pesquisar aluno\n");
        printf("\t\t\t\t4- Listar alunos cadastrados\n");
        printf("\t\t\t\t5- Remover Aluno\n");
        printf("\t\t\t\t6- Sair\n");
        printf("\t\t\t\tEscolha uma opção: ");
        scanf("%d",&op);
        switch(op){
            case 1:
               inputdataaluno();
            break;
            case 2:
                editaraluno();
            break;

            case 3:
                pesquisaraluno();
            break;

            case 4:
                listaraluno();
            break;
            case 5:
                removeraluno();
            break;
            case 6:
                system("cls");
                printf("\n\t\t\t\t*************************************************************\n");
                printf("\t\t\t\t********************* MENU DE ALUNOS ***********************\n");
                printf("\t\t\t\t*************************************************************\n");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\tMENU ALUNO finalizado com sucesso.\n\n\n");
            break;

            default:
                system("cls");
                printf("\n\t\t\t\tOpção inválida. Tecle algo para analisar o menu novamente.");
                getch();
            break;

        }
    }while(op!=6);
}
void MENUREMOVERpaciente(){
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************REMOVENDO PACIENTE********************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void MENUEDITARpaciente(){
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************EDITANDO PACIENTE********************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void MENUPESQUISARpaciente(){
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************PESQUISANDO PACIENTE********************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void MENULISTADEPACIENTES(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************LISTA COMPLETA DE PACIENTES*************\n");
        printf("\t\t\t\t*************************************************************\n");

}
typedef struct{
    int dia;
    int mes;
    int ano;
}nascimento;
typedef struct{
    char nome[50];
    char endereco[50];
    char codigo[50];
    char cpf[50];
    nascimento aniver;
}Dados_paciente;
void listar(){
    FILE* arquivo;
    Dados_paciente ctt;
    arquivo = fopen("agenda.txt","rb");
    MENULISTADEPACIENTES();
    if(arquivo == NULL){
        printf("\t\t\t\tProblemas na Abertura do Arquivo!");
    }
    else{
        while(fread(&ctt, sizeof(Dados_paciente),1,arquivo)==1){
            printf("\t\t\t\tNome: %s\n",ctt.nome);
            printf("\t\t\t\tEndereço: %s\n",ctt.endereco);
            printf("\t\t\t\tAniversário: %d/%d/%d\n",ctt.aniver.dia,ctt.aniver.mes,ctt.aniver.ano);
            printf("\t\t\t\tCódigo: %s\n",ctt.codigo);
            printf("\t\t\t\tCPF: %s\n",ctt.cpf);
            printf("\t\t\t\t-----------------------------------------------\n\n");
        }

    }
    fclose(arquivo);
    getche();
}
void MENUCADASTROPACIENTE(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************CADASTRANDO PACIENTE********************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void removerpaciente(){
    Dados_paciente ctt;
    char matricula[20],b[20];
    FILE *arquivo=fopen("agenda.txt","r+b");
    FILE *arquivo1=fopen("auxiliar2.txt","a+b");
    MENUREMOVERpaciente();
    fflush(stdin);
    printf("\t\t\t\tDigite o Código: ");
    gets(matricula);
    rewind(arquivo);
    while(fread(&ctt,sizeof(Dados_paciente),1,arquivo)==1){
        if(strcmp(matricula, ctt.codigo)==1){
            fwrite(&ctt,sizeof(Dados_paciente),1,arquivo1);
        }
    }
printf("\n\t\t\t\tAlUNO REMOVIDO com sucesso.\n\n\n");
printf("\t\t\t\tTECLE algo para voltar ao menu.\n\n");
system("pause>>NULL");
fclose(arquivo1);
fclose(arquivo);
system("del agenda.txt");
system("ren auxiliar2.txt agenda.txt");
}
void editarpaciente(){
    Dados_paciente ctt;
    char mat[20],i[20];
    FILE *arq=fopen("agenda.txt","r+b");
    FILE *arq1=fopen("auxiliar2.txt","a+b");
    MENUEDITARpaciente();
            fflush(stdin);
            printf("\t\t\t\tDigite o Código: ");
            gets(mat);
    while(fread(&ctt,sizeof(Dados_paciente),1,arq)==1){
        if(strcmp(mat, ctt.codigo)==0){
            system("cls");
            printf("\n\t\t\t\t****************************************************");
            printf("\n\t\t\t\t************** NOVOS DADOS DO PACIENTE *************");
            printf("\n\t\t\t\t****************************************************");
            printf("\n");
            printf("\t\t\t\tDigite o nome:");
            scanf (" %[^\n]s", ctt.nome);
            printf("\t\t\t\tDigite o CPF:");
            scanf(" %[^\n]s",ctt.cpf);
            printf("\t\t\t\tDigite o Endereço:");
            scanf (" %[^\n]s", ctt.endereco);
            fflush(stdin);
            printf("\t\t\t\tDigite o Código: ");
            gets(ctt.codigo);
            printf("\t\t\t\tDigite o aniversário: ");
            scanf("%d %d %d", &ctt.aniver.dia, &ctt.aniver.mes, &ctt.aniver.ano);
            printf("\n");
            printf("\n\t\t\t\tAlUNO EDITADO com sucesso.\n\n\n");
            printf("\t\t\t\tTECLE algo para voltar ao Menu.\n\n");
            system("pause>>NULL");;
            fwrite(&ctt, sizeof(Dados_paciente),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&ctt, sizeof(Dados_paciente), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del agenda.txt");
system("ren auxiliar2.txt agenda.txt");
}
void pesquisarpaciente(){
    FILE* arquivo;
    Dados_paciente ctt;
    char nome[50];
    arquivo = fopen("agenda.txt","rb");
    MENUPESQUISARpaciente();
    if(arquivo == NULL){
        printf("\t\t\t\tProblemas na abertura do arquivo\n\n");
    }
    else{
        fflush(stdin);
        printf("\t\t\t\tDigite o nome do paciente a pesquisar: ");
        gets(nome);

        while(fread(&ctt,sizeof(Dados_paciente),1,arquivo)==1){
            if(strcmp(nome, ctt.nome)==0){
            system("cls");
            MENUPESQUISARpaciente();
            printf("\t\t\t\t---------DADOS DO PACIENTE PESQUISADO----------\n\n");
            printf("\t\t\t\tNome: %s\n",ctt.nome);
            printf("\t\t\t\tEndereço: %s\n",ctt.endereco);
            printf("\t\t\t\tAniversário: %d/%d/%d\n",ctt.aniver.dia,ctt.aniver.mes,ctt.aniver.ano);
            printf("\t\t\t\tCódigo: %s\n",ctt.codigo);
            printf("\t\t\t\tCPF: %s\n",ctt.cpf);
            printf("\t\t\t\t-----------------------------------------------\n\n");
            printf("\t\t\t\tTecle algo para voltar ao menu principal.\n\n\n");
            }
        }

    }
    fclose(arquivo);
    getch();
}
void inputdatapaciente(){
    FILE* arquivo;
    Dados_paciente ctt;
    arquivo = fopen("agenda.txt","ab");

    if(arquivo == NULL){
        printf("\t\t\t\tProblemas na Abertura do Arquivo!");
    }
    else{
        do{
            MENUCADASTROPACIENTE();
            fflush(stdin);
            printf("\t\t\t\tDigite o nome: ");
            gets(ctt.nome);

            fflush(stdin);
            printf("\t\t\t\tDigite o endereco: ");
            gets(ctt.endereco);

            printf("\t\t\t\tDigite o aniversário: ");
            scanf("%d %d %d", &ctt.aniver.dia, &ctt.aniver.mes, &ctt.aniver.ano);

            fflush(stdin);
            printf("\t\t\t\tDigite o código do paciente: ");
            gets(ctt.codigo);

            printf("\t\t\t\tDigite o CPF do paciente: ");
            scanf("%s",&ctt.cpf);

            fwrite(&ctt, sizeof(Dados_paciente),1,arquivo);

            printf("\t\t\t\tDeseja continuar? se sim digite 's', se não digite outra tecla!\n");

        }while(getche() == 's');
        fclose(arquivo);
    }
}
void mainpaciente(){
    setlocale(LC_ALL,"Portuguese");
    int op;
    do{
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************MENU DE PACIENTES***********************\n");
        printf("\t\t\t\t*************************************************************\n");
        printf("\n\t\t\t\t1- Cadastrar paciente\n");
        printf("\t\t\t\t2- Editar pacinte\n");
        printf("\t\t\t\t3- Pesquisar paciente\n");
        printf("\t\t\t\t4- Listar pacientes cadastrados\n");
        printf("\t\t\t\t5- Remover um paciente\n");
        printf("\t\t\t\t6- Sair\n");
        printf("\t\t\t\tEscolha uma opção: ");
        scanf("%d",&op);
        switch(op){
            case 1:
               inputdatapaciente();
            break;

            case 2:
                editarpaciente();
            break;

            case 3:
                pesquisarpaciente();
            break;

            case 4:
                listar();
            break;

            case 5:
                removerpaciente();
                break;

            case 6:
                system("cls");
                printf("\n\t\t\t\t*************************************************************\n");
                printf("\t\t\t\t*********************MENU DE PACIENTES***********************\n");
                printf("\t\t\t\t*************************************************************\n");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\tMENU PACIENTE finalizado com sucesso.\n\n\n");
            break;

            default:
                system("cls");
                printf("\n\t\t\t\tOpção inválida. Tecle algo para analisar o menu novamente.");
                getch();
            break;

        }
    }while(op!=6);
}
typedef struct{
    char codigo[50];
    char nome[50];
    char curso[50];
}Dados_sup;
void MENUREMOVERsup(){
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* REMOVENDO SUPERVISOR *****************\n");
        printf("\t\t\t\t*************************************************************\n");

}
void MENUEDITARsup(){
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* EDITANDO SUPERVISOR *****************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void MENUPESQUISARSUP(){
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* PESQUISANDO SUPERVISOR *****************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void MENULISTASUP(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* LISTA COMPLETA DE SUPERVISORES **********\n");
        printf("\t\t\t\t*************************************************************\n");

}
void MENUCADASTROSUP(){
    system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t********************* CADASTRANDO SUPERVISOR ******************\n");
        printf("\t\t\t\t*************************************************************\n");
}
void pesquisarsup(){
    FILE* arquivo;
    Dados_sup ctt;
    char nome[50];
    arquivo = fopen("ddsup.txt","rb");
    MENUPESQUISARSUP();
    if(arquivo == NULL){
        printf("Problemas na abertura do arquivo\n\n");
    }
    else{
        fflush(stdin);
        printf("\t\t\t\tDigite o nome do supervisor(a) a pesquisar: ");
        gets(nome);

        while(fread(&ctt,sizeof(Dados_sup),1,arquivo)==1){
            if(strcmp(nome, ctt.nome)==0){
            printf("\t\t\t\t---------DADOS DO SUPERVISOR PESQUISADO----------\n\n");
            printf("\t\t\t\tCódigo: %s\n",ctt.codigo);
            printf("\t\t\t\tNome: %s\n",ctt.nome);
            printf("\t\t\t\tCurso: %s\n",ctt.curso);
            printf("\t\t\t\t-----------------------------------------------\n\n");
            }
        }
    }
    fclose(arquivo);
    getch();
}
void removersup(){
    Dados_sup ctt;
    char matricula[20],b[20];
    FILE *arquivo=fopen("ddsup.txt","r+b");
    FILE *arquivo1=fopen("auxiliar2.txt","a+b");
    MENUREMOVERsup();
    fflush(stdin);
    printf("\t\t\t\tDigite o Código: ");
    gets(matricula);
    rewind(arquivo);
    while(fread(&ctt,sizeof(Dados_sup),1,arquivo)==1){
        if(strcmp(matricula, ctt.codigo)==1){
            fwrite(&ctt,sizeof(Dados_sup),1,arquivo1);
        }
    }
printf("\n\t\t\t\tSUPERVISOR REMOVIDO com sucesso.\n\n\n");
printf("\t\t\t\tTECLE algo para voltar ao menu.\n\n");
system("pause>>NULL");
fclose(arquivo1);
fclose(arquivo);
system("del ddsup.txt");
system("ren auxiliar2.txt ddsup.txt");
}
void inputdatasup(){
    FILE* arquivo;
    Dados_sup ctt;
    arquivo = fopen("ddsup.txt","ab");

    if(arquivo == NULL){
        printf("Problemas na Abertura do Arquivo!");
    }
    else{
        do{
            MENUCADASTROSUP();
            fflush(stdin);
            printf("\t\t\t\tDigite o código: ");
            gets(ctt.codigo);

            fflush(stdin);
            printf("\t\t\t\tDigite o nome: ");
            gets(ctt.nome);

            fflush(stdin);
            printf("\t\t\t\tDigite o curso: ");
            gets(ctt.curso);

            fwrite(&ctt, sizeof(Dados_sup),1,arquivo);

            printf("\t\t\t\tDeseja continuar? se sim digite 's', se não digite outra tecla!\n");

        }while(getche() == 's');
        fclose(arquivo);
    }
}
void listarsup(){
    FILE* arquivo;
    Dados_sup ctt;
    arquivo = fopen("ddsup.txt","rb");
    MENULISTASUP();
    if(arquivo == NULL){
        printf("Problemas na Abertura do Arquivo!");
    }
    else{
        while(fread(&ctt, sizeof(Dados_sup),1,arquivo)==1){
            printf("\t\t\t\tCódigo: %s\n",ctt.codigo);
            printf("\t\t\t\tNome: %s\n",ctt.nome);
            printf("\t\t\t\tCurso: %s\n",ctt.curso);
            printf("\t\t\t\t-----------------------------------------------\n\n");
        }

    }
    fclose(arquivo);
    getche();
}
void editarsupervisor(){
    Dados_sup ctt;
    char mat[20],i[20];
    FILE *arq=fopen("ddsup.txt","r+b");
    FILE *arq1=fopen("auxiliar2.txt","a+b");
    MENUEDITARsup();
            fflush(stdin);
            printf("\t\t\t\tDigite o Código: ");
            gets(mat);
    while(fread(&ctt,sizeof(Dados_sup),1,arq)==1){
        if(strcmp(mat, ctt.codigo)==0){
            system("cls");
            printf("\n\t\t\t\t****************************************************");
            printf("\n\t\t\t\t************** NOVOS DADOS DO SUPERVISOR *************");
            printf("\n\t\t\t\t****************************************************");
            printf("\n");
            printf("\t\t\t\tDigite o nome:");
            scanf (" %[^\n]s", ctt.nome);

            printf("\t\t\t\tDigite o Código:");
            scanf(" %[^\n]s",ctt.codigo);

            printf("\t\t\t\tDigite o Curso:");
            scanf (" %[^\n]s", ctt.curso);

            printf("\n\t\t\t\tSUPERVISOR EDITADO com sucesso.\n\n\n");
            printf("\t\t\t\tTECLE algo para voltar.\n\n");
            system("pause>>NULL");;
            fwrite(&ctt, sizeof(Dados_sup),1,arq1);
            printf("\n");
            system("cls");

    }
     else
        {

    fwrite(&ctt, sizeof(Dados_sup), 1,  arq1);
        }

        }

fclose(arq1);
fclose(arq);
system("del ddsup.txt");
system("ren auxiliar2.txt ddsup.txt");
}
void mainsupervisor(){
    setlocale(LC_ALL,"Portuguese");
    int op;
    do{
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*********************MENU DOS SUPERVISORES*******************\n");
        printf("\t\t\t\t*************************************************************\n");
        printf("\n\t\t\t\t1- Cadastrar supervisor\n");
        printf("\t\t\t\t2- Editar supervisor\n");
        printf("\t\t\t\t3- Pesquisar supervisor\n");
        printf("\t\t\t\t4- Listar supervisores cadastrados\n");
        printf("\t\t\t\t5- Remover algum supervisor\n");
        printf("\t\t\t\t6- Sair\n\n");
        printf("\t\t\t\tEscolha uma opção: ");
        scanf("%d",&op);
        switch(op){
            case 1:
               inputdatasup();
            break;

            case 2:
                editarsupervisor();
            break;

            case 3:
                pesquisarsup();
            break;

            case 4:
                listarsup();
            break;

            case 5:
                removersup();
                break;

            case 6:
                printf("\t\t\t\tMENU SUPERVISOR finalizado com sucesso.\n");
            break;

            default:
                system("cls");
                printf("\n\t\t\t\tOpção inválida. Tecle algo para analisar o menu novamente.");
                getch();
            break;

        }
    }while(op!=6);
}

int main(){
    setlocale(LC_ALL,"Portuguese");
   do{
        system("cls");
        printf("\n\t\t\t\t*************************************************************\n");
        printf("\t\t\t\t*******************  C L I N I C A  U E P B  ****************\n");
        printf("\t\t\t\t*************************************************************\n");
        printf("\n\t\t\t\t1- Aluno\n");
        printf("\t\t\t\t2- Supervisor\n");
        printf("\t\t\t\t3- Paciente\n");
        printf("\t\t\t\t4- Sair\n");
        printf("\t\t\t\tEscolha uma opção: ");
        scanf("%d",&op);
        switch(op){
            case 1:
               mainaluno();
            break;

            case 2:
                mainsupervisor();
            break;

            case 3:
                mainpaciente();
            break;

            case 4:
                printf("\t\t\t\tPROGRAMA finalizado com sucesso.\n");
            break;

            default:
                system("cls");
                printf("\n\t\t\t\tOpção inválida. Tecle algo para analisar o menu novamente.");
                getch();
            break;

        }
    }while(op!=4);
}
