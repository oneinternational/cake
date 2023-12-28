#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define BUF_SIZE 1024

void choice_repeat (int clnt_sock, char (*menu_array)[BUF_SIZE], int num, char* message_from, char* message_to, char(*auto_handling)[BUF_SIZE], char(*all_information)[20], char (*Info_confirm)[BUF_SIZE], int* ea_save, int* money_save);

void confirm_reset(char (*arr)[BUF_SIZE])
{
    strcpy(arr[2], "주문 메뉴: ");
    strcpy(arr[3], "주문 수량: ");
    strcpy(arr[4], "주문 가격: ");
    strcpy(arr[5], "주문자 성함: ");
    strcpy(arr[6], "주문자 배송지: ");
}

void mem_clear(char* buf)
{
    memset(buf, 0, sizeof(buf));
}


void Info_clear(char (*arr)[20])
{
    int i; 
    for(i = 0; i<5; i++)
    {
        strcpy(arr[i], "");
    }
}
// void write_normal(int sock, char* buf)
// {
//     puts("손님에게 보낸 메시지: ");
//     write(sock, buf, strlen(buf));
//     printf("%s\n",buf);
//     memset(buf, 0, sizeof(buf));
// }

void write_auto(int sock, char* buf,  char(*arr)[BUF_SIZE], int num) //자동 메시지 보내기
{
    puts("손님에게 보낸 메시지: ");
    strcat(buf, arr[num]);
    write(sock, buf, strlen(buf));
    printf("%s\n",buf);
    memset(buf, 0, sizeof(buf));
}

void Info_confirm_write(int sock, char(*confirm)[BUF_SIZE],  char(*Info)[20], char *buf)
{
    puts("손님에게 보낸 메시지: ");
    int i;
    for(i =0; i<5; i++)
    {
        strcat(confirm[i+2], Info[i]);
        strcat(confirm[i+2], "\n");
    }
    

    for(i=0; i<8; i++)
    {
        strcat(buf, confirm[i]);
    }
    strcat(buf, "위 정보를 확인하시고 맞으면 (Y) 틀리면 (N) 추가를 원하시면 (A)를 입력해주세요\n");
    write(sock, buf, strlen(buf));
    printf("%s",buf);
    memset(buf, 0, sizeof(buf));
}

void read_routine(int sock, char* buf)
{
    int str_len =  read(sock, buf, BUF_SIZE );
    puts("손님에게  받은 메시지: "); 
    int recv_cnt = 0;
    while (recv_cnt < str_len-1) {
        putc(buf[recv_cnt],stdout);
        recv_cnt += 1;
    }
    buf[str_len -1]=0;
    printf("\n");
}

void error_handling(char *message);

int main(int argc, char* argv[])
{

    int serv_sock, clnt_sock;
    char  message_to[BUF_SIZE] ="";
    char  message_from[BUF_SIZE]="";

    char all_information[10][20]={"0",};

    char auto_handling[10][BUF_SIZE]={
        {"안녕하세요 Sangho's Bakery입니다. 무엇을 주문하시겠어요?"},
        {"수량을 말씀해주세요 (숫자만 입력)"},
        {"주문자 성함을 말씀해주세요"},
        {"배송지를 말씀해주세요"},
        {"결제 방식을 말씀해주세요(Cash/ Credit Card)"},
        {"결제가 완료되었습니다. 주문해주셔서 감사합니다. 배송 소요일은 3일 입니다."},
        {"처음으로 돌아갑니다. 다시 주문해주세요"},
        {"추가 주문을 해주세요"}
    };
    
    char Info_confirm[10][BUF_SIZE]={
        {"주문내역\n"},
        {"==========================================\n"},
        {"주문 메뉴: "},
        {"주문 수량: "},
        {"주문 가격: "},
        {"주문자 성함: "},
        {"주문자 배송지: "},
        {"==========================================\n"}
    };
   

    char menu[BUF_SIZE] = 
    "판매하는 케잌의 종류는 다음과 같습니다.\n"
    "=======================================\n"
    "메뉴\n"
    "1.초코듬뿍 케잌 15000원\n"
    "2.딸기듬뿍 케잌 18000원\n"
    "3.망고듬뿍 케잌 18000원\n"
    "4.고구마듬뿍 케잌 16000원\n"
   "5.바나나듬뿍 케잌 18000원\n"
    "6.생크림듬뿍 케잌 15000원\n"
    "7.아이스 케잌 20000원\n"
    "=======================================\n";

    char menu_array[7][BUF_SIZE] ={
    {"초코듬뿍 케잌"}, 
    {"딸기듬뿍 케잌"},
    {"망고듬뿍 케잌"},
    {"고구마듬뿍 케잌"},
    {"바나나듬뿍 케잌"},
    {"생크림듬뿍 케잌"},
    {"아이스 케잌"}
    };

    int str_len, i ;
    int ea_save = 0;
    int money_save = 0;
    struct  sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    if(argc !=2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1)
        error_handling("bind() error");
    
    if(listen(serv_sock, 5)==-1)
        error_handling("listen() error");
    
    clnt_adr_sz = sizeof(clnt_adr);

    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
    if(clnt_sock == -1)
        error_handling("accept error()!");
  
    puts("손님이 입장하였습니다.");
    write_auto(clnt_sock, message_to, auto_handling, 0); //어서옵셔
//==============================================================
    sleep(1);
    // while(1)
    // {
    write(clnt_sock, menu, strlen(menu));// 메뉴 보내기
    read_routine(clnt_sock, message_from);

    if((strcmp(message_from, "초코듬뿍 케잌"))==0 || (strcmp(message_from, "1"))==0 ){
        choice_repeat(clnt_sock, menu_array, 0, message_from, message_to, auto_handling, all_information, Info_confirm, &ea_save, &money_save);
    }
    else if((strcmp(message_from, "딸기듬뿍 케잌"))==0 || (strcmp(message_from, "2"))==0){
        choice_repeat(clnt_sock, menu_array, 1, message_from, message_to, auto_handling, all_information, Info_confirm, &ea_save, &money_save);
    }
    else if((strcmp(message_from, "딸기듬뿍 케잌"))==0 || (strcmp(message_from, "2"))==0){
        choice_repeat(clnt_sock, menu_array, 1, message_from, message_to, auto_handling, all_information, Info_confirm, &ea_save, &money_save);
    }


    //  }
    // close(serv_sock);
    // close(clnt_sock);
    // return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
    
void choice_repeat (int clnt_sock, char(*menu_array)[BUF_SIZE], int num, char* message_from, char* message_to, char(*auto_handling)[BUF_SIZE], char(*all_information)[20], char (*Info_confirm)[BUF_SIZE], int* ea_save, int* money_save)
{
    // char* menu_array
    // write(clnt_sock, menu, strlen(menu));// 메뉴 보내기                     
        
    // read_routine(clnt_sock, message_from);
    // if((strcmp(message_from, "초코듬뿍 케잌\n"))==0 || (strcmp(message_from, "1\n"))==0 )
    // {
    strcpy(all_information[0], menu_array[num]);
    // sprintf(all_information[0],  "초코듬뿍 케잌"); // 케잌 종류 저장
    mem_clear(message_from);

    write_auto(clnt_sock, message_to, auto_handling, 1); //수량
    read_routine(clnt_sock, message_from);
    
    *ea_save =  atoi(message_from);
    *money_save = *ea_save * 15000;

    sprintf(all_information[1], "%d", *ea_save); // 수량 저장
    sprintf(all_information[2], "%d", *money_save);//  가격정보 저장
    mem_clear(message_from);
    
    write_auto(clnt_sock, message_to, auto_handling, 2); //성함
    read_routine(clnt_sock, message_from);
    strcat(all_information[3], message_from); //이름 저장
    mem_clear(message_from);
    
    write_auto(clnt_sock, message_to, auto_handling, 3); //배송지
    read_routine(clnt_sock, message_from);
    strcat(all_information[4], message_from);//배송지 저장
    mem_clear(message_from);
    
    Info_confirm_write(clnt_sock, Info_confirm,  all_information, message_to);
    read_routine(clnt_sock, message_from); // (Y/N/A) 맞으면 Y 틀리면 N 추가하고싶은 메뉴가 있으면 A
        
    if((strcmp(message_from, "Y" )) == 0 || (strcmp(message_from, "y")) == 0)
    {
        int i;
        mem_clear(message_from);
        write_auto(clnt_sock, message_to, auto_handling, 4); //결제
        read_routine(clnt_sock, message_from);

        if((strcmp(message_from, "cash" )) == 0 || (strcmp(message_from, "credit card")) == 0 || (strcmp(message_from, "Credit Card")) == 0|| (strcmp(message_from, "Cash" )) == 0 )
        {
            write_auto(clnt_sock, message_to, auto_handling, 5); //결제
        }
    }
    else if((strcmp(message_from, "N" )) == 0 || (strcmp(message_from, "n")) == 0)//처음으로 돌아가서 메뉴판 전송
    {
        
        write_auto(clnt_sock, message_to, auto_handling, 6);// 처음으로 돌아갑니다.
        Info_clear(all_information);
        confirm_reset(Info_confirm);
    }
    // }
}




 
    

// 클라이언트 cash or credit 하면 10번 데이터 받을 준비

 
    
