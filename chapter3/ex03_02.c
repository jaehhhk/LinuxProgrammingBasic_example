# include <stdlib.h>
# include <fcntl.h>

int main(){

	int filedes;
	char pathname[] = "temp.txt";   // 문자열 배열을 활용한 상대 경로 지정 
	
    // 경로에 파일이 존재하면 읽기, 쓰기 가능한 상태로 개방, 
    //존재하지 않으면 파일을 새롭게 생성하고 접근 권한을 644로 설정하고 생성된 파일은 읽기와 쓰기 가능하다
    
    /*
    if ((filedes = open(pathname, O_CREAT | O_RDWR, 0644)) == -1){

        printf("file open error! \n");
        
        exit(1);

    }
    */

    // 이미 존재하는 파일에는 접근하지 못하도록 -> O_EXCL flag 사용
    if ((filedes = open(pathname, O_CREAT | O_RDWR | O_EXCL, 0644)) == -1){

    printf("file open error! \n");
    
    exit(1);

    }

    close(filedes);

}