#ifndef __PUBFUNC_H__
#define __PUBFUNC_H__

#include "base/stringUtils.h"
#include <string>
#include <vector>
#include <iostream>
#include "base/CoreException.h"
__USING_WILLOW_NS
using namespace std;

#define exstrcpy(dest_array, source) estrncpy(dest_array, source, #dest_array, #source, __FILE__, __LINE__)
//#define  CopyToCharArray
/**
  * Description     : ����strncpy����ͬ�������Դ�ַ������ȳ���Ԥ��ʱֱ�����쳣����ӡ��־
  * @param[out] dest    : Ŀ���ַ��������óɹ������׳��쳣ʱ��ŵ�����\0��β���ַ�����
  * @param[in] source   : Դ�ַ���
  * @param[in] dest_name        : Դ�ַ������壬Ĭ��Ϊdest����������Ŀɲ���
  * @param[in] source_name      : Ŀ���ַ������壬Ĭ��Ϊsource����������Ŀɲ���
  * @return         : Ŀ���ַ�������
  * @note           : Ч�ʽϵͣ�����ֻ�ڷ�����ʹ��
  * @exception      : ���Դ�ַ������ȳ���Ŀ���ַ�������ַ���������׳�stl�쳣exception�����lenΪ0Ҳ�����쳣
  */
template<int BufferSize>
inline int estrncpy(char (&dest)[BufferSize], const char*source,
             const char *dest_name = "dest",
             const char *source_name = "source", const char *filename = "", int line = 0)
{
    //ֻ��һ���ַ�������û����
    base_static_assert( BufferSize > 1 );

    size_t i;
    //����source���ݵ�dest�У���ิ��len���ַ�
    for (i = 0; i < BufferSize && (source[i] != '\0'); i++)
    {
        dest[i] = source[i];
    }

    //δ�����ĩβ����\0
    if (i != BufferSize)
    {
        dest[i] = '\0';
        //BASE_LOG_DEBUG("%s=[%s]", dest_name, dest);
    }
    else
    {
        //���������BufferSize���ַ���Ȼδ����\0
        //����ַ�������
        dest[ (int) BufferSize - 1 ] = '\0';
        char errbuf[1024];
        sprintf(errbuf, "Դ�ַ���[%s]���ȳ���Ԥ��! Ŀ���ַ���[%s]���ռ�Ϊ[%d]��",
            source_name, dest_name, (int) BufferSize);
			
        throw CoreException(errbuf);
    }

    return (int) i;
}

#endif