#include<pthread.h>
#include<unistd.h>
#include<iostream>
using namespace std;
void *runFun(void *data){
	
	while(1){
		cout<<"My name is";
		pthread_testcancel();
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	
	void *exitCode;
	char *name=static_cast<char*>("张三");
	pthread_create(&tid,NULL,runFun,NULL);
	pthread_cancel(tid);
	pthread_join(tid,&exitCode);
	
	if(exitCode==PTHREAD_CANCELED){
		cout<<"pthread_canceled"<<endl;
		cout<<tid<<endl;
	}else{
	
		cout<<"no exit?"<<endl;
	}
	return 0;
}
