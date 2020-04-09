// 银行客户排队系统.cpp
#include "pch.h"
#include "stdio.h"
#include "stdlib.h"

typedef int Status;
#define ERROR 0
#define OK 1
#define OVERFLOW -2


typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;


typedef struct NodeEvent{
	int Occurtime; //事件发生的时间
	int NType;  //事件的类型 0表示到达 1-4表示四个窗口
	struct NodeEvent *next;
}Event,*LinkList;

typedef LinkList EventList;

typedef struct CUS{
	int ArrivalTime;
	int Duration;
	struct CUS *next;
}Custom,*CustomPtr;

typedef struct {
	CustomPtr front;
	CustomPtr rear;
}LinkQueue;

EventList ev;  //事件表 

LinkQueue q[5]; //四个客户队列
Custom customer;//客户记录
int TotalTime, CustomerNum; //累计客户逗留时间，客户数


int cmp(Event a, Event b) {
	if (a.Occurtime < b.Occurtime) return -1;
	if (a.Occurtime = b.Occurtime) return 0;
	if (a.Occurtime > b.Occurtime) return 1;
	return ERROR;
}

Status InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(Event));
	L->next = NULL;
	return OK;
}

Status OrderInsert(EventList &ev, Event &en, int cmp(Event,Event)){
	LinkList p = ev;
	while (p->next) p = p->next;
	p->next = &en;
	return OK;
}

Status InitQueue(LinkQueue Q) {
	Q.front = (CustomPtr)malloc(sizeof(Custom));
	if (!Q.front) return OVERFLOW;
	Q.rear = Q.front;
	return OK;
}

int ListEmpty(EventList &ev) {
	if (ev->next) return 1;
	return 0;
}

void OpenForDay() {
	Event en;   // 事件
	TotalTime = 0; CustomerNum = 0;
	InitList(ev);
	en.Occurtime = 0; en.NType = 0;
	OrderInsert(ev, en, cmp);
}

Status DelFirst(int GetHead(EventList)) {

}

void Bank_Simulation(int CloseTime) {
	OpenForDay();
	while (! ListEmpty(ev))
	{

	}
}

int main()
{
	printf("hello");
}
