cmake_minimum_required(VERSION 3.24)
project(ATM)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATM main.cpp ATM.cpp colectie.cpp Iterator.cpp tranzactie.cpp ui.cpp ATM.h colectie.h Iterator.h tranzactie.h ui.h)
