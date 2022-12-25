/* 63p. ex03_01.c */

# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>    // 윈도우에선 io.h가 그 역할 대신

main()
{

int filedes, fdnew1, fdnew2;    // 이때 filedes는 file descripter
ssize_t nread;
off_t newpos;

char buffer[1024];                          // 파일로부터 읽어들인 내용을 임시로 저장
char content[] = "Hello my friend!! \n";    // 파일에 새롭게 저장할 문자열

filedes = open("data.txt", O_RDWR); // open 이용해 현재 디렉터리에 있는 data.txt를 읽기, 쓰기용으로 open.
                                    // 호출이 정상적으로 수행되면 open 함수는 양의 정수를 fd로 반한 -> 이 값은 현재 프로그램(ex03_01.c)이 data.txt파일을 읽기 쓰기 용으로 open했다는 뜻

nread = read(filedes, buffer, 1024); // read를 이용해 최대 1024바이트만큼 읽어와 buffer에 저장
printf("%s", buffer);

// write를 이용해 content의 내용 중 strlen()의 길이만큼 현재 읽기/쓰기 포인터 위치부터 data.txt에 저장
write(filedes, content, strlen(content));   // 이 문장에서는 배열 content의 전체 내용을 파일로 저장

newpos = lseek(filedes, (off_t)0, SEEK_SET);    // lseek를 이용해 읽기/쓰기 포인터 맨 앞으로 이동 -> 관련내용 노션에 정리
nread = read(filedes, buffer, 1024);
printf("%s", buffer);

close(filedes);

fdnew1 = open("newdata1.txt", O_RDWR | O_CREAT, 0644);  // 이때 0644는 접근권한(rw-r--r--)
fdnew2 = creat("newdata2.txt", 0644);

close(fdnew1);
close(fdnew2);
unlink("newdata2.txt"); // newdata2.txt를 삭제

}