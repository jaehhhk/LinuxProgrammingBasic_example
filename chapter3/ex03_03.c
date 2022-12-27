// 82p. open과 creat을 이용해 새로운 파일 생성하기

# include <fcntl.h>

int main(){

    int filedes1, filedes2;

    filedes1 = open("data1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);   // 만약 같은 이름의 파일이 있다면 기존 파일 내용 전부 삭제하고 새로 생성(O_TRUNC 플래그 역할)
    filedes2 = creat("data2.txt", 0644);    // 만약 같은 이름의 파일이 있다면 기존 파일 내용 전부 삭제하고 새로 생성 -> creat에는 O_EXCL 플래그 기능이 없기 때문

    close(filedes1);
    close(filedes2);

}