#include <stddef.h> // for size_t,    // size_t를 사용하기 위한 전처리기

#include <stdint.h> // for uint8_t    // uint_류를 사용하기 위한 전처리기

#include <stdio.h> // for printf      // printf를 사용하기 위한 전처리기

 

uint32_t my_change(uint32_t n) {

	return (n&0xFF000000)>>24 | (n&0x00FF0000)>>8 //32비트라서 이만큼 채워준것

	| (n&0x0000FF00)<<8| (n&0x000000FF)<<24;    

}

 

uint32_t next_change(uint32_t n) {

	return (n&0xFF000000)>>24 | (n&0x00FF0000)>>8 //32비트라서 이만큼 채워준것

	| (n&0x0000FF00)<<8| (n&0x000000FF)<<24;    

}

 

void  change1(uint32_t buffer, uint32_t big){

	uint32_t a = my_change(buffer);   //my_change라 사용, 뒤집어서 출력완료

    uint32_t b = next_change(big); 

	printf ("32bit number=%x\n", a); 

	printf ("32bit number=%x\n", b);

	printf ("32bit number=%x\n", a+b);

}

/*

uint32_t  change1(uint32_t buffer){

	uint32_t a = my_change(buffer);   //my_change라 사용, 뒤집어서 출력완료  

	printf ("32bit number=%x\n", a); 

	return a; 

}

 

uint32_t  change2(uint32_t big){

	uint32_t b = next_change(big);   //my_change라 사용, 뒤집어서 출력완료 

	printf ("32bit number=%x\n", b);  

	return b; 

} 

*/

 

int main()

{

uint32_t buffer;  //여기서는 아니지만 예를 들어 buffer[4]; 도 결국 4칸짜리변수이다. 

uint32_t big;      //big[4]; 도 4칸짜리변수이다.  

//uint32_t a;

//uint32_t b;

 

FILE *fp;

fp = fopen("five-hundred.bin","rb");  //쓰기/바이너리 모드(wb)로 엽니다.. 'rb'라고 적으면 바이너리 형식으로 파일을 읽겠다 

fread(&buffer, sizeof(uint32_t), 1, fp); //buffer가+ 한개 int 당  4바이트의 크기를 갖고 + 1번을 돌렸다 = 4X1=4바이트이다 (1번 돌렸다) + 파일포인터    

printf("%x\n", buffer); //00 00 03 e8 

fclose(fp);  //파일 포인터 닫기

 

FILE *ab;

ab = fopen("thousand.bin","rb");  //쓰기/바이너리 모드(wb)로 엽니다.. 'rb'라고 적으면 바이너리 형식으로 파일을 읽겠다

fread(&big, sizeof(uint32_t), 1, ab);   //big가+ 한개 int 당  4바이트의 크기를 갖고 + 1번을 돌렸다 = 4X1=4바이트이다 (1번 돌렸다) + 파일포인터

printf("%x\n", big); //00 00 01 f4

fclose(ab);  //파일 포인터 닫기

 

change1(buffer, big);   //여기서 buffer를 change함수로 가져왔다.  

return 0; //main 함수를 끝냄 

}

//printf(uint32_t(a+b)); 이건 왜 안되지 

 

 

 

 

 

 

/*

 f1 = open("five-hundred.bin")

 f2 = open("six-") 

}

 

int open(filename){

	fp=fopen(filname);

	fclos(fp);

	return 0; */

 
