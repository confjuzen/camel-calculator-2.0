#include <stdio.h>

int main(){

double a, b, result ;
char op, yn ;

printf("Callculate: \n");
scanf("%lf %c %lf", &a, &op, &b);

switch(op){
	case '+':
		printf("hi");
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '/':
		if(b==0){
			printf("Are you sure? (y)(n)");
	  		scanf(" %c", &yn);
	   		if(yn == 'y'){
				printf("breaking .... :(");
				return 1;
			}else{
				printf("Cool :)");
				return 0;
			}
		}else{
			result = a / b;
			break;
		}
	case '*':
		result = a * b;
		break;
	default:
		printf("errors");
		return 0;
}

printf("%f \n", result);


}
