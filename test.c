#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include "test.h"
void SeqListInit(PSeq ps, int capacity) {
	ps->_size = 0;
	ps->_capacity = capacity;
	ps->_array = (DataType*)malloc(sizeof(DataType)*capacity);
	if (ps->_array == NULL) {
		assert(0);//借此来确定是空间申请失败的问题，方便下一步调试
		return;
	}
}
void SeqListPushBack(PSeq ps, DataType data) {
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void SeqListPopBack(PSeq ps) {
	assert(ps);
	if (SeqListEmpty(ps)) {
		return;
	}
	ps->_size--;
}
void SeqListPushFront(PSeq ps, DataType data) {
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i > 0; --i) {
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}
void SeqListPopFront(PSeq ps) {
	assert(ps);
	if (SeqListEmpty(ps)) {
		return;
	}
		
	for (int i = 1; i < ps->_size; ++i) {
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}
void SeqListInsert(PSeq ps, int pos, DataType data) {
	assert(ps);
	if (pos<0 || pos> ps->_size)
		return;
	CheckCapacity(ps);
	for (int i = ps->_size; i > pos; --i) {
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}
void SeqListErase(PSeq ps, int pos) {
	assert(ps);
	if (pos<0 || pos>= ps->_size)
		return;
	for (int i = pos+1; i < ps->_size; ++i) {
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}
int SeqListFind(PSeq ps, DataType data) {
	assert(ps);
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data) {
			return i;
		}
	}
	return -1;
}
int SeqListEmpty(PSeq ps) {
	assert(ps);
	if (ps->_size == 0) {
		return -1;
	}
	return 0;
}
int SeqListSize(PSeq ps) {
	assert(ps);
	return ps->_size;
}
int SeqListCapacity(PSeq ps) {
	assert(ps);
	return ps->_capacity;
}
void SeqListClear(PSeq ps) {
	assert(ps);
	ps->_size = 0;
}
void SeqListRemove(PSeq ps, DataType data) {
	assert(ps);
	int ret = SeqListFind( ps, data);
	if (ret != -1) {
		SeqListErase(ps, ret);
	}
	else
		printf("没有找到值为data的元素！\n");
}
void SeqListDestory(PSeq ps) {
	if (ps->_array) {
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}
void CheckCapacity(PSeq ps) {
	assert(ps);
	if (ps->_size == ps->_capacity) {
		//printf("空间不足，进行扩容！\n");
		int newCapacity = ps->_capacity * 2;
		int* p = (DataType*)malloc(sizeof(DataType)*ps->_capacity);
		if (p == NULL) {
			assert(0);
			return;
		}
		for (int i = 0; i < ps->_size; ++i) {
			p[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = p;
		ps->_capacity = newCapacity;
	}
	
}
void PrintSeqList(PSeq ps) {
	assert(ps);
	for (int i = 0; i < ps->_size; ++i) {
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
void main() {
	int capacity = 10;
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 0);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	PrintSeqList(&s);
	SeqListPushBack(&s, 1);
	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	PrintSeqList(&s);
	SeqListInsert(&s, 1, 5);
	PrintSeqList(&s);
	SeqListErase(&s, 2);
	PrintSeqList(&s);
	SeqListRemove(&s, 2);
	PrintSeqList(&s);
	printf("%d\n",SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	//SeqListDestory(&s);


	system("pause");
	return;
}