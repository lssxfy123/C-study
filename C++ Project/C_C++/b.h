#ifndef B_H
#define B_H

// ͷ�ļ��ڱ���ʱֱ�Ӳ��뵽Դ�ļ���
// cpp�ļ���Ĭ�϶���__cplusplus
// ֮���Բ�����������ָ��#ifdef
// ����Ϊ�������cpp�ļ�����ֱ��
// ����#include "a.h"
#ifdef __cplusplus

// extern "C"����ʾ������
// a.h�еĺ�������C���Եķ�ʽ����
// C++��֧�ֺ������أ���C���Բ�֧��
// �⵼���ڱ���ʱ���������ڲ������ķ�ʽ
// ��ͬ
extern "C"
{
#endif

#include "a.h"

#ifdef __cplusplus
};

#endif

void func();

#endif  // B_H
