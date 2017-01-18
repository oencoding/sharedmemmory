/*
 * =====================================================================================
 *
 *       Filename:  event_2.h
 *
 *        Version:  1.0
 *        Created:  2012��07��06��
 *       Revision:  none
 *       Compiler:  gcc
 *	  Description:  ��ģ������̼߳��¼����ƣ�����DDNS,PPPOE,SMTP��ģ�顣
 *
 *         Author:  huangws
 *        Company:  jxj
 *
 * =====================================================================================
 */

#ifndef EVENT_H
#define EVENT_H

/*************************************************************
* �������ܣ�����EVENT
* �����������
* �����������
* ����ֵ  ��<0-ʧ�ܣ�>0-EVENT���
*************************************************************/
int event_open();

/*************************************************************
* �������ܣ��ȴ��¼�
* ���������handle: �¼����
*           want: �����յ�event
* ���������events:���յ����¼���Ϣ
* ����ֵ  ��<0-ʧ�ܣ�0-�ɹ�
*************************************************************/
int event_wait(int handle, unsigned int want, unsigned int* events);

/*************************************************************
* �������ܣ������¼�
* ���������handle: �¼����
* ���������events:�������¼�
* ����ֵ  ��<0-ʧ�ܣ�0-�ɹ�
*************************************************************/
int event_post(int handle, unsigned int events);

/*************************************************************
* �������ܣ������¼����ͷ���Դ
* ���������handle: �¼����
* �����������
* ����ֵ  ��<0-ʧ�ܣ�0-�ɹ�
*************************************************************/
int event_close(int handle);

#endif

