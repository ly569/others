#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector { // 顺序表的结构定义
    int *data; // 数据类型为int
    int size, length; // 顺序表大小和长度
} Vector;

Vector *init(int n) { // 顺序表的初始化操作，返回一个指向顺序表结构的指针，n表示顺序表的大小
    Vector *vec = (Vector *)malloc(sizeof(Vector)); // 开辟空间，强转为Vector指针类型
    vec->data = (int *)malloc(sizeof(int) * n); // 数据字段，动态开辟大小为n
    vec->size = n; // 修改当前顺序表大小为n
    vec->length = 0; // 修改当前顺序表长度为0
    return vec; // 返回指向顺序表的指针
}

int expand(Vector *vec) { // 扩容操作
    int extr_size = vec->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extr_size));
        if (p) break;
        extr_size /= 2;
    }
    if (p == NULL) return 0;
    vec->data = p;
    vec->size += extr_size;
    return 1;
}

int insert(Vector *vec, int ind, int val) { // 传入顺序表，ind代表插入位置，val代表插入值
    if (vec == NULL) return 0; // 判断顺序表是否存在
    if (ind < 0 || ind > vec->length) return 0; // 不合法插入
    if (vec->length == vec->size) { // 顺序表满
        if (!expand(vec)) return 0;
        printf("expand success! size = %d\n", vec->size);
    }
    for (int i = vec->length; i > ind; i--) { // 将ind位置空出，将val插入
        vec->data[i] = vec->data[i - 1]; // 元素后移
    }
    vec->data[ind] = val; // 维护结构
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind) { // 传入顺序表，ind代表删除位置
    if (vec == NULL) return 0; // 判断顺序表是否存在
    if (ind < 0 || ind >= vec->length) return 0; // 判断合法性
    for (int i = ind + 1; i < vec->length; i++) { // 将ind位置空出
        vec->data[i - 1] = vec->data[i]; // 元素前移
    }
    vec->length -= 1; // 维护结构
    return 1;
}

void output(Vector *vec) { // 打印顺序表
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        i && printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Vector *vec) { // 顺序表的清空操作，传入指针
    if (vec == NULL) return ;
    free(vec->data); // 释放数据域
    free(vec); // 释放顺序表
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *vec = init(MAX_OP);
    int op, ind, val;
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        ind = rand() % (vec->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 3: {
                printf("erase item at %d from Vector = %d\n", ind, erase(vec, ind));
            } break;
        }
        output(vec);
        printf("\n");
    }
    clear(vec);
    return 0;
}