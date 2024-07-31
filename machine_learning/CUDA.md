# CUDA 基础

CUDA中host和device
host是CPU和它的内存
device是GPU和它的内存

## CUDA 程序执行流程
1. 初始化：在Host端初始化数据，并分配内存。
2. 内存传输：将数据从Host内存传输到Device内存。
3. Kernel调用：在Device端执行Kernel函数。Kernel函数在多个线程上并行执行。
4. 内存传输：将计算结果从Device内存传输回Host内存。
5. 清理：释放分配的内存资源。
