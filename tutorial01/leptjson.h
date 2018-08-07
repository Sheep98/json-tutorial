#ifndef LEPTJSON_H__
#define LEPTJSON_H__

//lept_type 枚举变量 表示了JSON的七个数据类型
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;
//lept_value 数据结构 我们最终是要实现一个树的数据结构，所以每个节点用lept_value表示成一个JSON值
typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,             //无错
    LEPT_PARSE_EXPECT_VALUE,	   //若一个 JSON 只含有空白，传回 LEPT_PARSE_EXPECT_VALUE
    LEPT_PARSE_INVALID_VALUE,	   //若值不是那三种字面值，传回 LEPT_PARSE_INVALID_VALUE。
    LEPT_PARSE_ROOT_NOT_SINGULAR   //若一个值之后，在空白之后还有其他字符，传回 LEPT_PARSE_ROOT_NOT_SINGULAR。
};
//传入根节点指针和一个C字符串
//该函数解析JSON
int lept_parse(lept_value* v, const char* json);
//获取类型
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
