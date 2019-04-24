#pragma once
typedef int DataType;
typedef struct SeqList {
	DataType* _array;//ָ��̬���ٵ�����
	int _capacity;//˳�����ܴ�С
	int _size;//˳�������ЧԪ�صĸ���
}SeqList, *PSeq;

//˳���ĳ�ʼ��
void SeqListInit(PSeq ps, int capacity);

//��˳����β������ֵΪdata��Ԫ��
void SeqListPushBack(PSeq ps, DataType data);

//ɾ��˳������һ��Ԫ��
void SeqListPopBack(PSeq ps);

//��˳����ͷ������ֵΪdata��Ԫ��
void SeqListPushFront(PSeq ps, DataType data);

//ɾ��˳���ͷ����Ԫ��
void SeqListPopFront(PSeq ps);

//��˳���posλ�ò���ֵΪdata��Ԫ��
void SeqListInsert(PSeq ps, int pos, DataType data);

//ɾ��˳�����posλ�õ�Ԫ��
void SeqListErase(PSeq ps, int pos);

//��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1
int SeqListFind(PSeq ps, DataType data);

//���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط���ֵ���ǿշ���0
int SeqListEmpty(PSeq ps);

//����˳�������ЧԪ�صĸ���
int SeqListSize(PSeq ps);

//����˳����������С
int SeqListCapacity(PSeq ps);

//��˳����е�Ԫ�����
void SeqListClear(PSeq ps);

//ɾ��˳����е�һ��ֵΪdata��Ԫ��
void SeqListRemove(PSeq ps, DataType data);

//����˳���
void SeqListDestory(PSeq ps);

//˳��������
void CheckCapacity(PSeq ps);

void PrintSeqList(PSeq ps);