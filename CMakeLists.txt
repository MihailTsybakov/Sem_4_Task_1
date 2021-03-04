cmake_minimum_required(VERSION 3.1)

project(Task_1_Sem_4)

include_directories(${PROJECT_SOURCE_DIR})

set(TASK_1_SRC main.cpp Create.cpp CIntN.cpp Autotest.cpp exceptions.cpp CIntN0.cpp CIntN1.cpp factory.cpp)
set(TASK_1_HDR CIntN.h Create.h Autotest.h CIntN0.h CIntN1.h factory.h)

add_executable(${PROJECT_NAME} ${TASK_1_SRC} ${TASK_1_HDR})
