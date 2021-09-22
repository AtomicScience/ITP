cmake_minimum_required(VERSION 3.20)
project(ITP C)

set(CMAKE_C_STANDARD 99)

add_executable(ITP main.c include/structures/ExamDay.h include/structures/structureScan.h include/structures/structurePrint.h structureScan.c include/scanUtils.h scanUtils.c include/encryption.h encryption.c)
