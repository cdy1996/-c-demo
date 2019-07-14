#include <iostream>
#include <typeinfo>
#include "MmapTest.c"
using namespace std;

int main() {
//    mmapTest();
//    mmapDemo();
FILE *file;
    std::cout << "Hello, World!" << std::endl;
    char balance[] = {1};

    int *array = (int *) malloc(sizeof(int) * 10);

    array[0] = 1;
//    printf("%d", *array);
//    printf("%d", array[1]);

    int fd = 0;
    fd = open("/home/cdy/CLionProjects/demo/mmap_test", O_RDWR);

    read(fd, (void *) array, sizeof(int) * MAX);

//    try {
//        pwrite(fd, array, 1, MAX+1);

//    }catch ( exception &e )
//     {
//            cerr << "Caught " << e.what( ) << endl;
//            cerr << "Type " << typeid( e ).name( ) << endl;
//     };


    printf("%c",array[0]);
    pwrite(fd, balance, 1, 2);
    free(array);

    return 0;
}