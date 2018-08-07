#ifndef LEPTJSON_H__
#define LEPTJSON_H__

//lept_type ö�ٱ��� ��ʾ��JSON���߸���������
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;
//lept_value ���ݽṹ ����������Ҫʵ��һ���������ݽṹ������ÿ���ڵ���lept_value��ʾ��һ��JSONֵ
typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,             //�޴�
    LEPT_PARSE_EXPECT_VALUE,	   //��һ�� JSON ֻ���пհף����� LEPT_PARSE_EXPECT_VALUE
    LEPT_PARSE_INVALID_VALUE,	   //��ֵ��������������ֵ������ LEPT_PARSE_INVALID_VALUE��
    LEPT_PARSE_ROOT_NOT_SINGULAR   //��һ��ֵ֮���ڿհ�֮���������ַ������� LEPT_PARSE_ROOT_NOT_SINGULAR��
};
//������ڵ�ָ���һ��C�ַ���
//�ú�������JSON
int lept_parse(lept_value* v, const char* json);
//��ȡ����
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
