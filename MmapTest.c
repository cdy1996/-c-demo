//
// Created by cdy on 7/14/19.
//


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/mman.h>
#include "MmapTest.h"


#define MAX 1


void mmapDemo(){
    int fd;
    void *start;
    struct stat sb;
    fd = open("/etc/passwd", O_RDONLY); /*打开/etc/passwd */
    fstat(fd, &sb); /* 取得文件大小 */
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(start == MAP_FAILED) /* 判断是否映射成功 */
        return;
    printf("%s", start);
    munmap(start, sb.st_size); /* 解除映射 */
    close(fd);
}

void mmapTest() {
    int i = 0;
    int count = 0, fd = 0;
    struct timeval tv1, tv2;
    struct stat sb;
    int *array = (int *) malloc(sizeof(int) * MAX);

/*read*/

    gettimeofday(&tv1, NULL);
    fd = open("/home/cdy/CLionProjects/demo/mmap_test", O_RDWR);
    fstat(fd, &sb);
    read(fd, (void *) array, sizeof(int) * MAX);

    for (i = 0; i < MAX; ++i) {
        printf("%d",array[i]);
//        ++array[i];
    }
//    if (sizeof(int) * MAX != write(fd, (void *) array, sizeof(int) * MAX)) {
//        printf("Writing data failed.../n");
//        return;
//    }
    free(array);
    close(fd);
    gettimeofday(&tv2, NULL);
    printf("Time of read/write: %dms/n", tv2.tv_usec - tv1.tv_usec);

/*mmap*/

    gettimeofday(&tv1, NULL);
    fd = open("/home/cdy/CLionProjects/demo/mmap_test", O_RDWR);
    array = (int *)mmap(NULL, sizeof(int) * MAX, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for (i = 0; i < MAX; ++i) {
        printf("%d",array[i]);
//        ++array[i];
    }
    /* 解除映射 */
    munmap(array, sizeof(int) * MAX);
    /* sync */
    msync(array, sizeof(int) * MAX, MS_SYNC);
    free(array);
    close(fd);
    gettimeofday(&tv2, NULL);
    printf("Time of mmap: %dms/n", tv2.tv_usec - tv1.tv_usec);


}




