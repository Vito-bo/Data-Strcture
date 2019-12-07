
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˳���Ķ�̬�洢
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;      // ָ��̬���ٵ�����     
	size_t _size ;       // ��Ч���ݸ���     
	size_t _capacity ;   // �����ռ�Ĵ�С 
}SeqList;

//������ɾ��Ľӿ�
//��ʼ��˳���
void SeqListInit(SeqList* ps);
//����˳���
void SeqListDestory(SeqList* ps);
//��ӡ����
void SeqListPrint(SeqList* ps);
//���ռ��Ƿ���
void SeqListCheckCapacity(SeqList* ps);

//β��
void SeqListPushBack(SeqList* ps, SLDataType x); 
//βɾ
void SeqListPopBack(SeqList* ps); 


//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x); 
//ͷɾ
void SeqListPopFront(SeqList* ps);

//����
int SeqListFind(SeqList* ps, SLDataType x); 

//�м�ĳ������
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x); 

//ָ��λ��ɾ��
void SeqListErase(SeqList* ps, size_t pos); 

//ָ��Ԫ��ɾ��
void SeqListRemove(SeqList* ps, SLDataType x); 

//�޸�ĳ��λ�õ�ֵ
void SeqListModify(SeqList* ps, size_t pos, SLDataType x); 

//ð������
void SeqListBubbleSort(SeqList* ps);

//ð������
void SeqListBubbleSort(SeqList* ps);

//���ֲ���
int SeqListBinaryFind(SeqList* ps, SLDataType x);

#endif