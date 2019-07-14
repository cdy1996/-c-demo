//
// Created by cdy on 7/14/19.
//

#ifndef UNTITLED_MMAPTEST_H
#define UNTITLED_MMAPTEST_H

#endif //UNTITLED_MMAPTEST_H

//通过read和mmap两种方法分别对硬盘上一个名为“mmap_test”的文件进行操作，文件中存有10000个整数，程序两次使用不同的方法将它们读出，加1，再写回硬盘。通过对比可以看出，read消耗的时间将近是mmap的两到三倍。
void mmapTest();

//利用mmap()来读取/etc/passwd 文件内容
void mmapDemo();
