#include<stdio.h>
char a[10];
int t1 =-1; 
int push(char k){
a[++t1] = k;
return 1;
}
char pull(){
if(t1== -1){
	return 0;
}
return a[t1--];
}
char peek(){
	return a[t1];
}
int priority(char k)
{
	switch (k) 
    { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '/': 
        return 2; 
    case '^': 
        return 3; 
    } 
    return -1; 
}
int isempty(){
	if(t1==-1)
		return 1;
	else
		return 0;	
}
int main(){
	char arr[100];
	gets(arr);
	char b[50];
	int i=0 , j=0;
	while(arr[i]!= '\0'){
		if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')){
			b[j++] = arr[i];
		}
		else if(arr[i]=='('){
			push('(');
		}
		else if(arr[i]==')'){
			while(!isempty() && peek()!= '(')
				b[j++] = pull();
			if(!isempty() && peek()!= '(')
			{
				printf("Invalid statement");
				return 1;
			}
			else{
				pull();
			}

		}
		else {
			while(!isempty() && priority(arr[i])<= priority(peek()))
				b[j++] = pull();
			push(arr[i]);
		}
		i++;
	}
	while(!isempty()){
		b[j++] = pull();
	}
	b[j++]='\0';
	printf("%s\n",b);
}
