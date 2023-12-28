#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void mem_clear(char* buf)
{
    memset(buf, 0, sizeof(buf));
}
void write_routine(int sock, char* buf)
{
    puts("Bakery에 보낼 메시지: ");
    fgets(buf,sizeof(buf),stdin);
    write(sock, buf, strlen(buf));
}



void read_routine(int sock, char* buf)
{
    int str_len = read(sock, buf, BUF_SIZE - 1);
    int recv_cnt = 0;
    puts("Bakery에서 받은 메시지:");
    while (recv_cnt < str_len) {
        printf("%c", buf[recv_cnt]);
        recv_cnt += 1;
    }
    printf("\n");
    memset(buf, 0, sizeof(buf));
}

void error_handling(char *message);

int main(int argc, char *argv[])
{
    

    int clnt_sock;
    char message_to[BUF_SIZE] = "";
    char message_from[BUF_SIZE] = "";
    struct sockaddr_in serv_adr;

    if (argc != 3) {
        printf("Usage : %s <IP> <PORT>\n", argv[0]);
        exit(1);
    }

    clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (clnt_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if (connect(clnt_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error");

    read_routine(clnt_sock, message_from); //메뉴판 읽기
    while(1) {
        read_routine(clnt_sock, message_from); // 인사말 읽기
        write_routine(clnt_sock, message_to);



        if(!strcmp(message_to, "cash\n") || !strcmp(message_to, "credit card\n"))
        {
            int i;
            printf("결제중...\n");
            
            for(i = 0; i<5; i++)
            {
                printf("####");
                fflush(stdout);
                sleep(1);
            }
            printf("\n");
            puts("결제가 완료되었습니다. 주문해주셔서 감사합니다. 배송 소요일은 3일 입니다.");
            break;
        }
        mem_clear(message_to);
             
    }
    close(clnt_sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}